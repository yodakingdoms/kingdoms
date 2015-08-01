#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_rest(string str);
int do_reach(string str);

void create_object(void)
{
    set_short("A crossroad in the village");
    set_long("You are at a crossroad in the village. Roads lead north, " +
             "south, east and west. There are houses in the other " +
             "directions, but you can't enter any of them from here. A " +
             "huge oak stands here, stretching its branches out above " +
             "your head. In the shadow of the tree stands a bench. The " +
             "castle looms above the village.\n");
    set_new_light(5);

    add_item("oak|tree","The oak seems to be very old, but it is still " +
             "strong and healthy");
    add_item("branches","They are thick and strong. They hang out over your " +
             "head and provide shadow");
    add_item("bench","A white wooden bench. It looks made for resting on");
    add_item("castle","You try to get a closer look of the castle, but " +
             "you quickly avert your eyes");
    add_item("branch","It seems you could reach it and maybe climb up " +
             "into the tree");

    add_exit(ROOM + "road5","west");
    add_exit(ROOM + "road6","east");
    add_exit(ROOM + "road10","north");
    add_exit(ROOM + "road13","south");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "bilir",1);
}

void init(void)
{
    add_action("do_rest","rest");
    add_action("do_reach","reach");
}

int do_rest(string str)
{
    W("You sit down on the bench and rest. Here in the shadow of the " +
      "tree, you are sheltered from the strange power radiating from the " +
      "castle. The village seems much more inviting now. As you lean back, " +
      "one of the branches catches your attention.\n");
    S(TP->QN + " sits down on the bench, leans back and takes a deep " +
      "breath.\n");
    return 1;
}

int do_reach(string str)
{
    if(str == "branch")
    {
        W("You grab hold of the branch and pull yourself up into " +
          "the tree.\n\n");
        TP->move_player("grabs hold of a branch and pulls " + TP->QO +
                        "self up into the tree",ROOM + "tree",
                        "comes climbing up from below",1);
        return 1;
    }
    return notify_fail("Reach what?\n");
}
