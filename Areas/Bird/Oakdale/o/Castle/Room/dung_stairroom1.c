#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_block(string str);

void create_object(void)
{
    set_short("A small stairroom");
    set_long("A small room dimly lit by a flickering torch on one of the " +
             "walls. There is a wooden table here, and a few stools are " +
             "placed by it. Stairs go both up and down from this room. The " +
             "air is cold, and water is seeping through the stone walls, " +
             "forming small puddles on the floor.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("room","A small stairroom. It seems like it is halfway down " +
             "into the dungeons");
    add_item("torch","A single, flickering torch");
    add_item("wall|walls","Smooth, black stone");
    add_item("table","A small wooden table");
    add_item("stool|stools","There are two small wooden stools here");
    add_item("stair|stairs","Smooth, black stone steps");
    add_item("water","Water seeping through the walls, trickling down onto " +
             "the floor");
    add_item("puddle|puddles","Tiny puddles on the floor, where the water " +
             "seeping through the walls gather");
    add_item("floor","A smooth stone floor, with some puddles on it");

    add_exit(ROOM + "stable","up");
    add_exit(ROOM + "dung_guardroom1","down");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_soldier",2);
}

void init(void)
{
    add_multi_action("do_block","d|down");
}

int do_block(string str)
{
    if(present("soldier",TO))
    {
        W("A soldier grabs you and asks: And where do you think you're " +
          "going?\n");
        S("A soldier stops " + TP->QN + " from going down.\n");
        return 1;
    }
    return 0;
}
