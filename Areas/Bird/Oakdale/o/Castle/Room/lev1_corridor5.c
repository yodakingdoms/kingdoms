#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);

void create_object(void)
{
    set_short("A wider corridor");
    set_long("A wide corridor dimly lit by a flickering torch on one of " +
             "the walls. The corridor continues back to the west, where " +
             "there is an intersection. The south wall is lined with doors " +
             "as far west as you can see from here.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("corridor","A wide corridor with black stone walls, floor and " +
             "ceiling");
    add_item("intersection","This corridor meets a narrower corridor to " +
             "the north there");
    add_item("wall|walls|floor|ceiling","Smooth black stone");
    add_item("torch","A single, flickering torch");
    add_item("doors","A few of them in the south wall further east");

    add_exit(ROOM + "lev1_corridor4","west");

    (ROOM + "lev1_room2")->load_doors();
    reset(0);
}
