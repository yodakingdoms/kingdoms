#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
int load_doors(void);

void create_object(void)
{
    set_short("Second floor landing");
    set_long("A landing on the second floor of the sanatarium. There is " +
             "no window in this small room. The walls are made of stone " +
             "and the floor and the ceiling is made of wood. Stairs lead " +
             "down to the main room. There is a sign on the door here.\n");
    set_new_light(1);
    add_property("indoors");

    add_exit(ROOM + "sanatarium","down");

    add_item("wall","The wall is made of stone");
    add_item("walls","The walls are made of stone");
    add_item("ceiling|floor","Made of wood");
    add_item("stairs","Wooden stairs going down");
    add_item("sign","Try reading it");
    add_item("@sign","The sign says: 'Dangerous individual. DO NOT BELIEVE " +
             "A SINGLE WORD THIS MAN SAYS'");

    load_doors();
    reset(0);
}

int load_doors(void)
{
    string dir1 = "west";
    string dir2 = "east";
    string next_room = ROOM + "sanatarium3";
    string desc = "door";
    int closed = 1;
    int locked = 1;
    string key_id = "_oakdale_sanatarium_key_";
    string long_desc = "A wooden door. There is a sign on it.\n";
    string entercmd1 = "west";
    string entercmd2 = "east";
    int solidity = 10;
    int complex = 0;
    int hidden1 = 0;
    int hidden2 = 0;

    add_door(dir1, dir2, next_room, desc,  closed, locked, key_id,
             long_desc, entercmd1, entercmd2, solidity, complex,
             hidden1, hidden2 );
    return 1;
}
