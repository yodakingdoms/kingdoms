//=====================================================================
// This is the room where the fisherman sits during the daytime
//=====================================================================
#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
void init(void);
int  do_rest(string str);

object fisherman;

void create_object(void)
{
  set_short("A clearing (n)");
  set_long("The path ends in a small clearing in front of a really old "+
           "house. The house is made of stone with a wooden roof. The "+
           "chimney has crumbled and there are cracks in the walls. Bushes "+
           "grow on both sides of the door and there is one window facing the"+
           " clearing. Vines grow all over the walls. There is a small "+
           "wooden bench by the wall. The clearing is surrounded by tall "+
           "trees.\n");
  set_new_light(5);
  set_dragon_visibility(5);
  set_room_hint("This house is where a fisherman I know lives. If you want "+
                "to know about fishing, he's the one to ask!;)\n");

  add_item("path","It goes back through the forest to the north");
  add_item("clearing","A quite little clearing where a small house stands");
  add_item("house","A really old house and one that looks as if it has seen "+
           "better days. Quite a lot of them too. It looks as if it's about "+
           "to fall apart");
  add_item("stone","The house is made of old, cracked stone");
  add_item("roof","The roof is made of wood");
  add_item("wood","Yes, wood");
  add_item("chimney","There's not much left of it. It has crumbled");
  add_item("crack|cracks","Cracks in the old stone walls");
  add_item("wall|walls","They are cracked and the vines growing on them "+
           "almost cover them completely");
  add_item("bush|bushes","They grow by the walls on both sides of the door");
  add_item("window","There is one window in the wall that is facing the "+
           "clearing. The curtains are drawn");
  add_item("curtain|curtains","The curtains are dark and drawn");
  add_item("vine|vines","Thick, green vines cover the walls");
  add_item("bench","A wooden bench that looks as if it has been sat on many "+
           "a time. Just looking at it makes you feel like resting for a "+
           "while");
  add_item("tree|trees","Tall, healthy trees surround the clearing");
  
  add_exit(NROOM+"path2","north");

  (NROOM+"fisherman_cottage")->load_doors();
  reset(0);
}

void reset(int arg)
{
  fisherman = add_monster(NMONSTER+"fisherman",1);
  ::reset(arg);
}

void init(void)
{
  add_multi_action("do_rest","sit|rest");
  ::init();
}

int do_rest(string str)
{
  if(str == "bench" || str == "on bench")
  {
    if(present(fisherman))
    {
      W("You sit down next to Andalf and rest for a little while. Quite "+
        "enjoyable.\n");
      S(TP->QN+" sits down on the bench next to Andalf and rests for a "+
        "while.\n");
      return 1;
    }
    else
    {
      W("You sit down on the bench and rest for a little while. Quite "+
        "enjoyable.\n");
      S(TP->QN+" sits down on the bench and rests for a while.\n");
      return 1;
    }
  }
  notify_fail(C(query_verb())+" where?\n");
}
