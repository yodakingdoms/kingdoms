#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_sit(string str);

void create_object(void)
{
    ::create_object();
    set_short("A barn (u/e)");
    set_long("The bottom floor of a big barn. The floor here is covered " +
             "with damp hay. There are a few wooden stalls by the walls, " +
             "each one containing a wooden trough. A bale of hay stands " +
             "near the doorway out onto the yard and there's a pitchfork " +
             "leaned against the wall next to it. Narrow wooden stairs go " +
             "up to the floor above. A few buckets are standing in a neat " +
             "row lined against the back wall and in one of the stalls is " +
             "a small stool.\n");

    add_item("bottom floor","It is below the second floor");
    add_item("second floor|floor above","It is above the bottom floor");
    add_item("floor","It is covered with damp hay, it smells pretty bad");
    add_item("%|%floor|%hay|smell|%smell","It smells like a substance that " +
             "comes out of cows when the cows are done with it");
    add_item("hay|damp hay","You don't think the dampness is just water, " +
             "but that there's something else there too. You base this " +
             "on the smell rising from the floor");
    add_item("stall|stalls|wooden stall|wooden stalls","Places where the " +
             "farmer puts the cows when he wants them in the barn");
    add_item("barn|big barn","It would be big for someone the size of a " +
             "hobbit. From your perspective, it really isn't very big");
    add_item("wall|walls","The walls are made of wood");
    add_item("wood","That's what the walls and the stalls are made of");
    add_item("trough|troughs|wooden trough|wooden troughs","There's one " +
             "in each stall. That's where food for the cows is placed " +
             "when it's time to feed them");
    add_item("food","There's no food in the troughs right now");
    add_item("bale|bale of hay","It's probably standing here instead of " +
             "on the second floor so that it will be near when it is needed " +
             "down here");
    add_item("doorway","It's pretty big, it practically takes up the " +
             "whole wall");
    add_item("yard","You can see the yard outside the doorway");
    add_item("pitchfork","It stands against the wall. Maybe it was left " +
             "there the last time someone put hay on the floor here?");
    add_item("stair|stairs|wooden stair|wooden stairs|narrow wooden stair|" +
             "narrow wooden stairs","Narrow wooden stairs, they're so steep " +
             "they look more like a ladder than stairs");
    add_item("ladder","It's not so steep you will have any problems going " +
             "up");
    add_item("bucket|buckets|small bucket|small buckets","Small buckets " +
             "that look like they're nice hobbit size buckets");
    add_item("hobbit size bucket|hobbit size buckets","They're a bit small " +
             "for someone your size");
    add_item("row|back wall","A neat row of buckets is lined up against " +
             "the back wall");
    add_item("stool|small stool","The kind of stool one sits on when " +
             "milking a cow. This one is a bit small though");
    add_item("ceiling","Wooden beams hold up the planks that form the " +
             "ceiling");
    add_item("beam|beams|wooden beam|wooden beams","Looking at the beams " +
             "you get a reassuring feeling. You feel quite safe standing " +
             "under the ceiling when those beams are holding it up");
    add_item("plank|planks","Some of them seem to have been replaced " +
             "recently while others seem to have been in place for a long " +
             "time. None of them look particularily interesting though");

    add_exit(ROOM + "farm_west","east");
    add_exit(ROOM + "farm_barn_floor2","up");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "cow",3);
}

void init(void)
{
    add_action("do_sit","sit");
}

int do_sit(string str)
{
    if(str == "stool" || str == "on stool")
    {
        W("You sit down on the stool for a while. You have more important " +
          "things to do than to start milking or anything like that " +
          "though.\n");
        S(TP->QN + " sits down on the stool for a short while.\n");
        return 1;
    }
    return notify_fail("Sit on what?\n");
}
