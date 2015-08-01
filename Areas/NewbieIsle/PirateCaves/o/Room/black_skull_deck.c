#pragma strict_types
#include "../def.h"
inherit SHIP_ROOM;
inherit MOD_DOOR;

int sail_raised,rope_thrown;

void create_object(void);
string long_fun(void);
void my_reset(void);
void init(void);
int do_board(string str);
int do_disembark(string str);
int do_climb(string str);
int do_walk(string str);
int do_raise(string str);
int query_sail_raised(void);
int query_rope_thrown(void);

void create_object(void)
{
    ::create_object();
    set_short("The deck of the Black Skull (n)");
    set_long("#long_fun");

    add_item("deck","It is the deck of the Black Skull");
    add_item("mast|masts","They rise high above you. You could probably " +
             "climb up there if you wanted to");
    add_item("railing|wooden railing","A wooden railing going around the " +
             "deck, designed to prevent people to fall in");
    add_item("ropes","Ropes going up into the rigging");
    add_item("aft|part|aft part|back part|back","It's the back part of " + 
             "the ship");
    add_item("ladder|ladders|rope ladder|rope ladders","It would be easy " +
             "to climb a mast using one of them");
    add_item("rigging","It is up there in the masts");
    add_item("pair|stair|stairs","A pair of stairs going up to the part " +
             "of the deck where the rudder is");
    add_item("rudder","You'd have to walk up the stairs to see it");
    add_item("opening","There's a plank placed there");
    add_item("port side","A plank is placed in an opening in the railing on " +
             "that side");
    add_item("plank|wooden plank","A wooden plank. You could walk it to get " +
             "off the ship but you probably wouldn't be able to come back " +
             "and who knows where you'd end up, or if you'd even survive");
    add_func_item("sail|sails","#query_location",({
                  "The sails are furled at the moment",
                  "The sails are unfurled and filled by the wind",
                  "The sails are unfurled and filled by the wind"
                 }));
    add_func_item("cave|huge cave","#query_location",({
                  "The cave is huge! You can <disembark> the ship " +
                  "to get back there"
                 }));
    add_func_item("wind","#query_location",({
                  "",
                  "You can't see it but it's filling the sails",
                  "You can't see it but it's filling the sails"
                 }));
    add_func_item("gaff sail","#query_sail_raised",({
                  "",
                  "It is raised and filled by the wind"
                 }));
    add_func_item("rope","#query_rope_thrown",({
                  "",
                  "It's tied to the railing and hooked to the railing of " +
                  "the other ship. You could board the ship using the rope"
                 }));
    add_func_item("another ship|other ship","#query_location",({
                  "",
                  "",
                  "It's the ship currently under attack by the Black Skull"
                 }));

    add_func_item("crack|huge crack","#query_location",({
                  "A huge crack, big enough to sail a ship through"
                 }));

    add_exit(PCROOM + "black_skull_aft_deck","eastup");
    add_exit(PCROOM + "black_skull_forecastle","west");

    (PCROOM + "black_skull_cabin")->load_doors();
    (PCROOM + "black_skull_below_deck")->load_doors();
    reset(0);
}

string long_fun(void)
{
    string desc = "The deck of the Black Skull. Two masts rise high above " +
                  "you and a railing goes round the deck on both sides. " +
                  "There are many ropes and rope ladders hanging down from " +
                  "the rigging. ";

    if(query_location() == 0)
    {
        desc += "The sails in the masts above you are furled. ";
    }
    else if(query_location() == 1)
    {
        desc += "The sails in the masts above you are unfurled and filled " +
                "by the wind. ";
    }

    if(!sail_raised)
    {
        desc += "The gaff sail seems to be missing completely, however. " +
                "Maybe you could raise it if you had it. ";
    }

    desc += "There's a pair of stairs going up to the aft part of the " +
            "deck where the rudder is. There's an opening in the railing " +
            "on the port side of the ship where a wooden plank is placed, " +
            "going out into nowhere. ";

    if(rope_thrown)
    {
        desc += "A rope has been thrown out over to the other ship. You " +
                "could use it to board the ship if you wanted to. ";
    }

    if(query_location() == 0)
    {
        desc += "The cave arcs high above you and you see the sea outside " +
                "the huge crack to the west. ";
    }
    else if(query_location() == 1)
    {
        desc += "The gray sea rages around the ship. ";
    }
    else
    {
        desc += "On the starboard side is the ship you are attacking. ";
    }

    return desc + "\n";
}

