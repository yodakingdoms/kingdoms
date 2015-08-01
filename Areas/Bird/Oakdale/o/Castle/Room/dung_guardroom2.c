#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_block(string str);

void create_object(void)
{
    set_short("A could dungeon room");
    set_long("A cold dungeon room with rough, black stone walls. The room " +
             "is lit by a flickering torch. There is a wooden table here, " +
             "with a few mugs on it. A few stools are placed round the " +
             "table, and a wooden barrel stands in one of the corners. " +
             "Water is seeping through the walls, gathering in small " +
             "puddles on the floor. Stairs go down from here, and there " +
             "is a doorway in the north wall.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("room","A cold dungeon guardroom");
    add_item("wall|walls","Rough, black stone");
    add_item("torch","A single torch, struggling to stay lit in the cold, " +
             "damp air");
    add_item("table","A wooden table with some mugs on it");
    add_item("mug|mugs","There are a few empty mugs on the table");
    add_item("stool|stools","There are a few wooden stools round the table");
    add_item("barrel","A wooden barrel containing drinking water");
    add_item("water","Water is seeping through the walls, gathering in " +
             "small puddles as it trickles to the floor");
    add_item("floor","An uneven stone floor");
    add_item("puddle|puddles","Small puddles of dirty water");

    add_exit(ROOM + "dung_corridor5","north");
    add_exit(ROOM + "dung_guardroom3","down");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_trooper",2);
    add_monster(MONSTER + "darkling_dung_keeper",2);
    foreach(object ob: all_inventory())
    {
        if(ob->id("darkling")) ob->set_aggressive(1);
    }
}

void init(void)
{
    add_multi_action("do_block","d|down");
}

int do_block(string str)
{
    if(present("darkling",TO))
    {
        W("A darkling steps in your way and won't let you pass!\n");
        S(TP->QN + " tries to go down but is stopped by a darkling!\n");
        return 1;
    }
    return 0;
}
