// ==================================================================
// A pirate fishing by the cove shore.
// ==================================================================
#pragma strict_types
#include "../def.h"
inherit PCMONSTER + "pirate";

void create_object(void)
{
    ::create_object();
    // Want different descs for this one
    set_short("A drunk pirate trying to catch fish");
    set_long("A drunk pirate trying to fish by walking around in " +
             "the shallow water and grabbing them with his bare hands. " +
             "He doesn't seem to have much luck in his endevour.\n");
    add_id("drunk pirate");
    // Don't want this one to walk
    stop_walking();
    // And want different chats
    load_chat(15,({
        "Pirate hums: I only wish to catch the fish so juicy sweet.\n",
        "Pirate splashes around in the water, trying to catch a fish.\n",
        "Pirate catches a fish, but it slips from his hands.\n",
    }));
}
