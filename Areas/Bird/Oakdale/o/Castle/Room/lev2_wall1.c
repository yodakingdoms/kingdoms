#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("The battlements of the east wall");
    set_long("You are up on the battlements on the east wall of the castle. " +
             "Howling winds tear at your clothes and hair, and dark clouds " +
             "are hanging low over the castle. The wall continues to the " +
             "north. To the west is the drop down to the outer courtyard " +
             "and to the east is the ravine that separates the castle rock " +
             "and the forested valley side. The clouds above you seem to " +
             "circle the highest tower of the castle.\n");
    set_new_light(5);
    add_property("no_horse");

    add_item("battlements|wall","The outer line of defence for the castle");
    add_item("cloud|clouds","Dark, ominous clouds, slowly circling the " +
             "highest tower of the castle");
    add_item("courtyard","You would have to go down there to get a really " +
             "good look at it");
    add_item("ravine","A deep, steep ravine. It almost looks as if a huge " +
             "axe has cut right through the cliff");
    add_item("rock|cliff","The castle rock rises straight up from the " +
             "valley floor, like a finger pointing at the sky");
    add_item("valley|side","The valley is rising to the east, covered by " +
             "the forest");
    add_item("forest","A thick forest of oak trees");
    add_item("tree|trees|oak|oaks","Ancient oaks");
    add_item("tower","The narrow, highest tower of the castle. The dark " +
             "clouds over the castle seem to be circling it. There is " +
             "something eerie about that tower. Shivers run down your " +
             "spine as you look up there");
    add_item("$|$wind","The howling winds make it impossible to hear " +
             "anything else here");

    add_exit(ROOM + "lev2_tower","south");
    add_exit(ROOM + "lev2_wall2","north");
}
