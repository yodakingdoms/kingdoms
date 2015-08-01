#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_turn(string str);

void create_object(void)
{
    set_short("A road through the forest north of the village");
    set_long("You are on a road through the forest. The huge oak trees " +
             "stand close to the road, their branches reaching out over " +
             "it, almost creating a ceiling over your head. Only very " +
             "little light filters down through the branches, so it is " +
             "rather shadowy here. The road continues to the northeast " +
             "and the southwest. By the side of the road lies an " +
             "overturned wagon.\n");
    set_new_light(3);

    add_item("forest","A dark, silent forest of oak trees");
    add_item("tree|trees","Huge, old oak trees");
    add_item("branch|branches","The branches of the trees seem thick and " +
             "strong");
    add_item("ceiling","The branches ALMOST create a ceiling, so there's " +
             "no ceiling here");
    add_item("light","Very little, only a few beams get through the " +
             "branches. As a result, there is a very moody atmosphere here");
    add_item("wagon","One of the wagons that once carried rocks from the " +
             "quarry to the north down to the village. It looks as if it's " +
             "been lying here for quite some time. Maybe you could turn it " +
             "and see if there's anything interesting under it?");
    add_item("$|$sound|$soft sound|$wind","The only thing you hear is " +
             "the soft sound of the wind in the trees");

    add_exit(ROOM + "north_road6","southwest");
    add_exit(ROOM + "north_road9","northeast");
}

void init(void)
{
    add_action("do_turn","turn");
}

int do_turn(string str)
{
    if(str == "wagon")
    {
        if(TP->query_str() < 15)
        {
            W("You weakling! You're too skinny to turn even a wheelbarrow " +
              "over, and now you expect to be turning this wagon?!\n");
            S(TP->QN + " tries to turn the wagon over, but " + TP->QPR +
              " only manages to display " + TP->QPO + " embarrassing " +
              "lack of muscle.\n");
            return 1;
        }
        else
        {
            if(TP->query_str() < 14 + random(6))
            {
                W("You almost manage to turn it over, but not quite. It " +
                  "doesn't seem impossible, though.\n");
                S(TP->QN + " tries to turn the wagon over, and almost " +
                  "succeeds!\n");
                return 1;
            }
            else
            {
                W("You lift the heavy wagon just high enough to see that " +
                  "there is nothing but grass and rocks under it.\n");
                S(TP->QN + " lifts the wagon up just high enough so that " +
                  "you too can see what was under it. Disappointing. " +
                  "Nothing but grass and rocks.\n");
                if(TP->query_dex() < 14 + random(6))
                {
                    W("As you let the wagon fall back to the ground, you " +
                      "are too clumsy to get out of the way! The wagon " +
                      "lands on your foot, and it hurts!\n");
                    S("As " + TP->QPR + " drops the wagon to the ground " +
                      "again, " + TP->QPR + " manages to get " + TP->QPO +
                      " foot caught under it! How clumsy.\n");
                    TP->add_temporary_penalty(5 + random(5));
                    return 1;
                }
                W("You drop the wagon back to the ground and deftly " +
                  "get out of the way.\n");
                S(TP->QPR + " deftly gets out of the wagons way as " +
                  TP->QPR + " drops it back to the ground.\n");
                return 1;
            }
        }
    }
    return notify_fail("Turn what?\n");
}
