#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);

void create_object(void)
{
    set_short("A small clearing in the forest where there is a cottage");
    set_long("You are in a small clearing in the forest. The trees around " +
             "the clearing are very tall, so the clearing lies mostly in " +
             "shadow. Short grass grows on the ground. On the north side " +
             "of the clearing is a small wooden cottage with a stone " +
             "chimney, from which a thin pillar of smoke is rising. The " +
             "clearing is silent and the surrounding forest is dark.\n");
    set_new_light(5);

    add_item("clearing","A small clearing with short, well trimmed grass " +
             "on the ground");
    add_item("tree|trees|oak|oaks","The oaks growing in this part of the " +
             "valley are very old. They are also very tall, and are " +
             "overshadowing most of the clearing");
    add_item("valley","You entered it quite a while ago, didn't you notice?");
    add_item("shadow","You are in the shadow of the trees at the edge of " +
             "the clearing");
    add_item("cottage","A small wooden cottage with a stone chimney. You " +
             "see a light flicker in one of the windows");
    add_item("light|candle","It's a lit candle. Apparently someone is home");
    add_item("smoke|pillar","You conclude that there is a fire lit in the " +
             "fireplace");
    add_item("forest","This part of the forest is very old, it seems");
    add_item("$|$heart|$sound","Nothing can be heard except for the sound " +
             "of your own heart beating");

    add_exit(ROOM + "cottage_path2","southeast");

    (ROOM + "allirias_cottage")->load_doors();
    reset(0);
}
