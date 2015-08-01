#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A roof in the north part of the castle");
    set_long("You have come out on a roof in the north part of the castle. " +
             "To the east is a lookout tower and to the south, the main " +
             "part of the castle looms over you. To the west and the north " +
             "is a four foot high wall. Beyond the wall is the hundred " +
             "foot drop down the side of the cliff. The river flows by the " +
             "foot of the cliff far below, and the forest down in the " +
             "valley is dark and still. Dark clouds are gathering in the " +
             "skies above you, slowly circling the highest tower of the " +
             "castle to the south.\n");
    set_new_light(5);
    add_property("no_horse");

    add_item("roof","You are on a lookout platform on a roof in the north " +
             "part of the castle");
    add_item("tower","There is a lookout tower and a high tower nearby");
    add_item("lookout tower","The lookout tower is to th east. An archway " +
             "leads inside");
    add_item("archway","It leads inside the tower to the east");
    add_item("high tower","A thin, black tower. The dark clouds above the " +
             "castle seem to circle the tower. It looks eerie");
    add_item("wall","A wall that is just high enough to keep people from " +
             "blowing off the roof");
    add_item("drop|side|cliff","The cliff falls almost straight down, " +
             "hundreds of feet down into the river flowing straight past " +
             "it's foot. You feel dizzy looking down there");
    add_item("river|forest|foot|valley","Vertigo hits you like a ton of " +
             "bricks as you lean out over the wall. You lean back again " +
             "and decide you aren't really interested in looking down there");
    add_item("cloud|clouds","Dark, threatening clouds slowly circling the " +
             "thin tower to the south");

    add_exit(ROOM + "lev3_tower","east");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_sentry",1);
}
