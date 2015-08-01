#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A path going down the side of a ravine");
    set_long("A path going down the side of a ravine. The cliffside is " + 
             "steep, but the trees still manage to get hold and the forest " +
             "is dense around you. The path lies in shadow, as the branches " +
             "of the trees reach out over the path blocking out much of the " +
             "light. The path goes back up to the west and continues down " +
             "to the south, where it looks like you'll come out of the " +
             "forest. A strong rumbling sound can be heard from the " +
             "south.\n");
    set_new_light(3);
        
    add_item("path","The rocky path goes up and down the steep side of a " +
             "ravine");
    add_item("ravine|side|cliffside","It is pretty steep, but the forest " +
             "is still dense around you");
    add_item("tree|trees","Old oak trees, somehow managing to cling to " +
             "this steep cliffside");
    add_item("forest","The forest is dark and silent around you");
    add_item("branch|branches","The branches of the trees are thick and " +
             "strong, and reach out over the path, blocking out much of " +
             "the light");    
    add_item("$|$rumbling|$waterfall","You hear the loud rumbling of a " +
             "waterfall from the south");
    
    add_exit(ROOM + "river_bridge2","westup");
    add_exit(ROOM + "waterfall","southdown");    
}
