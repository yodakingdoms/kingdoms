#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
int load_doors(void);

void create_object(void)
{
    set_short("A dungeon corridor");
    set_long("You are in a cold, damp dungeon corridor lit by a flickering " +
             "torch. Water is seeping through the rough stone walls, slowly " +
             "trickling down to the floor and gathering in small puddles. " +
             "The corridor continues to the east, and a room is to the " +
             "west.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("corridor","A cold dungeon corridor with rough stone walls");
    add_item("torch","A torch struggling to stay lit in the cold, damp air");
    add_item("water","It is seeping through the walls and gathering in " +
             "small puddles as it trickles to the floor");
    add_item("walls|wall","Rough, black stone");
    add_item("puddle|puddles","Small puddles of dirty water");
    add_item("floor","Quite a smooth stone floor with a few puddles of " +
             "water on it");
    add_item("room","You should go there if you want a better look");

    add_exit(ROOM + "dung_guardroom1","west");
    add_exit(ROOM + "dung_corridor2","east");

    load_doors();
    reset(0);
}

int load_doors(void)
{
    string dir1 = "north";
    string dir2 = "south";
    string next_room = ROOM + "dung_cell1";
    string desc = "wooden door";
    int closed = 1;
    int locked = 1;
    string key_id = "_oakdale_cell_key_";
    string long_desc = "A thick, wooden cell door.\n";
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
