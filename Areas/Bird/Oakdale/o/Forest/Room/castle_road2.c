#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A road through the forest");
    set_long("You have entered the forest again. The road continues to the " +
             "east and the road is slowly beginning to slope upwards again. " +
             "The forest is closing in to the road and the branches of the " +
             "trees are reaching out over the road. The castle is no longer " +
             "in view and you feel relieved to have escaped it's attention. " +
             "Some distance to the west is the bridge crossing the river.\n");
    set_new_light(3);

    add_item("forest","A forest of oak trees. Dark and silent around you");
    add_item("road","The road continues to the east and to the west");
    add_item("ground","The ground is beginning to slope upwards as you " +
             "approach the east side of the valley");
    add_item("side|valley","You are now on the east side of the valley");
    add_item("branch|branches","All the branches seem thick and healthy");
    add_item("trees|tree|oak|oaks","All the trees in this forest seem to " +
             "be tall, majestic oaks");
    add_item("bridge|river","It is some distance to the west");

    add_exit(ROOM + "castle_road1","west");
    add_exit(ROOM + "castle_road3","east");
}
