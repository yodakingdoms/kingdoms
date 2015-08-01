#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
int load_doors(void);

void create_object(void)
{
    set_short("The top of the stairs");
    set_long("A small, dark room at the top of the stairs. The walls are " +
             "smooth and black and the floor is covered with dust. Not a " +
             "sound can be heard, but the air seems to be filled with a " +
             "strange, evil power coming mainly through the door in the " +
             "north wall. Every fiber of your being is crying out for you " +
             "to leave. To run down the stairs and get as far away from " +
             "this unholy tower as you can.\n");
    set_new_light(0);
    add_property("indoors");

    add_item("room","A small room at the top of the stairs. You are at the " +
             "top of the tower now");
    add_item("stair|stairs","The stairs descend into the darkness below");
    add_item("darkness","A thick, impenetrable darkness. Still, you'd " +
             "rather run down there than stay here");
    add_item("wall|walls","Smooth, black stone");
    add_item("floor","The smooth, black floor is covered with dust");
    add_item("dust","A thick, unmoving layer of dust. Looks like noone's " +
             "been here in a long time, but you still feel a powerful " +
             "presence here");
    add_item("air","There's something wrong with the air in here. An evil " +
             "power is coming through the door, making you just want to " +
             "run away");

    add_exit(ROOM + "lev4_tower","down");

    load_doors();
    reset(0);
}

int load_doors(void)
{
    string dir1 = "north";
    string dir2 = "south";
    string next_room = ROOM + "lev5_nirachs_study";
    string desc = "black oak door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A thick, black oak door. You can feel the evil " +
                       "magic in the room beyond through it.\n";
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
