#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A side road through the village");
    set_long("A small side road leading west to what appears to be some " +
             "sort of yard. The local adventurer's guild is to the north, " +
             "but it can't be entered from here. To the south the forest " +
             "is closing in on the village. The castle looms high over the " +
             "village to the east.\n");
    set_new_light(5);

    add_item("yard","A few houses are built around it, and there are " +
             "cobble stones on the ground");
    add_item("forest","A dense forest of oaks. The vegetation is lush and " +
             "the trees look healthy, but you see no animals in there");
    add_item("castle","It looms over the village to the northeast");
    add_item("village","A peaceful little village in a valley in the forest");
    add_item("valley","A forrested valley where a tranquil village lies");
    add_item("forest","The forest in the valley seems to be very old");

    add_exit(ROOM + "road15","east");
    add_exit(ROOM + "road19","west");
}
