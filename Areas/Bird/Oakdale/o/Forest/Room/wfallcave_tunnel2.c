#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A dark, cold tunnel");
    set_long("A dark, narrow tunnel. The air is damp and water is dripping " +
             "from the ceiling, forming small puddles on the rough stone " + 
             "floor. The passage opens up to the north, and to the south " +
             "you think there may be another, smaller cave. You feel the " +
             "weight of the hill above pressing down on you.\n");
    set_new_light(0);
    add_property("indoors");
        
    add_item("tunnel","The tunnel slopes slightly downwards to the south");
    add_item("water","Water dripping from the roof into small puddles on " + 
             "the floor");
    add_item("ceiling","A rough stone ceiling. Water is dripping from it");
    add_item("floor","A rough stone floor");
    add_item("puddle|puddles","Small puddles on the rough stone floor");
    add_item("cave","You can't really see it from here");
    
    add_sounds(05,80,({"Drip, drop...\n"}));    
    
    add_exit(ROOM + "wfallcave_mainroom","north");
    add_exit(ROOM + "wfallcave_empty","south");    
}
