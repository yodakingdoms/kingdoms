#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_man";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a huge, hairy man");
    set_long("Kendar Eirondar is a bear hunter. He is a huge, hairy man " +
             "with a brown beard. He looks depressed.\n");
    set_name("kendar");

    make(ARMOUR + "cloak");
    init_command("wear cloak");

    load_chat(4,({ "The man sighs heavilly.\n",
                   "The man says: There are no bears left... Nirach has " +
                   "driven them all away.\n" }));
}
