#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A road throught the forest north of the village");
    set_long("You are on a road through the forest. Silence surrounds you " +
             "as you walk deeper into the woods, just the sound of the " +
             "wind stirring the leafs of the trees can be heard. The road " +
             "is left in shadow as the branches of the old oak trees reach " +
             "out over the road. The forest is dense and dark around you " +
             "and no movement can be seen in there. There is a pleasant " +
             "atmosphere here in these woods.\n"); 
    set_new_light(3);
        
    add_item("forest|woods","The forest is dense, dark and silent around " +
             "you. The trees form an arch over the road, leaving it in " +
             "shadow");
    add_item("shadow","The trees are overshadowing the road");
    add_item("arch","The branches of the trees reach out over the road, " +
             "forming an arch over it");
    add_item("tree|trees|oak|oaks","Strong oak trees");
    add_item("road","It continues into the forest");
    add_item("$|$sound|$soft sound|$wind","The only thing you hear is " +
             "the soft sound of the wind in the trees");

    add_exit(ROOM + "north_road2","southeast");
    add_exit(ROOM + "north_road4","northwest");    
}
