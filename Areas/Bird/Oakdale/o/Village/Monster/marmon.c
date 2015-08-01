#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_man";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a pondering man");
    set_long("Marmon Sylifin is a fisherman. There isn't much fish in the " +
             "river anymore, so he spends most of his time on the bridge " +
             "watching the river rush by.\n");
    set_name("marmon");

    make(WEAPON + "knife");
    init_command("wield knife");
    make(OBJECT + "wood");

    load_chat(4,({ "The man says: Don't go up there. To the castle I " +
                   "mean...\n",
                   "The man sighs and looks up at the castle.\n" }));
}
