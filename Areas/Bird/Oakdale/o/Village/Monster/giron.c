#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_man";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a man");
    set_long("Giron Aragel is a man in his forties. He is one of the " +
             "best hunters in the village and lives here with his wife " +
             "and son.\n");
    set_name("giron");

    load_chat(4,({ "The man says: I can't even hunt anymore. The woods " +
                   "are full of Nirach's henchmen.\n",
                   "The man says: Nirach took our neighbours son last " +
                   "night. When will he come for us?\n" }));
}
