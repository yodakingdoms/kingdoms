#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_lean(string str);

void create_object(void)
{
    set_short("At the top of a tower");
    set_long("You are at the top of a lookout tower in the north part of " +
             "the castle. The wind is howling, pull at your hair and " +
             "clothes, and dark clouds are gathering in the sky above. The " +
             "wind is strong enough to blow you off the roof, so you dare " +
             "not lean over the wall and look down. To the south is the " +
             "main part of the castle, and the thin, high tower almost " +
             "seems to touch the clouds above. There is a hole in the " +
             "floor.\n");
    set_new_light(5);
    add_property("no_horse");

    add_item("cloud|clouds","Dark, threatening clouds slowly circling the " +
             "tower to the south");
    add_item("wall|walls","A three foot wall going round the edge of the " +
             "platform at the top of the tower");
    add_item("platform|top","That's where you are");
    add_item("tower","A thin, eerie looking tower. The dark clouds above " +
             "seem to be circling that tower");
    add_item("hole|floor","There is a hole in the floor. It was the hole " +
             "you came up through, and it is the way you have to take to " +
             "get away from here");

    add_exit(ROOM + "lev3_tower","down");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_sentry",1);
}

void init(void)
{
    add_action("do_lean","lean");
}

int do_lean(string str)
{
    W("As you lean over the wall, vertigo hits you hard. Panicking you " +
      "stumble backwards, away from the edge. Suddenly the floor disappears " +
      "under your feet, and you fall through the hole in the floor. You " +
      "hit the floor in the room below with a big THUD! That hurt!\n");
    TP->move_player("leans over the wall to look down. Suddenly " + TP->QPR +
                    "turns white, stumbles backward, and falls through the " +
                    "hole in the floor. You hear a THUD! as " + TP->QPR +
                    " lands on the floor in the room below",
                    ROOM + "lev3_tower",
                    "comes falling through the opening in the ceiling " +
                    "and lands with a THUD!",1);
    TP->add_temporary_penalty(random(5));
    return 1;
}
