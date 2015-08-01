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
    set_long("A small house in the village. There is a window in the " +
             "west wall and a fireplace to the south. There is a bed here, " +
             "and on a bearskin rug in the middle of the house stands a " +
             "table. A chair is placed by the table, and on the north " +
             "wall hangs the skin of a huge bear.\n");
    set_new_light(1);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("window","You can see the forest through the window");
    add_item("forest","A dense forest of oak trees");
    add_item("wall|walls","Made of stone");
    add_item("bed","A large bed. The cover is made of the skin of a " +
             "large bear");
    add_item("fireplace","Just a normal fireplace. It looks like there " +
             "hasn't been a fire lit in there for a while");
    add_item("rug","A beautiful bearskin rug");
    add_item("table","A sturdy oak table");
    add_item("chair","A large wooden chair. It does not look comfortable");
    add_item("skin|bearskin","The bear that once filled that skin must " +
             "have been really huge");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "kendar",1);
    ::reset(arg);
}

int load_doors(void)
{
    string dir1 = "east";
    string dir2 = "west";
    string next_room = ROOM + "road12";
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
