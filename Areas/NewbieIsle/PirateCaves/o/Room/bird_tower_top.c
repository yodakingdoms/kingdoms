// ===============================================================
// Top of the abandoned tower, this is where you land when you
// drink the potion in the birdvial.
// ===============================================================
#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_SOUND;

void create_object(void);
void init(void);
int do_listen(string str);

void create_object(void)
{
    set_short("Top of a tower (d)");
    set_long("You are at the top of an old tower. The tower stands in a " +
             "clearing in a forest and the trees around you are tall and " +
             "tower high above you. The tower seems to be in a state of " +
             "disrepair, small stones that have broken off from the wall " +
             "around the top of the tower and lie scattered around on the " +
             "floor. The floor itself is cracked and worn. There's a " +
             "feeling of peace here and you hear the sound of waves from " +
             "somewhere to the north. Some stairs lead down into the " +
             "tower.\n");
    set_new_light(5);

    add_item("tower","An old tower in a clearing in a forest somewhere");
    add_item("clearing","A clearing in a forest somewhere");
    add_item("forest","A forest somewhere");
    add_item("tree|trees","The trees in the forest tower high above you");
    add_item("stone|stones|small stone|small stones","Small stones that " +
             "have fallen from the slowly crumbling wall around the top " +
             "of the tower");
    add_item("wall|stone wall","A stone wall going around the top of the " +
             "tower");
    add_item("top","The top of the tower, where you are standing");
    add_item("floor","It is cracked and worn");
    add_item("cracks|crack","There are plenty of them in the floor");
    add_item("stairs|stair","The stairs go down");
    add_item("$|$waves|$waves|$sound|$sounds","You hear the sounds of " +
             "waves breaking upon rocks from the north");

    add_exit(PCROOM + "bird_tower","down");

    add_sounds(30,80, ({ "You hear the sounds of waves breaking upon " +
                         "rocks from the north.\n" }));
}

void init(void)
{
    "/sys/admin/room/admin_room"->visit(1099);
//    add_action("do_listen","listen");
}

int do_listen(string str)
{
    W("You can hear the sound of the waves from somewhere to the north.\n");
    S(TP->QN + " listens carefully.\n");
    return 1;
}
