#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit STD_TELL_LONG;

void create_object(void);
int  query_room_id(void);
void init(void);
int  do_anything(string str);
int  do_dance(string str);
void stop_dancing(object player);

object dancer;

void create_object(void)
{
  set_short("A clearing in the forest (n/sw/se)");
  set_long("You are in a clearing in the old forest. The trees surrounding "+
           "it form almost a perfect circle, and it almost looks "+
           "as if they are watching and guarding the clearing. The ground "+
           "here is as stony as in the rest of the forest, but there are "+
           "plenty of footprints in the moss. South of the clearing is a "+
           "small hill, and a trail leads off to the southwest round its "+
           "base. Another trail leads off to the north.\n");
  set_new_light(5);
  set_dragon_visibility(3);
  set_room_hint("The trolls only come out from their cave to the north at "+
                "night. During the day they stay inside it. I would not "+
                "recommend trying to kill them if all you have is a sword "+
                "and a shield. If that is the case then you should try "+
                "to get some more equipment first.;).\n");

  add_item("clearing","A small clearing deep inside the old forest. There is "+
           "something eerie about it. The trees seem to be watching you and "+ 
           "there are footprints all over the moss-covered ground, almost "+
           "like somebody or something has been dancing here");
  add_item("forest|woods","This forest must be one of the oldest in the "+
           "whole Kingdoms. The trees around you are ancient and seem to be "+
           "watching you");
  add_item("tree|trees","Very old trees surround the clearing, giving "+
           "you a feeling of being watched. Not a sound can be heard from "+
           "the surrounding woods");
  add_item("circle","A circle of trees surrounding the clearing");
  add_item("ground","It is as stony here as in the rest of the forest. It "+
           "is also covered by moss, and there are footprints everywhere");
  add_item("footprint|footprints","There is no doubt that the footprints "+
           "here were made by trolls");
  add_item("moss","Brown moss, same as the moss that grows everywhere else "+
           "in the forest");
  add_item("hill","A small hill that is, you guessed it, deep inside the "+
           "forest");
  add_item("trail","There is one going southwest and one going north from "+
           "the clearing");
  add_item("base","The base of the small hill");

  add_exit(NROOM+"troll_woods8","southwest");
  add_exit(NROOM+"troll_woods9","southeast");
  add_exit(NROOM+"troll_cave_out","north");
}

// Trolls use this function to know which room they 
// are in and which way to go when they return home
int query_room_id(void)
{
  return 10;
}

void init(void)
{
  add_action("do_dance","dance");
  add_action("do_anything","",1);
  ::init();
}

int do_anything(string str)
{
  if(query_verb() != "look")
  {
    if(TP == dancer)
    {
      if(query_verb() == "dance")
      {
        W("You are dancing already! A magical dance in the moonlight!\n");
        return 1;
      }
      W("You are enjoying this nightly dance too much to do anything else.\n");
      return 1;
    }
  }
}

int do_dance(string str)
{
  if(dancer)
  {
    W("Ssssh, "+TP->QN+" is dancing now...\n");
    return 1;
  }

  if(!can_see(TO))
  {
    W("It is too dark to be dancing around in the clearing now. You might "+
      "hurt yourself on a rock or something.\n");
    return 1;
  }

  if(query_daylight())
  {
    W("The daylight in the clearing kind of spoils the magical mood. Wait "+
      "until it gets dark.\n");
    S(TP->QN+" takes a few hesitant dance steps in the clearing.\n");
    return 1;
  }

  if(!query_daylight())
  {
    if(present("living_troll",TO))
    {
      W("You don't dare dance in the moonlight with trolls around!\n");
      S(TP->QN+" watches the trolls worriedly.\n");
      return 1;
    }
    dancer = TP;
    tell_long_message(({"You begin to dance around the clearing in the pale "+
                        "moonlight.\n",
                        "Some kind of magic seems to take control of your "+
                        "feet and after a while you notice you are floating "+
                        "around a foot above the ground, a sparkling light "+
                        "dancing around your feet.\n",
                        "You throw your head back and laugh merrily as the "+
                        "light of the moon and the stars in the night sky "+
                        "above grows brighter.\n",
                        "Suddenly, the sky seems to explode in light, "+
                        "blinding you momentarily!\nYou stumble and fall "+
                        "to the ground.\n",
                        "When you open your eyes, the clearing looks normal "+
                        "again, but the moonlight makes you feel quite "+
                        "uncomfortable as you stand up again...\n"}),
                        3.0,dancer);
    tell_long_message(({dancer->QN+" starts dancing around in the clearing in"+
                        " the pale moon light.\n",
                        "Suddenly you see a strange, sparkling light "+
                        "shimmer around "+dancer->QN+"'s feet.\n",
                        dancer->QN+" throws "+dancer->QPO+" head back "+
                        "and laughs merrily.\n",
                        "Suddenly "+dancer->QN+" stumbles and falls to the "+
                        "ground.\n",
                        dancer->QN+" stands up carefully, looking around "+
                        "the dark clearing suspiciously.\n"}),3.0,TO,dancer);
    set_alarm(13.0,0.0,"stop_dancing",dancer);
    return 1;
  }
}

void stop_dancing(object player)
{
  if(player == dancer)
  {
    dancer = 0;
  }
}



