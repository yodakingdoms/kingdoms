// ==================================================================
// The goblin chief.
// ==================================================================
#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);
int is_unkillable(void);
string unkillable_string(object attacker);

void create_object(void)
{
    object weapon;

    set_short("Skrowks the goblin chief",1);
    set_long("Skrowks is the leader of this particular tribe of goblins. " +
             "He led them here from their home to find a treasure he " +
             "believes was left here when whoever lived here fled. They " +
             "have not found it yet and his goblins are getting restless " +
             "he's bigger than any of the other goblins here and looks " +
             "stronger as well. Better not mess with him!\n");
    set_name("skrowks");
    add_id("goblin");
    add_id("chief");
    add_id("goblin chief");
    add_id("skrowks the goblin chief");

    set_level(3);
    set_race("goblin");
    set_sub_race(MANSION_GOBLIN_SUBRACE_FLAG);
    set_al(-160);
    add_money(100 + random(20));
    set_gender(1);

    weapon = make(WEAPON + "goblin_weapon");
    init_command("wield " + weapon->QN);
    make(ARMOUR + "leather_armour");
    make(ARMOUR + "goblin_armour");
    init_command("wear all");

    load_chat(5,({
        "Skrowks mumbles: The damn treasure has to be here somewhere.\n",
        "Skrowks says: Leave me be or my bodyguards will pound you.\n",
        "Skrowks looks nervous.\n"
    }));

    load_a_chat(20,({
        "Skrowks yells: This was a big mistake!\n",
        "Skrowks yells: The treasure is mine, not yours!\n",
        "Skrowks growls menacingly.\n"
    }));
}


int is_unkillable(void)
{
    return present("_goblin_bodyguard_",ENV(TO)) != 0;
}

string unkillable_string(object attacker)
{
    return "You can't get close enough to Skrowks as long as his bodyguards " +
           "are still in the same room.";
}
