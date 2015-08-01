#pragma strict_types
#include "../def.h"
inherit SHIP_ROOM;

int ship_spotted;
object *lookouts = ({});

void create_object(void);
void my_reset(void);
void init(void);
int do_climb(string str);
int do_spot(string str);
int do_stop_spotting(string str);
void spotting(object lookout);
int query_ship_spotted(void);

void create_object(void)
{
    ::create_object();
    set_short("Crows nest of the Black Skull (n)");
    set_cave_long("You are up in the crows nest of the ship. The ceiling " +
                  "of the cave arcs high above you and the shining stones " +
                  "sparkle like a starlit night sky. You see the deck below " +
                  "you but you're so high up in the mast you get a bit " +
                  "dizzy when you look down so you try not to. You could " +
                  "probably climb down the mast again to get back down to " +
                  "the deck.\n");
    set_sea_long("You are up in the crows nest of the ship. The mast sways " +
                 "violently as the ship rides across the waves of the " +
                 "raging sea but the view from here is great. The sea " +
                 "stretches out around you for miles and the wind blows " +
                 "strong in your face. This would probably be a good place " +
                 "to try and use a looking glass to spot a ship to " +
                 "plunder.\n");
    set_attacking_long("You are up in the crows nest of the ship. The ship " +
                       "is next to the ship you are attacking. As you look " +
                       "to the starboard side you see a shivering little " +
                       "lookout sit in the crows nest of that ship, almost " +
                       "level with you. Your counterpart is watching the " +
                       "horrible scenes on the deck below him with fear in " +
                       "his eyes. As you look out across the sea you see " +
                       "nothing but water so it does not look as if you're " +
                       "going to be disturbed while plundering the ship.\n");
    set_skip_obvious(1);

    add_item("nest|crows nest","A place up in the mast where the lookout " +
             "sits");
    add_func_item("ceiling","#query_location",({ "It arcs high above you" }));
    add_func_item("cave","#query_location",({
                  "It is big enough to fit a ship in"
                  }));
    add_func_item("stone|stones|shining stone|shining stones",
                  "#query_location",({
                  "They shine like stars in a night sky above you" }));
    add_func_item("star|stars","#query_location",({
                  "They look like stars, but they're really just shining " +
                  "stones"
                 }));
    add_item("deck","It's far below you. You'd probably feel safer if you " +
             "were to climb down there");
    add_item("mast","You could climb the mast down to the deck if you " +
             "wanted to");
    add_func_item("wave|waves","#query_location",({
                  "",
                  "The waves are high and scary",
                  "The waves are high and scary"
                 }));
    add_func_item("sea|raging sea","#query_location",({
                  "",
                  "The sea rages around you",
                  "The sea rages around you"
                 }));
    add_func_item("view|great view","#query_location",({
                  "",
                  "You could probably spot ships pretty far from you from " +
                  "up here if you had a looking glass",
                  ""
                 }));
    add_func_item("ship","#query_location",({
                  "Most of it is below you",
                  "You don't see one now. Maybe if you tried spotting one?",
                  "Most of it is below you"
                 }));
    add_func_item("lookout|counterpart","#query_location",({
                  "",
                  "",
                  "He looks really scared, and seems to be praying noone " +
                  "comes climbing up the mast to get him!"
                 }));
    add_func_item("scenes|horrible scenes|battle","#query_location",({
                  "",
                  "",
                  "A battle is taking place on the deck of the other ship"
                 }));
    add_func_item("water","#query_location",({
                  "",
                  "Water, water everywhere, nor any drop to drink",
                  "Water, water everywhere, nor any drop to drink"
                 }));
}

void my_reset(void)
{
    ship_spotted = 0;
}

void init(void)
{
    add_action("do_climb","climb");
    add_multi_action("do_spot","look|spot|use");
    add_action("do_stop_spotting","",1);
}

int do_climb(string str)
{
    if(str == "down" || str == "mast")
    {
        W("You climb down the mast.\n");
        TP->move_player("climbs down the mast",
                        PCROOM + "black_skull_deck",
                        "comes climbing down the mast",1);
        return 1;
    }
    return notify_fail("Climb where?\n");
}

int do_spot(string str)
{
    if((query_verb() == "look" && str == "for ship") ||
       (query_verb() == "spot" && str == "ship") ||
       (query_verb() == "use" && (str == "glass" || str == "looking glass")))
    {
        if(!SHIP_OBJ->query_sail_raised())
        {
            W("No point in looking for ships to plunder until the " +
              "gaff sail is raised so you can catch up with them.\n");
            return 1;
        }
        if(ship_spotted)
        {
            W("The ship you're after has already been spotted.\n");
            return 1;
        }
        if(present("_pirate_quest_looking_glass_",TP))
        {
            if(SHIP_OBJ->query_is_at_sea())
            {
                W("You start using the looking glass to try and spot the " +
                  "ship you're after.\n");
                S(TP->QN + " starts looking at the sea around you through " +
                  "the looking glass.\n");
                lookouts += ({ TP });
                set_alarm(5.0 + itof(random(5)),0.0,"spotting",TP);
                return 1;
            }
            else
            {
                W("There's no point in looking for a ship to plunder " +
                  "before this ship is at sea.\n");
                return 1;
            }
        }
        W("You need to be holding a looking glass to do that.\n");
        return 1;
    }
    if(query_verb() == "spot")
    {
        return notify_fail("Spot what?\n");
    }
    else if(query_verb() == "use")
    {
        return notify_fail("Use what?\n");
    }
    // Don't want to catch 'look' here
}

int do_stop_spotting(string str)
{
    if(member_array(TP,lookouts) != -1)
    {
        W("Looking for ships takes all your concentration so you stop " +
          "doing that to focus on doing something else.\n");
        lookouts -= ({ TP });
    }
}

void spotting(object lookout)
{
    if(member_array(lookout,lookouts) != -1)
    {
        set_this_player(lookout);
        if(!SHIP_OBJ->query_sail_raised())
        {
            W("The gaff sail should be raised before it's time to start " +
              "looking for a ship to plunder.\n");
            return;
        }
        if(!ship_spotted)
        {
            W("You look out across the sea, trying to spot a ship...\n");
            // +20 comes from the looking glass
            if(TP->query_skill("perception") + 20 >= random(100))
            {
                W("You spot a ship!\n");
                S(TP->QN + " exclaims: There it is! I must tell the " +
                  "captain!\n");
                SHIP_OBJ->tell_black_skull_rooms(TP->QN + " yells: Ship " +
                                                 "ahoy, she lies off the " +
                                                 "starboard bow, aarr!\n");
                W("'Aarr'? Maybe you've been around the captain for too " +
                  "long.\n");
                SHIP_OBJ->tell_black_skull_rooms("Captain Jack shouts: " +
                                                 "Excellent, arr!\n");
                SHIP_OBJ->tell_black_skull_rooms("The ship turns in the " +
                                                 "direction of your prey " +
                                                 "and starts catching up " +
                                                 "with it!\n");
                ship_spotted = 1;
            }
            else
            {
                set_alarm(5.0 + itof(random(5)),0.0,"spotting",TP);
            }
        }
        else
        {
            W("The ship has been spotted so you stop looking out across " +
              "the sea. There are probably more important things to be " +
              "done now!\n");
            lookouts -= ({ TP });
        }
    }
}

int query_ship_spotted(void)
{
    return ship_spotted;
}

