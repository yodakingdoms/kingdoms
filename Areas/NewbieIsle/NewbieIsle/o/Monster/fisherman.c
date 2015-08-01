//==================================================================
// fisherman.c - The fisherman in the Fish Tales quest
//               Also a lore skill raiser. Fish tales are a sort of
//               lore, are they not?:)
//==================================================================
// Not being able to wake him up was supposed to make him more real
// but it only makes him annoying. Changed him so players can wake
// him up if he's sleeping. Him going to sleep is real enough
// 031113 Yoda
//==================================================================
// Hissing players should be able to talk to him now
// 040731 Yoda
//==================================================================
#pragma strict_types
#include "../def.h"
inherit STD_SKILL_RAISER skill_raiser;
inherit MASTER_MONSTER;
inherit STD_TELL_LONG;
// This stuff seems to bug!
// I've replaced it with hourly (mud time)
// repeating alarms
// Yoda 990416
//inherit STD_EVENT;

void   create_object(void);
int    is_unkillable(void);
string unkillable_string(object attacker);
void   init(void);
void   catch_tell(string message);
void   player_introduced(object player);
void   player_asked(object player);
void   tell_about_fishing(int line);
int    do_tell_fish_tale(string str);
int    raise_skill(string skill); // Masked a bit from the master_skill_raiser
int    do_wake(string str);
int    query_sleeping(void);
void   greet_player(object player);
void   check_time(void);
void   go_to_sleep(int command);
void   wake_up(int command);
int    deny_object(object obj);

int asleep,doing_command,telling;
mapping current_questors = ([]);  // Player : Current 'points' for fish tales
mapping tales_told = ([]);        // Player : Number of fish tales told

void create_object(void)
{
  set_name("andalf");
  add_id("fisherman");
  add_id("man");
  set_short("Andalf the Fisherman, sitting on a bench");
  set_level(4);
  set_hp(150);
  set_wc(5);
  set_new_ac(10);
  set_skill("combat",30);
  set_skill("unarmed",30);
  set_al(20);
  set_gender(1);
  set_race("human");
  set_long("This is Andalf the old fisherman of Newbie Island. He looks "+
           "just as old and grumpy as every other fisherman you will come "+
           "across in the kingdoms. He sure looks as if he could tell some "+
           "tales about fishing, though. Perhaps if you asked him about "+
           "fishing, he would tell you a fish tale?\n");

  load_chat(5,({"Andalf grumbles: Damn I'm sick of this island.\n",
                "Andalf grumbles: The most important thing for a fisherman "+
                "is the ability to tell a damn fish tale.\n",
                "Andalf grumbles something incomprehensible.\n",
                "Andalf grumbles: You can raise yer damn lore skill here.\n"
                }));
  load_a_chat(20,({"Andalf grumbles: I've wrestled damn giant squids bigger "+
                   "than you...\n",
                   "Andalf grumbles: I've used shipmates of your size for "+
                   "bait for my damn whale hooks...\n"}));

  // Set events apparently don't work as they should
  set_alarm(2.0,300.0,"check_time");
  //set_event(21,"check_time");
  //set_event(5,"check_time");

  add_property("no_flee");

  ok_skill = ({ "lore" });
  limit_here = ({ "lore",50 });
}

string unkillable_string(object attacker)
{
  return ""; // Prints a 0 if this is left out unfortunately
}

int is_unkillable(void)
{
  if(asleep)
  {
    W("Andalf wakes up.\n");
  }
  W("Andalf *BONK*s you hard on top of your head.\n"+
    "Andalf grumbles: Where are yer damn manners? Trying to attack "+
    "an old fisherman like that!\n");
  S("Andalf *BONK*s "+TP->QN+" hard on top of "+TP->QPO+" head as "+
    TP->QN+" tries to attack him.\n");
  TP->command("shame");
  if(asleep)
  {
    W("Andalf goes back to sleep.\n");
  }
  add_nasty_player(TP);
  return 1;
}

void init(void)
{

  add_action("do_wake","wake");
  add_action("do_tell_fish_tale","tell");
  skill_raiser::this_init();
  ::init();
}

