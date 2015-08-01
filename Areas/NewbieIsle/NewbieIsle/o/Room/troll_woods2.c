#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_SOUND;

object animal1,animal2;

void create_object(void);
int  query_room_id(void);
void reset(int arg);

void create_object(void)
{
  set_short("In an ancient forest (se/nw/e)");
  set_long("You are in a really old forest where the ancient trees "+
           "around you have strange brown moss growing on their branches. "+
           "There are pine needles all over the stony ground, and that "+
           "strange brown moss grows on every rock you see as well. The "+
           "trail from the southeast ends here, but you can still go "+
           "further into the woods if you wish. Everything is silent and "+
           "still.\n");
  set_new_light(5);

  add_item("forest","This forest looks really old. The trees around you "+
           "look as if they've been standing here for hundreds of years");
  add_item("pines|pine|pine tree|pine trees|tree|trees","Very old pine "+
           "trees with brown moss growing on their branches");
  add_item("branch|branches","They are probably about as old as the rest "+
           "of the trees they are attached to, and covered with moss");
  add_item("moss","A brown moss that grows on both the trees around you "+
           "as well as on the ground");
  add_item("needle|needles|pine needle|pine needles","Green and brown "+
           "needles that have fallen off the old trees");
  add_item("ground","The ground is stony around here, and it is covered "+
           "by pine needles and the same brown moss that grows on the "+
           "trees. There are tracks all around");
  add_item("track|tracks","Tracks of all sorts of animals, as well as some "+
           "distinct footprints");
  add_item("troll footprints|footprint|footprints","Yes, these are troll "+
           "footprints too");
  add_item("rock|rocks","All the rocks on the ground have that brown "+
           "moss growing on them");
  add_item("trail","The trail stops here, but don't let that stop you from "+
           "going further into the woods!");
  add_item("$","Everything is silent");  
  add_item("woods","The woods around you are silent and still");

  add_exit(NROOM+"troll_woods1","southeast");
  add_exit(NROOM+"troll_woods3","east");
  add_exit(NROOM+"troll_woods4","northwest");

  add_sounds(20,10,({"You thought you saw something move somewhere deeper "+
                     "into the forest.\n",
                     "You hear the sound of a tree falling somewhere in the "+
                     "forest.\n"}));
  reset(0);
}

// Trolls use this function to know which room they 
// are in and which way to go when they return home
int query_room_id(void)
{
  return 2;
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
