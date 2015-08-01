#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_ring(string str);

void create_object(void)
{
    set_short("The bell tower of the Oakdale church");
    set_long("You are in the bell tower of the oakdale church. The slender " +
             "tower is made of white stone and rises over the trees, " +
             "providing you with an excellent view of the valley, as there " +
             "are windows in every direction. The ceiling is domed and in " +
             "the centre of the room, the church bell hangs. To the " +
             "northeast the castle looms over the village. Some stairs go " +
             "down from here.\n");
    set_new_light(10);
    add_property("indoors");

    add_item("tower","You are standing in it");
    add_item("tree|trees","Tall, healthy oak trees");
    add_item("view|valley","The whole valley stretches out before you. " +
             "To the north is the village, twenty or so small stone " +
             "houses, and a few thin pillars of smoke are peacefully " +
             "rising up into the air. In the centre of the village you " +
             "see a square and a crossroad where a tall tree stands. A road " +
             "leads north out of the village, and to the west of the road " +
             "you see a clearing in the forest. The road north ends in " +
             "some hills further north. East of the village the river " +
             "flows, and to the east of here it ends in a waterfall. On " +
             "the other side of the river the dark cliff rises. The castle " +
             "stands upon the cliff, dark and sinister");
    add_item("village","A peaceful little village");
    add_item("houses","Small stone houses with wooden roofs and stone " +
             "chimneys");
    add_item("pillars|smoke","Thin pillars of smoke. They rise slowly up " +
             "into the air and then dissolve");
    add_item("square","A small village square, but there does not seem to " +
             "be much activity");
    add_item("crossroad","The road from the church crosses the main road of " +
             "the village there");
    add_item("clearing","A small cottage stands there. You guess there is a " +
             "path from the road to the clearing");
    add_item("cottage","You can't see it clearly from here");
    add_item("hills","Some hills to the north. The north road seems to end " +
             "there");
    add_item("river","A swiftly flowing river, flowing from the north to " +
             "the south");
    add_item("waterfall","The river disappears down a cliff in a huge cloud " +
             "of spray there");
    add_item("cliff","It is several hundred feet high and looks impossible " +
             "to climb");
    add_item("castle","A chill runs down your spine as you look up at the " +
             "castle. You can't help thinking that this valley would be a " +
             "wonderful place if only that castle wasn't there");
    add_item("windows","Four undecorated windows providing you with a nice " +
             "view");
    add_item("stairs","They go down");
    add_item("ceiling","A domed ceiling you notice something about one of " +
             "the roofbeams");
    add_item("roofbeam|beam","There is a birds nest on it");
    add_item("nest","A small nest made out of twigs and leaves");
    add_item("stone","White stone");
    add_item("bell","A large bell, made of some strange metal. Beautiful " +
             "patterns are engraved in it");
    add_item("metal","You don't recognize the strange metal");
    add_item("patterns","The patterns are very beautiful");

    add_exit(ROOM + "church","down");
}

void init(void)
{
    add_action("do_ring","ring");
}

int do_ring(string str)
{
    if(str == "bell")
    {
        W("You pull the rope attached to the bell and the bell starts " +
          "tolling with a strange, muffled sound. It's almost like the " +
          "absence of the divine being that should be here numbs the " +
          "sound of the bell.\n");
        S(TP->QN + " pulls the rope attached to the bell. The bell starts " +
          "tolling with a strange muffled sound.\n");
        return 1;
    }
    return notify_fail("Ring what?\n");
}
