#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_back(string str);
int do_step(string str);

void create_object(void)
{
    set_short("You are in a grove");
    set_long("You find yourseld standing at the bank of a river. The " +
             "river flows swiftly from the north to the south, and the " +
             "forest grows all the way down to the stony riverside. To " +
             "the northeast you see the stone bridge crossing the river, " +
             "and the road leading into the forest on the other side. A " +
             "bit further to the southwest. Looming over the treetops to " +
             "the northeast, you see the cliff and the dark castle " +
             "overlooking the village. On the other side of the river the " +
             "ground is beginning to slope upwards again as the valley " +
             "ends. You can only go back west from here.\n");
    set_new_light(5);
    set_skip_obvious(1);

    add_item("bank|riverside","It is rocky. Many large boulders lie down " +
             "by the water's edge");
    add_item("boulders","Large boulders carried here by the river. You " +
             "could probably step on one of them");
    add_item("boulder","Yep, you could step on it");
    add_item("river","It flows swiftly to the south. It is approximatley " +
             "50 feet wide at this point");
    add_item("forest","A thick forest of oak trees");
    add_item("bridge","A sturdy stone bridge that looks very secure");
    add_item("road","It enters the forest and disappears among the trees");
    add_item("cliff","A sheer cliff. It looks impossible to climb");
    add_item("castle","You don't feel like looking at it for that long, so " +
             "you turn away");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "piper",1);
}

void init(void)
{
    add_action("do_back","back");
    add_action("do_back","west");
    add_action("do_back","w");
    add_action("do_step","step");
    if(!TP->test_flag(QUEST_SUB_FLAG_2))
    {
        TP->add_exp(10000,1);
        TP->set_flag(QUEST_SUB_FLAG_2);
    }
}

int do_back(string str)
{
    W("You make your way back.\n");
    TP->move_player("starts walking back towards the road",
                    ROOM + "grove",
                    "comes walking here from inside the grove",1);
    return 1;
}

int do_step(string str)
{
    if(str == "on boulder" || str == "boulder")
    {
        W("Oooops! It was slippery! You fall into the shallows with a big " +
          "SPLASH!! You were lucky that you weren't further out. You " +
          "return to the riverbank.\n");
        S(TP->QN + " does a fine impression of a dying swan as " + TP->QPR +
          " tries to step on a boulder, slips, and lands in the river with " +
          "a big SPLASH!!\n" + TP->QN + " looks embarrased as " + TP->QPR +
          " makes " + TP->QPO + " way back to the riverbank.\n");
        return 1;
    }
    return notify_fail("Step on what?\n");
}