void catch_tell(string message)
{
  int i;
  object player;
  string name,junk;
  string *junk_array;

  if(asleep) return;

  if(sscanf(message,"%s arrives from the north%s",name,junk) == 2)
  {
    if(!asleep && !doing_command)
    {
      player = find_player(lower_case(name));
      set_alarm(2.0,0.0,"greet_player",player);
    }
  }

  if(sscanf(message,"%s says: %s",name,junk) == 2 ||
     sscanf(message,"%s hisses: %s",name,junk) == 2)
  {
    junk_array = explode(junk," ");
    for(i = 0; i < sizeof(junk_array); ++i)
    {
       if(lower_case(junk_array[i]) == lower_case(name) ||
          lower_case(junk_array[i]) == lower_case(name)+"\n" ||
          lower_case(junk_array[i]) == lower_case(name)+".\n")
      {
        player = find_player(lower_case(name));
        if(player && present(player,ENV(TO)))
	{
          if(query_nasty_player(player))
          {
            tell_room(ENV(TO),"Andalf grumbles: I know yer damn name already "+
                      "you damn fisherman murderer.\n");
            return;
	  }

          if(query_friendly_player(player))
	  {
            tell_room(ENV(TO),"Andalf grumbles: I know yer damn name "+
                      "already, "+player->QN+".\n");
            return;
	  }
          set_alarm(1.0,0.0,"player_introduced",player);
	}
        else
	{
          tell_room(ENV(TO),"Andalf grumbles: You damn liar, that's "+
                    "not your name.\n");
	}
      }
    }
  }

  if(sscanf(message,"%s asks you: about fish%s",name,junk) == 2 ||
     sscanf(message,"%s asks you: about tale%s",name,junk) == 2 ||
     sscanf(message,"%s asks you: fish%s",name,junk) == 2 ||
     sscanf(message,"%s asks you: tale%s",name,junk) == 2)
  {
    name = name[1 .. (strlen(name))];
    player = find_player(lower_case(name));
    if(present(player,ENV(TO)))
    {
      if(!telling)
      {
        tell_room(ENV(TO),player->QN+" asks Andalf about fishing.\n",player);
        set_alarm(1.0,0.0,"player_asked",player);
      }
      else
      {
        tell_object(player,"Andalf is already talking about that.\n");
      }
    }
  }
}

void player_introduced(object player)
{
  tell_room(ENV(TO),"Andalf grumbles: How nice of you to introduce "+
	    "yer damn self, "+player->QN+".\n");
  add_friendly_player(player);
}

void player_asked(object player)
{
  if(query_friendly_player(player))
  {
    if(TP->test_flag(188))
    {
      tell_room(ENV(TO),"Andalf grumbles: I've told ye about damn fishing "+
                "already, "+TP->QN+". You solved the damn quest too if I "+
                "remember correctly.\n");
      return;
    }
    tell_room(ENV(TO),"Andalf grumbles: You've come to the right damn place "+
              "if you want to know about damn fishing, "+player->QN+".\n");
    set_alarm(2.0,0.0,"tell_about_fishing",0);
    telling = 1;
    current_questors[player] = 0;
  }
  else
  if(query_nasty_player(player))
  {
    tell_room(ENV(TO),"Andalf grumbles: First ye try to damn kill me and "+
              "now you want me to tell you about damn fishing?! Forget it, "+
              player->QN+"!\n");
  }
  else
  {
    tell_room(ENV(TO),"Andalf grumbles: You could at least be so polite as "+
              "to let me know yer damn name before ye start asking "+
              "questions.\n");
  }
}

void tell_about_fishing(int line)
{
  string *fishing = ({"The most important thing for a fisherman is the "+
                      "ability to tell a damn fish tale.\n",
                      "Take me for example, I once caught a whale with my "+
                      "bare hands, and then had to wrestle a giant squid for "+
                      "the corpse. And I won too. And that is a damn true "+
                      "fish tale.\n",
                      "These days I'm too damn old for such feats though, "+
                      "so telling those damn tales just depresses me.\n",
                      "I do enjoy listening to others damn fish tales though "+
                      "so perhaps you have one to tell me?\n",
                      "You need to catch some damn fish first though so go "+
                      "do that. There's a damn stone down by the west shore "+
                      "that is a good place for damn fishing.\n",
                      "Guess yer gonna need a damn fishing pole too. Think "+
                      "I left my damn one somewhere on the slope down to "+
                      "the damn beach. Ye could go look for that one if "+
                      "you haven't got one already.\n",
                      "Now go catch some damn fish and then come back here "+
                      "and impress me with some damn tales of how you "+
                      "caught them.\n"});

  if(!asleep)
  {
    tell_room(ENV(TO),"Andalf grumbles: "+fishing[line]+"\n");

    if(line < 6 && sizeof(ENV(TO)->query_players_here()))
    {
      set_alarm(5.0,0.0,"tell_about_fishing",++line);
    }
    else
    {
      telling = 0;
    }
  }
  else
  {
    telling = 0;
  }
}

