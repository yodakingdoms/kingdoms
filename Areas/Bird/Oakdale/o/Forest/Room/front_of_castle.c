#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("An open area in front of the eerie castle");
    set_long("You come out of the forest and enter an open area in front " +
             "of the castle. The road goes back down the side of the " +
             "castle rock, entering the forest to the southeast. To the " +
             "west is the castle. The castle is an impressive sight. The " +
             "road west passes through the outer gate tower rising before " +
             "you before it seems to reach a drawbridge. The gate is open " +
             "and the portcullis is raised. The gate tower is separated " +
             "from the castle proper by a deep chasm cutting through the " +
             "castle rock. Dark clouds are gathering in the sky above you, " +
             "slowly circling the highest towers of the castle, and a " +
             "howling wind is blowing through the gorge below.\n");
    set_new_light(5);
        
    add_item("forest","A forest of oak trees. It is dark and silent");
    add_item("area","An open area between the gate tower and the forest");
    add_item("castle","Dark and sinister it looms over you. The walls and " +
             "towers are black, and no light can be seen in any of the " +
             "windows. One tower rises above all the others, almost " +
             "touching the clouds gathering in the sky above");
    add_item("wall|walls","The smooth, black walls look impenetrable");
    add_item("towers","Tall, slender and black they rise towards the sky");
    add_item("tower","Look at gate tower or high tower");
    add_item("high tower","The highest tower almost reaches the clouds " +
             "gathering in the sky above. The clouds seem to be circling " +
             "that tower");
    add_item("gate tower","The first line of defence for the castle. If " +
             "you go west, you'll pass through it");
    add_item("line|defence","The outer gate tower");
    add_item("drawbridge","Well, you can't really see it clearly from here");
    add_item("gate","The gate is open, allowing you to enter");
    add_item("chasm|gorge","A deef chasm cutting through the cliff, " +
             "separating the castle rock from the rest of the cliff, " +
             "making the castle virtually impossible to take by force");
    add_item("rock|castle rock","The part of the cliff where the castle " +
             "stands");
    add_item("cliff","The high cliff overlooking the village");
    add_item("village","The castle is between you and the village, so you " +
             "can't see the village from here");
    add_item("cloud|clouds","Dark clouds gathering over the castle, " +
             "circling the highest tower");         
    add_item("$|$wind","You hear the wind howling through the chasm " +
             "cutting through the cliff");
             
    add_exit(ROOM + "castle_road6","southeast");
    add_exit(CASTLE + "Room/gatetower1","west");           
}
