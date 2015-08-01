#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
int load_doors(void);

void create_object(void)
{
    set_short("A cramped alcove");
    set_long("A cramped alcove with rough stone walls. There is a " +
             "torchholder on one of the walls, but there is no torch in " +
             "it. The only thing of interest here is the ladder going up " +
             "to the trapdoor in the ceiling. There's a doorway in the " +
             "south wall.\n");
    set_new_light(0);
    add_property("indoors");

    add_item("alcove","A cold, cramped alcove");
    add_item("wall|walls","Rough, black stone");
    add_item("torchholder","A rusty torchholder with no torch in it");
    add_item("ladder","It would allow you to go up if the trapdoor was open");
    add_item("ceiling","There is a trapdoor in it");
    add_item("doorway","Another room lies beyond it");
    add_item("room","Go there if you're curious");

    add_exit(ROOM + "dung_bottom2","south");

    load_doors();
    reset(0);
}

int load_doors(void)
{
    string dir1 = "up";
    string dir2 = "down";
    string next_room = ROOM + "dung_clericroom";
    string desc = "trapdoor";
    int closed = 1;
    int locked = 1;
    string key_id = "_oakdale_cleric_key_";
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
