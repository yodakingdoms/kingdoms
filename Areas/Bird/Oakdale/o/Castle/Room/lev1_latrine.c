#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void init(void);
int do_latrine(string str);
int load_doors(void);

void create_object(void)
{
    set_short("A latrine");
    set_long("A small, dark room with an awful smell. The stone walls are " +
             "smooth and black. The only thing in this room is a hole in " +
             "the floor. This is obviously a latrine.\n");
    set_new_light(0);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("room","Judging by the hole in the wall and the smell, this " +
             "is probably a latrine");
    add_item("wall|walls","Smooth, black stone");
    add_item("floor","Smooth, black stone with a hole in it");
    add_item("hole","Well, it's the kind of hole the things you normally " +
             "produce in a latrine are disposed of through");
    add_item("latrine","You're standing in it. However, you're not " +
             "enjoying it");
    add_item("%","Groan. You just want to get out of here as fast as you " +
             "can");

    load_doors();
    reset(0);
}

void init(void)
{
    add_multi_action("do_latrine","shit|pee|piss|relieve|crap");
    ::init();
}

int do_latrine(string str)
{
    W("Just as you're going to pull your pants down and get comfortable, " +
      "you notice something moving in the... umm, well, let's just say " +
      "'goo' under the hole, so you decide against it.\n");
    S(TP->QN + " steps up to the hole in the latrine, but suddenly it " +
      "seems like " + TP->QPR + " decides against getting comfortable.\n");
    return 1;
}

int load_doors(void)
{
    string dir1 = "north";
    string dir2 = "south";
    string next_room = ROOM + "lev1_diner";
    string desc = "wooden door";
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
