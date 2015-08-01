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
    set_long("You are in a small house in the village. There is a bearskin " +
             "rug on the floor, a fireplace by the west wall, and three " +
             "beds in this house. This house is quite cold, as there is " +
             "no fire burning in the fireplace at the moment. A window is " +
             "in the east wall.\n");
    set_new_light(1);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("rug","A soft bearskin rug");
    add_item("fireplace","A stone fireplace. The hearth is cold");
    add_item("hearth","The hearth is cold as there is no fire burning " +
             "right now");
    add_item("wall|walls","Made of stone");
    add_item("beds","Three neatly made beds");
    add_item("window","A small window on the east wall");
    add_item("bed","A neatly made bed. One of three in this house");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "aylia",1);
    ::reset(arg);
}

int load_doors(void)
{
    string dir1 = "west";
    string dir2 = "east";
    string next_room = ROOM + "road14";
    string desc = "door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A wooden door.\n";
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