int do_tell_fish_tale(string str)
{
  int story;
  object fish;

  if(str == "tale" || str == "fish tale" || str == "a tale" ||
     str == "a fish tale" || str == "fishtale" || str == "a fishtale")
  {
    if((fish = present("_fish_tale_quest_fish_",TP)))
    {
      if(query_nasty_player(TP))
      {
        tell_room(ENV(TO),"Andalf grumbles: Forget it, "+TP->QN+". For all "+
                  "I know you might be trying to kill me again.\n");
        return 1;
      }

      if(!(query_friendly_player(TP)))
      {
        tell_room(ENV(TO),"Andalf grumbles: I'd like to know yer damn name "+
                  "before ye start telling me fish tales.\n");
        return 1;
      }

      if(TP->test_flag(188))
      {
        tell_room(ENV(TO),"Andalf grumbles: You've already told me enough "+
                  "damn fish tales, "+TP->QN+". Telling me more won't get "+
                  "you more damn xp, heh.\n");
        return 1;
      }

      if(telling)
      {
        W("Andalf is busy talking about fishing.\n");
        return 1;
      }

      if(!(fish->query_tale_told()))
      {
        story = random(4) + (TP->query_skill("lore")/10);

        W("You say: ");
        S(TP->QN+" says: ");

        switch(story)
	{
          case 0: tell_long_message(({"This fish... It's really big! I mean "+
                                      "look at it! It was really hard to "+
                                      "catch it too!\n",
                                      "Andalf snorts at the lameness of that "+
                                      "fish tale.\n"}),2.0,ENV(TO));
            break;
          case 1: tell_long_message(({"Wow, this was some catch, this fish. "+
                                      "I nearly dropped it back into the "+
                                      "water when I removed the hook!\n",
                                      "Andalf does not look too impressed "+
                                      "with that fish tale.\n"}),2.0,ENV(TO));
            break;
          case 2: tell_long_message(({"A fine catch indeed this one. It "+
                                      "snapped my line twice, but I hooked "+
                                      "again and finally reeled it in!\n",
                                      "Andalf nods, politely trying to look "+
                                      "impressed by that fish tale.\n"}),
                                      2.0,ENV(TO));
            break;
          case 3: tell_long_message(({"This fine fish pulled me down from "+
                                      "the stone were I sat. I had to grab "+
                                      "it with my bare hands and wrestle it "+
                                      "to catch it. I saw skeletons on the "+
                                      "bottom from its previous victims, so "+
                                      "you can be sure it was a vicious "+
                                      "fight!\n",
                                      "Andalf grumbles: Well that was an "+
                                      "attempt at a real damn fish tale at "+
                                      "least.\n"}),
                                      2.0,ENV(TO));
            break;
          default: tell_long_message(({"This fish could have destroyed the "+
                                       "kingdoms! I hooked the fish and it "+
                                       "dragged me off to sea as I held on "+
                                       "to the pole! All its relatives "+
                                       "followed, destroying ships we "+
                                       "encountered. Finally the Kordic navy "+
                                       "tried to engage this fish, but were "+
                                       "defeated. In the end, up by the north"+
                                       " pole, it and its relatives got tired"+
                                       " and I could finally reel it in. What"+
                                       " a magnificent struggle it was!\n",
                                       "Andalf grumbles: Well, that's as good"+
                                       " a damn fish tale as you will ever "+
                                       "be able to tell.\n"}),2.0,ENV(TO));
            break;
	}
        current_questors[TP] += (story + fish->query_weight());
        ++tales_told[TP];
        fish->set_tale_told();

        if(current_questors[TP] > 15)
	{
          tell_long_message(({"","Andalf grumbles: Enough, you still have "+
                              "a lot to learn, "+TP->QN+". Inserting a 'damn'"+
                              " everywhere it's possible in the damn tale for"+
                              " example, but I think you might learn that in "+
                              "time. I'm pleased with yer damn performance "+
                              "for now so congratulations for solving the "+
                              "quest. Take yer damn quest xp and be on "+
                              "yer damn way.;)\n"}),
                              2.1,ENV(TO));
          write_file("/areas/Lars/NewbieIsle/log/Fishermen",
                     C(TP->QRN)+" became a real fisherman at level "+
                     TP->query_level()+". Time: "+ctime(time())+".\n");
          if(!(TP->test_flag(188)))
	  {
            if(TP->query_skill("lore") < 10)
	    {
              tell_long_message(({"","You feel you really learned some "+
                                 "storytelling techniques from that tip "+
                                 "Andalf gave you about adding a 'damn' into "+
                                 "every other sentence.\n"}),3.0,ENV(TO));
              TP->set_skill("lore",10);
	    }
            (NOBJECT+"fish_tale_quest_obj")->quest_solved(TP);
            TP->add_exp((NOBJECT+"fish_tale_quest_obj")->
                            query_experience(TP->query_level()),1);
	  }
          return 1;
	}
        else
        if(tales_told[TP] < 3)
	{
          tell_long_message(({"","Andalf grumbles: So, tell me another damn "+
                              "one.\n"}),2.5,ENV(TO));
	}

        if(tales_told[TP] >= 3)
	{
          tell_long_message(({"","Andalf grumbles: Better go catch some more "+
                              "damn fish if you want to impress me enough"+
                              ", "+TP->QN+".\n"}),2.5,ENV(TO));
          tales_told[TP] = 0;
          (NROOM+"fishing_stone")->reset_player(TP);
          return 1;
	}
        return 1;
      }
      else
      {
        W("Andalf grumbles: You've told a tale of that damn fish already. "+
          "Go drop it somewhere else and bring a new one and tell a tale "+
          "about that one instead.\n");
        return 1;
      }
    }
    else
    {
      W("Andalf grumbles: I don't see you carrying a damn fish to tell "+
        "a tale about.\n");
      return 1;
    }
  }
}

