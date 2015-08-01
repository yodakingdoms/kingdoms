#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
int load_doors(void);

void create_object(void)
{
    set_short("A luxurious dining hall");
    set_long("This must be the main dining hall of the castle. A huge " +
             "wooden table stands on a thick rug in the middle of the room. " +
             "Several comfortable looking chairs surround the table, and " +
             "in the north wall is a big fireplace. In the west wall are " +
             "two large windows with dark blue curtains. A big chandelier " +
             "hangs from the ceiling over the table and the walls are " +
             "covered with murals.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("room|hall","A quite luxurious dining hall");
    add_item("table","A finely crafted oak table. It is covered by a black " +
             "velvet tablecloth and there are two silver chandeliers with " +
             "black wax candles on it");
    add_item("tablecloth","A beautiful black velvet tablecloth");
    add_item("chandelier|chandeliers","Two small silver ones are on the " +
             "table, and a huge, crystal one is hanging from the ceiling");
    add_item("candle|candles","Black wax candles");
    add_item("rug","A thick, beautiful rug");
    add_item("chair|chairs","There are several nicely crafted oak chairs " +
             "around the table");
    add_item("fireplace","A huge stone fireplace. There's no fire lit in " +
             "it at the moment");
    add_item("wall|walls","Smooth, black, stone walls covered by murals");
    add_item("window|windows","Two big windows letting in plenty of light");
    add_item("curtain|curtains","Dark blue velvet curtains");
    add_item("ceiling","The ceiling is smooth, black stone");
    add_item("mural|murals","Large, beautifully wowen murals depicting a " +
             "man dressed in black robes. A huge shadow is hanging over him");
    add_item("man","A man dressed in black robes. His face cannot be seen");
    add_item("shadow","A huge shadow that has the shape of a dragon");
    add_item("shape|dragon","The shadow has the shape of a dragon");

    add_exit(ROOM + "lev2_corridor1","east");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_commander",1);
    ::reset(arg);
}

int load_doors(void)
{
    string dir1 = "south";
    string dir2 = "north";
    string next_room = ROOM + "lev2_kitchen";
    string desc = "oak door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A strong oak door.\n";
    string entercmd1 = "south";
    string entercmd2 = "north";
    int solidity = 10;
    int complex = 0;
    int hidden1 = 0;
    int hidden2 = 0;

    add_door(dir1, dir2, next_room, desc,  closed, locked, key_id,
             long_desc, entercmd1, entercmd2, solidity, complex,
             hidden1, hidden2 );
    return 1;
}
