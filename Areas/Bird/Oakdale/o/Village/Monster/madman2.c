#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_man";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a madman");
    set_long("A man who's been locked in because people thought he was a " +
             "madman. Well, even if he wasn't one when they locked him up, " +
             "the years spent in this dark room has turned him into one.\n");
    set_name("madman");
    add_id("mad man");

    make(ARMOUR + "straight_jacket");
    init_command("wear armour");

    load_chat(15,({ "Madman says: Welcome to where time stands still, " +
                    "noone leaves and noone will...\n",
                    "Madman says: Moon is full never seems to change, " +
                    "just labelled mentally deranged...\n"}));
    load_a_chat(10,({ "Madman tries to break free of the straightjacket " +
                      "but fails.\n" }));
}
