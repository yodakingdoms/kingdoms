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
  set_short("In the forest (n/nw/sw)");
  set_long("You are in an ancient forest. The air around you is very still, "+
           "and not even the strong wind blowing in from the sea to the "+
           "west finds its way in here among the trees. Tall, ancient pine "+
           "trees are all around you, their trunks and branches are covered "+
           "with brown moss. The ground is covered by pine needles and "+
           "every rock and boulder you see is covered by moss as well. "+
           "There is a small trail going off into the forest in two "+
           "directions from here, and the path goes back to the viewpoint "+
           "to the southwest. It is so silent you almost think you can hear "+
           "the forest itself breathing.\n");
  set_new_light(5);
  set_room_hint("Watch out for the trolls around here!:/\n");

  add_item("forest","The forest gives you an almost scary impression. It "+
           "is silent and still. However far in among the trees you look, "+
           "you see nothing moving");
  add_item("air","You can't see the air, but you feel it is very still here");
  add_item("wind|winds","You can't even feel the winds that were so strong "+
           "to the southwest here");
  add_item("sea","You can't even see the sea from here");
  add_item("pines|pine|pine trees|pine tree|tree|trees","Ancient pine "+
           "trees that are covered with moss");
  add_item("trunk|trunks|branch|branches","They are covered with some strange"+
           " brown moss");
  add_item("moss","A strange kind of brown moss grows all over the "+
           "trees and the rocks and boulders on the ground");
  add_item("rocks","The rocks on the ground are all covered with some "+
           "strange moss");
  add_item("boulders","They look like boulders usually do, except "+
           "they are covered with moss");
  add_item("ground","The ground is covered with pine needles. You notice "+
           "some footprints there too though");
  add_item("footprint|footprints","They look like troll footprints");
  add_item("troll footprint|troll footprints","They _are_ troll footprints!");
  add_item("needles|needle|pine needles|pine needle","Long, green and "+
           "brown needles that have fallen off the trees");
  add_item("rock|boulder","You see quite a few of them around here. Each "+
           "one covered by the brown moss");
  add_item("trail","It goes into the forest in two directions from here. "+
           "There are footprints on the trail");
  add_item("path","It goes back to the southwest to the viewpoint");
  add_item("viewpoint","It is southwest of here");
  add_item("here","Just type 'look'");  

  add_exit(NROOM+"viewpoint","southwest");
  add_exit(NROOM+"troll_woods2","northwest");
  add_exit(NROOM+"troll_woods3","north");

  add_sounds(30,50,({"You feel a faint puff of wind from the southwest.\n",
                     "You hear a creaking from somewhere off into the "+
                     "woods.\n",
                     "You thought you saw something moving further into "+
                     "the forest.\n"}));
  reset(0);
}

// Trolls use this function to know which room they 
// are in and which way to go when they return home
int query_room_id(void)
{
  return 1;
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
    W("You think you hear a low, rumbling sounds coming from somewhere "+
      "deep inside the forest. It almost sounds as if the forest is "+
      "breathing...\n");
    S(TP->QN + " listens carefully.\n");
    return 1;
  }
}
