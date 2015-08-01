#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_woman";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a young woman");
    set_long("Linia Lellirin is a young woman who's just moved into this " +
             "house with her husband.\n");
    set_name("linia");
    add_id("young woman");

    make(ARMOUR + "dress");
    init_command("wear dress");
    make(OBJECT + "bowl");

    load_chat(4,({ "Linia whispers: I saw some of his men sneak around in " +
                   "the village last night. I wonder who disappeared...\n",
                   "The woman wipes a tear away.\n" }));
}
