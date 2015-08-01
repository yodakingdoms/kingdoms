#pragma strict_types
#include "../def.h"
inherit MONSTER + "darkling";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_name("guard");
    add_id("darkling guard");
    set_short("a darkling guard");
    set_long("A darkling guard. He looks human, but has pale skin and long, " +
             "black hair. Long, black hair grows on the back of his hands " +
             "and on his bare feet. He has two long, protruding teeth in " +
             "his lower jaw, and his eyes are small, black and lack " +
             "pupils.\n");
    set_level(6);
    set_unarmed(0);
    set_db(1);
    set_hp(180);
    set_skill("combat",60);
    set_skill("longblade",60);
    set_skill("perception",60);
    set_skill("resist",60);
    set_wc(25);
    set_new_ac(35);
    add_money(random(100));
    make(ARMOUR + "dark_chainmail");
    make(WEAPON + "dark_ssword");
    make(ARMOUR + "dark_sshield");
    make(ARMOUR + "dark_lhelmet");
    init_command("wear all");
    init_command("wield sword");

    load_a_chat(15,({ "The guard shouts: Intruder! Die!\n" }));
}
