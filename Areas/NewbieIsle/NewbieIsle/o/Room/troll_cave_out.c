#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void   create_object(void);
int    query_room_id(void);
void   reset(int arg);
void   init(void);
int    do_move(string str);
int    query_rock_moved(void);
void   rock_moves(void);
int    do_smell(string str);
int    do_enter(string str);
string long_fun(void);
void   cliff_desc(void);
void   rock_desc(void);
void   opening_desc(void);

int rock_moved;

void create_object(void)
{
  set_short("Outside a cave (s)");
  set_long("#long_fun");
  set_new_light(5);
  set_dragon_visibility(1);
  set_room_hint("If you're not strong enough to move the stone on your "+
                "own, you could try get someone to help you. If more "+
                "people push it at the same time, it might be easier to "+
                "move it.;) Beware though. The trolls live in this cave "+
                "and they are here during the day and come out at night.\n");

  add_item("trail","It ends here in front of the opening. There are many "+
           "footprints on it");
  add_item("footprint|footprints","There are loads of them here and it "+
           "seems like the creatures who made them (it looks as if those "+
           "creatures were trolls!) have been walking in and out of the "+
           "opening");
  add_item("ground","The ground is as stony here as in the rest of the "+
           "forest. No moss grows here though");
  add_item("tree|trees","The trees in this forest are all very old. The ones "+
           "around you here seem a bit more twisted than the rest, as if "+
           "they are trying to turn away from the opening");
  add_item("forest","You're as deep inside the dark forest as you dare to "+
           "go now. Hope you can find your way back out");
  add_item("clearing","It is south of here");
  add_item("wall|cliffwall","#cliff_desc");
  add_item("rock","#rock_desc");
  add_item("opening","#opening_desc");

  add_exit(NROOM+"troll_clearing","south");

  rock_moved = 0;
  reset(0);
}

// Trolls use this function to know which room they 
// are in and which way to go when they return home
int query_room_id(void)
{
  return 11;
}

void reset(int arg)
{
  if(rock_moved)
  {
    rock_moves();
  }
}

void init(void)
{
  add_multi_action("do_move","move|push");
  add_action("do_enter","enter");
  add_action("do_smell","smell");
  ::init();
}
 
int do_move(string str)
{
  if(str == "rock" || str == "stone" || str == "boulder")
  {
    if(TP->query_race() == "newbie island troll")
    {
      if(!rock_moved)
      {
        tell_room(TO,"The troll groans and tries to push the rock aside.\n");
        rock_moves();
      }
      return 1;
    }
    else if(present("adult_troll",TO))
    {
      W("No way you're going to move that rock with a big troll standing "+
        "in the way!\n");
      return 1;
    }
    
    if(!rock_moved)
    {
      W("You start pushing the rock, trying to move it from the opening.\n");
      S(TP->QN + " starts pushing the rock, trying to move it from the "+
        "opening.\n");
    } 
    else
    {
      W("You start pushing the rock, trying to move it back in front of the " +
        "opening.\n");
      S(TP->QN + " starts pushing the rock, trying to move it back in front " +
        "of the opening.\n");
    }

    if(random(TP->query_str()) >= 5)
    {
      rock_moves();
      return 1;
    }
    else
    {
      W("The stone is too heavy, but you almost budged it. Perhaps " +
        "you can move it if you try again?\n");
      S(TP->QN + " looks exhausted and stops pushing the stone.\n");
      return 1;
    }
  }
  notify_fail(C(query_verb()) + " what?\n");
}

int query_rock_moved(void)
{
  return rock_moved;
}

void rock_moves(void)
{
  if(!rock_moved)
  {
    rock_moved = 1;
    tell_room(TO,"Suddenly the rock budges. It is pushed to " +
              "the side, exposing a cave opening.\n");
    tell_room((NROOM+"troll_cave_in"),"The rock that is " +
              "covering the opening is pushed aside.\n");
    add_item("cave","A scary looking cave. There is a " +
             "horrible smell coming from it. If you are "+
             "really brave, you could try to enter it");
    (NROOM+"troll_cave_in")->add_exit(NROOM+"troll_cave_out","out");
  }
  else
  {
    rock_moved = 0;
    tell_room(TO,"The rock is moved back in front of the opening.\n");
    tell_room((NROOM+"troll_cave_in"),"The boulder outside rolls " +
              "back in front of the opening.\n");
    remove_item("cave");
    (NROOM+"troll_cave_in")->remove_exit("out");
  }
}

int do_smell(string str)
{
  if(!rock_moved)
  {
    W("There seems to be an unpleasant smell coming from behind the rock.\n");
    S(TP->QN+" smells something in the air.\n");
    return 1;
  }
  else
  {
    W("BLEARGH! There is a horrible smell coming from the opening!\n");
    S(TP->QN+" smells something in the air and turns green.\n");
    return 1;
  }
}

int do_enter(string str)
{
  if(rock_moved)
  {
    if(str == "cave" || str == "opening")
    {
      W("You hold your nose and enter the dark cave.\n");
      TP->move_player("enters the cave, holding "+TP->QPO+" nose",
                      (NROOM+"troll_cave_in"),
                      "arrives from the outside",
                      1);
      return 1;
    }
    notify_fail("Enter what?\n");
  }
}

string long_fun(void)
{
  if(!rock_moved)
  {
    return "The trail ends in front of a steep cliffwall. There is a "+
           "big rock here covering an opening in the wall. There are "+
           "footprints on the stony ground and they disappear in under "+
           "the rock. The old trees around you seem to be turning away "+
           "from the opening, and there is a horrible smell coming from "+
           "behind the rock. The trail goes back south to the clearing.\n";
  }
  else
  {
    return "The trail ends in front of a steep cliffwall. There is a "+
           "big rock here, beside a cave opening in the wall. There are "+
           "footprints on the stony ground and they disappear into "+
           "the cave. The old trees around you seem to be turning away "+
           "from the opening, and there is a horrible smell coming from "+
           "the cave. The trail goes back south to the clearing.\n";
  }
}

void cliff_desc(void)
{
  if(!rock_moved)
  {
    W("The cliffwall is steep and jagged. There is a rock leaning against "+
      "it, covering an opening.\n");
  }
  else
  {
    W("The cliffwall is steep and jagged. There is a cave opening in it, "+
      "and next to it is a rock that seems to have been covering it.\n");
  }
}

void rock_desc(void)
{
  if(!rock_moved)
  {
    W("A big rock, covering an opening in the cliffside. It looks heavy, "+
      "but you could still try to move it.\n");
  }
  else
  { 
    W("A big rock that seems to have been moved from covering the opening "+
      "in the cliffside. It looks heavy, but you could try to move it back "+
      "in front of the opening.\n");
  }
}

void opening_desc(void)
{
  if(!rock_moved)
  {
    W("The opening is covered by the big rock in front of it.\n");
  }
  else
  {
    W("The opening leads into a dark cave in the cliffside. The footprints "+
      "on the ground enter it and a horrible smell comes from it. Would you "+
      "dare to enter it?\n");
  }
}
