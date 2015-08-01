#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A road throught the forest north of the village");
    set_long("You have entered the forest. The trees stand close to the " +
             "road, their branches blocking out much of the light, leaving " +
             "the road in shadow. The forest around you is dense and dark " +
             "and you can only see a short distance in among the trees. You " +
             "can't see any animals, and the only thing you hear is the " +
             "soft wind in the trees. The castle is no longer in sight and " +
             "you feel relieved to have escaped it's attention. To the " +
             "south is the forest and to the north the road continues into " +
             "the forest.\n");
    set_new_light(3);
    
    add_item("forest","The forest is dense, dark and silent around you. The "+
           "trees form an arch over the road, leaving it in shadow");
    add_item("shadow","The trees are overshadowing the road");
    add_item("arch","The branches of the trees reach out over the road, forming"+
           "an arch over it\n");
    add_item("tree|trees|oak|oaks","Strong oak trees");
    add_item("road","It continues into the forest");
    add_item("village","It lies to the south");
    add_item("$|$sound|$soft sound|$wind","The only thing you hear is " +
             "the soft sound of the wind in the trees");

    add_exit(VILLAGE + "Room/road12","south");
    add_exit(ROOM + "north_road2","north");    
}
