#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("The main road through the village");
    set_long("You are on the main road through the village. To the east " +
             "is a crossroad where a huge oak stands. To the north is a " +
             "shop and to the south is a bank. The castle towers above " +
             "you.\n");
    set_new_light(5);

    add_exit(ROOM + "road4","west");
    add_exit(ROOM + "crossroad","east");
    add_exit(ROOM + "shop","north");
    add_exit(ROOM + "bank","south");

    add_item("oak","It is a HUGE oak");
    add_item("castle","You try to examine the castle more closely, but you " +
             "can't bear the sight of it for more than a few seconds");
}
