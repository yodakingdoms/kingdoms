#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_woman";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a woman");
    set_long("Nanicia Cirdal is a beautiful woman with long, dark hair. " +
             "She is at the well getting water. She peers suspiciously " +
             "at you.\n");
    set_name("nanicia");

    make(ARMOUR + "band");
    init_command("wear band");

    load_chat(4,({ "Nanicia says: The well is nearly dry. I bet Nirach " +
                   "is responsible for that too.\n",
                   "The woman looks down into the well.\n" }));
}
