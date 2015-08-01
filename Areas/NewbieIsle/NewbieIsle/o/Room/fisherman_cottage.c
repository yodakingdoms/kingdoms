#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
int  load_doors(void);
void init(void);
int  do_open(string str);
int  do_sleep(string str);
void bed_desc(void);

void create_object(void)
{
  set_short("A really old house");
  set_long("You are in a really old stone house. The wooden floor "+
           "is creaking as you move around, and the ceiling looks as if it "+
           "might come down on top of you any moment. There is only one "+
           "window, and the curtains are drawn, so the light here is dim. "+
           "The only furniture in here is a bed and a table. There is a "+
           "fireplace in the south wall, but it does not look as if it has "+
           "been used lately.\n");
  set_light(3);
  set_skip_obvious(1);
  set_dragon_visibility(0);
  add_property("indoors");

  add_item("house","You are standing in it");
  add_item("floor","The floor is made up of wooden boards. The floor creaks "+
           "as you walk around on it, making you think that it might break "+
           "any second");
  add_item("wall|walls","The walls in the old house are made of stone");
  add_item("south wall","The south wall looks just like the other walls, " + 
           "but it is the only one that has a fireplace in it");
  add_item("north wall|west wall|east wall","It is made of stone");
  add_item("stone|stones","Solid stone walls make this a very solid house");
  add_item("board|boards","Old, creaking wooden boards");
  add_item("$|$boards","The only thing you hear is the boards creaking under "+
           "your feet");
  add_item("ceiling","It looks to be in almost as bad a shape as the floor, "+
           "ready to fall down on top of you any moment");
  add_item("window","There is a small window in the wall, but the curtains "+
           "are drawn, so you can't see outside");
  add_item("curtain|curtains","They are quite dark, and they are drawn");
  add_item("furniture","Only furniture you see is the bed and the table");
  add_item("bed","#bed_desc");
  add_item("table","A wooden table with nothing on it. It looks to be in the "+
           "same bad shape as the rest of the house");
  add_item("fireplace","The chimney of the fireplace seems to have caved "+
           "in. You see only darkness as you peer up the shaft that should "+
           "lead out into the air. Seems like the fireplace hasn't been "+
           "been used in a long time");
  add_item("chimney","Well, normally it is supposed to be on top of the "+
           "house, but this chimney has almost fallen down into the "+
           "fireplace"); 
  add_item("darkness","It is pretty dark");
  add_item("shaft","You peer up the shaft and, yes: It is dark up there");
  add_item("air","You can't see it, but you're pretty sure it is there "+
           "nontheless");

  load_doors();
  reset(0);
}

int load_doors(void)
{
  add_door("to the north","to the south",NROOM+"cottage_clearing",
           "wooden door",1,0,"nokey","An wooden door.\n","north","south",
           5,10,0,0);
  return 1;
}

void init(void)
{
  add_action("do_open","open");
  add_multi_action("do_sleep","sleep|rest|lie|nap");
  ::init();
}

int do_open(string str)
{
  if(str == "curtain" || str == "curtains")
  {
    W("You think the person who lives here would like to keep them "+
      "drawn, so you only open them briefly and look outside. This is "+
       "what you see:\n");
    (NROOM+"cottage_clearing")->long();
    S(TP->QN+" opens the curtains and peers out the window for a short while "+
      "before drawing the curtains again.\n");
    tell_room(NROOM+"cottage_clearing","Someone opens the curtains in the "+
              "window briefly and peers out at you before drawing them "+
              "again.\n");
    return 1;
  }
}

int do_sleep(string str)
{
  object fisherman = present("fisherman");

  if(str == "bed" || str == "in bed" || str == "on bed")
  {
    W("You're not quite sure if it is safe to fall asleep in a building "+
      "like this, so you opt against it.\n");
    if(fisherman && fisherman->query_sleeping())
    {
      W("Besides, the bed is occupied by the fisherman already.\n");
    }
    return 1;
  }
  notify_fail(C(query_verb())+" where?\n");
}

void bed_desc(void)
{
  object fisherman = present("fisherman");

  W("A sad excuse for a bed. It looks to be in the same bad shape as the "+
    "rest of the house. ");
  if(fisherman && fisherman->query_sleeping())
  {
    W("The bed is occupied by the sleeping fisherman. ");
  }
  W("\n");
}
