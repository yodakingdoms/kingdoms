#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_listen(string str);

void create_object(void)
{
    set_short("The shore of a pond and the foot of a waterfall");
    set_long("You have come out of the forest and stand at the foot of a " +
             "high waterfall. The river falls down the steep side of the " +
             "ravine and cascades down into a small pond, before it " +
             "continues to flow eastwards. The rumble is almost deafening " +
             "and the air is filled with drizzle. A few small rainbows can " +
             "be seen whenever sunlight seeps through the canopies of the " +
             "trees at the edge of the ravine and enters the damp air. " +
             "Behind the curtain of the waterfall you see the entrance to " +
             "a cave. A narrow ledge in the cliff wall will take you " +
             "there.\n");
    set_new_light(5);
    
    add_item("forest","It is a forest of oak trees. It is dark and " +
             "uninviting");
    add_item("waterfall","A majestic waterfall comes tumbling down the " +
             "side of the cliff, throwing up a huge cloud of drizzle as it " +
             "falls down into a small pond");
    add_item("river","The river continues it's flow to the east");
    add_item("cliffside|sides|side|ravine","A narrow ravine with steep " +
             "sides");
    add_item("pond","A small forest pond where the water from the fall is " +
             "collected before the river continues to the east");
    add_item("drizzle","The air is filled with it. Your clothes are damp " +
             "and your hair is clinging to your forehead");
    add_item("rainbow|rainbows","A few small rainbows can be seen whenever " +
             "a beam of sunlight enters the damp air");
    add_item("tree|trees","Tall, old oak trees");
    add_item("canopy|canopies","The canopies of the trees are huge and " +
             "majestic");
    add_item("edge","The edge of the ravine is high above you");
    add_item("wall|walls","The walls of the ravine are steep and high");
    add_item("entrance|cave","You can't see what lies inside it from here");
    add_item("ledge","You could easily enter the cave by walking out on " +
             "the ledge behind the waterfall");
    
    add_sounds(05,70,({ "The waterfall roars majestically as it comes " +
                        "tumbling down the side of the ravine.\n",
                        "Your damp hair clings to your forehead.\n" })); 

    add_exit(ROOM + "river_path4","northup");
    add_exit(ROOM + "wfallcave_entrance","ledge");    
}

void init(void)
{
    add_action("do_listen","listen");
    SYS_ADMIN->visit(299);
    ::init();
}

int do_listen(string str) 
{
    W("The loud rumbling of the waterfall prevents you from hearing " +
      "anything else.\n");
    S(TP->QN + " listens carefully.\n");
    return 1;
}
