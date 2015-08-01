#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_cross(string str);

void create_object(void)
{
    set_short("A path following the river downstream. A rope bridge " +
              "crosses the river here");
    set_long("The path has taken you to a rope bridge crossing the river. " +
             "The bridge sways and creaks and doesn't look very safe, but " +
             "you see the path continue into the forest on the other " +
             "side, so you could probably try to cross the bridge The " +
             "river flows swiftly to the southeast, and the forest on the " +
             "other side is dark and silent. You can hear a low rumbling " +
             "in the distance to the southeast. The castle looms over " +
             "the forest to the northeast.\n");
    set_new_light(5);

    add_item("bridge","The bridge creaks and sways violently and does " +
             "not look particularily safe. Still, if you dare, you " +
             "could cross it");
    add_item("river","The river flows swiftly from the northwest to the " +
             "southeast. Downstream you see a bend in the river");
    add_item("bend","The river bends to the east there");
    add_item("path","The path continues into the forest on the other " +
             "side of the river");
    add_item("forest","The forest on the other side of the river is dark " +
             "and silent");
    add_item("castle","It looms over the forest, dark and sinister");
    add_item("$|$creaking|$bridge|$rumble|$waterfall","You hear the " +
             "creaking of the bridge and the low rumble of a waterfall " +
             "somewhere to the southwest");

    add_sounds(10,30,({ "The rope bridge creaks loudly.\n",
                        "You hear the low rumbling of a waterfall from " +
                        "the southeast.\n" }));

    add_exit(ROOM + "river_path3","northwest");
}

void init(void)
{
    add_multi_action("do_cross","cross|e|east");
    ::init();
}

int do_cross(string str)
{
    W("You carefully step out onto the bridge. The bridge sways violently " +
      "under your feet and the river roars like a beast about to be fed. " +
      "You sigh with relief when you plant your feet on the firm ground on " +
      "the other side of the river.\n\n");
    TP->move_player("steps out onto the bridge, which sways violently and " +
                    "creaks loudly as " + TP->QPR + " crosses it. " +
                    "Eventually " + TP->QPR + " reaches the other side, " +
                    "looking very relieved",
                    ROOM + "river_bridge2",
                    "comes walking across the bridge",1);
    return 1;
}
