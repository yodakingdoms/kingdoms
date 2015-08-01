#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
int load_doors(void);

void create_object(void)
{
    set_short("A short, narrow corridor");
    set_long("A short, narrow corridor. The only light in here is coming " +
             "from a flickering torch on one of the black stone walls. " +
             "There is an archway in the west wall.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("corridor","A narrow corridor");
    add_item("torch","A single, flickering torch");
    add_item("wall|walls","Smooth, black stone");
    add_item("archway","It leads west");

    add_exit(ROOM + "lev3_landing2","west");

    load_doors();
    reset(0);
}

int load_doors(void)
{
    string dir1 = "south";
    string dir2 = "north";
    string next_room = ROOM + "lev3_room2";
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
