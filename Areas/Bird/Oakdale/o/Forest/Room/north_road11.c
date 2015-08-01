#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A side road through the forest north of the village");
    set_long("You are on a small road through the forest. The forest is " +
             "closing in to the road again, the trees casting dark " +
             "shadows over you. The forest around you is dark, and " +
             "nothing can be heard except the wind in the trees. To the " +
             "east there seems to be an old building.\n");
    set_new_light(3);
        
    add_item("forest","The forest is dark and silent around you");
    add_item("tree|trees","Huge, old oak trees");
    add_item("light","Very little, only a few beams get through the " +
             "branches. As a result, there is a very moody atmosphere here");
    add_item("shadow|shadows","Dark, eerie shadows cast by the trees around " +
             "you");
    add_item("building","The building looks to be in a state of decay. It " +
             "is almost completely hidden by trees, bushes and weeds");
    add_item("bush|bushes|weed|weeds","Things clinging to the walls of the " +
             "building to the east. You'd have to go there to get a good " +
             "look at them");           
    add_item("$|$sound|$soft sound|$wind","The only thing you hear is " +
             "the soft sound of the wind in the trees");           

    add_exit(ROOM + "north_road9","southwest");
    add_exit(ROOM + "shrine_outside","east");
}
