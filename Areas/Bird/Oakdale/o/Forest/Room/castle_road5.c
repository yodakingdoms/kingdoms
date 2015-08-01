#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A road through the forest, climbing the castle rock");
    set_long("You are on a road climbing the castle rock. The road goes up " +
             "to the north and down to the south. The trees are still " +
             "standing close to it, their branches reaching out over it, " +
             "leaving it in shadow. It is very quiet, even the wind seems " +
             "to have faded away now, and the silence here is nothing but " +
             "eerie. You see a bend the road to the north, turning west, " +
             "towards the castle.\n");
    set_new_light(3);

    add_item("road","The road is rising sharply now, taking you up the " +
             "side of the valley towards the castle rock");
    add_item("side|valley","You are on the east side of the valley");
    add_item("rock|cliff","The high cliff the castle is built upon");
    add_item("castle","You can't see it from here, but you have a feeling " +
             "this road will take you there");
    add_item("tree|trees","Old oak trees spreading their branches out " +
             "across the road");
    add_item("forest","A forest of oak trees. It is dark and silent");
    add_item("branch|branches","The branches of the trees reach out over " +
             "the road, leaving it in shadow");
    add_item("shadow|shadows","Dark, unsettling shadows");
    add_item("bend","The road turns west there... Probably heading for " +
             "the castle");

    add_exit(ROOM + "castle_road6","northup");
    add_exit(ROOM + "castle_road4","southdown");
}
