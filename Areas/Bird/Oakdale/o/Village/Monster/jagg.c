#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_man";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("an old man");
    set_long("Jagg Darlond is an old man with a bald head and a white " +
             "beard. He has been living alone since his wife passed away.\n");
    set_name("jagg");
    add_id("old man");

    make(OBJECT + "pipe");

    load_chat(4,({ "The old man says: Do not try to oppose Nirach. " +
                   "The villagers will be the ones who will suffer.\n",
                   "The old man lights his pipe.\n" }));
}
