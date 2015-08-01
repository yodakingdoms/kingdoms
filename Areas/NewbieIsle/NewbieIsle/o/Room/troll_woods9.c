#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

object animal1,animal2;

void create_object(void);
int  query_room_id(void);
void reset(int arg);

void create_object(void)
{
  set_short("Deep in the woods (nw/s)");
  set_long("You are walking at the foot of a small hill deep into the "+
           "dark woods. The ground around you is stony and brown moss "+
           "grows everywhere. The trees around you are very old and they "+
           "all seem to reach for you with their branches. You think you "+
           "hear the sound of running water from the south, and to the "+
           "northwest, there seems to be a clearing.\n");
  set_new_light(5);

  add_item("foot|hill","You are at the foot of a small hill that is rising "+
           "to the west of here");
  add_item("woods|forest","The forest seems to be very old indeed");
  add_item("ground","The ground is stony and brown moss grows everywhere");
  add_item("moss","Brown moss. You should know that by now");
  add_item("tree|trees","Very old trees that seem to be looking at you, "+
           "wondering what you're doing here");
  add_item("branch|branches","The brown moss grows on the branches as well");
  add_item("$|$sound|$water|$to sound|$to water","Yes, it sounds as if "+
           "there is a brook or a spring south of here");
  add_item("water|brook|spring","It is somewhere to the south of here");
  add_item("clearing","The clearing is northwest of here");
  
  add_exit(NROOM+"troll_woods6","south");
  add_exit(NROOM+"troll_clearing","northwest");

  reset(0);
}

// Trolls use this function to know which room they 
// are in and which way to go when they return home
int query_room_id(void)
{
  return 9;
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
