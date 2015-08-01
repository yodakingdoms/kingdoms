#pragma strict_types
#include "../def.h"
inherit MONSTER + "goblin";

void create_object(void);
void init(void);

void create_object(void)
{
    ::create_object();
    set_short(short() + " looking battered and bruised");
    set_long("A goblin that looks as if he's been in a fight recently. " +
             "He has bruises all over his body and he's breathing " +
             "heavily and panting uncontrollably. You wonder what he " +
             "has encountered down here that managed to do that to him " +
             "and worry that you might meet the same fate!\n");

    load_chat(10,({
        QN + " pants uncontrollably.\n",
        QN + " breathes heavily.\n",
        QN + " groans heavily.\n",
        QN + " pants: I need reinforcements.\n",
    }));

    load_a_chat(30,({
        QN + " yells: Let me at least get some fastpotions first!\n",
        QN + " groans: Can't I rest for a while before we do this?!.\n",
    }));
}

void init(void)
{
    // Have to do this in init instead of create_object because the
    // goblin heals over time if he's not killed
    if(query_hp() > 10)
    {
        // This player will get xp without this line
        set_this_player(0);
        reduce_hit_point(10);
        // Goblin will be aggressive without the line below and
        // set_aggressive(0) did not work
        stop_fight();
    }
}
