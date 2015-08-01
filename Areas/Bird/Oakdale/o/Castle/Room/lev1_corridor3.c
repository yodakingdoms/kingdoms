#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void)
{
    set_short("A narrow corridor");
    set_long("You are in a narrow corridor going north and south. The " +
             "corridor is dimly lit by a flickering torch on one of the " +
             "walls. To the south there seems to be an intersection.\n");
    set_new_light(5);
    add_property("indoors");
        
    add_item("corridor","A narrow corridor with black stone walls, floor " +
             "and ceiling");
    add_item("wall|walls|floor|ceiling","Smooth, black stone");
    add_item("torch","A single, flickering torch");
    add_item("intersection","This corridor meets a wider, east-west going " +
             "corridor there");

    add_exit(ROOM + "lev1_corridor2","north");
    add_exit(ROOM + "lev1_corridor4","south");    
}
