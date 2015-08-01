#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_block(string str);

void create_object(void)
{
    set_short("A cold dungeon room");
    set_long("You have entered the castle dungeons. This is a cold, damp " +
             "room with rough stone walls. The room is lit by a single, " +
             "flickering torch. There is a table and a wooden barrel here, " +
             "and a few stools are placed around the table. A corridor " +
             "leads off to the east, and stairs go up.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("room","A cold guardroom in the upper levels of the dungeon");
    add_item("wall|walls","The stone walls in this room are very rough " +
             "and uneven");
    add_item("torch","A single torch struggling to stay lit in the cold, " +
             "damp air");
    add_item("table","A small wooden table");
    add_item("stool|stools","A few small wooden stools are placed round the " +
             "table");
    add_item("corridor","A dungeon corridor going east");
    add_item("stair|stairs","Smooth stone steps going up");

    add_exit(ROOM + "dung_stairroom1","up");
    add_exit(ROOM + "dung_corridor1","east");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_trooper",2);
}

void init(void)
{
    add_multi_action("do_block","e|east");
}

int do_block(string str)
{
    if(present("darkling trooper",TO))
    {
        W("The trooper blocks your way and snarls: Get out of here.\n");
        S("A trooper stops " + TP->QN + " from going east.\n");
        return 1;
    }
    return 0;
}
