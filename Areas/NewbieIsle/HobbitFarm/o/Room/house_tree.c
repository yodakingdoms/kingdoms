#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_down(string str);
int do_climb(string str);

void create_object(void)
{
    set_short("Top of the tree");
    set_long("You're at the top of a huge oak tree growing on top of a " +
             "large hill on the farm. The branches are thick and so is " +
             "the foliage. Unfortunately the leaves hide most of what " +
             "should have been a magnificent view, you can only see " +
             "glimpses of the surrounding area. There are some remnants of " +
             "what seems to have been a treehouse here and many birds " +
             "seem to have found this a good place to build nests. The " +
             "tree sways lightly in the wind, maybe it would be safer to " +
             "climb down to the hill again?\n");

    set_new_light(3);
    set_skip_obvious(1);

    add_item("top","Well, not quite at the top but probably as high as " +
             "you can climb in the tree without the branches breaking");
    add_item("tree|oak|huge tree|huge oak|oak tree|huge oak tree","It is " +
             "very big and must be hundreds of years old");
    add_item("hill|large hill","A hill that has been dug out and functions " +
             "as a hobbit house");
    add_item("hobbit house","Hobbits often live in hills such as " +
             "the one the oak grows on");
    add_item("farm","It is a farm run by hobbits");
    add_item("hobbit|hobbits","Sadly, there are no hobbits up here");
    add_item("branch|branches|thick branch|thick branches","The branches " +
             "here are thick and easily carry your weight. That doesn't " +
             "look to be the case higher up so this is as high as you " +
             "will climb");
    add_item("foliage","The foliage is think and hides the view. Maybe " +
             "that has something to do with why the treehouse up here " +
             "seems abandoned");
    add_item("view","It would probably be spectacular if the leaves were " +
             "not in the way. As it is, you feel rather disappointed");
    add_item("leaf|leaves|large leaf|large leaves|oak leaf|oak leaves|" +
             "large oak leaf|large oak leaves","Large oak leaves, obscuring " +
             "the view up here");
    add_item("glimpse|glimpses","As the branches sway in the wind, the " +
             "occasionally opens up to let you catch a short glimpse of " +
             "the farm below");
    add_item("area|surrounding area","Unfortunately you cannot see much " +
             "of it from here, due to the thick foilage");
    add_item("remnant|remnants|house|treehouse","Someone built a treehouse " +
             "up here one time but apparently he or she or it grew tired " +
             "of it a long time ago since it's almost fallen apart now. " +
             "It looks more like a few planks nailed haphazardly together " +
             "now");
    add_item("plank|planks|rotten plank|rotten planks","They seem rotten " +
             "and don't look very useful");
    add_item("bird|birds|nest|nests","Many birds have built nests here. " +
             "This place should provide good shelter from predators so " +
             "it makes sense");
    add_item("shelter|good shelter|predator|predators","Predators would " +
             "have a hard time seeing through the foliage");
    add_item("$|$sound|$leaf|$leaves","You hear the sound of ruffling " +
             "leaves in the swaying branches around you");

    add_sounds(30,10,({ "The leaves around you sway gently in the wind.\n",
                        "The branch you sit on sways gently in the wind.\n"
                     }));
    reset(0);
}

void init(void)
{
    SYS_ADMIN->visit(1118);
    add_action("do_climb","climb");
    add_multi_action("do_down","down|d");
    ::init();
}

int do_climb(string str)
{
    if(str == "down")
    {
        W("You climb down from the tree.\n");
        TP->move_player("climbs down from the tree",
                        ROOM + "house_hill",
                        "comes climbing down from the tree",1);
        return 1;
    }
    return notify_fail("Climb where?\n");
}

int do_down(string str)
{
    W("You have to <climb> down if you want to get out of the tree.\n");
    return 1;
}