// Masked a bit from /std/guild/master_skill_raiser to better
// suit this particular monster
int raise_skill(string skill)
{
  if(asleep || skill != "lore")
  {
    return 0;
  }

  if(query_nasty_player(TP))
  {
    W("Andalf grumbles: No way I'm going to teach someone who's tried to "+
      "kill me any damn lore skill.\n");
    return 1;
  }

  if(!query_friendly_player(TP))
  {
    W("Andalf grumbles: I'd like to know yer damn name if I'm going to teach "+
      "you any damn lore skill.\n");
    return 1;
  }

  W("Andalf grumbles: ");
  skill_raiser::raise_skill(skill);
  return 1;
}

int do_wake(string str)
{
  if(asleep)
  {
    if(str == "fisherman" || str == "man" || str == "andalf")
    {
      W("You wake the fisherman. He looks really grumpy.\n");
      S(TP->QN+" steps over to the bed and wakes the fisherman. He looks "+
        "really grumpy.\n");
      tell_room(ENV(TO),"Andalf grumbles REALLY loudly.\n");
      wake_up(0);
      return 1;
    }
    notify_fail("Wake who?\n");
  }
}

int query_sleeping(void)
{
  return asleep;
}

void greet_player(object player)
{
  // Added so he doesn't greet players who come in and leave within 2 seconds
  // and say hello when they're not in the same room
  // Yoda - 031115
  if(!present(player,ENV(TO)))
  {
    tell_room(ENV(TO),"Andalf grumbles: Whoever that was, he, she or it " +
              "was in a damn hurry.\n",player);
    return;
  }

  if(player->test_flag(188) && !(query_nasty_player(player)))
  {
    add_friendly_player(player);
  }

  if(query_unknown_player(player))
  {
    tell_object(player,"Andalf peers at you and grumbles: Greetings, "+
                "traveller. I don't think I have seen you here before.\n");
    tell_room(ENV(TO),"Andalf grumbles a greeting as "+player->QN+" enters "+
              "the room.\n",player);
    add_met_player(player);
  }
  else
  {
    if(query_met_player(player))
    {
      tell_object(player,"Andalf grumbles: Oh, it's you again. Still don't "+
                  "know yer damn name though.\n");
      tell_room(ENV(TO),"Andalf grumbles something to "+player->QN+".\n",
                player);
      return;
    }

    if(query_nasty_player(player))
    {
      tell_room(ENV(TO),"Andalf grumbles: Ack, it's damn "+TP->QN+". Go "+
                "away, you have no business here, damn landlubber. Or are "+
                "you going to try to kill me again?\nAndalf grumbles.\n");
      return;
    }

    if(query_friendly_player(player))
    {
      tell_room(ENV(TO),"Andalf grumbles: Oh, it's you again "+player->QN+
                ". How are you doing?\n");
      if(present("_fish_tale_quest_fish_",player) && !(TP->test_flag(188)))
      {
        tell_room(ENV(TO),"Andalf grumbles: I see you've caught some fish! "+
                  "Let's hear a damn tale about it.\n");
      }
      return;
    }
  }
}

