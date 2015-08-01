#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
int load_doors(void);

void create_object(void)
{
    set_short("A dark room in the sanatarium");
    set_long("A dimly lit room with walls, floor and ceiling of stone. " +
             "High up on one of the walls is a tiny hole that lets in " +
             "some light. There is no furniture in the room, only some " +
             "hay and a few empty plates on the floor.\n");
    set_skip_obvious(1);
    set_new_light(10);
    add_property("indoors");

    add_item("hole","A tiny hole that you wouldn't even be able to push " +
             "your fist through. It is the only source of light here");
    add_item("wall|walls|floor|ceiling","Made of grey stone");
    add_item("plates","The warden gives the lunatics food on these plates");
    add_item("hay","A sorry excuse for a bed");
    add_item("plate","A small metal plate the lunatics get their food on");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "madman2",1);
    add_monster(MONSTER + "fool",1);
    add_monster(MONSTER + "lunatic",1);
    add_monster(MONSTER + "wierdo",1);
    ::reset(arg);
}

int load_doors(void)
{
    string dir1 = "west";
    string dir2 = "east";
    string next_room = ROOM + "sanatarium";
    string desc = "door";
    int closed = 1;
    int locked = 1;
    string key_id = "_oakdale_sanatarium_key_";
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
