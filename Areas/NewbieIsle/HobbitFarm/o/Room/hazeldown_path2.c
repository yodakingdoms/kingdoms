#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(string str);
int do_relax(string str);

void create_object(void)
{
    set_short("A path through rolling hills (n/sw)");
    set_long("The well trodden path leads to a small river running through " +
             "the rolling landscape. A stone bridge crosses the river and " +
             "the path continues on the other side. There is a tall hill " +
             "to the northwest and some thick bushes grow the east side of " +
             "the path. In the grass next to the bridge lies a thick log " +
             "that someone has dragged here. In the distance on the other " +
             "side of the river you see a fence, and beyond that some " +
             "buildings. The path goes back to the north.\n");

    set_new_light(5);

    add_item("path|well trodden path","It looks as if it has been used " +
             "for a long time, and like it has been trodden on by many");
    add_item("river|small river","It runs from the northwest to the " +
             "southeast. It does not seem to be in a hurry as it gently " +
             "flows downstream");
    add_item("landscape|rolling landscape","The hills look like they are " +
             "rolling towards the south");
    add_item("hills","There are quite a lot of them, most of them have " +
             "trees growing on top of them");
    add_item("top|tops|top of the hill|top of the hills|tops of the hills",
             "Most of the hills have trees growing there");
    add_item("bridge|stone bridge|old bridge|old stone bridge|sturdy bridge",
             "A stone bridge that looks old and worn but still looks " +
             "sturdy enough to hold your weight. The river is pretty calm, " +
             "maybe that's why it is in a good shape despite being old");
    add_item("hill|tall hill|grassy hill|tall, grassy hill","A tall, grassy " +
             "hill. A small grove of trees grows on top of it");
    add_item("grove|grove of trees|tree|trees","The trees on top of the " +
             "hill grow close together. It almost looks as if they've " +
             "been planted that way");
    add_item("bush|bushes|thick bush|thick bush","Thick bushes with green " +
             "leaves and thorny branches");
    add_item("thorn|thorns","You do not want to get too close to those " +
             "thorns");
    add_item("branch|branches|thorny branch|thorny branches","The branches " +
             "have thorns growing on them. You do not want to get too close");
    add_item("leaf|leaves|green leaf|green leaves","The leaves have a " +
             "strange shape, you don't recognise these bushes from anywhere " +
             "else");
    add_item("shape|strange shape","They're shaped differently from any " +
             "other leaves you've seen on bushes before");
    add_item("east side","Thick bushes grow there, preventing you from " +
             "leaving the path in that direction");
    add_item("grass|tall grass","The grass is tall and sways gently in the " +
             "wind");
    add_item("log|thick log","It has been chopped down elsewhere and " +
             "dragged here by someone. It looks as if it has been used for " +
             "sitting on and relaxing by the river");
    add_item("fence","It seems to go quite some distance to the north and " +
             "to the south");
    add_item("building|buildings","From this distance it looks like a farm " +
             "but it's hard to tell. Maybe if you went further west?");
    add_item("farm","It does look like one, but from this distance you " +
             "can't be sure");
    add_item("$","You hear the soothing sound of running water from the " +
             "river");
    add_item("%|%bush|%bushes|%smell|%sweet smell|%strange smell|" +
             "%strange, sweet smell","A strange, sweet smell comes from " +
             "the bushes");

    add_exit(ROOM + "hazeldown_path1","north");
    add_exit(ROOM + "hazeldown_path3","southwest");

    add_sounds(30,10,({ "The grass around you sways gently in the wind.\n",
                        "You hear the sound of running water from the river.\n"
                     }));
}

void init(string str)
{
    add_multi_action("do_relax","relax|sit|rest");
    ::init();
}

int do_relax(string str)
{
    W("You sit down on the log for a while, watching the river flow by " +
      "to the southeast. You stand up after a while, reinvigorated.\n");
    S(TP->QN + " sits down on the log and relaxes for a while.\n");
    return 1;
}
