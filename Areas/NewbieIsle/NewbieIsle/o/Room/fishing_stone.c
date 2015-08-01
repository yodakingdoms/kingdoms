// Rest in this room -> Fall asleep -> fall into water -> some underwater
// area perhaps?
//------------------------------------------------------------------------
// Added Dreadlord guild to the guilds that don't have to wield the
// pole to fish, doh. Dreadlords weren't open when I wrote this room ;)
// Yoda - 990418
//------------------------------------------------------------------------
#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_SOUND;

void create_object(void);
void reset(int arg);
void init(void);
int  do_swim(string str);
int  do_wade(string str);
int  do_fish(string str);
void watch_float(object fisherman);
void catch_fish(object fisherman);
void threw_one_back(void);
void reset_player(object player);
int  query_fish_tale_quest_fishing_place(void);

mapping fish_caught = ([]);  // [ player:number of fish caught this boot ]
object  *fishermen = ({});   // To check which people are actually fishing.

void create_object(void)
{
  set_short("On a stone in the water");
  set_long("You are standing on a big stone a few feet from the shore. "+
           "The water is clear and it laps gently against the stone. You "+
           "wonder why you bothered coming here at all. Seems like there's "+
           "not much to do here except look at the small fishes swimming "+
           "round the stone near the bottom. You feel safe and calm here as "+
           "the island rises over you to the east and the sea stretches out "+
           "to the west.\n");
  set_new_light(5);
  set_skip_obvious(1);
  set_dragon_visibility(3);
  set_room_hint("Hey, look at those fish. Looks as if this place would be "+
                "a good place to sit down with a fishing pole. Perhaps "+
                "you could find one somewhere else on the island? I've heard "+
                "the best places to look for fishing poles are usually "+
                "someplace that is not too far from the shore either.;)\n");

  add_item("stone","It's the one under your feet");
  add_item("shore","The shore is not far from here. You could easily wade "+
           "back there");
  add_item("water","It's very clear. You can see the bottom and several "+
           "fishes swimming around down there");
  add_item("bottom","The bottom looks sandy and nice");
  add_item("sand","The bottom is covered with a layer of fine sand");
  add_item("fishes","Many different kinds of fish swim around this "+
           "stone. This might be a good place to do some fishing!!!");
  add_item("island","The tiny little island they call Newbie Island");
  add_item("sea","The great grey and blue sea. Far in the distance you "+
           "see the continent of Larsia");
  add_item("continent|larsia|Larsia","You see it far it the distance to the "+
           "west");

  add_sounds(30,70,({"The waves lap gently against the stone.\n",
                     "A fish jumps out of the water a yard from the stone "+
                     "disappearing under the surface again with a *plask*.\n",
                     "A galley ship passes close to the island.\n"}));

  reset(0);
}

void reset(int arg)
{
  // Some people like sorcerers waste their fish by
  // turning them into sp and can't be reset.. 
  fish_caught = ([]);
}

void init(void)
{
  "/sys/admin/room/admin_room"->visit(987);
  add_action("do_swim","swim");
  add_action("do_wade","wade");
  add_action("do_fish","fish");
  ::init();
}

int do_swim(string str)
{
  W("You wouldn't want to scare the fish away!! Besides... Those fish "+
    "might not be very big, but some of them look quite nasty...\n");
  S(TP->QN+" looks down into the water for a while.\n");
  TP->command("worried");
  return 1;
}

int do_wade(string str)
{
  if(str == "back" || str == "to shore" || str == "shore")
  {
    if(member_array(TP,fishermen) > -1)
    {
      W("Patience is the sign of any great fisherman. You can't just leave "+
        "while your float is bobbing on the waves in front of you.\n"+
	     "You stay for a while longer.\n");
      return 1;
    }
    W("You jump down from the stone, back into the water and wade "+
      "back to the shore.\n");
    TP->move_player("jumps down from the stone and wades back to shore",
                    NROOM+"shore3",
                    "comes wading to the shore from the stone",
                    1);
    return 1;
  }
  notify_fail("Wade where?\n");
}

