#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
void init(void);
int do_play(string str);
int load_doors(void);

void create_object(void)
{
    set_short("A small house in the village");
    set_long("You are in a small house in the village. There are nice " +
             "white curtains by the window in the east wall. A small fire " +
             "is burning in the fireplace, and a bed is by the north wall. " +
             "A chair and a number of little stools are placed around a " +
             "round table in the centre of the room. Toys are scattered all " +
             "over the floor.\n");
    set_new_light(10);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("curtains","Nice white curtains with small flowers on them");
    add_item("flowers","While we wait for someone to get a botanist guild " +
             "going, the unsatisfactory answer will have to be:'You don't " +
             "recognize them");
    add_item("window","You see the forest outside the window");
    add_item("forest","A dense forest of oak trees");
    add_item("wall|walls","Made of stone");
    add_item("fireplace","A small fire is burning in the stone fireplace");
    add_item("bed","A neatly made bed");
    add_item("chair","A small wooden chair");
    add_item("stools","There are about six of them placed round the table");
    add_item("table","A heavy round wooden table");
    add_item("stool","A small wooden stool");
    add_item("toys","Lots of different toys of the kind small children " +
             "like to play with");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "child",5);
    add_monster(MONSTER + "lynia",1);
    ::reset(arg);
}

void init(void)
{
    add_action("do_play","play");
    ::init();
}

int do_play(string str)
{
    if(str == "with toys")
    {
        W("You start playing with the toys. You have a great time, but " +
          "when you look up for a moment you notice the whole population " +
          "of the village standing in the door peering quizzically at you. " +
          "Embarrassed you put the toys back on the floor.\n");
        S(TP->QN + " starts playing with the toys, looking utterly silly.\n");
        return 1;
    }
    return notify_fail("Play with what?\n");
}

int load_doors(void)
{
    string dir1 = "west";
    string dir2 = "east";
    string next_room = ROOM + "road21";
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
