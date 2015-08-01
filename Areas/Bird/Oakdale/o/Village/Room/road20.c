#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);

void create_object(void)
{
    set_short("A side road in the village");
    set_long("A smaller side road going north from the square of the " +
             "village. There is a house to the east and to the west is " +
             "the Oakdale post office. The road continues north. The " +
             "castle looms over the village to the east.\n");
    set_new_light(5);

    add_item("house","A nice little stone house with a green roof and a " +
             "stone chimney");
    add_item("chimney","It is made of stone. There is no smoke coming " +
             "from it");
    add_item("castle","You get an uneasy feeling looking at that castle");

    add_exit(ROOM + "square","south");
    add_exit(ROOM + "post","west");
    add_exit(ROOM + "road21","north");

    (ROOM + "house2")->load_doors();
    reset(0);
}
