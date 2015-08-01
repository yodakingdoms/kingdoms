#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_man";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a man treating his wife");
    set_long("Kardan Moloran has red hair and a long red beard. He looks " +
             "after his wife, who's ill.\n");
    set_name("kardan");

    make(OBJECT + "cloth");

    load_chat(4,({ "The man wipes his wife's forehead gently with a damp " +
                   "cloth.\n",
                   "The man says: Nirach is the one to blame for my wife's " +
                   "illness. I am sure of that.\n" }));
}
