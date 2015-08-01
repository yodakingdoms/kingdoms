#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("Clearing in the forest (w/nd)");
    set_long("A clearing in the forest, surrounded by trees and bushes. " +
             "In the center of the clearing stands a round tower that seems " +
             "to be in a state of disrepair. The door lies on the ground " +
             "outside of the tower and the walls are cracked and worn. The " +
             "glass in the window on the bottom floor is broken and the " +
             "grass in the clearing is long and unkept. A path goes west " +
             "into the forest, and to the north the ground slopes down to " +
             "a sandy shore.\n");
    set_new_light(5);

    add_item("clearing","You are standing in it. You feel peaceful here");
    add_item("forest","The forest surrounds the clearing");
    add_item("trees|tree|bush|bushes","The trees and bushes surround the " +
             "clearing");
    add_item("tower|round tower","The tower seems to be abandoned. It is " +
             "made of stone, but the walls have cracked, the window is " +
             "broken and the door lies on the ground");
    add_item("stone|stones","The tower is made of several of them");
    add_item("wall|walls|stone wall|stone walls","The stone walls of the " +
             "tower are worn and cracked");
    add_item("crack|cracks","Cracks in the stone walls of the tower");
    add_item("door","The door has been broken and lies on the ground in " +
             "front of the tower");
    add_item("glass","There's none of it in the window anymore, it's been " +
             "broken");
    add_item("window","The glass in the window has been broken");
    add_item("floor|botton floor","The bottom floor of the tower");
    add_item("ground","Long grass grows on the ground in the clearing");
    add_item("grass|long grass","The grass in the clearing is long and " +
             "unkept. It's obvious noone's been here to maintain it and " +
             "keep it short in quite a while");
    add_item("path","It continues into the forest to the west");
    add_item("shore|sandy shore","There seems to be a shore down the slope " +
             "to the north");
    add_item("slope","The ground slopes down to the north");

    add_exit(PCROOM + "bird_tower_path2","west");
    add_exit(PCROOM + "bird_tower","enter");
    add_exit(PCROOM + "cove_shore","northdown");
}
