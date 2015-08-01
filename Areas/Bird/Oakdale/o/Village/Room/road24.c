#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);

void create_object(void)
{
    set_short("A road through the village");
    set_long("You are on a road through the village. The road leads east " +
             "and south from here and there are houses to the north and " +
             "west. You can hear the sound of the river from the " +
             "southeast. The castle looms over the village to the " +
             "northeast.\n");
    set_new_light(5);

    add_item("houses","Stone houses with wooden roofs and stone chimneys");
    add_item("chimneys","They are made of stone");
    add_item("castle","You shiver as you glance at the castle");
    add_item("house","A stone house with a wooden roof and a stone chimney");
    add_item("chimney","A nice looking stone chimney");
    add_item("$|$river","You can hear the river in the distance to the " +
             "southeast");

    add_exit(ROOM + "road23","east");
    add_exit(ROOM + "road25","south");
}
