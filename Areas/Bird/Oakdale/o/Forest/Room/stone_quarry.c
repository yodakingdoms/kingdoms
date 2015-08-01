#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("The stone quarry in a clearing in the forest");
    set_long("You are in a clearing in the forest where you see a hill, or " +
             "rather half a hill. The side of the hill has been dug out, " +
             "leaving a vertical cliffside where a few caves can be seen. " +
             "This must be the old stone quarry where the stones for the " +
             "village houses came from. The forest surrounding the " +
             "clearing is dark and silent. On the ground in front of the " +
             "caves are the remnants of a fireplace. You now see the castle " +
             "loom over the forest to the southeast.\n");
    set_new_light(5);
        
    add_item("clearing","Hmm, try typing 'look'");
    add_item("forest","The forest is dark and silent around you");
    add_item("side|cliffside","An almost vertical cliffside with a few " +
             "caves in it");
    add_item("hill","This hill was probably where the villagers took the " +
             "stones for their houses from. Only half the hill remains " +
             "and facing the clearing is a vertical cliffside with a few " +
             "caves in it");
    add_item("cave|caves","There are three of them here. They look pretty " +
             "dark and uninviting");
    add_item("quarry","This used to be it, but it has been a long time " +
             "since people used it");
    add_item("ground","There are remnants of a fireplace one the ground");
    add_item("remnants|fireplace","There's been a fire burning here " +
             "sometime during the last two days");
    add_item("castle","Dark and sinister it stands there. You get a bad " +
             "feeling looking at it, so you soon turn away");
           
    add_exit(ROOM + "north_road10","east");
    add_exit(ROOM + "dgcave_empty","westcave");
    add_exit(ROOM + "dgcave_small","northwestcave");
    add_exit(ROOM + "dgcave_entrance","northcave");           
}
