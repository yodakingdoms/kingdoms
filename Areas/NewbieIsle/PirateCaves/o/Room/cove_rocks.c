#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

int hook_found;

void create_object(void);
string long_fun(void);
void my_reset(void);
void init(void);
int do_search(string str);
int do_swim(string str);
int do_climb(string str);
int query_rope_tied(void);

void create_object(void)
{
    set_short("Rocks by the waterline");
    set_long("#long_fun");
    set_new_light(5);
    set_skip_obvious(1);

    add_item("rock|rocks","Rocks down by the waterline in the cove");
    add_item("waterline","It's very rocky");
    add_item("cove","It stretches far into the island to the east, you " +
             "can't see where it ends from here");
    add_item("cliff|cliffs","The cliffs on both sides rise steeply into " +
             "the air above you");
    add_item("wave|waves","High waves coming in from the ocean to the " +
             "west");
    add_item("ocean","It lies west of here");
    add_item("water|seawater|cold seawater","Cold seawater");
    add_item("debris","It doesn't look like a shipwreck, instead it looks " +
             "like someone's been amusing themselves by throwing wooden " +
             "boxes down here from the outcropping above you. Maybe you " +
             "could find something interesting if you searched the debris?");
    add_item("box|boxes","They are all broken");
    add_item("shore|sandy shore","It's on the same side of the water as " +
             "the rocks you are standing on. Maybe you could try swimming " +
             "there? You'd better be a good swimmer if you try though");
    add_func_item("outcropping|balcony","#query_rope_tied",({
                 "An outcropping above you that looks sort of like a " +
                 "balcony. Maybe you could climb up the cliff to get up " +
                 "there?",
                 "An outcropping above you that looks sort of like a " +
                 "balcony. Maybe you could climb up the rope to get up " +
                 "there?"
                }));
    add_func_item("rope","#query_rope_tied",({
                 "",
                 "The rope is dangling in front of you, tied to something " +
                 "up on the balcony. You could climb it to get back up there"
                }));
}

string long_fun(void)
{
    string long_desc = "You stand on some rocks down by the waterline. " +
               "The cove stretches far into the island to the east and the " +
               "cliffs on the sides of the cove tower high above you. " +
               "Waves crash into the rocks around you, splashing you with " +
               "water. The rocks are covered with different kinds of debris " +
               "but it doesn't look like typical shipwreck debris. As you " +
               "look east you think you see a sandy shore on the south " +
               "side of the cove. Above you, you see an outcropping in the " +
               "cliff that looks like kind of like a balcony.";

    if(query_rope_tied())
    {
        long_desc += " A rope hangs down from there, making it possible " +
                     "to climb up.";
    }
    return long_desc + "\n";
}

void my_reset(void)
{
    hook_found = 0;
}

void init(void)
{
    add_action("do_search","search");
    add_action("do_swim","swim");
    add_action("do_climb","climb");
    "/sys/admin/room/admin_room"->visit(1102);
}

int do_search(string str)
{
    object hook;

    if(str == "debris")
    {
        if(!hook_found)
        {
            if(TP->query_skill("perception") > 20 + random(20))
            {
                W("You search through the debris and find a grappling " +
                  "hook!\n");
                S(TP->QN + " searches through the debris and finds a " +
                  "grappling hook!\n");
                // Hook needed for the quest
                hook = make(PCOBJECT + "grappling_hook");
                if(transfer(hook,TP))
                {
                    W("It's too heavy for you to carry, so you drop it.\n");
                    S(TP->QN + " doesn't seem to be able to carry the " +
                      "hook.\n");
                }
                set_alarm(300.0,0.0,"my_reset");
                hook_found = 1;
                return 1;
            }
            else
            {
                W("You search the debris but don't find anything. Maybe " +
                  "you could try again or maybe you need to be more " +
                  "perceptive to find something.\n");
                S(TP->QN + " rummages through the debris for a while.\n");
                return 1;
            }
        }
        else
        {
            W("It looks as if someone else has been searching the debris " +
              "recently.\n");
            S(TP->QN + " rummages through the debris for a while.\n");
            return 1;
        }
    }
    return 0;
}

int do_swim(string str)
{
    if(str == "shore" || str == "to shore")
    {
        if(TP->query_skill("swim") > 40)
        {
            W("You jump into the water and skillfully swim east and " +
              "walk up onto the sandy shore.\n");
            TP->move_player("jumps into the water and swims east",
                            PCROOM + "cove_shore",
                            "swims to the shore from the west and walks " +
                            "up onto the sand",1);
            return 1;
        }
        else
        {
            W("You jump into the water and try to swim east, but you " +
              "quickly loose control and you're swept away!\nYou bump " +
              "your head against a rock! *THUMP*\n");
            TP->add_temporary_penalty(15 + random(10));
            // Beat them up a bit without killing them
            TP->do_spell_damage(TP->query_hp() / 10 +
                                random(TP->query_hp() / 10),
                                ({ "blunt" }));
            W("That hurt!\nThe waves sweep you up onto the shore. " +
              "That was close!\n");
            TP->move_player("jumps into the water and is swept away to the " +
                            "east",
                            PCROOM + "cove_shore",
                            "is swept onto the shore from the west",1);
            return 1;
        }
    }
    return notify_fail("Swim where?\n");
}

int do_climb(string str)
{
    if(str == "up" || str == "cliff")
    {
        if(TP->query_skill("climb") > 40)
        {
            W("You climb the cliff with ease.\n");
            TP->move_player("climbs up the cliff",
                            PCROOM + "lev1_balcony",
                            "comes climbing up the cliff from below",1);
            return 1;
        }
        else
        {
            if(!query_rope_tied())
            {
                W("The cliff is too high and steep for you to be able to " +
                  "climb it. Maybe you could do it if there was a rope " +
                  "tied to the balcony or if you were more skillful in " +
                  "climbing.\n");
            }
            else
            {
                W("The cliff is too high and steep for you to be able to " +
                  "climb it. It would probably be easier to climb the " +
                  "rope.\n");
            }
            S(TP->QN + " looks at the cliff for a moment, contemplating.\n");
            return 1;
        }
    }
    else if(str == "rope" && query_rope_tied())
    {
        W("You climb the rope with ease.\n");
        TP->move_player("climbs up the rope",
                        PCROOM + "lev1_balcony",
                        "comes climbing up the rope from below",1);
        return 1;
    }
    return notify_fail("Climb what?\n");
}

int query_rope_tied()
{
    return (PCROOM + "lev1_balcony")->query_rope_tied();
}
