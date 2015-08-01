#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_block(string str);

void create_object(void)
{
    set_short("A cold, damp dungeon room");
    set_long("A cold, damp dungeon room. The rough stone walls of the room " +
             "are black, and water is seeping through them, slowly " +
             "trickling down to the floor, forming small puddles. There " +
             "is a wooden table here, with a small lamp on it. Two wooden " +
             "stools stand by the table. Some stairs go up to the floor " +
             "above, and there's an archway in the west wall.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("room","A cold, damp guardroom in the dungeon");
    add_item("wall|walls","Rough, black stone");
    add_item("water","It is gathering in small puddles on the floor");
    add_item("puddle|puddles","Small puddles of black, cold water");
    add_item("floor","Black, uneven stone");
    add_item("table","A wooden table with a small oil lamp on it");
    add_item("lamp","A small oil lamp, desperately struggling to stay lit " +
             "in the damp air");
    add_item("stool|stools","Two small wooden stools");
    add_item("stairs","The stairs go up to another floor");

    add_exit(ROOM + "dung_guardroom2","up");
    add_exit(ROOM + "dung_torture","west");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_dung_keeper",3);
    foreach(object ob: all_inventory())
    {
        if(ob->id("darkling")) ob->set_aggressive(1);
    }
}

void init(void)
{
    add_multi_action("do_block","w|west");
}

int do_block(string str)
{
    if(present("darkling",TO))
    {
        W("A darkling steps out in front of you and stops you from going " +
          "that way!\n");
        S("A darkling stops " + TP->QN + " from going west");
        return 1;
    }
    return 0;
}
