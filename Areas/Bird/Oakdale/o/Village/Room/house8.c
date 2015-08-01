#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
int load_doors(void);

void create_object(void)
{
    set_short("A small house in the village");
    set_long("A small house in the village. There is a window in the " +
             "north wall, a table and two beds here. Two chairs are " +
             "placed around the table.\n");
    set_new_light(10);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("window","You see the forest outside the window");
    add_item("forest","A dense forest of oak trees");
    add_item("table","A heavy oak table");
    add_item("beds","Two neatly made beds");
    add_item("bed","A neatly made bed");
    add_item("chair","A rickety chair");
    add_item("chairs","Two rickety chairs");

    load_doors();
    reset(0);
}

int load_doors(void)
{
    string dir1 = "south";
    string dir2 = "north";
    string next_room = ROOM + "road21";
    string desc = "wooden door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A wooden door.\n";
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
