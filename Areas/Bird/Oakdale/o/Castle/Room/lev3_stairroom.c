#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
int load_doors(void);

void create_object(void)
{
    set_short("A cramped, dark room");
    set_long("A cramped, dark room. There is a holder for a torch one of " +
             "the walls, but there is no torch in it. There is dust and " +
             "spiderwebs everywhere and it looks like noone has been here " +
             "in a long time. Narrow, spiralling stairs go up into the " +
             "darkness above.\n");
    set_new_light(0);
    add_property("indoors");

    add_item("room","A cramped stairroom");
    add_item("holder","A rusty torch holder that doesn't look as if it's " +
             "been used lately");
    add_item("wall|walls","Smooth, black stone");
    add_item("dust","A thick layer of dust. It looks as if noone's been " +
             "here in a very long time");
    add_item("webs|web|spiderweb|spiderwebs","Huge spiderwebs. You would " +
             "not want to meet the spiders responsible for those webs");
    add_item("stairs|staircase","A spiraling staircase going up into the " +
             "darkness above");
    add_item("darkness","You feel very uneasy about climbing the stairs " +
             "up into the darkness");

    add_exit(ROOM + "lev4_stairroom","up");

    load_doors();
    reset(0);
}

int load_doors(void)
{
    string dir1 = "east";
    string dir2 = "west";
    string next_room = ROOM + "lev3_yzwulsroom";
    string desc = "oak door";
    int closed = 1;
    int locked = 1;
    string key_id = "_oakdale_yzwul_key_";
    string long_desc = "A very thick oak door.\n";
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
