#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

object *thieves;

void create_object(void);
void reset(int arg);
void init(void);
int do_nick(string str);
int load_doors(void);

void create_object(void)
{
    set_short("A house in the village");
    set_long("You are in a small house in the village. There is a small " +
             "window in the south wall and a fireplace by the west wall. " +
             "There are two beds, a table, two chairs and a rug here.\n");
    set_new_light(10);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("window","A small window through which you can see the forest");
    add_item("forest","A forest of oak trees. It is thick an impenetrable");
    add_item("fireplace","A stone fireplace set in the west wall. There is " +
             "a log in it");
    add_item("log","A log of the type you use to make fires in fireplaces");
    add_item("beds","Two neatly made beds");
    add_item("bed","A neatly made bed");
    add_item("table","An oak table. There is a plate with cookies on it");
    add_item("cookies","They look very tasty. Maybe you could nick one?");
    add_item("wall|south wall","The south wall has a window in it");
    add_item("chair|chairs","Two chairs, precisely placed by the table");
    add_item("rug","A nice, soft dark green rug");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "dylon");
    thieves = ({});
    ::reset(arg);
}

void init(void)
{
    add_action("do_nick","nick");
    ::init();
}

int do_nick(string str)
{
    if(str == "cookie")
    {
        if(!is_in(TP,thieves))
        {
            W("Mmmmmmmmm! A warm, tingling feeling fills your stomach. This " +
              "was truly a delicious cookie.\n");
            S(TP->QN + " steals a cookie and looks very pleased eating it.\n");
            thieves += ({ TP });
            return 1;
        }
        else
        {
            W("You've already nicked a cookie recently and while the cookie " +
              "was excellent, you're not in the mood for more right now.\n");
            return 1;
        }
    }
    return notify_fail("Nick what?\n");
}

int load_doors(void)
{
    string dir1 = "north";
    string dir2 = "south";
    string next_room = ROOM + "road19";
    string desc = "door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A wooden door.\n";
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
