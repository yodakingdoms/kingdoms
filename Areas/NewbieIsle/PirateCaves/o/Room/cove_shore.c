#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A sandy beach");
    set_long("A sheltered sandy beach on the south side of a narrow cove " +
             "stretching east into the island. Steep cliffs tower high " +
             "above you on the north side of the cove. The waves from the " +
             "ocean to the west crash into the cove and break upon the " +
             "rocks and cliffs on the sides of the cove. The ground slopes " +
             "up the south and trees and bushes grow there. You see a " +
             "clearing where some sort of structure stands in that " +
             "direction.\n");
    set_new_light(5);


    add_item("beach|sandy beach|sheltered sandy beach","A sheltered sandy " +
             "beach on the south side of a narrow cove");
    add_item("cove|narrow cove","It stretches far into the island to the " +
             "east");
    add_item("island","The island you are on");
    add_item("cliff|cliffs|steep cliff|steep cliffs","They tower high above " +
             "you to the north");
    add_item("water","The waves crash into the rocks on the side of the " +
             "cove");
    add_item("wave|waves","They crash into the rocks on the sides of the " +
             "cove");
    add_item("ocean","You can make it out some distance to the west of here");
    add_item("rock|rocks","The rocks on the sides of the cove");
    add_item("ground","It slopes up to the south, grass grows on it");
    add_item("grass|long grass","The grass on the ground to the sound grows " +
             "long");
    add_item("tree|trees|bush|bushes","When this many trees and bushes grow " +
             "in roughly the same place, it's called a forest");
    add_item("forest","A suitable word to describe the trees and bushes");
    add_item("clearing","The clearing is up there to the south, a tower " +
             "seems to stand there");
    add_item("structure|tower|round tower","A round tower stands in the " +
             "clearing to the south");

    add_exit(PCROOM + "bird_tower_clearing","southup");

    reset(0);
}

void reset(int arg)
{
    add_monster(PCMONSTER + "fishing_pirate",1);
}
