// Inherited by female villagers
#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_adult";

void create_object(void);

void create_object(void)
{
    ::create_object();
    add_id("woman");
    set_gender(2);

    load_a_chat(25,({ "The woman pleads: Please stop. I can do you no "+
                      "harm.\n" }));
}
