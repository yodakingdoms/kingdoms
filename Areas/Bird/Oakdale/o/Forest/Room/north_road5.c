#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A road through the forest north of the village");
    set_long("You are on a road leading north and south through the " +
             "forest. The huge oak trees stand close to the road, their " +
             "branches reaching out over it, almost creating a ceiling over " +
             "your head. Only very little sunlight filters down through " +
             "the branches, so it is rather shadowy here. The road " +
             "continues north and south.\n");
    set_new_light(3);
        
    add_item("forest","A dark, silent forest of oak trees");
    add_item("tree|trees","Huge, old oak trees");
    add_item("branch|branches","The branches of the trees seem thick and " +
             "strong");
    add_item("ceiling","The branches ALMOST create a ceiling, so there's " +
             "no ceiling here");
    add_item("light","Very little, only a few beams get through the " +
             "branches. As a result, there is a very moody atmosphere here");
    add_item("$|$sound|$soft sound|$wind","The only thing you hear is " +
             "the soft sound of the wind in the trees");

    add_exit(ROOM + "north_road4","south");
    add_exit(ROOM + "north_road_path","north");    
}
