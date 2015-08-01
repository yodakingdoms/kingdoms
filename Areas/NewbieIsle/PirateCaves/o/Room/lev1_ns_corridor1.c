#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

void create_object(void);
void init(void);
int do_drink(string str);
int do_jump(string str);

void create_object(void)
{
    ::create_object();
    set_short("An underground corridor (n/s)");
    set_long("An underground corridor going north and south. Some distance " +
             "to the north is an opening and fresh air seems to come into " +
             "the corridor from there. There is an archway in the west " +
             "wall, beyond which there seems to be a storage room. Water is " +
             "dripping from the ceiling and gathering in a small puddle on " +
             "the floor.\n");

    add_item("corridor|underground corridor","It continues to the north " +
             "and to the south");
    add_item("opening","It seems to lead outside, but you'll have to go " +
             "north to get a closer look");
    add_item("air","You can't see it, but it seems fresher here than it " +
             "did south of here");
    add_item("archway","It leads to a room to the west");
    add_item("room|storage room","That's what it seems like. It's pretty " +
             "dark in there so you may have to light a torch to be able " +
             "to see there");
    add_item("water","It's dripping from the ceiling into a puddle on the " +
             "floor");
    add_item("puddle|small puddle","A small puddle of water on the floor");

    add_exit(PCROOM + "lev1_wn_corridor","south");
    add_exit(PCROOM + "lev1_gunpowder_room","west");
    add_exit(PCROOM + "lev1_se_corridor","north");
}

void init(void)
{
    add_multi_action("do_drink","drink|taste");
    add_action("do_jump","jump");
}

int do_drink(string str)
{
    if(str == "water" || str == "from puddle")
    {
        W("It looks clear but you never know what kind of junk gathers " +
          "in puddles like that one so you decide against it.\n");
        S(TP->QN + " looks at the puddle of water, pondering.\n");
        return 1;
    }
    return notify_fail(C(query_verb()) + " what?\n");
}

int do_jump(string str)
{
    if(str == "puddle" || str == "in puddle" || str == "into puddle")
    {
        W("You jump around in the puddle for a little while but the only " +
          "thing you accomplish by doing that is getting your clothes " +
          "wet.\n");
        S(TP->QN + " jumps around in the puddle for a little while.\n");
        return 1;
    }
    return notify_fail("Jump where?\n");
}