// ==================================================================
// A pirate searching for treasure in the bird tower.
// ==================================================================
#pragma strict_types
#include "../def.h"
inherit PCMONSTER + "pirate";

void create_object(void)
{
    ::create_object();
    // Want different descs for this one
    set_short("A drunk pirate searching for treasure");
    set_long("A drunk pirate has found his way to the tower and is " +
             "rummaging around, searching for treasure.\n");
    add_id("drunk pirate");
    // Don't want this one to walk
    stop_walking();
    // And want different chats
    load_chat(10,({
        "Pirate mumbles: Arr, there be treasure in this here tower " +
        "I'd wager.\n",
        "Pirate says: Gold and silver there be hidden somewhere here " +
        "for sure, arr.\n",
        "Pirate rummages around.\n",
    }));
}
