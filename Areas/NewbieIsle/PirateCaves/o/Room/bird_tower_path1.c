#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_SOUND;

void create_object(void);

void create_object(void)
{
    set_short("Path through the forest (sd/e)");
    set_long("A path through a forest. To the west is a cliffwall with " +
             "a doorway, and you see some stairs going down into the cliff " +
             "there. You are surrounded by trees and bushes and the grass " +
             "by the side of the path is long and thick. The path " +
             "continues into the woods to the east. You can hear the sounds " +
             "of waves breaking against a cliff from the north.\n");
    set_new_light(5);

    add_item("path","A path going east through a forest");
    add_item("cliff|cliffwall","A steep cliffwall to the west");
    add_item("doorway","A doorway into the cliff. There are some stairs " +
             "going down in there");
    add_item("stair|stairs","They go down into the cliff");
    add_item("tree|trees|bush|bushes|forest|wood|woods","You are surrounded " +
             "by the trees and bushes of this forest");
    add_item("grass","It grows long and thick beside the path");
    add_item("$|$wave|$waves","You hear the sound of waves from the north");

    add_exit(PCROOM + "lev1_east_stairs","westdown");
    add_exit(PCROOM + "bird_tower_path2","east");

    add_sounds(30,80, ({ "You hear the sounds of waves breaking upon " +
                         "rocks from north.\n" }));
}
