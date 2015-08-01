#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void   create_object(void);
void   reset(int arg);
void   init(void);
int    do_break(string str);
string long_fun(void);
void   construction_desc(void);
void   rack_desc(void);
void   damage_desc(void);

int rack_destroyed,rack_hp;

void create_object(void)
{
  set_short("A path through the forest (nw/s/e)");
  set_long("#long_fun");
  set_new_light(3);
  set_dragon_visibility(5);
  set_room_hint("The cottage to the south belongs to a grumpy old fisherman "+
                "(Are all fishermen in the Kingdoms old and grumpy? Seems "+
                "like that at times). He might be the one to talk to if you "+
                "are interested in fish tales.;)\n");

  add_item("path","The path looks well travelled. You notice some stones in "+
           "the worn ground");
  add_item("stones|stone","Looks like old paving stones. Perhaps this path "+
           "was once a road?");
  add_item("forest","You seem to be getting closer to the edge of the forest,"+
           " and you see a clearing to the south");
  add_item("edge","The place where the forest turns into something that is "+
           "not a forest");
  add_item("road","Well, it's a road no longer");
  add_item("bush|bushes","Bushes of the kind that normally grow in forests");
  add_item("tree|trees","Nice, healthy looking trees. There seem to be fewer "+
           "of them to the east");
  add_item("construction|wooden construction","#construction_desc");
  add_item("rack","#rack_desc");
  add_item("cottage","Looks like a cottage is standing in a clearing to the "+
           "south");
  add_item("clearing","There is one to the south but you'd have to go there "+
           "to get a closer look at it");

  add_exit(NROOM+"path1","northwest");
  add_exit(NROOM+"cottage_clearing","south");
  add_exit(NROOM+"forest_edge","east");

  rack_hp = 20;

  reset(0);
}

void reset(int arg)
{
  if(rack_destroyed)
  {
    W("A magic wind blows through the room and suddenly and automagically "+
      "the rack is rebuilt.\n");
    add_item("rack","#rack_desc");
    remove_item("remains");    
    rack_destroyed = 0;
  }
  rack_hp = 20;
}

void init(void)
{
  add_multi_action("do_break","break|tear");
}

int do_break(string str)
{
  object wood;

  if(str == "construction" || str == "rack" || str == "wooden construction" ||
     str == "construction down" || str == "rack down")
  {
    if(!rack_destroyed)
    {
      rack_hp -= random(TP->query_str()) + 2;
      
      if(rack_hp <= 0)
      {
        // Later on I will possibly put some wood here to build a raft
        // or something, but not now - Yoda
        W("You rip the poor old fishnet rack apart. Good work. Do you "+
          "feel better now?\n");
        S(TP->QN+" tears the fishnet rack to pieces.\n");
        rack_destroyed = 1;
        remove_item("rack");
        add_item("remains","#construction_desc");
        return 1;
      }
      W("You try to tear the thing apart, and it looks in worse shape when "+
        "you are done, but it's still not quite broken yet.\n");
      S(TP->QN+" tries to tear the rack apart, almost succeeding.\n");
      return 1;
    }
    W("It sure looks broken already to me.\n");
    return 1;
  }
  notify_fail("Break what?\n");
}

string long_fun(void)
{
  if(!rack_destroyed)
  {
    return "You are on a path winding its way between bushes and trees. "+
           "The forest is not as dense here as it was to the northwest, "+
           "and as you look to the east you think you see it end. By the "+
	   "side of the path is a wooden construction of some sort, and "+
	   "there is another path going south from here. Seems like there "+
           "is a cottage to the south where it leads.\n";
  }
  else
  {
    return "You are on a path winding its way between bushes and trees. "+
           "The forest is not as dense here as it was to the northwest, "+
           "and as you look to the east you think you see it end. By the "+
           "side of the path is the destroyed remains of a wooden "+
           "construction of some sort, and there is another path going "+
           "south from here. Seems like there is a cottage to the south "+
           "where it leads.\n";
  }
}

void construction_desc(void)
{
  if(!rack_destroyed)
  {
    W("When you look at it more closely, you think it looks like a kind of "+
      "rack. Perhaps some sort of rack where you hang nets to dry. It does "+
      "not look as if it is being used all that much anymore, and it sure "+
      "doesn't look very sturdy, so if you need wood for something, you "+
      "could probably break it down. ");
    damage_desc();
  }
  else
  {
    W("There's not much left of whatever it was.\n");
  }
}

void rack_desc(void)
{
  W("Yes, now when you look at it again, you're quite sure it "+
    "is the kind of rack fishermen use to hang their nets to dry on. "+
    "Nothing's hanging on it now, though. ");
  damage_desc();
}

void damage_desc(void)
{
  if(rack_hp > 15)
  {
    W("\n");
  }
  else
  if(rack_hp > 10)
  {
    W("It looks as if someone's been trying to tear it down.\n");
  }
  else
  if(rack_hp > 5)
  {
    W("It looks as if it's about to come apart on its own.\n");
  }
  else
  if(rack_hp > 0)
  {
    W("It looks as if a slow breeze could tear it apart.\n");
  }
}
