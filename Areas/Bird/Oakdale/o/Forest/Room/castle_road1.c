#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("The east bank of the river");
    set_long("The east bank of the river. The road continues into the " +
             "forest to the east. To the west is the stone bridge crossing " +
             "the river and beyond that lies the village. The river flows " +
             "swiftly from the north to the south. To the east, the ground " +
             "is slowly beginning to slope upwards again, and to the north " +
             "you see the castle on it's cliff loom over the village.\n");
    set_new_light(5);

    add_item("river","The river flows swiftly from the north to the south. " +
             "It's not very wide, but it would be very hard to swim " +
             "across, since it is very wild");
    add_item("road","The road continues into the forest to the east");
    add_item("bridge","A sturdy stone bridge. It looks to have been made by " +
             "very skilled craftsmen");
    add_item("village","A small village of small stone houses");
    add_item("house|houses","All the houses are small stone houses");
    add_item("ground","It is beginning to slope upwards to the east, as you " +
             "are approaching the east side of the valley");
    add_item("side|valley","You are on the east side of the valley, and " +
             "the ground and the road is slowly beginning to slope upwards " +
             "again");
    add_item("castle","The castle doesn't look quite as threatening now " +
             "that you have left the village. It somehow seems like you've " +
             "escaped it's attention.");
    add_item("cliff","A sheer, black cliff, several hundred feet high. It " +
             "would be impossible to climb");

    add_exit(VILLAGE + "Room/bridge","west");
    add_exit(ROOM + "castle_road2","east");
}
