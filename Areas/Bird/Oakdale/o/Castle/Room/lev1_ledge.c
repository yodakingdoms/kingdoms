#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_climb(string str);

void create_object(void)
{
    set_short("A ledge on the side of the cliff");
    set_long("You are on a narrow ledge, hundreds of feet above the " +
             "valley floor. The strong winds threaten to tear you down " +
             "from the ledge any minute. There is an opening in the cliff " +
             "wall, where the shaft continues back up to the kitchen. " +
             "High above you are the black walls of the castle. The cliff " +
             "wall above and below you is completely vertical.\n");
    set_new_light(5);
    set_skip_obvious(1);
    add_property("no_horse");

    add_item("ledge","A narrow ledge. You want to get out of here!");
    add_item("floor|valley","You don't really feel like looking down right " +
             "now");
    add_item("cliff|wall","It is completely vertical");
    add_item("opening|shaft|handles|handle","You notice some handles in " +
             "the shaft. You could probably climb back up again");
    add_item("castle","You feel dizzy looking up there, and decide not to " +
             "look at it any longer");

    add_sounds(5,50,({ "The wind is howling around the ledge.\n",
                       "The wind almost tears you down from the ledge.\n" }));
}

void init(void)
{
    add_action("do_climb","climb");
    SYS_ADMIN->visit(303);
    ::init();
}

int do_climb(string str)
{
    W("You grab hold of the handles and climb all the way back up again. " +
      "Your legs are shaking when you get back to the kitchen and you fall " +
      "flat on the floor, gasping for air. It takes you several moments to " +
      "compose yourself.\n");
    TP->move_player("climbs back up through the hole",
                    ROOM + "lev1_kitchen",
                    "comes climbing up through the hole. " + TP->QPR +
                    " is pale and falls flat on the floor, gasping for air. " +
                    "After a few moments, " + TP->QPR + " seems to calm " +
                    "down",1);
    return 1;
}
