#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int  do_search(string str);
int  do_climb(string str);

int pole_found;

void create_object(void)
{
  set_short("A path going up the slope");
  set_long("You are on a path going up the steep slope from the beach. "+
           "There are plenty of bushes and trees clinging on to the rocky "+
           "slope around you, even though it is so steep you have to "+
           "struggle with every step. Brown moss covers the stones beside "+
           "the path. The path goes back down the slope to the southwest, "+
           "and up to the east, where there seems to be a clearing.\n");
  set_new_light(3);
  set_dragon_visibility(1);
  set_room_hint("When you look at a <plural> and it says there is something "+
                "special with one of them, it often pays to look at the "+
                "<singular>;). Taking a closer look at something often means "+
                "it is a good idea to 'search' it.;)");

  add_item("path","The path winds its way up the slope between trees, "+
           "rocks, and bushes");
  add_item("slope","The slope is quite steep here, and you have to dig "+
           "the sides of your feet into the ground to get foothold to "+
           "go further on up the path");
  add_item("ground","Most of the ground is covered by the bushes and rocks");
  add_item("beach","The beach is to the southwest. You can hear the waves "+
           "lap against the shore from here");
  add_item("$|$waves","You hear the gentle lapping of the waves against "+
           "the shore from here");
  add_item("bushes","Big bushes growing on the slope. One of them looks a "+
           "bit strange");
  add_item("strange bush|bush","It looks as if there's something lying "+
           "under it, perhaps if you gave it a closer look?");
  add_item("pines|pine|pine trees|tree|trees","Some not too tall pine trees "+
           "clinging to the steep slope. They don't look very climb-friendly");
  add_item("stone|stones|rock|rocks","They are all almost covered by "+
           "the brown moss");
  add_item("moss","A brown, moist moss that grows on the stones here. It "+
           "smells funny");
  add_item("%moss","The moss smells like some damp socks or something. "+
           "Quite BLAEH! actually");
  add_item("clearing","There is a clearing up there. You can't see too "+
           "much of it from down here, so you'd better go up there and "+
           "see what it looks like!!");  

  add_exit(NROOM+"shore1","southwest");
  add_exit(NROOM+"clearing","eastup");

  reset(0);
}

void reset(int arg)
{
  pole_found = 0;
}

void init(void)
{
  add_action("do_search","search");
  add_action("do_climb","climb");
}

int do_search(string str)
{
  object fishingpole;

  if(str == "bush")
  {
    if(TP->query_skill("perception") + 5 > random(15))
    {
      if(!pole_found)
      {
        W("You find a nice fishing pole that somebody has left under "+
          "the bush.\n");
        S(TP->QN+" looks under a bush and finds a fishing pole.\n");
        fishingpole = make(NWEAPON+"fishing_pole");
      
        if(!(transfer(fishingpole,TP)))
        {
          W("You pick it up.\n");
        }
        pole_found = 1;
        return 1;
      }
      else
      {
        W("You don't find anything now, but it looks as if someone's been "+
          "searching the bush before you, and not too long ago.\n");
        S(TP->QN+" looks under a bush without finding anything.\n");
        return 1;
      }
    }
    W("You search but don't find anything. Perhaps you could try again, "+
      "and perhaps more perception skill would help?\n");
    S(TP->QN + " searches the bushes for a while but doesn't find "+
      "anything.\n");
    return 1;
  }
}

int do_climb(string str)
{
  if(str == "tree" || str == "trees")
  {
    W("Climbing these trees would only be a waste of time, but that "+
      "doesn't mean there aren't other trees worth climbing!\n");
    S(TP->QN+" looks at the trees and ponders.\n");
    return 1;
  }
  W("Climb what?\n");
  return 1;
}

