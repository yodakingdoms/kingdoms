#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A road through the forest, climbing the castle rock");
    set_long("You are on a road climbing the castle rock. The road goes " +
             "down to the south, and turns up to the northwest, where it " +
             "looks like you will come out of the forest. The trees are " +
             "perfectly still, and no leaf rustling or branch creaking " +
             "can be heard. The road is left in shadow as the silent " +
             "branches reach out over you. No sounds can be heard in the " +
             "forest around you.\n");
    set_new_light(3);

    add_item("road","The road goes down to the south and rises to the " +
             "northwest. If you go northwest, you'll come out of the forest");
    add_item("tree|trees","Old oak trees spreading their branches out " +
             "across the road");
    add_item("forest","A forest of oak trees. It is dark and silent");
    add_item("branch|branches","The branches of the trees reach out over " +
             "the road, leaving it in shadow");
    add_item("shadow|shadows","Dark, unsettling shadows");
    add_item("rock","The high cliff where the castle stands");
    add_item("cliff|castle","You can't see it now, but you have a feeling " +
             "that the road you are on will take you there eventually");

    add_exit(ROOM + "front_of_castle","northwest");
    add_exit(ROOM + "castle_road5","southdown");

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
