#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM room;
inherit MOD_WATER water_module;

void create_object(void);
string long_fun(void);
void init(void);
int do_dive(string str);
int query_ship_at_sea(void);

void create_object(void)
{
    set_short("In the water");
    set_long("#long_fun");

    add_property("indoors");
    add_property("water");
    set_new_light(1);
    set_skip_obvious(1);

    add_item("lagoon|underground lagoon","You are swimming in it");
    add_func_item("ship|moored ship","#query_ship_at_sea",({
                  "The ship towers above you, it is quite an intimidating " +
                  "sight",
                  ""
                  }));
    add_func_item("hull","#query_ship_at_sea",({
                  "Seaweed clings to the hull of the ship",
                  ""
                  }));
    add_item("water","It is pretty nice to swim in this water");
    add_func_item("seaweed","#query_ship_at_sea",({
                  "The seaweed floats on the surface and clings to the hull " +
                  "of the ship",
                  "The seaweed floats on the surface of the water"
                  }));
    add_item("surface","Seaweed floats on it");
    add_item("fish|small fish","Small fish, swimming swiftly around you");
    add_item("ladder","You can climb it to get out of the water");
    add_func_item("bottom","#query_ship_at_sea",({
                  "You can probably dive down there, but be careful not to " +
                  "get trapped under the ship",
                  "You can probably dive down there"
                  }));
    add_func_item("sea","#query_ship_at_sea",({
                  "",
                  "You can see the sea through the crack"
                  }));
    add_func_item("crack","#query_ship_at_sea",({
                  "",
                  "It's big enough to sail a ship through!"
                  }));

    add_exit(PCROOM + "lev3_harbour_under_water","down");
    below = PCROOM + "lev3_harbour_under_water";
}

string long_fun(void)
{
    if(!query_ship_at_sea())
    {
        return "You are swimming in the underground lagoon next to a " +
               "moored ship. The water is pretty warm and calm and not " +
               "unpleasant to be in. Seaweed floats on the surface and " +
               "clings to the hull of the ship and small fish swim " +
               "around you. There's a ladder on the side of the dock that " +
               "you could use to climb out of the water. The ship towers " +
               "above you in an intimidating way and you think you can see " +
               "the bottom below you.\n";
    }
    else
    {
        return "You are swimming in the underground lagoon. The water is " +
               "pretty warm and calm and not unpleasant to be in. Seaweed " +
               "floats on the surface and small fish swim around you. " +
               "There's a ladder on the side of the dock that you could " +
               "use to climb out of the water. You can see the sea through " +
               "the crack to the west and think you can see the bottom " +
               "below you.\n";
    }
}

void init(void)
{
    add_multi_action("do_dive","dive|swim");
    add_action("do_climb","climb");
    "/sys/admin/room/admin_room"->visit(1103);
    water_module::init();
    room::init();
}

int do_dive(string str)
{
    if((query_verb() == "swim" && str == "down") || !str)
    {
        if(!try_down())
        {
            W("You dive down into the water below.\n");
            TP->move_player("dives down into the water below",
                            PCROOM + "lev3_harbour_under_water",
                            "dives down from below",1);
        }
        return 1;
    }
}

int do_climb(string str)
{
    if(str == "ladder")
    {
        W("You climb the ladder up to the dock.\n");
        TP->move_player("climbs the ladder up to the dock",
                        PCROOM + "lev3_harbour",
                        "comes climbing up out of the water",1);
        return 1;
    }
    return notify_fail("Climb what?\n");
}

int query_ship_at_sea(void)
{
    return SHIP_OBJ->query_is_at_sea();
}
