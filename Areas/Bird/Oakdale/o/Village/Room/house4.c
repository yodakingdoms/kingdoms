#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
void init(void);
int do_sit(string str);
int load_doors(void);

void create_object(void)
{
    set_short("A house in the village");
    set_long("A small house in the village. There is a window in the north " +
             "wall, a table and two beds here. Two chairs are placed " +
             "around the table.\n");
    set_new_light(1);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("window","A small window. You see the forest outside");
    add_item("forest","It is a dense forest of oak trees");
    add_item("fireplace","A stone fireplace, very clean and neat");
    add_item("walls|wall","Made of stone");
    add_item("bed","A double bed with blue sheets, very neatly made");
    add_item("sheet","They have a nice blue colour");
    add_item("table","An oak table with blue tablecloth");
    add_item("chair|chairs","Two nice chairs with blue pillows on them");
    add_item("pillow|pillows","Soft cushions with a nice blue colour");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "kardan",1);
    add_monster(MONSTER + "tamina",1);
    ::reset(arg);
}

void init(void)
{
    add_action("do_sit","sit");
    ::init();
}

int do_sit(string str)
{
    if(str == "in chair")
    {
        W("Ooh, a nice tingling sensation fills your bottom. This was " +
          "truly a comfortable chair.\n");
        S(TP->QN + " sits down on one of the chairs.\n");
        return 1;
    }
    return notify_fail("Sit where?\n");
}

int load_doors(void)
{
    string dir1 = "east";
    string dir2 = "west";
    string next_room = ROOM + "road11";
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
