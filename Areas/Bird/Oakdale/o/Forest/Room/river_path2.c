#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A path following the river downstream");
    set_long("You are on a path following the river. The river flows " +
             "swiftly from the north to the south, and the forest grows " +
             "all the way down to the riverbank on the other side. South " +
             "of here the river turns to the southeast, and further " +
             "south you think you see a bridge. To the northeast the " +
             "castle looms over the forest.\n");
    set_new_light(5);
        
    add_item("path","You can follow the path north and south");
    add_item("river","The river flows rapidly southwards. It's not very " + 
             "wide, but it's speed would make it very difficult to " +
             "swim across");
    add_item("forest","A dark, silent forest of oak trees");
    add_item("oak|oaks|tree|trees","Tall, majestic trees indeed");
    add_item("stone|stones","Small stones carried here by the river");
    add_item("boulder|boulders","Large boulders carried here by the " +
             "river from somewhere upstream");
    add_item("castle","A dark, eerie castle. You decide you're in no " +
             "hurry to go up there");
    add_item("bridge","It appears to be a rope bridge that will take you " +
             "across the river");
    add_item("bank|riverbank","This side of the bank is littered with " + 
             "stones and boulders");
    
    add_sounds(10,30,({ "The river slams into the boulders down by the " +
                        "water's edge.\n",
                        "Twigs and leaves float by, carried south by the " +
                        "roaring river.\n" }));
                    
    add_exit(ROOM + "river_path1","north");
    add_exit(ROOM + "river_path3","south");
}
