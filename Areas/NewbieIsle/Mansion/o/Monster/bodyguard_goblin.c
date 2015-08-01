// ==================================================================
// These goblins protect the goblin leader.
// ==================================================================
#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void)
{
    object weapon;

    set_short("A goblin bodyguard");
    set_long("This is a puny little goblin but he looks quite determined " +
             "to cause you trouble should you attack him anyway. He's been " +
             "assigned bodyguard duties and it is his job to protect his " +
             "leader or die trying. He looks a bit stronger than the other " +
             "goblins you have encountered here.\n");
    set_name("bodyguard");
    add_id("goblin");
    add_id("guard");
    add_id("_goblin_bodyguard_");

    set_level(2);
    set_race("goblin");
    set_sub_race(MANSION_GOBLIN_SUBRACE_FLAG);
    set_al(-150);
    set_hp(50);
    add_money(50 + random(20));
    set_gender(1);

    weapon = make(WEAPON + "goblin_weapon");
    init_command("wield " + weapon->QN);
    make(ARMOUR + "leather_armour");
    make(ARMOUR + "goblin_armour");
    init_command("wear all");

    load_chat(1,({
        "The bodyguard fingers his weapon threateningly at you.\n",
        "The bodyguard snarls menacingly.\n",
        "The bodyguard growls softly.\n"
    }));

    load_a_chat(20,({
        "The bodyguard yells: This was a big mistake!\n",
        "The bodyguard says: I'll eat you for dinner once we're done here.\n",
        "The bodyguard growls: Die, worm.\n"
    }));
}
