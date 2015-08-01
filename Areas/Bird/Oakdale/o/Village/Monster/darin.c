#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_man";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a young man");
    set_long("Darin Lellirin is a young man who's just moved into this " +
             "house with his wife. He's cooking food.\n");
    set_name("darin");

    load_chat(4,({ "The man comforts his wife.\n",
                   "The man stirs the soup.\n" }));
}
