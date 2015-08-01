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
    set_long("You are in a small house in the village. There is a window " +
             "in the north wall and a fireplace in the west one. A small " +
             "fire is burning in the fireplace creating a cozy atmosphere. " +
             "There are three beds and a small crib here, and a table " +
             "stands on a rug on the floor.\n");
    set_skip_obvious(1);
    set_new_light(1);
    add_property("indoors");

    add_item("window","The main village road is on the other side");
    add_item("road","You'd see it a lot better if yod go there");
    add_item("wall|walls","Stone walls");
    add_item("fireplace","A stone fireplace where a small fire is burning");
    add_item("fire","A small fire providing the house with just enough heat");
    add_item("beds","Two normal sized beds and one small bed");
    add_item("bed","Probably a bed for a child");
    add_item("crib","A place where babies sleep");
    add_item("table","A heavy oak table");
    add_item("rug","A nice green rug");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "alena",1);
    add_monster(MONSTER + "ylena",1);
    ::reset(arg);
}

int load_doors(void)
{
    string dir1 = "north";
    string dir2 = "south";
    string next_room = ROOM + "road7";
    string desc = "door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A wooden door.\n";
    string entercmd1 = "north";
    string entercmd2 = "south";
    int solidity = 10;
    int complex = 0;
    int hidden1 = 0;
    int hidden2 = 0;

    add_door(dir1, dir2, next_room, desc,  closed, locked, key_id,
             long_desc, entercmd1, entercmd2, solidity, complex,
             hidden1, hidden2 );
    return 1;
}
