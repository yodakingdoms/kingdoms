#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A wider corridor");
    set_long("A wide corridor going east and west. Another, narrower " +
             "corridor continues to the north. The corridor is dimly lit " +
             "by a flickering torch on the wall. You notice that the " +
             "corridor is lined with doors on the south wall both to the " +
             "east and the west.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("corridor","A wide corridor with black stone walls, floor " +
             "and ceiling");
    add_item("wall|walls|floor|ceiling","Smooth, black stone");
    add_item("torch","A single flickering torch");
    add_item("doors","A few of them, both further east and west");

    add_exit(ROOM + "lev1_corridor3","north");
    add_exit(ROOM + "lev1_corridor5","east");
    add_exit(ROOM + "lev1_corridor6","west");

    (ROOM + "lev1_room1")->load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_officer",1)->set_walking();
    ::reset(arg);
}
