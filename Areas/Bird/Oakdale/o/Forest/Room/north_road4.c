#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A road throught the forest north of the village");
    set_long("The road through the forest turns north here. The forest " +
             "around you is as dense as ever, and darkness prevails in " +
             "there. The road too is left in shadow as the branches of " +
             "the old oak trees reach out over it. Nothing moving can be " +
             "seen in the forest, and the only thing you hear is the " +
             "wind, slowly shaking the leaves and branches of the trees.\n");
    set_new_light(3);
        
    add_item("leaf|leaves","Big green oak leafs, moving slowly in the " +
             "soft wind");
    add_item("forest","The forest is dense, dark and silent around you. " +
             "The trees form an arch over the road, leaving it in shadow");
    add_item("shadow","The trees are overshadowing the road");
    add_item("arch","The branches of the trees reach out over the road, " +
             "forming an arch over it");
    add_item("darkness","The forest around you is dark and uninviting");
    add_item("tree|trees|oak|oaks","Strong oak trees");
    add_item("road","It continues into the forest");
    add_item("$|$sound|$soft sound|$wind","The only thing you hear is " +
             "the soft sound of the wind in the trees");
    
    add_exit(ROOM + "north_road3","southeast");
    add_exit(ROOM + "north_road5","north");    
}
