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
    set_long("A small house in the village of Oakdale. In this house there " +
             "are two beds, a table and a fireplace. Four chairs are " +
             "placed around the table and on the west wall there is a " +
             "window.\n");
    set_new_light(10);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("beds","Two neatly made beds");
    add_item("bed","A neatly made bed");
    add_item("table","A sturdy wooden table");
    add_item("fireplace","A fireplace made of stone");
    add_item("chairs","Four chairs standing around the table. They are not " +
             "looking very comfortable");
    add_item("window","A small window in the west wall");
    add_item("chair","An uncomfortable looking chair");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "sarah",1);
    ::reset(arg);
}

int load_doors(void)
{
    string dir1 = "east";
    string dir2 = "west";
    string next_room = ROOM + "road25";
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
