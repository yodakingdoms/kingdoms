#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

int rope_tied;

void create_object(void);
void reset(int arg);
void init(void);
int do_climb(string str);
int do_sit(string str);
int query_rope_tied(void);

void create_object(void)
{
    set_short("A cliffside balcony (s)");
    set_long("A small outcropping in the side of a sheer cliff. There is a " +
             "railing made of wood around the edge and a small bench next " +
             "to the wall by the opening. This balcony is on the south side " +
             "of a secluded cove that stretches far into the island to the " +
             "east. The cliff wall on the other side is just as steep as " +
             "the one on this side. The water splashes high below you as " +
             "the waves roar into the cove from the sea to the west and " +
             "break upon the sharp rocks down there. Green vines grow on " +
             "the cliff wall behind you and hang down to partially cover " +
             "the opening.\n");
    set_new_light(5);

    add_item("outcropping|small outcropping","It forms a sort of natural " +
             "balcony in the side of the cliff");
    add_item("balcony","It does not look as if anyone has built it, it has " +
             "been shaped by nature");
    add_item("nature","Isn't nature brilliant?");
    add_item("cliff|sheer cliff|cliffs|sheer cliffs","The cliffs on both " +
             "sides of the cove plunge straight down into the water. It " +
             "might be possible to climb down, but the cliff is so steep " +
             "it won't be easy");
    add_item("railing|wooden railing","A wooden railing around the edge of " +
             "the outcropping. It looks pretty sturdy and strong");
    add_item("edge","There's a wooden railing going around it. The railing " +
             "is probably nice to have here if you're a drunk pirate");
    add_item("bench","A small, wooden bench. Nice to sit on if you're " +
             "trying to get over a hangover probably");
    add_item("cove|secluded cove|narrow cove","A narrow cove stretching " +
             "quite far into the island to the east");
    add_item("island|newbie island|Newbie Island","It is Newbie Island");
    add_item("wall|cliff wall|walls|cliff walls","Both cliff walls plunge " +
             "steeply into the raging waters below");
    add_item("water|waters","It splashes high into the air when it crashes " +
             "into the narrow cove and breaks upon the rocks down by the " +
             "waterline");
    add_item("wave|waves","The waves splash high into the air when they " +
             "crash into the narrow cove and break upon the rocks down by " +
             "the waterline");
    add_item("$|$wave|$waves","You hear the waves roar below you");
    add_item("waterline|rocky waterline","It is rocky");
    add_item("sea","You can make it out some distance to the west");
    add_item("rock|rocks|sharp rock|sharp rocks","Sharp rocks down by the " +
             "waterline");
    add_item("vine|vines|green vine|green vines","Green vines growing on " +
             "the cliff wall to the south. They don't look strong enough " +
             "to climb");
    add_item("opening","An opening that leads into an underground corridor");
    add_item("corridor|underground corridor","You'd have to go south to get " +
             "a better look");

    add_exit(PCROOM + "lev1_se_corridor","south");

    reset(0);
}

void reset(int arg)
{
    add_monster(PCMONSTER + "pirate",1);
}

void init(void)
{
    add_action("do_climb","climb");
    add_action("do_sit","sit");
}

int do_climb(string str)
{
    if(str == "vine" || str == "vines")
    {
        W("The vines don't look strong enough to climb.\n");
        S(TP->QN + " ponders climbing the vines, but decides " +
          "against it.\n"); //Changed QB to QN 20050614 Angelwings
        return 1;
    }
    else if(str == "down" || str == "cliff" || (rope_tied && str == "rope"))
    {
        if(rope_tied)
        {
            W("You grab the rope and climb down the cliff.\n");
            TP->move_player("grabs the rope, jumps over the railing " +
                            "and climbs down the cliff",
                            PCROOM + "cove_rocks",
                            "climbs down from above",1);
            return 1;
        }
        else if(TP->query_skill("climb") > 65)
        {
            W("You manage to climb down the cliff.\n");
            TP->move_player("jumps over the railing and climbs down the " +
                            "cliff!",PCROOM + "cove_rocks",
                            "climbs down from above",1);
            return 1;
        }
        else
        {
            W("It's too steep for you to climb. Maybe if you were more " +
              "skilled in climbing, or if there was a rope tied to the " +
              "railing that you could use...\n");
            S(TP->QN + " steps up to the railing and looks down for a " +
              "while.\n");
            return 1;
        }
    }
    return notify_fail("Climb what?\n");
}

int do_sit(string str)
{
    if(str == "bench" || str == "on bench")
    {
        if(TP->query_intoxication() > 0)
        {
            W("You sit down on the bench and try to get over your " +
              "hangover.\n");
            S(TP->QN + " sits down on the bench.\n");
            TP->add_intoxication(-10);
            W("It seems to help!\n");
            return 1;
        }
        else
        {
            W("You are not hung over so you don't really need to sit down " +
              "enjoy some fresh air.\n");
            S(TP->QN + " looks a the bench, pondering.\n");
            return 1;
        }
    }
    return notify_fail("Sit on what?\n");
}

/**
* Called by the standard ropes when tying rope to items.
*/
int tie(string str)
{
    if((str == "railing" || str == "wooden railing") && !rope_tied)
    {
        tell_room(PCROOM + "cove_rocks","The end of a rope falls down " +
                  "from above. The rope is now dangling down from there.\n");
        rope_tied = 1;
        return 1;
    }
    return 0;
}

/**
* Called by ropes when untying.
*/
int untie(void)
{
    if(rope_tied)
    {
        tell_room(PCROOM + "cove_rocks","The rope is pulled up from above.\n");
        rope_tied = 0;
        return 1;
    }
    return 0;
}

int query_rope_tied(void)
{
    return rope_tied;
}
