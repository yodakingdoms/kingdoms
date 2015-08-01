#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
void init(void);
int do_prepare(string str);
int load_doors(void);

void create_object(void)
{
    set_short("A kitchen (w)");
    set_long("This used to be the kitchen. Large wooden tables and benches " +
             "take up most of the space in the room. There is dirt and " +
             "debris everywhere. Some broken pots and pans lie thrown " +
             "in one of the corners. There are some cupboards by one of the " +
             "walls. Their doors are long gone and the shelves inside are " +
             "all empty. There's a huge cauldron in the large fireplace " +
             "in the east wall. It doesn't look like it's been used in a " +
             "long time.\n");

    set_new_light(5);
    add_property("indoors");
    set_skip_obvious(1);

    add_item("kitchen|filthy kitchen","That's what this used to be. You " +
             "would not want to eat a meal prepared here now though, as " +
             "it is filthy");
    add_item("table|tables|wooden table|wooden tables|large table|" +
             "large tables|large wooden table|large wooden tables|" +
             "filthy table|filthy tables","Large wooden tables used to " +
             "prepare food on. They are absolutely filthy");
    add_item("food","Not much of that here now, but the cupboards were " +
             "probably full of food in the days when people lived here");
    add_item("bench|benches|workbench|workbenches|filthy workbench|" +
             "filthy workbenches|filthy bench|filthy benches","Workbenches " +
             "to prepare food on. They are absolutely filthy");
    add_item("room","It's a kitchen, the heart of the house in many " +
             "peoples opinion");
    add_item("dirt|debris","There's lots and lots of that all around the " +
             "room. Not a nice environment to prepare food in");
    add_item("environment","It's not a nice one, the room is absolutely " +
             "filthy");
    add_item("pot|pots|broken pot|broken pots","Broken pots. Once useful, " +
             "now useless");
    add_item("pan|pans|broken pan|broken pans","Broken pans. Once useful, " +
             "now useless");
    add_item("corner|corners","There are broken pots and pans in one of " +
             "them. Someone seems to have been searching through the " +
             "kitchen and tossed them in the corner by the looks of it");
    add_item("cupboard|cupboards|shelf|shelves","All of them are empty, " +
             "except for filth. It looks as if they've been searched " +
             "many times");
    add_item("filth","There's lots of filth in the kitchen, it looks as if " +
             "it's been a long time since someone last cleaned it");
    add_item("wall|walls","There are cupboards by one of them and a " +
             "fireplace in another");
    add_item("doors","The doors of the cupboards have disappeared. Judging " +
             "by how the hinges look, the doors have been torn off by " +
             "someone");
    add_item("hinge|hinges|broken hinge|broken hinges","The hinges are all " +
             "broken. It looks like someone was in a real hurry to open " +
             "the doors");
    add_item("cauldron|huge cauldron","Looks like one could cook a lot of " +
             "food in that cauldron but now it is empty");
    add_item("fireplace|large fireplace","It takes a large fireplace to " +
             "hold that huge cauldron. It does not look as if there's been " +
             "a fire lit there lately");
    add_item("east wall","There's a huge fireplace in it");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "goblin",3);
    ::reset(arg);
}

void init(void)
{
    add_action("do_prepare","prepare");
    ::init();
}

int do_prepare(string str)
{
    if(str == "food")
    {
        W("You don't want to prepare any food on these filthy tables.\n");
        S(TP->QN + " looks at the tables and hmms thoughtfully.\n");
        return 1;
    }
    return notify_fail("Prepare what?\n");
}

int load_doors(void)
{
    string dir1 = "to the west";
    string dir2 = "to the east";
    string next_room = ROOM + "house_floor1_dining_room";
    string desc = "wooden door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A worn door.\n";
    string entercmd1 = "west";
    string entercmd2 = "east";
    int solidity = 30;
    int complex = 20;
    int hidden1 = 0;
    int hidden2 = 0;

    add_door(dir1, dir2, next_room, desc,  closed, locked, key_id,
             long_desc, entercmd1, entercmd2, solidity, complex,
             hidden1, hidden2 );
    return 1;
}