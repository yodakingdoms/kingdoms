#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_man";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a bearded man");
    set_long("Bilir Cirdal is a retired miner. He has dark hair and " +
             "a long, black beard. He still looks very strong.\n");
    set_name("bilir");

    load_chat(4,({ "The man paces around.\n",
                   "The man says: You're a stranger here, aren't you?\n" }));
}
