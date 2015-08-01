#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

object animal1,animal2;

void create_object(void);
int  query_room_id(void);
void reset(int arg);

void create_object(void)
{
  set_short("An old, dark forest (ne/se)");
  set_long("You are walking through an old forest. The ground here is "+
           "stony and difficult to walk upon. Brown moss grows on the "+
           "rocks on the ground and on the branches of the trees around "+
           "you. There are many trees growing here, all of them look "+
           "hundreds of years old.\n");
  set_new_light(5);
  set_dragon_visibility(1);

  add_item("forest","The forest looks to be very old. Most of the trees "+
           "seem to have been standing here for hundreds of years");
  add_item("ground","The ground is stony and difficult to walk upon in "+
           "this part of the forest");
  add_item("moss","The same brown moss that seems to grow everywhere in the "+
           "forest");
  add_item("rock|rocks","The brown moss growing on them makes them slippery "+
           "and difficult to walk upon");
  add_item("branch|branches","Brown moss grows on them, making them "+
           "look very old");
  add_item("tree|trees","The trees in this forest seem to have been standing "+
           "here for hundreds of years. That's how old they look");

  add_exit(NROOM+"troll_woods2","southeast");
  add_exit(NROOM+"troll_woods8","northeast");

  reset(0);
}

// Trolls use this function to know which room they 
// are in and which way to go when they return home
int query_room_id(void)
{
  return 4;
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


