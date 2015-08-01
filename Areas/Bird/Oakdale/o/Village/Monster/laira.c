#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_woman";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a woman");
    set_long("Laira Aragel is a middle-aged woman. She has dark hair and " +
             "brown eyes and is rather skinny. She looks a bit distressed " +
             "when she sees you.\n");
    set_name("laira");

    load_chat(4,({ "Laira whispers: Please don't cause trouble. Leave " +
                   "the valley and forget about us.\n",
                   "The woman sobs quietly.\n" }));
}
