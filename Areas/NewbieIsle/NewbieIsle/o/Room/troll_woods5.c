#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_SOUND;

object animal1,animal2;

void create_object(void);
int  query_room_id(void);
void init(void);
void reset(int arg);
int  do_climb(string str);

void create_object(void)
{
  set_short("Foot of a hill in the forest (nw/e/s)");
  set_long("You are deep into the woods now, and the old trees "+
           "seem to be closing in on you, reaching for you with their "+
           "branches. The brown moss grows everywhere around you, "+
           "covering the stony ground of the forest. In front of you "+
           "to the north rises a small hill, and you notice a trail "+
           "northwest around its base. The same trail continues to the "+
           "east, where the ground is beginning to slope downwards.\n");
  set_new_light(5);
  set_dragon_visibility(1);
  set_room_hint("Might be interesting to climb that hill.;)\n");

  add_item("woods|forest","You are deep inside it now and you just hope you "+
           "will be able to find your way back when you want to leave!");
  add_item("tree|trees","You get a strange feeling the old trees are "+
           "watching every move you are making. It is not exactly a "+
           "pleasant feeling");
  add_item("branch|branches","The brown moss growing everywhere in the "+
           "forest grows on these branches as well");
  add_item("moss","It is brown and it is the same one that grows everywhere "+
           "else in this forest");
  add_item("ground","The ground here is stony, but there are still "+
           "footprints to be seen in the moss around you");
  add_item("troll footprints|footprint|footprints","They look unnervingly "+
           "like troll footprints");
  add_item("hill","Just a small hill in the forest. It might be interesting "+
           "to climb it though. There is a trail following the base of it "+
           "to the northwest");
  add_item("base","The base of the hill in front of you");
  add_item("trail","It goes northwest, apparently around the hill, and to "+
           "the east, where the ground is beginning to slope downward");
  add_item("$","You think you hear the sound of water from the east");  

  add_exit(NROOM+"troll_woods3","south");
  add_exit(NROOM+"troll_woods6","east");
  add_exit(NROOM+"troll_woods8","northwest");

  add_sounds(10,10,({"You can hear the sound of water trickling to the "+
                     "east.\n"}));
  reset(0);
}

// Trolls use this function to know which room they 
// are in and which way to go when they return home
int query_room_id(void)
{
  return 5;
}

void init(void)
{
  add_action("do_climb","climb");
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

int do_climb(string str)
{
  if(str == "hill")
  {
    W("You carefully climb up the small hill.\n");
    TP->move_player("climbs up the small hill carefully",
                    (NROOM+"troll_hill"),
                    "comes climbing up to the top of the hill",1);
    return 1;
  }
  notify_fail("Climb what?\n");
}
