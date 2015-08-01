#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int  do_clear(string str);
int  do_search(string str);
int  do_read(string str);
void obelisk_desc(void);
void stones_desc(void);
void road_desc(void);

int obelisk_cleared;
string *found_stones = ({});

void create_object(void)
{
  set_short("A winding path (w/se)");
  set_long("You are on a path winding its way between trees and bushes "+
           "on the west side of the island. The ground slopes gently down "+
           "towards the east here, and it looks as if the forest is not "+
           "as dense towards the southeast. By the side of the path is an "+
           "almost totally overgrown obelisk, standing almost like a sentry, "+
           "guarding the path.\n");
  set_new_light(3);
  set_dragon_visibility(1);
  set_room_hint("It often pays to try to perform actions suggested when "+
                "looking at things in a room, like the obelisk does here. "+
                "Many times that is the only way to find vital hints or to "+
                "get to new places. Often when you are told that taking "+
                "a closer look at something might be a good idea, it pays "+
                "to <search> that thing;)\n");

  add_item("path","The path looks well travelled. Something looks odd about "+
           "it though... Might want to take a closer look");
  add_item("tree|trees","Many trees grow here. The path you are on winds its "+
           "way between them");
  add_item("bush|bushes","There are plenty of bushes growing around here");
  add_item("island","You are somewhere on the west side of this island");
  add_item("ground","It's what you're standing on, surprisingly");
  add_item("forest","It looks as if you'll come out of it if you continue "+
           "eastwards");
  add_item("obelisk","#obelisk_desc");
  add_item("stones","#stones_desc");
  add_item("road","#road_desc");
  add_item("stone","The obelisk is made of stone that was once white, but "+
           "now it is grey and cracked");
  add_item("vine|vines","The vines cling to the obelisk, almost covering it "+
           "completely");
  add_item("sentry","Well there is no sentry here. It only looks as if the "+
           "obelisk is guarding the path");

  add_exit(NROOM+"clearing","west");
  add_exit(NROOM+"path2","southeast");

  reset(0);
}

void reset(int arg)
{
  tell_room(TO,"Suddenly the vines on the obelisk grow back again to "+
            "cover it.\nHow eerie...\n");
  obelisk_cleared = 0;
  remove_item("runes");
  remove_item("surface");
}

void init(void)
{
  add_action("do_clear","clear");
  add_action("do_search","search");
  add_action("do_read","read");
}

int do_clear(string str)
{
  if(str == "obelisk" || str == "vines")
  {
    W("You rip some of the vines from the obelisk and clear a surface, "+
      "uncovering some runes!\n");
    S(TP->QN+" clears some of the vines from the obelisk.\n");
    obelisk_cleared = 1;
    add_item("surface","There are some runes on the surface of the obelisk");
    add_item("runes","Might try to read them?");
    return 1;
  }
  notify_fail("Clear what?\n");
}

int do_search(string str)
{
  if(str == "path" || str == "ground")
  {
    if(TP->query_skill("perception") > random(15))
    {
      W("Some of the stones on the ground look like paving stones. Perhaps "+
        "this path was once a road? Must have been a long time ago though, "+
        "considering how it looks now.\n");
      found_stones += ({TP->QRN});
      return 1;
    }
    else
    {
      W("Hmm, you search but don't find anything this time...\n");
      return 1;
    }
  }
}

int do_read(string str)
{
  if(str == "runes")
  {
    if(obelisk_cleared)
    {
      W("The runes look ancient, but you can somehow read them anyway. They "+
        "say: In Cors Name, Kordar lays claim to this Isle. It is dated "+
        "Februarius 18, 687.\n");
      S(TP->QN+" reads the runes on the obelisk.\n");
      return 1;
    }
  }
}

void obelisk_desc(void)
{
  if(!obelisk_cleared)
  {
    W("The obelisk is about a foot taller than you are, made of once white "+
      "stone it seems. It is almost totally overgrown by vines now. Seems "+
      "like there might be something interesting beneath the vines if you "+
      "could clear them.\n");
  }
  else
  {
    W("The obelisk is about a foot taller than you are, made of once white "+
      "stone it seems. It is almost totally overgrown by vines now. A small "+
      "surface of the obelisk has been cleared of vines though, and you see "+
      "some runes there.\n");
  }
}

void stones_desc(void)
{
  if(member_array(TP->QRN,found_stones) != -1)
  {
    W("They look like old paving stones from a very old road.\n");
  }
  else
  {
    W("There are no stones here.\n");
  }
}

void road_desc(void)
{
  if(member_array(TP->QRN,found_stones) != -1)
  {
    W("It might once have been a road, but by the look of it, that was "+
      "a long time ago.\n");
  }
  else
  {
    W("There is no road here.\n");
  }
}

