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
    set_long("You are in a small house in the village. There is a window in " +
             "the south wall, and a fireplace in the west. By the north " +
             "wall stands a bed, and in the middle of the room is a table. " +
             "Two chairs stand next to the table. There are no " +
             "decorations at all in this house.\n");
    set_new_light(10);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("window","The main village road is on the other side");
    add_item("road","You'd get a better look if you'd go there");
    add_item("wall|walls","Made of stone");
    add_item("table","A heavy wooden table");
    add_item("chairs|chair","Two very spartan looking chairs are near the " +
             "table");
    add_item("fireplace","The old stone fireplace is used to warm the room");
    add_item("bed","The bed is simple and neatly made up");
    add_item("floor|floors","The floors are scuffed and worn");
    add_item("ceiling","You examine the thatched roof");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "arkam",1);
    ::reset(arg);
}

int load_doors(void)
{
    string dir1 = "west";
    string dir2 = "east";
    string next_room = ROOM + "road20";
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
