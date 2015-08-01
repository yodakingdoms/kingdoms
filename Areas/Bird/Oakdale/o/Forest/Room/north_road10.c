#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A road through the forest north of the village");
    set_long("You are on a road through the forest. The forest is not " +
             "quite as dense here and you can actually see a few yards " +
             "in among the trees. A bit more light is reaching the road, " +
             "but it is still quite shadowy here. The undergrowth by the " +
             "side of the road is thick, and you can't see anything " +
             "moving in the silent forest around you. To the west you " +
             "see a clearing where a hill stands.\n");
    set_new_light(5);
    
    add_item("forest","The forest seems to be thinning out a bit here");
    add_item("tree|trees","All the trees here are huge, old oak trees");
    add_item("light","More light reaches the road here, but it would " +
             "still be easy for someone to hide in the shadows around you..");
    add_item("undergrowth","The undergrowth beside the road is very thick. " +
             "You would have a hard time walking through the forest, " +
             "should you leave the road");
    add_item("shadows|shadows","Who knows what may be lurking in the " +
             "shadows? Maybe you shouldn't stick around and find out..");
    add_item("clearing","A clearing in the forest where a hill stands");
    add_item("hill","It seems the side of the hill has been dug out, and " +
             "there seem to be a few caves there. It is apparently the " +
             "site of the stone quarry of the village");
    add_item("cave|caves|side","You'd have to go there to get a closer look");    
    add_item("$|$sound|$soft sound|$wind","The only thing you hear is " +
             "the soft sound of the wind in the trees");

    add_exit(ROOM + "north_road9","southeast");
    add_exit(ROOM + "stone_quarry","west");    
}
