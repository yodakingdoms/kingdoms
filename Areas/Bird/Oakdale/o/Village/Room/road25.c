#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);

void create_object(void)
{
    set_short("A road through the village");
    set_long("You are on a road in the village. The road leads north and " +
             "south. To the west is a house and to the east is a " +
             "boathouse. You can hear the sound of the river from the " +
             "south east. The castle looms over the village to the " +
             "northeast.\n");
    set_new_light(5);

    add_item("houses","Stone houses with wooden roofs and stone chimneys");
    add_item("house","A stone house with wooden roof and stone chimney");
    add_item("chimneys","They are made of stone");
    add_item("chimney","A nice looking stone chimney");
    add_item("castle","You shiver as you glance at the castle");
    add_item("$|$river","You can hear the river in the distance to the " +
             "southeast");

    add_exit(ROOM + "road24","north");
    add_exit(ROOM + "road26","south");

    (ROOM + "house10")->load_doors();
    reset(0);
}
