#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_climb(string str);
int do_swim(string str);
int do_drink(string str);

void create_object(void)
{
    set_short("Bottom of a gully (e)");
    set_long("You are at the bottom of a deep gully in the forest. The " +
             "gully runs down towards the east from here, and to the west " +
             "is a steep cliff preventing travel in that direction. Water " +
             "falls down from cliff, gathering in a small puddle on the " +
             "ground before it trickles down to the east in the form of a " +
             "small brook. The sides of the gully are steep and grassy and " +
             "the ground beside the brook is dry. You can make out the " +
             "trees beside the gully above you, and on top of the cliff are " +
             "some thick bushes.\n");

    set_new_light(5);

    add_item("bottom|dry bottom|grassy bottom|dry and grassy bottom",
             "The bottom of the gully is dry and grassy. It seems the " +
             "stream that made the gully turned into this small brook " +
             "quite a long time ago");
    add_item("stream","There must have been one here earlier, and this " +
             "place would probably have been a specacular waterfall then. " +
             "Something must have happened further upstream to turn it " +
             "into the small brook it is now");
    add_item("gully|deep gully|wide gully|deep and wide gully","A deep and " +
             "wide gully cutting through the forest towards the east");
    add_item("forest","You can't see much of it from down here, you can " +
             "only make out some of the trees above you");
    add_item("tree|trees","You can make out some of the trees next to the " +
             "gully above you");
    add_item("cliff|steep cliff","A steep cliff to the west. Water falls " +
             "down from it into a puddle on the ground");
    add_item("water","Water falls down from the cliff into a puddle on the " +
             "ground. There's not a lot of it, not enough to actually call " +
             "it a waterfall");
    add_item("waterfall","It looks more like a watertrickle");
    add_item("spectacular waterfall","It's not very spectacular anymore");
    add_item("watertrickle","A good, albeit made up, word to describe the " +
             "water coming down from the cliff and gathering in the puddle");
    add_item("puddle","A small puddle where the water falling from the " +
             "cliff gathers before trickling down to the east");
    add_item("brook|small brook","It trickles gently down towards the east");
    add_item("side|sides|steep side|steep sides|grassy side|grassy sides|" +
             "steep and grassy side|steep and grassy sides","The sides of " +
             "the gully are steep and grassy and look impossible to climb");
    add_item("ground|dry ground|grassy ground|dry and grassy ground",
             "The ground is dry and grassy");
    add_item("grass","It grows on the ground and on the sides of the gully");
    add_item("bush|bushes|thick bush|thick bushes","Thick bushes on top " +
             "of the cliff to the west");

    add_exit(ROOM + "gully_bottom2","east");

    add_sounds(10,10,({ "Water falls down from the cliff and splashes into " +
                        "the puddle.\n",
                        "You hear the soothing sound of running water.\n",
                        "You hear a bird singing somewhere in the trees " +
                        "above.\n"
                      }));
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "water_goblin1");
    add_monster(MONSTER + "water_goblin2");
}

void init(void)
{
    add_action("do_climb","climb");
    add_multi_action("do_swim","swim|dive");
    add_multi_action("do_drink","drink|taste");
    ::init();
}

int do_climb(string str)
{
    if(str == "cliff" || str == "steep cliff")
    {
        W("The cliff is too steep and slippery for you to be able to climb " +
          "it.\n");
        S(TP->QN + " looks up towards the top of the cliff, pondering.\n");
        return 1;
    }
    else if(str == "side" || str == "sides")
    {
        W("The sides of the gully are too steep to climb here.\n");
        S(TP->QN + " looks up towards the side of the gully, pondering.\n");
        return 1;
    }
    return notify_fail("Climb what?\n");
}

int do_swim(string str)
{
    if(str == "water" || str == "in water" || str == "into water")
    {
        W("There's water both in the puddle and in the brook.\n");
        S(TP->QN + " looks confused as " + TP->QPR + " watches the puddle " +
          "and the brook.\n");
        return 1;
    }
    else if(str == "brook" || str == "in brook" || str == "into brook")
    {
        W("The brook is far too shallow for you to be able to swim in it. " +
          "You walk around in it for a while, splashing water everywhere.\n");
        S(TP->QN + " walks around in the brook for a while, splashing " +
          "water at you!\n");
        return 1;
    }
    else if(str == "puddle" || str == "in puddle" || str == "into puddle")
    {
        W("The puddle is too shallow for you to be able to swim in it so " +
          "you just sit down with a *SPLASH*!\nYour pants are all wet " +
          "now.\nYou stand up again.\n");
        S(TP->QN + " sits down in the puddle with a *SPLASH*!\n" +
          TP->QN + " stands up again.\n");
        return 1;
    }
    return notify_fail(C(query_verb()) + " where?\n");
}

int do_drink(string str)
{
    if(str == "water")
    {
        W("You " + query_verb() + " the water. It is very cold and tastes " +
          "good.\n");
        S(TP->QN + " bends down and drinks some water.\n");
        return 1;
    }
    return notify_fail(C(query_verb()) + " what?\n");
}
