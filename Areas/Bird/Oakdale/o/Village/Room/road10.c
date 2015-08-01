#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A road through the village");
    set_long("A road through the village leading north and south. To the " +
             "south is a crossroad where a huge oak stands. To the west " +
             "is a shop that can't be entered from here and to the east " +
             "is the Oakdale tavern. The tavern has a window in this " +
             "direction. The castle on the cliff looms over the village " +
             "to the east.\n");
    set_new_light(5);

    add_item("crossroad","This road crosses the main road through the " +
             "village there");
    add_item("oak","A huge oak, casting it's shadow over the crossroad");
    add_item("tavern","There is no door here, just a window");
    add_item("window","You look through the window but you don't see very " +
             "much. The air inside is filled with smoke, and the main room " +
             "is dark. There are a few people inside, but to get a better " +
             "look at the tavern you would have to enter it");
    add_item("castle","There is something eerie about that castle... You " +
             "feel uncomfortable just by looking at it");
    add_item("cliff","A sheer cliff. It looks impossible to climb");

    add_exit(ROOM + "crossroad","south");
    add_exit(ROOM + "road11","north");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "airon",1);
    add_monster(MONSTER + "nirin",1);
    add_monster(MONSTER + "tyron",1);
}
