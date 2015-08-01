// This particular madman is alone in his cell and one of his
// chats is a hint for the quest (hit the rock in the caves)
#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_man";

void create_object()
{
    ::create_object();
    set_short("a mad man chained to the wall");
    set_long("This man was one of the rebels. The things he saw on the " +
             "disastrous raid into the castle robbed him of his sanity. " +
             "Still, he alone survived, and has been chained to this wall " +
             "ever since.\n");
    set_name("madman");
    add_id("mad man");
    set_al(300);

    load_chat(75,({ "Madman says: Ah! Keep away!\n",
                    "Madman rambles: This can't be.. this can't be.. " +
                    "thiscan'tbethiscan'tbeTHISCAN'TBE!!!\n",
                    "Madman swears: Aagh, we have been deceived.\n",
                    "The man collapses in a convulsing heap.\n",
                    "The man suddenly looks up with clear eyes: Sometimes " +
                    "the rock gets stuck... Then you have to hit it...\n",
                    "Madman shouts: No! Let me go!\n" }));
    load_a_chat(10,({ "Mad man shouts: Yes! Set me free!!\n" }));
}
