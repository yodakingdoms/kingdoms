#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A small tower room");
    set_long("A small, cramped room lit by a flickering torch on one of " +
             "the black stone walls. Stairs go down from here and there " +
             "is a ladder going up through an opening in the ceiling. " +
             "There is an archway in the west wall.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("room","A cramped stairroom");
    add_item("torch","A single, flickering torch");
    add_item("wall|walls","Smooth, black stone");
    add_item("stair|stairs","They go down");
    add_item("ladder","A wooden ladder going up through an opening in the " +
             "ceiling");
    add_item("archway","It looks as if you'll come out on a roof if you go " +
             "through it");
    add_item("roof|top","You would have to go there to get a better look");
    add_item("opening","It looks as if you'll come out at the top of the " +
             "tower if you climb up there");
    add_item("tower","You are in it");

    add_exit(ROOM + "lev3_roof","west");
    add_exit(ROOM + "lev4_lookout","up");
    add_exit(ROOM + "lev2_guardroom2","down");
}
