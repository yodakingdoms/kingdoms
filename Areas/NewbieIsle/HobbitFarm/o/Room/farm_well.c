#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A well on the farm (n)");
    set_long("A small flat lawn in a corner of the farm, where a well " +
             "has been built. The well is built of stone and stands in the " +
             "centre of the lawn. The wooden crank mechanism rises above " +
             "the well and there's a rope with a hook hanging down from it. " +
             "East and south of here is the wooden fence that encircles the " +
             "farm and to the west is a large hill. A huge oak tree grows " +
             "on top of the hill, casting a shadow over the lawn. Thick " +
             "bushes grow on the south side of the lawn.\n");

    set_new_light(5);

    add_item("lawn|flat lawn|small lawn|small flat lawn","A small lawn on " +
             "the farm that seems to be off limits to animals since the " +
             "grass here is not trampled at all");
    add_item("ground","The ground looks a bit different here, it is not " +
             "trampled at all");
    add_item("grass|short grass","The grass here is trimmed short and " +
             "not trampled at all. It seems like this lawn is being taken " +
             "care of for some purpose other than having animals on");
    add_item("corner|secluded corner","This is a secluded corner of the " +
             "farm. Animals don't seem to come here");
    add_item("farm","Most of it is north and west from here");
    add_item("well|stone well|stone","A stone well with a wooden crank. " +
             "It looks a bit small to you, but it would be of normal size " +
             "if you were the size of a hobbit");
    add_item("crank|mechanism|crank mechanism|wooden mechanism|" +
             "wooden crank mechanism","It seems as if it is broken! The " +
             "farmers probably have to go to the river to the east to get " +
             "their water now");
    add_item("rope","A rope that is supposed to be used to sink a bucket " +
             "down into the water. It's not very useful now due to the " +
             "condition of the crank");
    add_item("hook","The bucket is supposed to hang there but it's not " +
             "very useful now due to the condition of the crank");
    add_item("fence","The fence is delicately carved and seems to go round " +
             "the whole farm");
    add_item("hill|large hill|grassy hill","There are windows in the " +
             "side of the hill. It looks like a hobbit house");
    add_item("house|hobbit house","It looks like one. There's no entrance " +
             "to it from this direction");
    add_item("top|top of the hill","A huge oak tree grows there");
    add_item("tree|oak|oak tree|huge tree|huge oak|huge oak tree","It " +
             "towers above you and looks huge even to someone who is not " +
             "the size of a hobbit");
    add_item("shadow","A shadow cast by the huge oak");
    add_item("bush|bushes","Thick bushes with small flowers growing on " +
             "them");
    add_item("flower|flowers|small flower|small flowers","The flowers " +
             "smell nice");
    add_item("%flower|%flowers|%","The smell from the flowers fills your " +
             "nostrils and you feel like all is right with the world");

    add_exit(ROOM + "farm_gate","north");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "butterfly",5);
}
