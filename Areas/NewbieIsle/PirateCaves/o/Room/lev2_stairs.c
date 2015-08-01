#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

void create_object(void);
void init(void);
int do_listen(string str);

void create_object(void)
{
    ::create_object();
    set_short("Stairs (d/s)");
    set_long("A narrow stairwell with some stairs going down. The air here " +
             "is damp and you think you hear the sound of water from below. " +
             "The stairwell is lit by a small shining stone in a niche in " +
             "the wall. A messy corridor continues south from here and you " +
             "can sounds of feasting from that direction.\n");

    add_item("stairwell|narrow stairwell","It goes down");
    add_item("air","It is damp, seems like there might be water down there");
    add_item("stone|small stone|shining stone|small shining stone","A " +
             "small, shining stone set in a niche in the wall");
    add_item("niche","A niche in the wall with a small, shining stone");
    add_item("corridor|messy corridor","It does not look as if it has been " +
             "cleaned in a long time");

    add_exit(PCROOM + "lev2_corridor3","south");
    add_exit(PCROOM + "lev3_stairs","down");
}

void init(void)
{
    add_action("do_listen","listen");
}

int do_listen(string str)
{
    W("You hear the sound of water from below and sounds of feasting " +
      "from the south.\n");
    S(TP->QN + " listens carefully.\n");
    return 1;
}