void check_time(void)
{
  if(query_hour() >= 21 || query_hour() < 5)
  {
    if(!asleep)
    {
      tell_room(ENV(TO),"Andalf grumbles: Damn, it's late.\n");
      if(!doing_command)
      {
        go_to_sleep(0);
      }
    }
    else
    {
      tell_room(ENV(TO),"Andalf snores very loudly.\n");
    }
  }
  else
  if(query_hour() >= 5 && query_hour() < 21)
  {
    if(asleep)
    {
      tell_room(ENV(TO),"Andalf yawns.\n");
      wake_up(0);
    }
  }
  else
  {
    tell_room(ENV(TO),"Andalf grumbles.\n");
  }
}

void go_to_sleep(int command)
{
  doing_command = 1;

  switch(command)
  {
    case 0: tell_room(ENV(TO),"Andalf stands up.\n");
            set_short("Andalf the Fisherman");
            set_long("Andalf is on his way to bed.\n");
      break;
    case 1: init_command("open door");
      break;
    case 2: init_command("open door"); // Extra open door in case a player
                                       // closes the door during the delay
            init_command("south");
      break;
    case 3: init_command("close door");
      break;
    case 4: tell_room(ENV(TO),"Andalf climbs into bed and goes to sleep.\n");
            set_short("Andalf the Fisherman, sleeping in his bed");
            set_long("Andalf the fisherman is sleeping at the moment. You "+
                     "could try to wake him up, but he might get mad at you "+
                     "if you do that.\n");
            asleep = 1;
            load_chat(20,({"Andalf snores loudly.\n"}));
      break;
  }
  ++command;

  if(command < 5)
  {
    set_alarm(2.0,0.0,"go_to_sleep",command);
  }
  else
  {
    doing_command = 0;
  }
}

void wake_up(int command)
{
  doing_command = 1;

  switch(command)
  {
  case 0: tell_room(ENV(TO),"Andalf wakes up and stands up.\n");
          set_short("Andalf the Fisherman");
          set_long("Andalf is on his way to his beloved bench.\n");
          asleep = 0;
          load_chat(5,({"Andalf grumbles: Damn I'm sick of this island.\n",
		        "Andalf grumbles: The most important thing for a "+
                        "fisherman is the ability to tell a damn fish tale.\n",
		        "Andalf grumbles something incomprehensible.\n"}));
    break;
  case 1: init_command("open door");
    break;
  case 2: init_command("open door"); // Extra open door in case player closes
                                     // it during the delay
          init_command("north");
    break;
  case 3: init_command("close door");
    break;
  case 4: tell_room(ENV(TO),"Andalf sits down on the bench.\n");
          set_short("Andalf the Fisherman, sitting on a bench");
          set_long("This is Andalf the old fisherman of Newbie Island. He "+
	           "looks just as old and grumpy as every other fisherman "+
	           "you will come across in the kingdoms. He sure looks as "+
	           "if he could tell some tales about fishing, though. "+
	           "Perhaps if you asked him about fishing, he would tell "+
                   "you a fish tale?\n");
    break;
  }
  ++command;

  if(command < 5)
  {
    set_alarm(2.0,0.0,"wake_up",command);
  }
  else
  {
    doing_command = 0;
  }
}

int deny_object(object obj)
{
  if(obj->query_fish_tale_quest_fish())
  {
    if(!asleep)
    {
      W("Andalf grumbles: I don't want yer damn fish, "+
        "I only want ye to <tell fish tale> about the damn thing.\n");
    }
    else
    {
      W("Andalf doesn't seem to want to take the fish. Perhaps "+
        "that is not so strange, since he is sleeping.\n");
    }
    return 1;
  }
}
