#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

int corpse_found = 0;

void create_object(void);
void reset(int arg);
void init(void);
int do_pull(string str);

void create_object(void)
{
    set_short("A dark, smelly cave");
    set_long("A disgusting smell hits you as you enter this dark cave. The " +
             "cave is almost circular and the rough stone ceiling is high " +
             "above you. Stacked against the east wall is a huge heap of " +
             "rotting wood, putrid flesh, bones, rusty equipment and other " +
             "garbage that almost reaches the ceiling. The stench in here " +
             "is unbearable.\n");
    set_new_light(0);
    add_property("indoors");

    add_item("cave","A dark cave. Apparently it is serving as a garbage dump");
    add_item("heap","A huge heap of stinking, disgusting trash. Apart from " +
             "all the normal domestic trash, you also notice severed limbs " +
             "and a few more or less mutilated corpses. You feel your " +
             "stomach beginning to turn");
    add_item("bones|flesh|limb|limbs|corpses","Severed limbs and mutilated " +
             "corpses in various states of decay. This is disgusting! You " +
             "think you see one interesting corpse, though");
    add_item("corpse","It is the decaying corpse of a humanoid of " +
             "undistinguishable race. The interesting thing about it is " +
             "that it still seems to be fully equipped. It looks like you " +
             "could pull the corpse away from the heap and look at it " +
             "more closely");
    add_item("garbage","A big heap of it");
    add_item("ceiling","The ceiling in this cave is high");
    add_item("wood","The pieces of wood you find are sickly rotten and " +
             "crumbles at your touch");
    add_item("trash","Just your typical domestic trash");
    add_item("%","Oh, BLAEH! You feel like you're going to throw up");

    add_exit(ROOM + "dgcave_small","southwest");

    reset(0);
}

void reset(int arg)
{
    corpse_found = 0;
}

void init(void)
{
    add_action("do_pull","pull");
}

int do_pull(string str)
{
    if(str == "corpse")
    {
        if(!corpse_found)
        {
            W("Yick! This is one of the most disgusting things you have " +
              "ever done. The smell of putrid flesh penetrates your " +
              "nostrils and you feel like just running out into the fresh " +
              "air and throw up. As you pull the corpse from the heap, it " +
              "falls into pieces, and the equipment on it falls down on the " +
              "floor.\n");
            S(TP->QN + " pulls a rotting corpse out of the heap. How "+
              "disgusting!!!! It falls into pieces, and all its equipment " +
              "falls down on the floor.\n");
            corpse_found = 1;
            make(CASTLE + "Armour/dark_plate");
            make(CASTLE + "Armour/dark_shield");
            make(CASTLE + "Armour/dark_helmet");
            make(CASTLE + "Armour/dark_glove");
            make(CASTLE + "Weapon/dark_lsword");
            return 1;
        }
        else
        {
            W("Hmm, apparently someone's been here allready. On a closer " +
              "look you realize that all the equipped corpses have been " +
              "pulled out allready.\n");
            return 1;
        }
    }
    return notify_fail("Pull what?\n");
}
