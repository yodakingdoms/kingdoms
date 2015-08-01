#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    ::create_object();
    set_short("A kitchen (u/e)");
    set_long("The filthiest kitchen you have ever seen. The air is filled " +
             "with fumes and smoke from the cauldrons in the fireplace and " +
             "the pots and pans on the stove. The floor is wet and slimy " +
             "and dirty knives, forks and pots lie everywhere. In one " +
             "corner is a huge stack of unwashed plates with strange green " +
             "things growing and occasionally moving on them. Dirt and " +
             "grime is everywhere.\n");

    add_item("kitchen|filthy kitchen","You are in a filthy kitchen");
    add_item("air","Filled with smoke and fumes. You can't wait to get out " +
             "of here");
    add_item("fumes|smoke","Fumes and smoke from the boiling pots and " +
             "cauldrons");
    add_item("pot|pots","Filthy pots with strange things cooking in them");
    add_item("pan|pans","Filthy pans with strange things frying in them");
    add_item("cauldron|cauldrons","Filthy cauldrons with strange things " +
             "boiling in them");
    add_item("thing|things|strange thing|strange things","You almost " +
             "throw up at the thought of that being served as food");
    add_item("fireplace","A big enough fireplace to have room for several " +
             "cauldron");
    add_item("stove","A big stove covered with filth and grime");
    add_item("filth|grime|stuff","Stuff that really has no place in a " +
             "kitchen");
    add_item("floor","It's wet and slimy, covered with a dirt, water and " +
             "other disgusting wet things");
    add_item("water|wet things","You'd rather not think about what's " +
             "mixed with the water on the floor");
    add_item("knife|fork|knives|forks","They are filthy");
    add_item("corner","There's a huge stack of unwashed plates there");
    add_item("stack|huge stack|plate|plates","Strange green things grow on " +
             "them, and sometimes it seems like they move!");
    add_item("green thing|green things","Might be a new lifeform");
    add_item("lifeform","A green and disgusting lifeform");
    add_item("dirt|grime","Things that really have no place in a kitchen");

    add_exit(PCROOM + "lev1_kitchen_stairs","up");
    add_exit(PCROOM + "lev2_corridor1","east");

    reset(0);
}

void reset(int arg)
{
    add_monster(PCMONSTER + "pirate_cook",1);
}
