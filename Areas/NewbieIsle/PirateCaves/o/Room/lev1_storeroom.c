#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

int rope_taken;

void create_object(void);
void init(void);
void my_reset(void);
int do_take(string str);
int query_rope_taken(void);

void create_object(void)
{
    ::create_object();
    set_short("A storage room (n)");
    set_long("An underground storage room with wooden shelves on the wall " +
             "and boxes, sacks and barrels on the floor. There's dirt and " +
             "dust everywhere and it doesn't look like the room has been " +
             "used much lately. Most of the shelves are empty except for " +
             "one where you see a few old ropes. You feel cramped and there " +
             "is plenty of dust in the air, making it uncomfortable to " +
             "breathe.\n");

    add_item("room|storage room|underground storage room","It doesn't look " +
             "as if the room has been used in a long time. You can only " +
             "deduce that the pirates aren't very active anymore");
    add_item("shelf|shelves|wooden shelf|wooden shelves","They are mostly " +
             "empty. There are some ropes on one of them");
    add_item("box|boxes","The boxes don't contain anything particularly " +
             "interesting");
    add_item("sack|sacks","The sacks look as if they are rotten and useless");
    add_item("barrel|barrels","The barrels are empty");
    add_item("dirt|dust","It is everywhere");
    add_func_item("rope|ropes","#query_rope_taken",({
                 "Most of the ropes are rotten and useless, but you spot " +
                 "one that looks as if it still has some life in it. Maybe " +
                 "you could take that one from the shelf?",
                 "All the ropes are rotten and useless"
                }));

    add_exit(PCROOM + "lev1_ew_corridor2","north");
}

void init(void)
{
    add_multi_action("do_take","take|get");
}

void my_reset(void)
{
    rope_taken = 0;
}

int do_take(string str)
{
    object rope;

    if(!rope_taken && (str == "rope" || str == "rope from shelf"))
    {
        W("You take a rope from the shelf.\n");
        S(TP->QN + " takes a rope from a shelf.\n");
        rope_taken = 1;
        rope = make(PCOBJECT + "rope");
        if(transfer(rope,TP))
        {
            W("It's too heavy for you to carry so you drop it on " +
               "the floor.\n");
            S(TP->QN + " drops the rope on the floor.\n");
        }
        // A rope is needed for the quest ...
        set_alarm(300.0,0.0,"my_reset");
        return 1;
    }
    return 0;
}

int query_rope_taken(void)
{
    return rope_taken;
}