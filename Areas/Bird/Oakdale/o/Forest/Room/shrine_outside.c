#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_reach(string str);

void create_object(void)
{
    set_short("Outside an old building");
    set_long("The road through the forest ends here in front of an old " +
           "building. The trees stand close to the road and their branches " +
           "reach out over it, leaving it in shadow. Nothing can " +
           "be heard in the dark forest around you. The building in front " +
           "of you is in a state of decay, but not yet a ruin. It appears " +
           "to have been used as a shrine once, but now it lays deserted. " +
           "An archway leads inside.\n");
    set_new_light(3);

    add_item("road","The road ends here in front an old building");
    add_item("forest","The forest is dark and silent. You would surely get " +
             "lost should you enter it");
    add_item("building","The building is the decaying remains of an old " +
             "shrine");
    add_item("remains","The building is deteriorating, but it is not " +
             "really a ruin quite yet");
    add_item("tree|trees","Majestic old oak trees");
    add_item("branch|branches","The branches of the trees reach out over " +
             "the road, leaving it in shadow. They are very close and you " +
             "could probably reach one of them");
    add_item("shadow","Long shadows created by the branches hanging out " +
             "over the road");
    add_item("ruin","The building has not yet deteriorated enough to be " +
             "called a ruin");
    add_item("shrine","The building looks as if it was once used as a " +
             "shrine. On the roof above the entrance is a symbol");
    add_item("symbol","The symbol of The Church of True Faith");
    add_item("archway","The archway is decorated with figures and symbols");
    add_item("figure|figures","Figures depicting the struggle between good " +
             "and evil");
    add_item("symbols","Symbols of The Church of True Faith");

    add_exit(ROOM + "north_road11","west");
    add_exit(ROOM + "shrine_entrance","east");
}

void init(void)
{
    add_action("do_reach","reach");
}

int do_reach(string str)
{
    W("As you reach for the branches, the trees begin to groan. Suddenly " +
      "the branches jerk away from your hand... You suddenly feel very " +
      "uneasy...\n");
    S("As " + TP->QN + " reaches for a branch, the trees begin to groan. " +
      "Suddenly the branch jerks away from " + TP->QPO + " hand...\n");
    return 1;
}
