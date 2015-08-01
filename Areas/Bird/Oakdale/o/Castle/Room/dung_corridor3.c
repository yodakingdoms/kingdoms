#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A dungeon corridor");
    set_long("You are in a cold, damp dungeon corridor lit by a flickering " +
             "torch. Water is seeping through the rough stone walls, slowly " +
             "trickling down to the floor and gathering in small puddles. " +
             "The corridor turns here, and continues to the west and to the " +
             "south.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("corridor","A cold dungeon corridor with rough stone walls. It " +
             "turns here and goes west and south");
    add_item("torch","A torch struggling to stay lit in the cold, damp air");
    add_item("water","It is seeping through the walls and gathering in " +
             "small puddles as it trickles to the floor");
    add_item("walls|wall","Rough, black stone");
    add_item("puddle|puddles","Small puddles of dirty water");
    add_item("floor","Quite a smooth stone floor with a few puddles of " +
             "water on it");

    add_exit(ROOM + "dung_corridor2","west");
    add_exit(ROOM + "dung_corridor4","south");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_dung_keeper",1);
}