void my_reset(void)
{
    sail_raised = 0;
    rope_thrown = 0;
}

void init(void)
{
    add_action("do_board","board");
    add_action("do_disembark","disembark");
    add_action("do_climb","climb");
    add_action("do_walk","walk");
    add_action("do_raise","raise");
    add_action("do_throw","throw");
    "/sys/admin/room/admin_room"->visit(1100);
    ::init();
}

int do_board(string str)
{
    if(SHIP_OBJ->query_rope_thrown())
    {
        if(str == "ship")
        {
            W("You climb the rope over to the other ship.\n");
            TP->move_player("climbs the rope and boards the other ship",
                            PCROOM + "riaa_deck",
                            "comes climbing the rope from the Black Skull",
                            1);
            return 1;
        }
        notify_fail("Board what?\n");
    }
}

int do_disembark(string str)
{
    if(!SHIP_OBJ->query_is_at_sea())
    {
        W("You walk down the gangway and disembark the ship.\n");
        TP->move_player("walks down the gangway and disembarks the ship",
                        PCROOM + "lev3_harbour",
                        "comes walking down the gangway, disembarking " +
                        "the ship",1);
        return 1;
    }
}

int do_climb(string str)
{
    if(str == "up" || str == "mast" || str == "ladder" || str == "rope ladder")
    {
        W("You climb up the mast.\n");
        TP->move_player("climbs up the mast",
                        PCROOM + "black_skull_crows_nest",
                        "comes climbing up the mast",1);
        return 1;
    }
    return notify_fail("Climb where?\n");
}

int do_walk(string str)
{
    if(SHIP_OBJ->query_is_at_sea())
    {
        if(str == "plank")
        {
            W("You walk the plank and fall into the water with a *SPLASH*!\n");
            S(TP->QN + " walks the plank and falls into the water with a " +
              "*SPLASH*!\n");
            make(PCOBJECT + "floating_obj",TP);
            TP->move_player("walks the plank and falls into the water with " +
                            "a *SPLASH*!",
                            PCROOM + "floating",
                            "falls into the water from above with a *SPLASH*!",
                            1);
            return 1;
        }
        return notify_fail("Walk what?\n");
    }
    W("Not much point in walking the plank from a ship that's in port, " +
      "is there?\n");
    return 1;
}

int do_raise(string str)
{
    object sail;
    if(str == "sail" || str == "gaff sail")
    {
        if(sail_raised)
        {
            W("The sail is already raised.\n");
            return 1;
        }
        sail = present("_pirate_quest_gaff_sail_",TO);
        if(!sail)
        {
            sail = present("_pirate_quest_gaff_sail_",TP);
        }
        if(sail)
        {
            if(SHIP_OBJ->query_is_at_sea())
            {
                W("You raise the gaff sail.\n");
                S(TP->QN + " raises the gaff sail.\n");
                sail->destroy();
                sail_raised = 1;
                return 1;
            }
            else
            {
                W("There's no point in raising the sail before the " +
                  "ship is at sea.\n");
                return 1;
            }
        }
        W("There's no sail here for you to raise!\n");
        return 1;
    }
    return notify_fail("Raise what?\n");
}

int do_throw(string str)
{
    object rope;
    if(str == "rope" || str == "grappling rope")
    {
        if(rope_thrown)
        {
            W("There is already a rope hooked to the railing of " +
              "the other ship here.\n");
            return 1;
        }
        rope = present("_pirate_quest_grappling_rope_",TP);
        if(rope)
        {
            if(SHIP_OBJ->query_is_at_sea())
            {
                if(SHIP_OBJ->query_cannon_fired())
                {
                    W("You throw the hook towards the other ship and " +
                      "it gets stuck in the railing.\n");
                    S(TP->QN + " throws a hook with a rope tied to " +
                      "it towards the other ship. The hook gets stuck " +
                      "in the railing.\n");
                    tell_room(TO,"There's now a rope from this ship to " +
                              "the other that you can use to board the " +
                              "other ship.\n");
                    rope->destroy();
                    rope_thrown = 1;
                    return 1;
                }
                else
                {
                    W("There's no point in doing that until you are " +
                      "alongside a crippled ship.\n");
                    return 1;
                }
            }
            else
            {
                W("There's no point in doing that until the ship is " +
                  "at sea.\n");
                return 1;
            }
        }
        W("You need a rope with a grappling hook tied to it to do that.\n");
        return 1;
    }
}

int query_sail_raised(void)
{
    return sail_raised;
}

int query_rope_thrown(void)
{
    return rope_thrown;
}
