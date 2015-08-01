//======================================================================
// This thing is inherited by the different treasures used for making
// the scarecrow
//======================================================================
#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void init(void);
int do_build(string str);

void init(void)
{
    add_multi_action("do_build","build|make");
}

int do_build(string str)
{
    object carrot = present("_scarecrow_quest_carrot_",TP),
           hay = present("_scarecrow_quest_hay_",TP),
           pumpkin = present("_scarecrow_quest_pumpkin_",TP),
           scarecrow;

    if(str == "scarecrow")
    {
        if(!carrot || !hay || !pumpkin)
        {
            W("You don't have everything you need to build a scarecrow. " +
              "You need enough hay to make the body, a suitable pumpkin " +
              "for the head and a suitable carrot for the nose.\n");
            return 1;
        }
        else if(!ENV(TP)->query_is_quest_shed())
        {
            W("You need to find a place where there are appropriate tools " +
              "for the job before you can make a scarecrow.\n");
            return 1;
        }
        W("You grab a rake and break it into sticks. You tie them " +
          "together with a leather strap you get from a hook on the " +
          "wall. You tie the hay to the frame and stick the pumpkin on " +
          "top of it. As a finishing touch, you stick the carrot into " +
          "the pumpkin to make a nose. You've just made a scarecrow!\n");
        S(TP->QN + " breaks a rake into twigs and grabs a leather " +
          "strap to tie them together, ties some hay to the frame, sticks " +
          "a pumpkin on top and, as a finishing touch, sticks a carrot " +
          "into the pumpking to make a nose.\n" + TP->QN + " has just " +
          "made a scarecrow!\n");
        scarecrow = make(OBJECT + "scarecrow",ENV(TP));

        // Things mess up here if we just destroy them, one item stays
        // in inventory sometimes, not always. So we use a junk room
        // where they're destroyed with a short delay instead so this
        // function has time to do what it's supposed to first
        transfer(carrot,ROOM + "dest_room");
        transfer(hay,ROOM + "dest_room");
        transfer(pumpkin,ROOM + "dest_room");

        if(transfer(scarecrow,TP))
        {
            W("It is too heavy for you to carry though.\n");
            S(TP->QN + " doesn't seem to be able to carry the " +
              "scarecrow.\n");
        }
        return 1;
    }
    return notify_fail(C(query_verb()) + " what?\n");
}
