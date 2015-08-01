#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void init(void);
int do_sit(string str);
int do_clean(string str);
int load_doors(void);

void create_object(void)
{
    set_short("A small house in the village");
    set_long("You are in a small house in the village. This house is in " +
             "quite a mess. There is a bed, a table and a chair here as " +
             "well as a fireplace in the south wall. Everything is covered " +
             "by dust, and it looks like whoever lives here hasn't been " +
             "home in a long time.\n");
    set_new_light(1);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("mess","Well, not really a mess... Everything is where it " +
             "should be, but it is all covered in dust");
    add_item("bed|table|chair","Covered by a thick layer of dust");
    add_item("fireplace","It is cold and black");
    add_item("dust","A thick layer of dust covers everything here, giving " +
             "the impression that noone's been here in a long time");

    load_doors();
    reset(0);
}

void init(void)
{
    add_action("do_sit","sit");
    add_multi_action("do_clean","dust|tidy|clean");
}

int do_sit(string str)
{
    if(str == "chair" || str == "in chair")
    {
        W("You wouldn't feel right about disturbing the layer of dust on " +
          "it so you decide against it.\n");
        S(TP->QN + " looks at the chair, pondering.\n");
        return 1;
    }
    return notify_fail("Sit where?\n");
}

int do_clean(string str)
{
    W("You think about it for a while but then decide you have more " +
      "interesting things to do.\n");
    S(TP->QN + " looks around in the room, pondering.\n");
    return 1;
}

int load_doors(void)
{
    string dir1 = "west";
    string dir2 = "east";
    string next_room = ROOM + "road16";
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
