// Inherited by male villagers
#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_adult";

void create_object(void);

void create_object(void)
{
    ::create_object();
    add_id("man");
    set_gender(1);

    load_a_chat(25,({ "The man shouts: Foul servant of Nirach!\n" }));
}
