#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A small guardroom");
    set_long("This is a small room lit by a flickering torch on one of the " +
             "black stone walls. There is a small wooden table with some " +
             "things on it here, and around the table are several wooden " +
             "stools. There is an archway in the east wall.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("room","A small room that looks like a guardroom");
    add_item("torch","A single flickering torch");
    add_item("wall|walls","Smooth, black stone");
    add_item("things","A few emtpy plates and mugs");
    add_item("table","A small table with a few empty plates and mugs on it");
    add_item("mug|mugs","There are a few empty mugs on the table");
    add_item("plate|plates","There are a few empty plates on the table");
    add_item("stool|stools","There are a few uncomfortable looking wooden " +
             "stools around the table");
    add_item("archway","It leads to a bigger room to the east");

    add_exit(ROOM + "lev2_tower","east");

    (ROOM + "lev2_corridor2")->load_doors();

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_soldier",3);
    foreach(object ob: all_inventory())
    {
        if(ob->id("soldier")) ob->set_aggressive(1);
    }
    ::reset(arg);
}
