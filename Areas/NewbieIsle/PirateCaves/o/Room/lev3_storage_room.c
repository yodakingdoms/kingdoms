#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

int sail_found;

void create_object(void);
void my_reset(void);
void init(void);
int do_listen(string str);
int do_search(string str);

void create_object(void)
{
    ::create_object();
    set_short("A storage room (s)");
    set_long("A cold storage room with many wooden shelves. Stacked on the " +
             "shelves are many sails of different sizes and shapes. Most of " +
             "the sails seem to be in a pretty bad shape. The air here is " +
             "very damp and the sound of water can be heard from the south. " +
             "Some barrels stand in a corner but they seem to be rotten and " +
             "useless.\n");

    add_item("room|cold room|storage room|cold storage room","It seems to " +
             "be used for storing sails");
    add_item("shelf|shelves|wooden shelf|wooden shelves","There are many " +
             "sails on them");
    add_item("sail|sails","Most of them seem to be in a pretty bad shape " +
             "but maybe you could find some that are still useable if you " +
             "searched them?");
    add_item("air","The air is very damp");
    add_item("barrel|barrels|rotten barrel|rotten barrels","The barrels " +
             "all seem to be rotten, probably from standing in the damp " +
             "room for too long");
    add_item("corner|corners","There are some barrels in one of the corners");


    add_exit(PCROOM + "lev3_harbour","south");
}

void my_reset(void)
{
    sail_found = 0;
}

void init(void)
{
    add_action("do_listen","listen");
    add_action("do_search","search");
}

int do_listen(string str)
{
    W("You hear the sound of water from the west.\n");
    S(TP->QN + " listens carefully.\n");
    return 1;
}

int do_search(string str)
{
    object sail;

    if(str == "sail" || str == "sails")
    {
        if(TP->query_skill("perception") > 10 + random(10))
        {
            if(!sail_found)
            {
                W("You search through the " + str + " and find one " +
                  "sail that still seems to have some life in it.\n");
                S(TP->QN + " searches the " + str + " and finds a " +
                  "sail.\n");
                sail = make(PCOBJECT + "gaff_sail");
                if(transfer(sail,TP))
                {
                    W("You're carrying too much to pick it up so you " +
                      "drop it on the floor.\n");
                    S(TP->QN + " drops it in the floor.\n");
                }
                sail_found = 1;
                set_alarm(300.0,0.0,"my_reset");
            }
            else
            {
                W("It looks like someone has searched the " + str +
                  " already.\n");
                S(TP->QN + " searches through the " + str + " but " +
                  "doesn't seem to find anything.\n");
            }

        }
        else
        {
            W("You search the " + str + " but don't find anything. " +
              "Maybe you have to try again or maybe you're just not " +
              "perceptive enough.\n");
            S(TP->QN + " searches through the " + str + " but doesn't " +
              "seem to find anything.\n");
        }
        return 1;
    }
}