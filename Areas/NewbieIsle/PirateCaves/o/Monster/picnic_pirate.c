// ==================================================================
// A picnicking pirate in the forest.
// ==================================================================
#pragma strict_types
#include "../def.h"
inherit PCMONSTER + "pirate";

void create_object(void)
{
    ::create_object();
    // Want different descs for this one
    set_short("A drunk pirate having a picnic");
    set_plural_short("drunk pirates having a picnic");
    set_long("A drunk pirate having a picnic in the forest. By the looks " +
             "of him you you get the impression a picnic for the pirates " +
             "means getting as drunk as they normally do, just outside.\n");
    add_id("drunk pirate");
    // Don't want this one to walk
    stop_walking();
    // And want different chats
    load_chat(15,({
        "Pirate ponders: Now where's that last bottle of rum, arr?\n",
        "Pirate trips over his own two feet and falls FLAT on his face!\n",
        "Pirate looks at the beautiful scenery and adds some vomit to it.\n",
        "Pirate stares at the sky.\n",
    }));
}
