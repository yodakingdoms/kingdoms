#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_smell(string str);
int do_taste(string str);

void create_object(void)
{
    set_short("A small cave with a big fireplace in the wall");
    set_long("A small cave with a big fireplace in one wall. A hot fire is " +
             "roaring it it, and the room is hot enough to make you sweat " +
             "lightly. A few wooden barrels and crates are here, and a " +
             "bench and a table stand by the wall opposite to the " +
             "fireplace. The smell in this room is not very pleasant, " +
             "in fact it could be categorized as appalling. If this is a " +
             "kitchen, and it looks like just that, you're glad you're " +
             "not here for dinner.\n");
    set_new_light(10);
    add_property("indoors");

    add_item("cave","A small cave, apparently serving as a kitchen");
    add_item("fireplace","Basically a big hole in the wall. There is a " +
             "hot fire burning in it. A pot is hanging over it");
    add_item("fire","Looks like someone's preparing a big meal");
    add_item("pot","A sickly green soup is boiling in it");
    add_item("soup","If it tastes as well as it smells, you decide death " +
             "at the hands of the Demogorgon would a less cruel fate than " +
             "to have to taste it");
    add_item("hole","The fireplace looks more or less like a hole in the " +
             "wall");
    add_item("barrel|crate|barrels|crates","Things for storing food and " +
             "water in");
    add_item("bench","A wooden bench");
    add_item("table","A wooden table");
    add_item("wall|walls","Smooth stone walls");
    add_item("kitchen","Looks like it. If the smell here is any indication " +
             "of how the food prepared here tastes, you probably will not " +
             "like what they serve");

    add_exit(ROOM + "dgcave_entrance","west");
    add_exit(ROOM + "dgcave_guards","east");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "DGcook",1);
    add_monster(MONSTER + "DGnome",2);
}

void init(void)
{
    add_action("do_smell","smell");
    add_action("do_taste","taste");
}

int do_smell(string str)
{
    W("It smells like someone's just prepared a meal, but considering how " +
      "this room smells, you're glad you didn't have to eat that meal...\n");
    S(TP->QN + " fills " + TP->QPO + " nostrils with the scent in the " +
      "room but doesn't look too impressed.\n");
    return 1;
}

int do_taste(string str)
{
    if(str == "soup")
    {
        W("Hmm... Wow! This is actually not that bad! It smells like " +
          "sewage, but it tastes really good! What a pleasant surprise!:)\n");
        S(TP->QN + " tastes the soup! Does " + TP->QPR + " have a " +
          "deathwish??\nHmm... It looks like " + TP->QPR + " will live " +
          "after all, and " + TP->QPR + " even looks pleasantly " +
          "surprised.\n");
        return 1;
    }
    return notify_fail("Taste what?\n");
}
