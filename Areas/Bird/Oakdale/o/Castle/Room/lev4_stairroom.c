#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
int load_doors(void);

void create_object(void)
{
    set_short("A dark room at the top of the stairs");
    set_long("A cramped, dark room at the top of the stairs. There is a " +
             "holder for a torch on one of the walls, but it is empty. " +
             "Everything in this room is covered with dust, and there are " +
             "huge spider webs everywhere. Stairs descend into the " +
             "darkness below you. It looks like noone's been here in a " +
             "long while.\n");
    set_new_light(0);
    add_property("indoors");

    add_item("room","A dark, cramped stairroom. It doesn't look like " +
             "anyone has been here in a long time");
    add_item("holder","A rusty old torchholder");
    add_item("wall|walls","Smooth, black stone");
    add_item("dust","A thick layer of dust covers everything in the room. " +
             "It looks as if noone's been here in a long time");
    add_item("web|webs|spiderweb|spiderwebs","Big, old spiderwebs clinging " +
             "to you as you move through the room. You really hope there " +
             "are no spiders left, hiding somewhere among the webs..");
    add_item("stair|stairs","A spiralling staircase going down");
    add_item("darkness","Thick, impenetrable darkness");

    add_exit(ROOM + "lev3_stairroom","down");

    load_doors();
    reset(0);
}

int load_doors(void)
{
    string dir1 = "north";
    string dir2 = "south";
    string next_room = ROOM + "lev4_roof";
    string desc = "thick wooden door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A wooden door that doesn't look like it has been " +
                       "opened in a long time.\n";
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
