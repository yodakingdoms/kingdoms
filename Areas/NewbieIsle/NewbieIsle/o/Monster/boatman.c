//=========================================================================
// boatman.c - The boatman ferrying players from Larstown to Newbie Island.
//             he will bring newbies for free and charge other players more
//             money the higher level they are. Hopefully this will let
//             newbies have the area to themselves once the higher levels
//             have explored it and done the quest. He will not ship anyone
//             who's tried to hurt him until the next reboot.
//=========================================================================
// 031113 - Changed him so he only asks 1000 coins from people > lvl 4.
//          Those people don't come here anyway, charging thousands of coins
//          to explore a new area is a bit pointless.
//          - Yoda
//=========================================================================
// 040414 - Changed him again so he only charges 200 for people > lvl 4.
//          Making people stay away from here is more counterproductive
//          than good.
//          - Yoda
//=========================================================================
#pragma strict_types
#include "../def.h"
inherit  MASTER_MONSTER;

int location;  // 0 = sea, 1 = larstown, 2 = island

void   create_object(void);
void   init(void);
int    do_poke(string str);
int    do_pay(string str);
void   set_at_sea(void);
void   set_at_island(void);
void   set_at_lars(void);
int    is_unkillable(void);
string unkillable_string(object attacker);

void create_object(void)
{
  set_name("boatman");
  add_id("man");
  add_id("the boatman");
  add_id("a boatman");
  set_short("An old boatman");
  set_level(4);
  set_hp(50);
  set_wc(5);
  set_new_ac(10);
  set_skill("navigation",100);
  set_skill("boathandling",100);
  set_al(20);
  set_gender(1);
  set_race("human");

  load_chat(5,({"The boatman sighs deeply.\n",
                "The boatman stares out towards the open sea.\n"}));
}

void init(void)
{
  ::init();
  add_action("do_poke","poke");
  add_action("do_pay","pay");
}

int do_poke(string str)
{
   int fee;

   if((str == "man" || str == "boatman") && location == 1)
   {
     W("You poke the boatman in the ribs and ask him about the "+
       "passage to Newbie Island.\n");
     S(TP->QN + " pokes the boatman in the ribs and asks him about the "+
       "passage to Newbie Island.\n");
     if(query_nasty_player(TP))
     {
       W("The boatman looks angrily at you.\n");
       S("The boatman looks angrily at " + TP->QN + ".\n");
       tell_room(ENV(TO),"The boatman says: As far as I am concerned, " +
                 TP->QN + ", you can swim to Newbie Island. I will not " +
                 "ferry somebody who's tried to kill me. *grumble*\n");
       return 1;
     }
     W("The boatman looks wearily at you and says: ");
     S("The boatman looks wearily at " + TP->QN +  " and says: ");
     switch(TP->query_level())
     {
       case 1: case 2: case 3: case 4:
         tell_room(ENV(TO),"I will take you to Newbie Island, little one." +
                   " Just board the boat and wait for me to set sail.\n");
         break;
       default:
         fee = 200;
         tell_room(ENV(TO),"I will take you to Newbie Island, " + TP->QN +
                   ". However, for someone of your stature, I will have " +
                   "to charge a fee for the passage. I would charge you " +
                   fee + " gold. This fee is charged so " +
                   "that I can make a living and keep taking people to " +
                   "and from Newbie Island. " +
                   "Just <pay> me and wait in the boat for me to set " +
                   "sail.\n");
         break;
     }
     return 1;
   }
}

int do_pay(string str)
{
  int fee;

  if(TP->query_level() <= 4)
  {
    W("The boatman looks at you and says: ");
    S("The boatman looks at " + TP->QN + " and says: ");
    tell_room(ENV(TO)," I will take you to Newbie Island free of charge, "+
              "little one ;). Just <board boat> and wait for me.\n");
    return 1;
  }

  if((str == "man" || str == "boatman") && location == 1)
  {
    if(query_nasty_player(TP))
    {
      W("The boatman looks at you and says: ");
      S(TP->QN + " wants to pay the boatman for passage to " +
        "Newbie Island.\n" +
        "The boatman looks at " +  TP->QN + " and says: ");
        tell_room(ENV(TO),"You must be a fool, " + TP->QN + ", if you " +
                "think I will take you in my boat after you've tried to " +
                "kill me. *grumble*\n");
      return 1;
    }

    fee = 200;
    if(TP->query_money() < fee)
    {
      W("The boatman looks at you and says: ");
      S("The boatman looks at " + TP->QN + " and says: ");
      tell_room(ENV(TO),"I would be glad to take you to Newbie Island, "+
                TP->QN + ", but you do not have enough gold on you.\n");
      return 1;
    }

    TP->add_money(-fee);
    W("You pay the boatman " + fee + " gold coins and board the boat.\n");
    TP->move_player("pays the boatman and boards the boat",NROOM+"ferry",
                    "joins you on board the boat",1);
    return 1;
  }
  if(location == 1)
  {
    W("Pay whom?\n");
    return 1;
  }
  return 0;
}
void set_at_sea(void)
{
  set_long("This is the man who is in charge of the boat that carries "+
           "people to and from Newbie Island. He has the rugged look "+
           "of one who spends most of his time out at sea. His hair "+
           "is flying in the wind, and he has a maniacal grin on his face "+
           "as he pilots the boat across the stormy sea! Somehow you "+
           "don't really feel very safe knowing your life is in the "+
           "hands of someone with that expression on his face!\n");
  load_chat(10,({"The boatman laughs maniacally as he steers the boat "+
                 "across the stormy sea!\n",
                 "The boatman says: Arr, hope ye enjoy ye ride, landlubber!\n",
                 "The boatman throws his head back and cackles with glee "+
                 "when he sees how seasick you look!\n"}));
  location = 0;
}

void set_at_island(void)
{
  set_long("This is the man who is in charge of the boat that carries "+
           "people to and from Lars Town. He has the rugged look of one "+
           "who spends most of his time out at sea. He's sitting on a rock "+
           "down by the shore, staring out at sea in a melancholic way.\n");
  load_chat(5,({"The boatman sighs deeply.\n",
                "The boatman stares out towards the open sea.\n"}));
  location = 2;
}

void set_at_lars(void)
{
  set_long("This is the man who is in charge of the boat that carries "+
       "people to and from Newbie Island. He has the rugged look of "+
       "one who spends most of his time out at sea. He's sitting on "+
       "a rock staring out at sea in a melancholic way. Perhaps you "+
       "could <poke> him, get his attention and find out if he can "+
       "take you to Newbie Island?\n");
  load_chat(5,({"The boatman sighs deeply.\n",
                "The boatman stares out towards the open sea.\n"}));
  location = 1;
}

int is_unkillable(void)
{
  return 1;
}

string unkillable_string(object attacker)
{
  tell_room(ENV(TO),attacker->QN + " looks as if " + attacker->QPR + " is " +
            "going to attack the boatman. The old boatman turns around and "+
            "tells " + attacker->QOB + " off!\n" +
            attacker->QN + " hangs " + attacker->QPO + " head in shame.\n",
            ({ attacker }));
  if(attacker->query_level() > 4)
  {
    add_nasty_player(attacker);
  }
  return "The old boatman gives you an awful stare and says: You wicked "+
         "young adventurerling! Don't ever let me see you attacking an "+
         "old boatman again!\nYou hang your head in shame.";
}
