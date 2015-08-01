#pragma strict_types
#include "../def.h"
inherit SHIP_ROOM;

void create_object(void);
void init(void);
int do_turn(string str);

void create_object(void)
{
    ::create_object();
    set_short("Aft deck of the Black Skull (wd)");
    set_cave_long("The aft deck of the Black Skull. The cave arcs " +
                  "high above your head and the shining stones makes it " +
                  "look like a starlit sky. There's a wooden railing going " +
                  "around the deck and in the middle of the deck is the big " +
                  "rudder used to steer the ship. The masts on the deck in " +
                  "front of you block most of the view that way, but you " +
                  "see the sky outside the cave and dock of the harbour " +
                  "in the cave as you look down behind you.\n");
    set_sea_long("The aft deck of the Black Skull. The wind is strong in " +
                 "your face as you look up to the gray skies above you " +
                 "There's a wooden railing going around the deck and the " +
                 "middle of the deck is the big rudder used to steer the " +
                 "ship. The masts on the deck front of you block the view " +
                 "that way, but you see the waves of the raging sea as you " +
                 "look down behind you.\n");
    set_attacking_long("The aft deck of the Black Skull. The wind is strong " +
                 "in your face as you look up to the gray skies above you " +
                 "There's a wooden railing going around the deck and the " +
                 "middle of the deck is the big rudder used to steer the " +
                 "ship. The masts on the deck front of you block the view " +
                 "that way, but you see the ship you are attacking as you " +
                 "look to the starboard side.\n");

    add_item("deck|aft deck","You're on the aft deck of the Black Skull");
    add_item("black skull","The ship you are on");
    add_func_item("cave","#query_location",({
                  "It arcs high above you" }));
    add_func_item("stone|stones|shining stone|shining stones",
                  "#query_location",({ "They look like stars" }));
    add_func_item("star|stars|starlit sky","#query_location",({
                  "The stones make it look like a starlit sky" }));
    add_func_item("wind","#query_location",({
                  "",
                  "The wind is strong today, looks like you picked a good " +
                  "day to go sailing",
                  "The wind is strong today, looks like you picked a good " +
                  "day to go sailing"
                  }));
    add_func_item("skies|gray skies","#query_location",({
                  "",
                  "The skies above you are gray",
                  "The skies above you are gray"
                  }));
    add_item("railing|wooden railing","A wooden railing probably designed " +
             "to protect the crew from falling off the deck");
    add_item("rudder|wheel|wooden wheel|handle|handles","A big wooden " +
             "wheel with handles. When you turn the wheel the ship changes " +
             "course");
    add_item("mast|masts","They make it difficult to see forward, but " +
             "seeing forward isn't really necessary to steer a ship like this");
    add_func_item("dock|underground harbour|harbour","#query_location",({
                  "The dock in the underground harbour seems deserted" }));
    add_func_item("wave|waves|high wave|high waves","#query_location",({
                  "",
                  "The waves are high and the sea is raging",
                  "The waves are high and the sea is raging"
                  }));
    add_func_item("ship","#query_location",({
                  "The ship is moored in an underground harbour",
                  "The ship rides the waves well",
                  "The ship you are attacking is on your starboard side"
                  }));
    add_func_item("starboard side","#query_location",({
                  "",
                  "",
                  "The ship you are attacking is on that side"
                  }));

    add_exit(PCROOM + "black_skull_deck","westdown");
}

void init(void)
{
    add_action("do_turn","turn");
}

int do_turn(string str)
{
    if(str == "rudder" || str == "wheel")
    {
        if(SHIP_OBJ->query_is_at_sea())
        {
            W("The captain is steering the ship right now, he " +
              "probably would not appreciate the interruption.\n");
            return 1;
        }
        else
        {
            W("You turn the rudder a bit but since the ship is lying still " +
              "in the harbour it doesn't change course very much.\n");
            S(TP->QN + " turns the rudder a bit but since the ship is lying " +
              "still in the harbour it doesn't change course very much.\n");
            return 1;
        }
    }
    return notify_fail("Turn what?\n");
}
