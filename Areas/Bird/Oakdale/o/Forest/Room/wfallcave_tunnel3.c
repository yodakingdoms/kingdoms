#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void init(void);
void do_feel(string str);

void create_object(void)
{
    set_short("A dark, cold tunnel");
    set_long("A narrow tunnel sloping gently downwards to the west. The " +
             "air is damp, but you think you feel some puffs of fresh air " +
             "coming from the east. Water is dripping from the ceiling, " +
             "falling to the floor and slowly trickling down to the west. " +
             "You can almost feel the weight of the hill above pressing " +
             "down upon the ceiling.\n");
    set_new_light(0);
    add_property("indoors");

    add_item("tunnel","A narrow tunnel sloping gently downwards");
    add_item("wall|walls","The stone walls are black and cold");
    add_item("water","Water dripping from the ceiling, trickling down to " +
             "the west as it hits the floor");
    add_item("ceiling","A rough stone ceiling");
    add_item("floor","A rough stone floor");

    add_sounds(05,80,({ "Drip, drop...\n" }));

    add_exit(ROOM + "wfallcave_mainroom","east");
    add_exit(ROOM + "wfallcave_kitchen","west");
}

void init(void)
{
    add_action("do_feel","feel");
    ::init();
}

int do_feel(string str)
{
    W("The air is damp, but you do feel some puffs of fresh air coming " +
      "from the west...\n");
    S(TP->QN + " looks as if " + TP->QPR + " feels something.\n");
    return 1;
}
