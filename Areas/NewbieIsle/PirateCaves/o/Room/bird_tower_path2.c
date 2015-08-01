#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_SOUND;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("Path through the forest (w/e)");
    set_long("A path going west and east through a forest. Some distance " +
             "to the west the path seems to end at a cliffwall and east " +
             "of here is a clearing where some sort of structure stands. " +
             "You are surrounded by trees and bushes and the grass by the " +
             "side of the path is long and thick. You can hear the sounds " +
             "of waves breaking against a cliff from the north.\n");
    set_new_light(5);

    add_item("path","A path going west and east through a forest");
    add_item("cliff|cliffwall","A steep cliffwall some distance to the west");
    add_item("clearing","It's east of here and there seems to be some sort " +
             "of structure built in it");
    add_item("structure","It looks like a tower");
    add_item("tower","You'll have to go closer to get a better look at it");
    add_item("tree|trees|bush|bushes|forest|wood|woods","You are surrounded " +
             "by the trees and bushes of this forest");
    add_item("grass","It grows long and thick beside the path");
    add_item("wave|waves","You can't see them, but you can hear them");
    add_item("$|$wave|$waves","You hear the sound of waves from the north");

    add_exit(PCROOM + "bird_tower_path1","west");
    add_exit(PCROOM + "bird_tower_clearing","east");

    add_sounds(30,80, ({ "You hear the sounds of waves breaking upon " +
                         "rocks from north.\n" }));

    reset(0);
}

void reset(int arg)
{
    add_monster(PCMONSTER + "picnic_pirate",2);
}