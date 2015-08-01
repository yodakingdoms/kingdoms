#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);

void create_object(void)
{
    set_short("A wider corridor");
    set_long("A wide corridor dimly lit by a flickering torch on one of " +
             "the walls. The corridor ends here and continues back to east. " +
             "Doors line the south wall as far east as you can see.\n");
    set_new_light(5);
    add_property("indoors");
    
    add_exit(ROOM + "lev1_corridor6","east");
    
    add_item("corridor","A wide corridor with black stone walls, floor " +
             "and ceiling");
    add_item("wall|walls|floor|ceiling","Smooth, black stone");
    add_item("torch","A lone, flickering torch");
    add_item("doors","There are several of them in the south wall of the " +
             "corridor");

    (ROOM + "lev1_room4")->load_doors();
    reset(0);
}
