#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
int load_doors(void);

void create_object(void)
{
    set_short("A stable, now serving as a guardroom");
    set_long("A large hall that apparently once was used as a stable. Now, " +
           "however it is used as a guardroom. Several benches and tables " +
           "stand on the wooden floor, and a few flickering torches hang " +
           "on the windowless stone walls. Stone stairs in one end of the " +
           "room go down, and some wooden stairs in the other end go up.\n");
    set_new_light(5);
    add_property("indoors");
    add_property("allow_horse");

    add_item("hall|room","A square hall that looks as if it has been used " +
             "as a stable");
    add_item("bench|benches","Wooden benches");
    add_item("table|tables","Heavy wooden tables");
    add_item("floor","A dirty wooden floor");
    add_item("torch|torches","There are a few flickering torches on the " +
             "walls, providing barely enough light for you to be able to " +
             "see in here");
    add_item("wall|walls","Black stone walls with no windows in them");
    add_item("stairs","Stone stairs going down and wooden stairs going up");
    add_item("stone stairs","They go down");
    add_item("wooden stairs","They go up");

    add_exit(ROOM + "icourtyardw","south");
    add_exit(ROOM + "lev2_guardroom2","up");
    add_exit(ROOM + "dung_stairroom1","down");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_sentry",2);
    add_monster(MONSTER + "darkling_guard",2);
    add_monster(MONSTER + "darkling_trooper",2);
    ::reset(arg);
}

int load_doors(void)
{
    string dir1 = "west";
    string dir2 = "east";
    string next_room = ROOM + "supply";
    string desc = "oak door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A strong oak door.\n";
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
