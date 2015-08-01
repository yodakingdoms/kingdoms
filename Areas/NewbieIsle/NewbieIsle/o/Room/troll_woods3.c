#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_SOUND;

object animal1,animal2;

void create_object(void);
int  query_room_id(void);
void reset(int arg);
void init(void);
int  do_listen(string str);

void create_object(void)
{
  set_short("In an old forest (n/s/w/ne)");
  set_long("You are walking through a dark, ancient forest. The old "+
           "pine trees around you seem to reach out for you with their "+
           "moss-covered branches. The stony ground slopes down to the "+
           "northeast here, and the barely noticeable trail you are on "+
           "goes down in that direction. Further north into the woods there "+
           "seems to be some sort of hill.\n");
  set_new_light(5);

  add_item("woods|forest","This forest must have been here for hundreds of "+ 
           "years, judging by how old the trees seem. It is dark and silent "+
           "and quite scary, actually");
  add_item("pine|pines|pine tree|pine trees|tree|trees","They are very old "+
           "in this part of the woods. They seem to reach for you with "+
           "their branches, but you're sure you're just imagining that");
  add_item("branch|branches","Brown moss grows on the branches of all the "+
           "trees around here");
  add_item("moss","A strange, brown moss that seems to be growing every"+
           "where in these woods");
  add_item("ground","The ground here is stony and it slopes downwards to "+
           "the northeast. The trail continues down that way too, and there "+
           "are plenty of tracks and footprints here");
  add_item("track|tracks","Tracks of many different small animals");
  add_item("footprint|footprints","They look like they might have been made "+
           "by trolls! Better watch out if you're in the forest at night");
  add_item("trail","The trail goes down towards the northeast");
  add_item("hill","Further north there seems to be a small hill");
  add_item("water","There is no water here, but it sounds as if there "+
           "might be a brook or something to the northeast");
  add_item("brook","You can't see it from here, but it sounds as if "+
           "there might be one to the northeast");  

  add_exit(NROOM+"troll_woods2","west");
  add_exit(NROOM+"troll_woods1","south");
  add_exit(NROOM+"troll_woods5","north");
  add_exit(NROOM+"troll_woods6","northeast");

  add_sounds(10,10,({"You think you hear water trickling to the "+
                     "northeast.\n"}));
  reset(0);
}

// Trolls use this function to know which room they 
// are in and which way to go when they return home
int query_room_id(void)
{
  return 3;
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
  add_action("do_listen","listen");
  ::init();
}

int do_listen(string str)
{
  if(!str)
  {
    W("You can hear the sound of running water coming from the northeast.\n");
    S(TP->QN + " listens carefully.\n");
    return 1;
  }
}
