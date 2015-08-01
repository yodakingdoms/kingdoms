#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void)
{
    set_short("A narrow corridor");
    set_long("You are in a narrow corridor dimly lit by a flickering torch. " +
             "The corridor turns to the south, and to the west is an " +
             "archway beyond which you see the main entrance hall. The " +
             "corridor continues to the south.\n");
    set_new_light(5);
    add_property("indoors");
        
    add_item("corridor","A narrow corridor with black stone walls, floor " +
             "and ceiling");
    add_item("wall|walls|ceiling","Smooth, black stone");
    add_item("torch","A single, flickering torch");
    add_item("archway","The main entry hall lies beyond it");
    add_item("hall","It lies beyond the archway to the west");

    add_exit(ROOM + "lev1_entr","west");
    add_exit(ROOM + "lev1_corridor3","south");    
}
