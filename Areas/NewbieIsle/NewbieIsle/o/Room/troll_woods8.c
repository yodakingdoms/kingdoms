#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

object animal1,animal2;

void create_object(void);
int  query_room_id(void);
void reset(int arg);
void init(void);
int  do_climb(string str);

void create_object(void)
{
  set_short("Deep in the forest (ne/se/sw)");
  set_long("You are on a barely noticeable trail going northeast and "+
           "southeast from here around the base of a small hill. The "+
           "ground around the trail is stony and brown moss grows "+
           "everywhere. The woods are dark here, and the trees around "+
           "you look very old. There are footprints on the trail, which "+
           "leads into a clearing to the northeast.\n");
  set_new_light(5);
  set_dragon_visibility(1);

  add_item("trail","The trail is barely noticeable. There are footprints "+
           "on it");
  add_item("hill","There is a small one to the east. It does not look as "+
           "if you could climb it just here, though");
  add_item("foot|base","The trail follows the foot of the small hill");
  add_item("ground","The ground is stony and brown moss grows everywhere");
  add_item("moss","The same brown moss growing everywhere else in the "+
           "forest");
  add_item("forest|woods","It is dark and old, and pretty scary. It is "+
           "very still and silent");
  add_item("tree|trees","Most of the trees in this forest look as if they "+
           "have been standing here for hundreds of years, and most of them "+
           "look as if they intend to stay here for another hundred years");
  add_item("footprints|footprint","They do look like troll footprints");
  add_item("troll footprint|troll footprints","Yes, they sure are troll "+
           "footprints. Scary, huh?");
  add_item("clearing","Well, go northeast to look more closely at "+
           "the clearing");
  
  add_exit(NROOM+"troll_woods4","southwest");
  add_exit(NROOM+"troll_woods5","southeast");
  add_exit(NROOM+"troll_clearing","northeast");

  reset(0);
}

// Trolls use this function to know which room they 
// are in and which way to go when they return home
int query_room_id(void)
{
  return 8;
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
  add_action("do_climb","climb");
  ::init();
}

int do_climb(string str)
{
  if(str == "hill")
  {
    W("It looks a bit too unclimbable here. Perhaps if you tried it "+
      "someplace further to the southeast?\n");
    S(TP->QN+" looks up the hill, pondering something.\n");
    return 1;
  }
  notify_fail("Climb what?\n");
}
