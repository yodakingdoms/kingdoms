#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
void init(void);
int do_kneel(string str);
int load_doors(void);

void create_object(void)
{
    set_short("A spartan room");
    set_long("A small room lit only by a small candle. The air is cold, " +
             "but not as damp as in the rest of the dungeon. The black " +
             "stone walls are smooth and bare, and there's a ladder going " +
             "up through the trapdoor in the ceiling. A round mat is on the " +
             "floor, and seven small candles are placed in a circle around " +
             "it on the floor. A wooden bed stands by the north wall, and " +
             "by the east wall is a small stone altar. There is a strange " +
             "smell in the air, and something about this room makes you " +
             "feel uneasy.\n");
    set_skip_obvious(1);
    set_new_light(5);
    add_property("indoors");

    add_item("room","This looks almost like some kind of shrine. You feel " +
             "watched an uneasy here");
    add_item("shrine","That's what this room looks at");
    add_item("candle","A small wax candle on the stone altar. It's flame " +
             "wavers, but it stays lit");
    add_item("air","The air is cold and... Hmm... 'greasy' in some strange " +
             "way");
    add_item("wall|walls","Smooth, black stone. The walls are completely " +
             "undecorated");
    add_item("ladder","A ladder that will take you up through the trapdoor " +
             "in the ceiling");
    add_item("ceiling","There is a trapdoor in the ceiling");
    add_item("floor","A smooth, black stone floor");
    add_item("mat","It looks like a prayer mat");
    add_item("prayer mat","A mat you kneel on when you pray");
    add_item("circle|candles","Seven small candles placed round the mat in " +
             "a circle on the floor. They are not lit at the moment");
    add_item("bed","A hard wooden bed without a matress");
    add_item("altar","A small stone altar. There is a small wax candle on " +
             "it, and nothing else");
    add_item("%|%incense","It smells almost like incense, but not quite");

    load_doors();
    (ROOM + "dung_bottom1")->load_doors();

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_cleric",1);
    ::reset(arg);
}

void init(void)
{
    add_multi_action("do_kneel","kneel|pray");
    ::init();
}

int do_kneel(string str)
{
    W("No, you don't feel at ease here, and you have no desire to call on " +
      "whatever being it is that is worshipped here.\n");
    return 1;
}

int load_doors(void)
{
    string dir1 = "up";
    string dir2 = "down";
    string next_room = ROOM + "dung_stairroom2";
    string desc = "trapdoor";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A wooden trapdoor.\n";
    string entercmd1 = "up";
    string entercmd2 = "down";
    int solidity = 10;
    int complex = 0;
    int hidden1 = 0;
    int hidden2 = 0;

    add_door(dir1, dir2, next_room, desc,  closed, locked, key_id,
             long_desc, entercmd1, entercmd2, solidity, complex,
             hidden1, hidden2 );
    return 1;
}
