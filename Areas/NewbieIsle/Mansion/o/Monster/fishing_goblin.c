#pragma strict_types
#include "../def.h"
inherit MONSTER + "goblin";

void create_object(void)
{
    ::create_object();
    set_short("A goblin fishing from the pond");
    set_long("A goblin ordered to catch fish from the pond. He smells bad " +
             "and is extremely ugly like most goblins are. He doesn't " +
             "seem to be having much luck but he doesn't seem to try " +
             "very hard either. He mainly just sits here dipping his " +
             "dirty feet in the water.\n");

    load_chat(2,({
        "Goblin yawns.\n",
        "Goblin splashes his feet in the water.\n",
        "Goblin pulls the float out of the water and throws in back in " +
        "again.\n",
        "Goblin snores softly.\n",
    }));

    load_a_chat(30,({
        "Goblin shouts: There's no fish in the pond, you can have it!\n",
        "Goblin tries to knee you, without much effect.\n",
        "Goblin snarls.\n",
    }));

    make(WEAPON + "fishing_pole");
    init_command("wield pole in left hand");
}
