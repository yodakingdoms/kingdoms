#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("The drawbridge of the castle");
    set_long("The drawbridge of the castle. The broad wooden bridge " +
             "crosses the deep chasm separating the castle rock and the " +
             "outer gatetower. Two huge chains are attached to the bridge " +
             "and hang down from openings high up on the walls of the " +
             "castle towering before you. The walls are black and the " +
             "windows and openings look like hollow eye sockets of the " +
             "skeletal remains of some huge beast. Towers and battlements, " +
             "wall upon wall rise before you. A thin, black tower rises " +
             "above all others, almost touching the dark clouds gathering " +
             "above the castle. A howling wind is blowing through the " +
             "chasm under the bridge.\n");
    set_new_light(5);

    add_item("drawbridge|bridge","It's lowered right now. If it wouldn't " +
             "have been, there would have been no way for you to enter " +
             "the castle");
    add_item("castle","The sinister castle towers above you. The walls are " +
             "black and hundreds of small slits and windows peer down at " +
             "you. A thin, black tower rises higher than all the others. " +
             "The dark clouds hanging over the castle seem to be circling " +
             "that tower slowly");
    add_item("tower","A thin, black tower rising above the rest of the " +
             "castle. The dark clouds seem to gather around that tower. " +
             "For a moment you think you see a light flicker and die in " +
             "one of the windows, and you think you saw the silhouette " +
             "of a man in the window");
    add_item("silhouette|man","You can't see it anymore, but that one " +
             "glimpse made your skin crawl");
    add_item("chain|chains","The chains are connected to some kind of " +
             "machinery inside the castle, used to raise the drawbridge. " +
             "Or that's what you suppose");
    add_item("opening|openings","Holes for the chains to pass through on " +
             "their way to the machinery on the inside");
    add_item("wall|walls","The walls of the castle are pitch black and no " +
             "chicks or nicks can be seen in any of them. You discern no " +
             "foot-, or handhold that could be used to climb the walls");
    add_item("windows","Many windows. You can see no light or movement in " +
             "any of them");
    add_item("window","The light in the window flickered briefly, but now " +
             "it is gone");
    add_item("light","You can't see it anymore");
    add_item("towers","High, slender, black towers");
    add_item("battlement|battlements","A very impressive sight. This castle " +
             "would be virtually impossible to take by force");
    add_item("chasm|gorge","A deep gorge cutting through the cliff, " +
             "separating the main castle rock from the outer gate tower");
    add_item("rock|cliff","The cliff upon which the castle stands");
    add_item("gate tower","A tower providing the first line of defence for " +
             "the castle");
    add_item("defence|line","This castle seems to be very easy to defend");
    add_item("$|$howling|$wind","You only hear the howling of the wind " +
             "raging through the gorge below");

    add_exit(ROOM + "gatetower1","east");
    add_exit(ROOM + "gatetower2","west");
}
