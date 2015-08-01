#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void)
{
    object weapon,armour;

    set_short("Lames the Junior Rhymer",1);
    set_long("Lames is an angry looking bard with a very rough appearance. " +
             "He has a beard and he's scowling angrily. He's not a part of " +
             "the crew of the Riaa, but the goods she's distributing are " +
             "his and Jars' and they hate to see them stolen by pirates.\n");
    set_name("lames");
    add_id("minstrel");
    add_id("bard");
    add_id("jars the minstrel");

    set_level(2);
    set_race("newbie island bard");
    set_hp(80 + random(25));
    set_al(0);
    add_money(100 + random(20));
    set_gender(1);
    set_skill("combat",20 + random(10));

    make(PCWEAPON + "mandolin");
    make(PCARMOUR + "black_shirt");
    init_command("wield mandolin");
    init_command("wear shirt");

    load_chat(10,({
        "Lames growls: Smashing through the boundaries, lunacy has found " +
        "me, cannot stop the Battery.\n",
        "Lames growls: Adrenaline starts to flow, you're trashing all " +
        "around. Acting like a maniac, Whiplash.\n",
        "Lames growls: Blackened is the end, winter it will send.\n",
        "Lames growls: For a hill men would kill, why? They do not know.\n",
    }));

    load_a_chat(30,({
        "Lames growls: Obey your master.\n",
        "Lames growls: Darkness, imprisoning me, all that I see, " +
        "absolute horror!\n",
        "Lames growls: Fight fire with fire. Ending is near.\n",
        "Lames growls: Blood will follow blood, dying time is here, " +
        "Damage Incorporated.\n",
    }));
}
