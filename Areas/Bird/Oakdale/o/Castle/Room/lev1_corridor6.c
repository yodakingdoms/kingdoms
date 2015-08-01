#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);

void create_object(void)
{
    set_short("A wider corridor");
    set_long("You are in a wide corridor dimly lit by a flickering torch " +
             "on one of the walls. The corridor continues to the east and " +
             "the west. To the east there is an intersection where a " +
             "narrower corridor from the north meets this one.\n");
    set_new_light(5);
    add_property("indoors");
        
    add_item("corridor","A wide corridor with black stone walls, floor and " +
             "ceiling");
    add_item("wall|walls|floor|ceiling","Smooth, black stone");
    add_item("torch","A single flickering torch");
    add_item("doors","A few of them, both to the west and further east");

    add_exit(ROOM + "lev1_corridor4","east");
    add_exit(ROOM + "lev1_corridor7","west");

    (ROOM + "lev1_room3")->load_doors();
    reset(0);
}
