#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A road through the village");
    set_long("You are on the main road through the village. To the west " +
             "is a crossroad where a huge oak stands. Further to the east " +
             "there seems to be a square. The house to the south has no " +
             "entrance from this side, but the door to the north house is " +
             "wide open. Talking voices can be heard from within, and on " +
             "the wall is a sign. The castle looms above the village.\n");
    set_new_light(5);

    add_item("oak","It's really huge");
    add_item("square","There does not seem to be very much activity");
    add_item("sign|@sign","It says:'Oakdale tavern'");
    add_item("castle","There is something disturbing about the castle. You " +
             "can't look at it for more than a few seconds. You are very " +
             "aware of the fact that every step you take brings you " +
             "closer to it..");
    add_item("$|$voices","You mostly hear voices talking in a serious " +
             "manner in the tavern. Noone seems to be laughing");

    add_exit(ROOM + "crossroad","west");
    add_exit(ROOM + "tavern","north");
    add_exit(ROOM + "road7","east");
}
