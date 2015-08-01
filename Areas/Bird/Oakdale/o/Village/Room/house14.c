#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
void init(void);
int do_taste(string str);
int load_doors(void);

void create_object(void)
{
    set_short("A house in the village");
    set_long("You are in a small house in the village. In the south wall " +
             "there is a small window, and in the west wall there is a " +
             "fireplace. A small pot is hanging over a small fire. There " +
             "are two beds and a table with two chairs around it in this " +
             "house.\n");
    set_new_light(10);
    set_skip_obvious(10);
    add_property("indoors");

    add_item("window","You can see the forest outside the window");
    add_item("forest","A dense forest of oak trees");
    add_item("wall|walls","Made of stone");
    add_item("fireplace","A stone fireplace where a small pot is hanging " +
             "over the fire");
    add_item("pot","A small pot containing some soup");
    add_item("soup","It looks tasty, but you'll never know if you don't " +
             "taste it");
    add_item("fire","A small fire, over which a small pot is hanging");
    add_item("beds","Two neatly made beds");
    add_item("table","A heavy oak table");
    add_item("chairs","Two wooden chairs");
    add_item("bed","A neatly made bed");
    add_item("chair","A wooden chair");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darin",1);
    add_monster(MONSTER + "linia",1);
    ::reset(arg);
}

void init(void)
{
    add_action("do_taste","taste");
    ::init();
}

int do_taste(string str)
{
    if(str == "soup")
    {
        W("Ouch! It was a bit too hot to taste.\n");
        S(TP->QN + " tastes the soup but spits it out. Apparently it was " +
          "too hot.\n");
        return 1;
    }
    return notify_fail("Taste what?\n");
}

int load_doors(void)
{
    string dir1 = "north";
    string dir2 = "south";
    string next_room = ROOM + "road26";
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