int do_fish(string str)
{
  if(present("fishingpole",TP) || present("fishing pole",TP) ||
     present("fishpole",TP) || present("fish pole",TP))
  {
    if(TP->query_weapon(1)->id("fishingpole") || 
       TP->query_weapon(1)->id("fishing pole") ||
       TP->query_weapon(1)->id("fishpole") ||
       TP->query_weapon(1)->id("fish pole") ||
       TP->query_guild() == NINJA ||
       TP->query_guild() == DEMON ||
       TP->query_guild() == MONK ||
       TP->query_guild() == DREADLORD) 
    {
      if(fish_caught[TP] >= 5)
      {
        W("You don't think you'll be able to catch more fish right now "+
          "than those you already have caught.\n");
        return 1;
      }
   
      if(member_array(TP,fishermen) > -1)
      {
        W("You're already fishing.\n");
        return 1;
      }

      W("You throw the hook and the float into the water and sit down "+
        "to do some fishing!\n");    
      S(TP->QN+" sits down to fish for a while.\n");
      fishermen += ({TP});
      set_alarm(4.0,0.0,"watch_float",TP);
      return 1;
    }
    else
    {
      W("It would be easier to fish if you wielded your fishing pole.\n");
      S(TP->QN+" tries to fish without using the fishing pole "+TP->QPR+
        " has. How odd.\n");
      return 1;
    }
  }
  notify_fail("You need a fishing pole to fish!\n");
}

void watch_float(object fisherman)
{
  set_this_player(fisherman); // Diablos

  if(present("fishingpole",fisherman) ||
     present("fishing pole",fisherman) ||
     present("fishpole",fisherman) ||
     present("fish pole",fisherman))
  {
    if(fisherman->query_weapon(1)->id("fishingpole") || 
       fisherman->query_weapon(1)->id("fishing pole") ||
       fisherman->query_weapon(1)->id("fishpole") ||
       fisherman->query_weapon(1)->id("fish pole") ||
       fisherman->query_guild() == NINJA ||
       fisherman->query_guild() == DEMON ||
       fisherman->query_guild() == MONK ||
       fisherman->query_guild() == DREADLORD)
    {
      tell_object(fisherman,"You watch the float bob up and down as the " +
                  "water gently laps against the stone where you sit.\n");
      set_alarm(4.0,0.0,"catch_fish",fisherman);
    }
    else
    {
       fishermen -= ({ fisherman });
    }
  }
  else
  {
    fishermen -= ({ fisherman });
  }
}

void catch_fish(object fisherman)
{
  object fish;

  set_this_player(fisherman); // Diablos

  if(present("fishingpole",fisherman) ||
     present("fishing pole",fisherman) ||
     present("fishpole",fisherman) ||
     present("fish pole",fisherman))
  {
    if(fisherman->query_weapon(1)->id("fishingpole") || 
       fisherman->query_weapon(1)->id("fishing pole") ||
       fisherman->query_weapon(1)->id("fishpole") ||
       fisherman->query_weapon(1)->id("fish pole") ||
       fisherman->query_guild() == NINJA ||
       fisherman->query_guild() == DEMON ||
       fisherman->query_guild() == MONK ||
       fisherman->query_guild() == DREADLORD)
    {
      // Don't think many players will have fishing skill, but perhaps...;)
      if(fisherman->query_skill("fishing") + 30 > random(50))
      {
        W("You feel a fish grab the hook and you pull it up. It lands on " +
          "the stone next to you.\nCongratulations! You caught a fish!\n");
        S(fisherman->QN+" pulls a fish out of the water with "+fisherman->QPO+
          " fishing pole!\n");
        fish = make(NOBJECT+"fish");
        fish->set_catcher(fisherman);
        ++fish_caught[fisherman];
      }
      else
      {
        W("You feel a fish nibble the bait of the hook, but pull it up "+
          "too late. Some fisherman you are! *heh* Perhaps you should try "+
          "again.\n");
        S(fisherman->QN+" pulls the hook out of the water, but apparently "+
          "too late since there is no fish on it. Some fisherman, *heh*\n");
      }
    }
  }
  fishermen -= ({fisherman});
}

void threw_one_back(void)
{
  if(fish_caught[TP] > 0)
  {
    --fish_caught[TP];
  }
}

void reset_player(object player)
{
  fish_caught[TP] = 0;
}
  
int query_fish_tale_quest_fishing_place(void)
{
  return 1;
}
