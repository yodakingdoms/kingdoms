#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_SOUND;

void create_object(void);
int  query_room_id(void);
void reset(int arg);
void init(void);
int  do_taste(string str);
int  do_climb(string str);

object animal1,animal2;
mapping tasters = ([]);  // Player : Number of times player has drunk
                         // Max will be 10. Something so newbies can fight 
                         // a bit without having to bring so many heals.
                         // Also something to PROMOTE MURDERING *MUAHAHA*smirk*
                         // (Above written when there still were murderers
                         //  Yoda - 971002)
                         // Wohoo - there are murderers again now!
                         //  Yoda - 980917 (So, I'm not the fastest area
                         //                 coder on the mud :)) 
                         // The area is still not open, but it should be soon!
                         //  Yoda - 990408

void create_object(void)
{
  set_short("In the very old forest (n/ed/w/sw)");
  set_long("You are wandering through the dark, old forest. Here, in a "+
           "crack in the side of a hill is a small spring, where water "+
           "is running out to form a small brook flowing down the slope "+
           "to the east. The trees around you look as old as all the "+
           "other trees in the forest, and the same moss that grows every"+
           "where else grows on the stony ground here as well. Apart from "+
           "the sound of the running water, everything is still. You "+
           "think you see a pond down there to the east.\n");
  set_new_light(5);
  set_dragon_visibility(1);
  set_room_hint("This water has some nice healing effects. At other times "+
                "when you don't have springs like this one around, it is a "+
                "good idea to carry healing potions around in a bag or sack "+
                "and make a define for drinking them, for example: define "+
                "0 do take medicine from bag,drink medicine. Then you will "+
                "just have to type a 0 to do the whole thing. Ask older "+
                "players for more advice on this.;)\n");

  add_item("forest|woods","This forest is dark and very, very old. You "+
           "think some of these trees must have been standing here for "+
           "hundreds of years");
  add_item("crack","A small crack in the hill where water flows out, "+
           "forming a small brook that merrily dances down the slope to "+
           "the east");
  add_item("spring","A small spring in the side of the hill. The water "+
           "coming out of it looks very clear and refreshing");
  add_item("hill","A small hill that might be interestring to climb, but "+
           "this side of it is too steep for that");
  add_item("water","Cold, clear water that looks really refreshing. Perhaps "+
           "you could taste it?");
  add_item("brook","A small forest brook that merrily dances down the slope "+
           "to the east");
  add_item("tree|trees","All the trees around here are very, very old");
  add_item("slope","The ground slopes downwards to the east here");
  add_item("moss","The same brown moss that seems to grow everywhere else "+
           "in the forest too");
  add_item("ground","The stony ground is a bit difficult to walk upon, and "+
           "here it slopes downwards to the east as well. Brown moss grows "+
           "everywhere");
  add_item("pond","It looks as if the brook runs down the slope to form "+
           "a forest pond down there to the east");
  add_item("$","You hear the pleasant sound of running water from the brook");

  add_exit(NROOM+"troll_woods3","southwest");
  add_exit(NROOM+"troll_woods5","west");
  add_exit(NROOM+"troll_woods7","eastdown");
  add_exit(NROOM+"troll_woods9","north");

  add_sounds(5,50,({"The brook makes pleasant sounds as it dances down "+
                    "the stony slope to the east.\n",
                    "The sound of running water makes you feel at ease.\n"}));
  reset(0);
}

// Trolls use this function to know which room they 
// are in and which way to go when they return home
int query_room_id(void)
{
  return 6;
}

void reset(int arg)
{
  if(!animal1 || !living(animal1))
  {
    animal1 = make(NMONSTER+"animal");
  }
 
  if(!animal2 || !living(animal2))
  {
    animal2 = make(NMONSTER+"animal");
  }
}

void init(void)
{
  add_multi_action("do_taste","taste|drink");
  add_action("do_climb","climb");
  ::init();
}

int do_taste(string str)
{
  if(str == "water")
  {
    if(tasters[TP] < 10)
    {
      W("You taste the water and wince for a moment at the coldness of it. "+
        "It does taste really good though, and it is clear as only water "+
        "from a good forest spring can be. You feel slightly better after "+
        "drinking it!\n");
      S(TP->QN+" cups "+TP->QPO+" hand under the spring and tastes the "+
        "water coming out if it.\n");
      TP->reduce_temporary_penalty(random(10));
      TP->reduce_hit_point(-(10+random(10)));
      ++tasters[TP];
    }
    else
    {
      W("You have drunk enough of this nice water now. You have "+
        "to wait for a while for your body to recover before you can drink "+
        "more of it.\n");
    }
    return 1;
  }
  notify_fail(C(query_verb())+" what?\n");
}

int do_climb(string str)
{
  if(str == "hill")
  {
    W("This hill is too steep here for you to climb it. Perhaps you "+
      "could try somewhere else?\n");
    return 1;
  }
}
