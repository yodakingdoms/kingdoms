#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_WATER;

int looking_glass_found;

void create_object(void);
void my_reset(void);
string long_fun(void);
void init(void);
int do_search(string str);
int query_ship_at_sea(void);

void create_object(void)
{
    set_short("Underwater");
    set_long("#long_fun");

    add_property("indoors");
    add_property("under_water");
    set_new_light(1);
    set_skip_obvious(1);

    add_item("water","The water is clear even though there is plenty " +
             "of seaweed growing here");
    add_item("lagoon|underground lagoon","You are swimming under the " +
             "surface of the lagoon");
    add_item("surface","It is above you");
    add_item("seaweed","It grows from the bottom. Be careful that you " +
             "don't get stuck in it and drown");
    add_item("bottom","Plenty of seaweed grows here");
    add_func_item("hull|ship","#query_ship_at_sea",({
             "The hull of the ship towers above your head. You see the " +
             "remains of an unfortunate soul tied to a rope running " +
             "under the keel of the ship"
            }));
    add_func_item("remains|skeleton|grinning skeleton",
             "#query_ship_at_sea",({
             "Probably the remains of some unfortunate soul who did " +
             "something bad enough to be punished by being keelhauled. " +
             "You wonder if you would find something interesting if " +
             "you searched it"
            }));
    add_func_item("rope","#query_ship_at_sea",({
             "A thick rope running from one side of the ship, under the " +
             "keel and up the other side"
            }));
    add_func_item("keel","#query_ship_at_sea",({
             "A part of the ship that helps keep it upright"
            }));
    add_item("fish|school|schools|small school|small schools","They're " +
             "darting around in the water close to the seaweed");

    add_exit(PCROOM + "lev3_harbour_water","up");
    above = PCROOM + "lev3_harbour_water";
}

void my_reset(void)
{
    looking_glass_found = 0;
}

string long_fun(void)
{
    if(!query_ship_at_sea())
    {
        return "You are swimming under the water in the underground lagoon. " +
               "The water is clear but plenty of seaweed grows on the " +
               "bottom and stretches up around you, if you're not careful " +
               "you could get stuck. Small schools of fish are swimming " +
               "around in the seaweed. The hull of the ship is right above " +
               "you and tied to a rope running under the keel is a grinning " +
               "skeleton! You'd better not stay down here for too long " +
               "without going back up to the surface to catch your breath " +
               "if you don't want to drown.\n";
    }
    else
    {
        return "You are swimming under the water in the underground lagoon. " +
               "The water is clear but plenty of seaweed grows on the " +
               "bottom and stretches up around you, if you're not careful " +
               "you could get stuck. Small schools of fish are swimming " +
               "around in the seaweed. You'd better not stay down here " +
               "for too long without going back up to the surface to " +
               "catch your breath if you don't want to drown.\n";
    }
}

void init(void)
{
    add_action("do_search","search");
    ::init();
}

int do_search(string str)
{
    object looking_glass;

    if(!query_ship_at_sea() &&
       (str == "remains" || str == "skeleton" || str == "grinning skeleton"))
    {
        if(!looking_glass_found)
        {
            W("The skeleton has a looking glass stuck in its belt. You take " +
              "it.\n");
            S(TP->QN + " searches the skeleton and finds a looking glass.\n");
            looking_glass = make(PCOBJECT + "looking_glass");
            if(transfer(looking_glass,TP))
            {
                W("You can't carry it, so it floats to the bottom.\n");
                S(TP->QN + " drops the looking glass and it floats to the " +
                  "bottom.\n");
            }
            looking_glass_found = 1;
            set_alarm(300.0,0.0,"my_reset");
            return 1;
        }
        else
        {
            W("You don't find anything, looks like someone's been here " +
              "before you.\n");
            S(TP->QN + " searches the remains.\n");
            return 1;
        }
    }
}

int query_ship_at_sea(void)
{
    return SHIP_OBJ->query_is_at_sea();
}
