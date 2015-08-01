#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A road through the village");
    set_long("A road through the village going north and south. To the " +
             "west is a house you can't enter from here and to the east " +
             "is the Oakdale inn. A sign is hanging above the door to the " +
             "inn. To the north is a crossroad where a huge oak stands. " +
             "The castle looms over the village to the east.\n");
    set_new_light(5);

    add_item("inn","Enter it if you want to check it out");
    add_item("sign|@sign","'The Oakdale Inn'");
    add_item("crossroad","This road crosses the main road through the " +
             "village there");
    add_item("oak","A huge oak. One of the tallest oaks you have ever seen");
    add_item("castle","For some strange reason you just don't feel like " +
             "looking at the castle for more than a few seconds. You " +
             "quickly avert your eyes");

    add_exit(ROOM + "crossroad","north");
    add_exit(ROOM + "road14","south");
    add_exit(ROOM + "inn","east");
}
