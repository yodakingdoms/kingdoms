#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

void create_object(void);
void init(void);
int do_listen(string str);

void create_object(void)
{
    ::create_object();
    set_short("Stairs (u/s)");
    set_long("A narrow stairwell with some stairs going up. The air is damp " +
             "and you hear the sound of water from the west, where it looks " +
             "like there is a huge cave. There is an opening in the south " +
             "wall leading into a hall of some sort. The stairwell is lit " +
             "by a small shining stone in a niche in the wall.\n");

    add_item("stairwell","It's narrow");
    add_item("stair|stairs","They go up");
    add_item("air","It is damp and your hair clings to your face");
    add_item("huge cave|cave","It looks huge, but you will have to go " +
             "there to get a better look");
    add_item("opening","It leads south into a hall of some kind");
    add_item("south wall","There is an opening in it");
    add_item("hall","You will have to go south to get a better look");
    add_item("stone|small stone|shining stone|small shining stone","A " +
             "small, shining stone set in a niche in the wall");
    add_item("niche","A niche in the wall with a small, shining stone");

    add_exit(PCROOM + "lev2_stairs","up");
    add_exit(PCROOM + "lev3_bowling_hall","south");
    add_exit(PCROOM + "lev3_harbour","west");
}

void init(void)
{
    add_action("do_listen","listen");
}

int do_listen(string str)
{
    W("You hear the sound of water from the west.\n");
    S(TP->QN + " listens carefully.\n");
    return 1;
}
