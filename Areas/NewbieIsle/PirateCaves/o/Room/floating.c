// ========================================================================
// This is where players go when they walk a plank from one of the ships
// (either to abort the quest or to get back if left behind on the captured
// ship) and float back to the island.
// ========================================================================
#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
void float_ashore(object player);
int do_anything(string str);
int dump_inventory(void);

void create_object(void)
{
    set_short("Floating in the sea");
    set_long("You are clinging on to a chair, trying to stay afloat on " +
             "the raging sea. The skies above you are gray and the waves " +
             "around you are high.\n");
    set_skip_obvious(1);
    set_new_light(10);
    add_property("no_horse");
    add_property("no_steal");
    add_property("no_fight");
    add_property("no_special");

    add_item("chair|wooden chair","A wooden chair that someone was kind " +
             "enough to throw down to you after you walked the plank");
    add_item("sea|raging sea","It is raging above you");
    add_item("skies|gray skies","They are gray, the clouds are dark");
    add_item("cloud|clouds|dark cloud|dark clouds","They are dark");
    add_item("wave|waves|high wave|high waves","They are high");
}

void init(void)
{
    if(present("_pirate_caves_floating_obj_",TP))
    {
        add_action("do_anything","",1);
    }
    else
    {
        set_alarm(1.0,0.0,"float_ashore",TP);
    }
}

void float_ashore(object player)
{
    tell_object(player,"Completely exhausted, you are washed ashore on a " +
                "beach on a small island.\n");
    player->move_player("x",SHORE);
    tell_room(ENV(player),player->QN + " is washed up on the shore by the " +
              "waves.\n",player);
}

int do_anything(string str)
{
    if(query_verb() == "glance" || query_verb() == "l" ||
       query_verb() == "look" || query_verb() == "examine" ||
       query_verb() == "tell" || query_verb() == "quit" ||
       TP->query_level() >= LEVELS_NEWBIE)
    {
        return 0;
    }
    W("You are too busy clinging on to the chair trying to stay afloat...\n");
    return 1;
}

int dump_inventory(void)
{
    return 1;
}