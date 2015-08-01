#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);

void create_object(void)
{
    set_short("A barely noticable path through the forest");
    set_long("You are on a small path going west. To the east is the road " +
             "through the forest. The forest is very dense here, and you " +
             "can just barely make out the path. The vegetation by the " +
             "side of the path is very thick, and you don't think it would " +
             "be a good idea to leave it. The path leads further into the " +
             "dark forest, and you have no idea what may lie at its end.\n");
    set_new_light(3);

    add_item("path","A barely noticable path. Apparently seldom used");
    add_item("forest","A forest of oak trees. It looks dark and uninviting");
    add_item("vegetation","Very thick. Should you leave the path, you " +
             "doubt you'd find your way back again");
    add_item("road","The road through the forst is to the east");
    add_item("tree|trees|oak|oaks","Tall, majestic oaks");

    add_exit(ROOM + "north_road_path","east");
    add_exit(ROOM + "cottage_path2","west");
}

void init(void)
{
    SYS_ADMIN->visit(287);
}
