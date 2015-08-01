#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
int load_doors(void);

void create_object(void)
{
    set_short("A narrow corridor");
    set_long("A narrow corridor dimly lit by a flickering torch on one of " +
             "the black stone walls. The corridor continues to the west. " +
             "You hear noises and talking voices from to other side of " +
             "the door to the south.\n");
    set_new_light(1);
    add_property("indoors");

    add_item("corridor","A narrow, dimly lit corridor");
    add_item("torch","A single, flickering torch");
    add_item("wall|walls","Smooth, black stone");
    add_item("$","It sounds like there are some guards on the other side " +
             "of the door");

    add_exit(ROOM + "lev2_corridor1","west");

    load_doors();
    reset(0);
}

int load_doors(void)
{
    string dir1 = "south";
    string dir2 = "north";
    string next_room = ROOM + "lev2_guardroom1";
    string desc = "oak door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A strong oak door.\n";
    string entercmd1 = "south";
    string entercmd2 = "north";
    int solidity = 10;
    int complex = 0;
    int hidden1 = 0;
    int hidden2 = 0;

    add_door(dir1, dir2, next_room, desc,  closed, locked, key_id,
             long_desc, entercmd1, entercmd2, solidity, complex,
             hidden1, hidden2 );
    return 1;
}
