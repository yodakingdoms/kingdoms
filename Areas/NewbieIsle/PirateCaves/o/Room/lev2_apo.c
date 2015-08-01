#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;
inherit MOD_APO;

void create_object(void);
void reset(int arg);
void init(void);

void create_object(void)
{
    ::create_object();
    set_short("An apothec (e)");
    set_long("A small room with shelves around the walls. The shelves " +
             "are full of bottles and jars and herbs of different kinds " +
             "hang from the ceiling. There's a wooden counter by the wall " +
             "and a sign with a menu on it hangs on the wall behind it. " +
             "There are some barrels in one corner and a few sacks in " +
             "another. This seems to be an apothek.\n");

    add_item("room","It seems to be an apothek");
    add_item("apothek","That's what this room seems to be");
    add_item("shelf|shelves","There are many jars and bottles on them");
    add_item("jar|jars|bottle|bottles","They contain many strange things");
    add_item("thing|things|strange thing|strange things","You have no " +
             "idea what they might be");
    add_item("herb|herbs","Probably herbs with some kind of healing " +
             "properties");
    add_item("counter|wooden counter","A wooden counter next to a wall");
    add_item("sign|@sign","There's a menu on it, which you might try to " +
             "read");
    add_item("menu","#reading");
    add_item("corner","There are some barrels in one and some sacks in " +
             "another");
    add_item("barrel|barrels|sack|sacks","You can't see what they contain");

    add_exit(PCROOM + "lev2_corridor3","west");

    medicine = ({ "rumpotion","alepotion" });
    bloodclotters = ({ "sailclot" });
    criticals = ({ "saltwater" });
    ware = medicine + bloodclotters + criticals;
    ware_path = PCOBJECT;
    max_strength_apothek = 3000;
    max_strength_player = 500;
    waitername = "Chubby";

    reset(0);
}

void reset(int arg)
{
    add_monster(PCMONSTER + "apothekary",1);
    apothek_module_reset(arg);
}

void init(void)
{
    apothek_module_init();
}
