#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_west(string str);

void create_object(void)
{
    set_short("A cave behind the waterfall");
    set_long("You are in a cave behind the waterfall. The gray walls of the " +
             "cave are rough and uneven, and water is dripping from the " +
             "ceiling, forming small puddles on the floor. The waterfall " +
             "creates a curtain covering the opening to the east, as it " +
             "tumbles down into the pond with a deafening roar. Some light " +
             "manages to seep through the curtain, creating strange, " +
             "beautiful light effects in the cave. The cave continues to " +
             "the west, and you can follow the ledge back out into the " +
             "clearing.\n");
    set_new_light(1);
        
    add_item("cave","A cave with rough stone walls, floor and ceiling");
    add_item("waterfall|curtain","The water falls down into the pond " +
             "outside the cave, creating a curtain covering the mouth of " +
             "the cave");
    add_item("opening|mouth","You can leave the cave through it");
    add_item("wall|walls","Rough stone walls");
    add_item("water","Water is dripping from the ceiling, forming small " +
             "puddles on the floor");
    add_item("ceiling","A rough stone ceiling. Water is seeping through it " +
             "and dripping onto the floor, forming small puddles");
    add_item("puddles","Puddles of water dripping from the ceiling");
    add_item("light|effects","The light is diverted as it passes through " +
             "the waterfall, creating enchanting, moving patterns of light " +
             "and shadow on the walls of the cave");
    add_item("shadow|patterns","Beautiful hypnotic patterns. You could " +
             "fall asleep if you would look at them for too long");
    add_item("ledge","The ledge will take you back out into the clearing");
    add_item("$|$roar|$waterfall","You can't hear anything over the " +
             "deafening roar of the waterfall");

    add_sounds(05,80,({ "The waterfall roars majestically as it tumbles " +
                        "down into the pond outside.\n",
                        "The light coming through the waterfall dances " +
                        "enchantingly on the walls of the cave.\n" }));

    add_exit(ROOM + "waterfall","out");
    add_exit(ROOM + "wfallcave_tunnel1","west");
}

void init(void)
{
    add_action("do_west","west");
    add_action("do_west","w");
    ::init();
}

int do_west(string str)
{
    W("You walk further into the cave, leaving the roar of the waterfall " +
      "behind you.\n");
    return 0;
}
