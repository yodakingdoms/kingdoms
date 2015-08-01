#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_man";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a man");
    set_long("Lamin Carelyn has blond hair and brown eyes. He looks " +
             "worried.\n");
    set_name("lamin");

    make(ARMOUR + "sandals");
    init_command("wear sandals");

    load_chat(4,({ "The man coughs nervously.\n",
                   "The man asks: You're not from these parts, are you?\n" }));
}
