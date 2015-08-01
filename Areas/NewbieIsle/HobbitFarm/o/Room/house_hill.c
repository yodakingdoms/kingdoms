#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_climb(string str);
int do_relax(string str);

void create_object(void)
{
    set_short("Top of the hill");
    set_long("You are at the top of a large grassy hill overlooking " +
             "the small farm. A huge oak tree grows here, its branches " +
             "reaching out over the hill almost forming a ceiling over " +
             "it. There are some wooden steps in the south side of the " +
             "hill going down to the garden on that side. In the other " +
             "directions you see the farm spread out under the hill. " +
             "To the east is the well and the gate in the fence, to the " +
             "north is the main yard and the stable and to the west is " +
             "the barn, a shed and some fields. The grass on the hill " +
             "is long and sways in the wind.\n");

    set_new_light(5);

    add_item("top","You are at the top of the hill, next to a huge " +
             "oak tree. The view here is pretty nice");
    add_item("hill|grassy hill","A grassy hill that serves as a house " +
             "to some hobbits");
    add_item("house","Hobbits often live in hills");
    add_item("hobbit|hobbits","There are no hobbits here now, maybe they " +
             "have more important things to take care of");
    add_item("gate|fence","You would have to go down there to get a " +
             "better look");
    add_item("view","You can almost see the whole farm from here");
    add_item("farm|small farm","The main yard is north of the hill. There " +
             "are some buildings around the yard and some fields to the " +
             "beyond the buildings");
    add_item("yard|main yard","It's right next to the hill, the farm " +
             "is built around the yard");
    add_item("building|buildings","You can see a stable, a barn and " +
             "a shed");
    add_item("stable","It's north of the main yard");
    add_item("barn","It's west of the main yard");
    add_item("shed","It's crammed in between the barn and the stable to " +
             "the northwest");
    add_item("field|fields","There are two larger fields to the " +
             "northwest and southwest and one smaller field to the " +
             "northeast and another to the west of the hill");
    add_item("large field|large fields|larger field|larger fields","The " +
             "field to the northwest seems to be used for keeping animals " +
             "on while the one to the southwest seems to be a cornfield");
    add_item("animal|animals","You'd have to go there to get a better " +
             "look");
    add_item("cornfield","It looks like a cornfield, but you'd have to " +
             "go there to get a better look and be sure");
    add_item("small field|small fields|smaller field|smaller fields","The " +
             "one to the west seems to be used for keeping animals and " +
             "the one to the northeast for growing something");
    add_item("something","You can't tell what's growing there from here");
    add_item("tree|oak|oak tree|huge oak|huge tree|huge oak tree","It " +
             "might be the largest oak you have ever seen. Then again, " +
             "it might not. It looks as if it would be possible to climb " +
             "the tree");
    add_item("branch|branches|ceiling","The branches reach out over you " +
             "forming a sort of ceiling. They sway gently in the wind. " +
             "It looks as if you could climb the tree to get up there " +
             "among the branches");
    add_item("step|steps|wooden step|wooden steps","You can use them to " +
             "go down to the garden a bit more easily that climbing down " +
             "the hill would have been");
    add_item("side|south side","There's a garden there");
    add_item("garden|small garden","A small garden behind the hill. You'd " +
             "have to go there to get a better look");
    add_item("well","The well is on the east side of the hill. It " +
             "stands in the middle of a lawn on that side");
    add_item("lawn|neat lawn","The lawn is very neat. There's a well in " +
             "the middle of it");
    add_item("ground","The ground is covered with grass");
    add_item("grass|long grass","The grass is long and it looks like it " +
             "would be very nice to lie down and relax in it for a while");
    add_item("$|$sound|$sounds|$animal|$animals","You hear the sounds of " +
             "farm animals coming from the farm below");
    add_item("%|%smell|%animal|%animals","You feel the smell of farm " +
             "animals. It is very faint here though");

    add_exit(ROOM + "house_garden","southdown");

    add_sounds(60,10,({ "The grass around you sways gently in the wind.\n",
                        "The branches above you sway gently in the wind.\n"
                     }));
}

void init(void)
{
    add_action("do_climb","climb");
    add_multi_action("do_relax","relax|lie|nap|sleep|rest");
    ::init();
}

int do_climb(string str)
{
    if(str == "tree" || str == "oak" || str == "oak tree")
    {
        if(TP->QS("climb") >= 15)
        {
            W("You climb up into the tree.\n");
            TP->move_player("climbs up into the tree",
                            ROOM + "house_tree",
                            "comes climbing up from below",1);
        }
        else
        {
            W("You try but you're not skilled enough in climbing to " +
              "get up there.\n");
            S(TP->QN + " tries to climb the tree but is apparently not " +
              "skilled enough in climbing.\n");
        }
        return 1;
    }
    return notify_fail("Climb what?\n");
}

int do_relax(string str)
{
    W("You lie down in the grass for a while and relax. You almost fall " +
      "asleep before you shake your head and stand up. You have more " +
      "important things to do after all.\n");
    S(TP->QN + " lies down in the grass and relaxes for a while.\n");
    return 1;
}
