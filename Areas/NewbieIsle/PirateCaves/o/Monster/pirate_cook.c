// ==================================================================
// A pirate cook in the kitchen.
// ==================================================================
#pragma strict_types
#include "../def.h"
inherit PCMONSTER + "pirate";

void create_object(void)
{
    ::create_object();
    // Want different descs for this one
    set_short("A pirate cook");
    set_long("A drunk pirate trying to make food. He doesn't look like " +
             "a proper cook, but more like the poor sod who happened to " +
             "draw the short straw today.\n");
    add_id("cook");
    add_id("pirate cook");
    // Don't want this one to walk
    stop_walking();
    // And want different chats
    load_chat(15,({
        "Pirate ponders: Now where's the salt, arr?\n",
        "Pirate pours a bottle of rum into a pot.\n",
        "Pirate tastes some of his food and turns green in the face.\n",
        "Pirate states: More testicles means more iron, arr.\n",
    }));
}
