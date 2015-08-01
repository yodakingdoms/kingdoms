#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
void init(void);
int do_sit(string str);
int do_sleep(string str);
int load_doors(void);

void create_object(void)
{
    set_short("A small house in the village");
    set_long("You are in one of the small houses in the village. There is a " +
             "window on the west wall through which you see the forest. A " +
             "bed, a table and a chair are the only pieces of furniture in " +
             "this house.\n");
    set_skip_obvious(1);
    set_new_light(10);
    add_property("indoors");

    add_item("window","A small window through which you see the forest");
    add_item("forest","A dense forest of oak trees");
    add_item("bed","A very uncomfortable looking bed");
    add_item("chair","A rickety looking chair");
    add_item("table","A small bedside table");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "jagg",1);
    ::reset(arg);
}

void init(void)
{
    add_action("do_sit","sit");
    add_multi_action("do_sleep","sleep|lay");
    ::init();
}

int do_sit(string str)
{
    W("You sit down on the chair, but it's not the most comfortable " +
      "chair you've ever sat in.\n");
    S(TP->QN + " sits down in the chair but doesn't seem to be very " +
      "comfortable.\n");
    return 1;
}

int do_sleep(string str)
{
    W("The bed looks too uncomfortable, you don't want to do that.\n");
    S(TP->QN + " looks at the bed, pondering.\n");
    return 1;
}

int load_doors(void)
{
    string dir1 = "east";
    string dir2 = "west";
    string next_room = ROOM + "road19";
    string desc = "door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A wooden door.\n";
    string entercmd1 = "east";
    string entercmd2 = "west";
    int solidity = 10;
    int complex = 0;
    int hidden1 = 0;
    int hidden2 = 0;

    add_door(dir1, dir2, next_room, desc,  closed, locked, key_id,
             long_desc, entercmd1, entercmd2, solidity, complex,
             hidden1, hidden2 );
    return 1;
}
