#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int  do_slip(string str);

void create_object(void)
{
    set_short("Underground stone staircase (u/d)");
    set_long("An underground stone staircase going down and up. There is "+
             "no source of light here, but light both from above and below "+
             "is enough to let you see. That is a good thing, since the "+
             "cold stone steps are wet and slippery and you'd probably "+
             "slip and break your neck walking here in the dark. The air "+
             "here is chilly and damp.\n");
    set_new_light(5);
    set_property("indoors");

    add_item("staircase","It is a slippery stone staircase");
    add_item("source","There's no source of light in this room, but the "+
             "light in the rooms above and below is bright enough to let "+
             "you see in this room as well");
    add_item("stone|black stone|cold stone|cold, black stone",
             "Cold, black stone");
    add_item("light","Light is spilling into this room from the rooms "+
             "above and below you");
    add_item("room","It's just halfway down an underground staircase");
    add_item("wall|walls","Cold stone walls that look as if they have "+
             "been dug out of the rock by someone, rather than created "+
             "naturally");
    add_item("rooms","You would have to go up or down to get a better "+
             "look at the rooms above and below this one");
    add_item("step|steps","The stone steps are wet, no doubt thanks to "+
             "the damp air, and are very slippery. It would be easy to slip "+
             "and risk breaking your neck here");
    add_item("neck","You have a hard time getting a good look at your "+
             "own neck");
    add_item("air","The air here is a bit chilly and damp");

    add_exit(PCROOM + "forest_entrance","up");
    add_exit(PCROOM + "lev1_south_guardroom","down");
}

void init(void)
{
    add_action("do_slip","slip");
}

int do_slip(string str)
{
    W("You slip on one of the slippery steps and tumble, head first, "+
      "down the stairs!\n");
    TP->move_player("slips on one of the steps and tumbles down the "+
                    "stairs!",
                    PCROOM + "lev1_south_guardroom",
                    "comes tumbling down the stairs from above!",1);
    W("You land in the room below with a *THUD*\n");
    TP->add_temporary_penalty((2+random(5)));
    W("That was a pretty stupid thing to do! You're lucky you didn't "+
      "break your neck!\n");
    return 1;
}
