#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A narrow corridor");
    set_long("A dark, narrow corridor continuing to the east. The corridor " +
             "is lit by a flickering torch on one of the walls. There are " +
             "archways in the west and south walls.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("corridor","A narrow corridor, dimly lit by a torch on the wall");
    add_item("torch","A single, flickering torch");
    add_item("wall|walls","Black stone walls");
    add_item("archway|archways","Two archways beyond which other rooms lie");
    add_item("room|rooms","You'll have to visit them to look at them");

    add_exit(ROOM + "lev2_landing","south");
    add_exit(ROOM + "lev2_corridor2","east");
    add_exit(ROOM + "lev2_dininghall","west");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_officer",1)->set_walking();
}
