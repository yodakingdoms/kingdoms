#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A road through the forest, climbing the side of the valley");
    set_long("You are on a road through the forest. The road is going " +
             "north and rising sharply as it ascends the castle rock. The " +
             "leaves on the branches of the old oaks reaching out over the " +
             "road rustle quietly, as the wind moves the softly. Still no " +
             "other sound can be heard. The dark forest around you almost " +
             "seems deserted by all living creatures.\n");
    set_new_light(3);

    add_item("road","The road is rising sharply now, taking you up the side " +
             "of the valley towards the castle rock");
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

    add_exit(ROOM + "castle_road5","northup");
    add_exit(ROOM + "castle_road3","southwest");

    reset(0);
}

void reset(int arg)
{
    add_monster(CASTLE + "Monster/darkling_sentry",1);
    foreach(object ob: all_inventory())
    {
        if(ob->id("darkling")) ob->set_walking();
    }
}
