#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
int load_doors(void);

void create_object(void)
{
    set_short("A house in the village");
    set_long("You are in a small house in the village. There is a small " +
             "window in the north wall and a fireplace in the east wall. " +
             "In this house you see three beds, and there are three " +
             "chairs standing around a table. On the west wall there is a " +
             "shelf.\n");
    set_new_light(1);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("window","You see the forest outside the window");
    add_item("forest","A dense forest of oak trees");
    add_item("fireplace","A stone fireplace. There are some ashes in it");
    add_item("ashes","Probably from a fire that is no longer burning");
    add_item("beds","Three neatly made beds");
    add_item("chairs","They stand around the table and there are three of " +
             "them");
    add_item("chair","One of three chairs standing round the table");
    add_item("table","A heavy oak table");
    add_item("shelf","A wooden shelf with some plates on it");
    add_item("wall|walls","Made of stone");
    add_item("plates","Some plain white plates of the kind commonly use for " +
             "eating from");
    add_item("plate","A plain white plate of the kind commonly used for " +
             "eating from");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "lamin",1);
    add_monster(MONSTER + "cara",1);
    ::reset(arg);
}

int load_doors(void)
{
    string dir1 = "south";
    string dir2 = "north";
    string next_room = ROOM + "road9";
    string desc = "door";
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
