#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A path following the river downstream");
    set_long("A path following the river. The river turns to the " +
             "southeast here, flowing swiftly from the north. On the " +
             "other side, the forest grows all the way down to the " +
             "riverbank. The path continues to the southeast, " +
             "eventually reaching a bridge crossing the river. The " +
             "castle looms over the forest to the northeast.\n");
    set_new_light(5);
        
    add_item("path","It goes north towards the village and southeast to a " +
             "rope bridge crossing the river");
    add_item("river","The river flows rapidly to the south. It's not very " +
             "wide, but it's wild. Swimming across it would be very " +
             "difficult");
    add_item("forest","A dark, silent forest of oak trees");
    add_item("oak|oaks|tree|trees","Tall, majestic trees");
    add_item("riverbank|bank","The bank of the river is littered with " +
             "stones and boulders");
    add_item("stone|stones","Small stones probably carried here by the river");
    add_item("boulder|boulders","Larger stones carried here by the river " +
             "from somewhere further upstream");
    add_item("bridge","A rope bridge crossing the river");
    add_item("castle","The dark, sinister castle stands there, silently " +
             "watching the village");
    
    add_sounds(10,30,({ "The river roars as it continues southeast.\n",
                        "The bridge to the southeast creaks noisly.\n" }));
                    
    add_exit(ROOM + "river_path2","north");
    add_exit(ROOM + "river_bridge","southeast");                    
}
