#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A road through the forest, going up the side of the valley");
    set_long("You are on a road through the forest. The road is sloping " +
             "gently upwards and turning to the northeast. The trees stand " +
             "close to the road, spreading their branches out over you. " +
             "The only thing that can be heard is the wind in the trees, " +
             "quite strange since you are this close to a big castle...\n");
    set_new_light(3);

    add_item("road","The road is turning northeast, talking you higher up " +
             "the side of the valley");
    add_item("tree|trees","Old oak trees spreading their branches out " +
             "across the road");
    add_item("forest","A forest of oak trees. It is dark and silent");
    add_item("branch|branches","The branches of the trees reach out over " +
             "the road, leaving it in shadow");
    add_item("castle","The castle should bu just around the next turn. It " +
             "is actually not a very pleasant thought..");
    add_item("shadow|shadows","Dark, unsettling shadows");
    add_item("$|$sounds|$castle|$wind","You hear none of the sounds you " +
             "usually hear in the vicinity of a castle of the size of the " +
             "one in this valley. You only hear the wind, and a small bird " +
             "somewhere in the forest");
    add_item("$bird","A small bird is singing somewhere in the forest. That " +
             "only seems to emphasize the silence elsewhere in the woods");

    add_exit(ROOM + "castle_road2","west");
    add_exit(ROOM + "castle_road4","northeast");
}
