#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

int rock_hit;
int keystone_found;

void create_object(void);
void my_reset(void);
void init(void);
int do_push(string str);
int do_hit(string str);
int do_search(string str);
int query_rock_hit(void);

void create_object(void)
{
    set_short("A cold, dark cave with a low ceiling");
    set_long("A cold, dark cave with a low ceiling. The air is cold and " +
             "water is dripping from the ceiling, forming small puddles on " +
             "the rough stone floor. Two wooden crates stand by the north " +
             "wall. The narrow tunnel goes back up to the southeast and no " +
             "other exit can be seen. The ceiling is so low you can't " +
             "stand up straight in here, and you feel most uneasy.\n");
    set_new_light(0);
    add_property("indoors");

    add_item("cave","A cold, damp cave with a low ceiling");
    add_item("water","Water dripping from the ceiling, forming small " +
             "puddles on the floor");
    add_item("puddle|puddles","Small puddles of water formed by the water " +
             "dripping from the ceiling");
    add_item("ceiling","A rough stone ceiling");
    add_item("floor","A rough stone floor");
    add_item("walls","Grey stone walls");
    add_item("tunnel","It goes back the way you came");
    add_item("crate|crates","Two wooden crates that obviously have been " +
             "standing here a long time. They are empty, and the wood has " +
             "decayed to the point where it looks like they would fall " +
             "apart if you would touch them. You notice something odd about " +
             "the wall behind the crates, though..");
    add_func_item("wall","#query_rock_hit",({
                  "You notice an eye-catching rock in the wall",
                  "You notice a small hole in the wall" }));
    add_func_item("hole","#query_rock_hit",({
                  "",
                  "A small hole in the wall. Maybe a more thorough " +
                  "examination would be useful" }));
    add_func_item("rock","#query_rock_hit",({
                  "It looks as if you should be able to push the rock " +
                  "into the wall...",
                  "There is no rock here" }));

    add_sounds(05,80,({ "Drip, drop...\n" }));

    add_exit(ROOM + "wfallcave_tunnel4","southeast");
}

void my_reset(void)
{
    rock_hit = 0;
    keystone_found = 0;
}

void init(void)
{
    add_action("do_push","push");
    add_action("do_hit","hit");
    add_action("do_search","search");
    ::init();
}

int do_push(string str)
{
    if(!rock_hit)
    {
        if(str == "rock")
        {
            W("You push the rock as hard as you can, but it won't budge. " +
              "Apparently it is stuck.\n");
            S(TP->QN + " tries to push the rock into the wall, but it won't " +
              "budge. It looks like it's stuck.\n");
            return 1;
        }
        return notify_fail("Push what?\n");
    }
    return 0;
}

int do_search(string str)
{
    object pouch;


    if(str == "hole")
    {
        if(!rock_hit)
        {
            return 0;
        }
        else if(!keystone_found)
        {
            pouch = make(OBJECT + "pouch");
            make(OBJECT + "keystone",pouch);
            keystone_found = 1;
            set_alarm(600.0,0.0,"my_reset");
            if(transfer(pouch,TP))
            {
                W("You decide to search the hole. You stick your hand into " +
                  "the compartment and find a pouch that you quickly pull " +
                  "out, but since you can't carry more, you drop it to the " +
                  "floor.\n");
                S(TP->QN + " sticks " + TP->QPO + " hand into the hole in " +
                  "the wall and pulls out a pouch, which " + TP->QPR +
                  " drops on the floor.\n");
            }
            else
            {
                W("You decide to search the hole. You stick your hand into " +
                  "the compartment and find a pouch that you quickly take.\n");
                S(TP->QN+" sticks "+TP->QPO+" hand into the hole in the " +
                  "wall and seems to find something!\n");
            }
            if(!TP->test_flag(QUEST_SUB_FLAG_3))
            {
                TP->add_exp(15000);
                TP->set_flag(QUEST_SUB_FLAG_3);
            }
            return 1;
        }
        else
        {
            W("You stick your hand into the hole, but sadly you don't " +
              "find anything. It looks as if someone else has been here " +
              "before you.\n");
            S(TP->QN + " sticks " + TP->QPO + " hand into the hole in the " +
              "wall, but doesn't find anything.\n");
            return 1;
        }
    }
    if(str == "crates")
    {
        W("The crates have obviously been here a long time and are rotten. " +
          "You don't find anything interseting in them, but you do see " +
          "something strange about the wall behind them...\n");
        return 1;
    }
    return 0;
}

int do_hit(string str)
{
    if(str == "rock")
    {
        if(!rock_hit)
        {
            W("You put all your weight behind the blow and hit the rock as " +
              "hard as you can. It hurts, but the rock budges! It " +
              "disappears into the wall, revealing a small hole!\n");
            S(TP->QN + " hits the rock in the wall as hard as " + TP->QPR +
              " can, and the rock budges, revealing a small hole.\n");
            rock_hit = 1;
            return 1;
        }
        else
        {
            write("There is no rock here that you would like to hit.\n");
            return 1;
        }
    }
    return notify_fail("Hit what?\n");
}

int query_rock_hit(void)
{
    return rock_hit;
}
