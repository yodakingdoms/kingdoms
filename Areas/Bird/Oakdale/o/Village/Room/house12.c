#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
int load_doors(void);

void create_object(void)
{
    set_short("A small house in the village");
    set_long("You are in one of the small houses in the village. The stone " +
             "walls are grey and undecorated, and there is a window to the " +
             "west. There is a fireplace with a small fire burning in it " +
             "in the north wall. A table with a few chairs, and a few beds " +
             "are here as well. A small lamp is hanging from the wooden " +
             "ceiling.\n");
    set_new_light(1);
    add_property("indoors");
    set_skip_obvious(1);

    add_item("wall|walls","Made of stone");
    add_item("window","A small window through which you can see the forest");
    add_item("forest","A forest of oak trees");
    add_item("fireplace","A well built fireplace");
    add_item("fire","A nice, small fire");
    add_item("table","A heavy oak table");
    add_item("chairs|beds","There are three of them here");
    add_item("chair|bed","One of three in the room");
    add_item("lamp","An oil lamp, not lit at the moment");
    add_item("ceiling","Made of wood");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "giron",1);
    add_monster(MONSTER + "laira",1);
    ::reset(arg);
}

int load_doors(void)
{
    string dir1 = "east";
    string dir2 = "west";
    string next_room = ROOM + "well";
    string desc = "door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A wooden door.\n";
    string entercmd1 = "east";
    string entercmd2 = "west";
    int solidity = 10;
    int complex = 0;
    int hidden1 = 0;
    int hidden2 = 0;

    add_door(dir1, dir2, next_room, desc,  closed, locked, key_id,
             long_desc, entercmd1, entercmd2, solidity, complex,
             hidden1, hidden2 );
    return 1;
}
