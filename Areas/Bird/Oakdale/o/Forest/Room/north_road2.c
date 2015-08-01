#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A road through the forest");  
    set_long("A road through the forest north of the village. The branches " +
             "of the old oak trees leave the road in shadow as they reach " +
             "out over your head, their leaves rustling softly in the " +
             "wind. The forest around you is dense and dark and not much " +
             "can be seen in there. You see no sign of movement in there " +
             "and the only thing that can be heard is still the soft " +
             "sound of the wind in the trees. The road turns to the " +
             "northwest here.\n");
    set_new_light(3);
        
    add_item("branches|branch","They hang out over the road, creating an " +
             "arch, under which the road runs");
    add_item("leaf|leaves","Big, green oak leaves, moving slowly in the " +
             "soft wind");
    add_item("forest","The forest is dense, dark and silent around you. " +
             "The trees form an arch over the road, leaving it in shadow");
    add_item("shadow","The trees are overshadowing the road");
    add_item("arch","The branches of the trees reach out over the road, " +
             "forming an arch over it\n");
    add_item("tree|trees|oak|oaks","Strong oak trees");
    add_item("road","It continues into the forest");    
    add_item("$|$sound|$soft sound|$wind","The only thing you hear is " +
             "the soft sound of the wind in the trees");
  
    add_exit(ROOM + "north_road1","south");
    add_exit(ROOM + "north_road3","northwest");
}
