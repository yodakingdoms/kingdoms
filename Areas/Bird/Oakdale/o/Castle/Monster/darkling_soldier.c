#pragma strict_types
#include "../def.h"
inherit MONSTER + "darkling";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_name("soldier");
    add_id("darkling soldier");
    set_short("a darkling soldier");
    set_long("A darkling soldier. He looks human, but has pale skin and " +
             "long, black hair. Long, black hair grows on his bared feet " +
             "and on the back of his hands. He has two long, protruding " +
             "teeth in his lower jaw, and his eyes are small, black and " +
             "lack pupils.\n");
    set_level(8);
    set_unarmed(0);
    set_db(1);
    set_hp(200);
    set_skill("combat",65);
    set_skill("longblade",65);
    set_skill("resist",65);
    set_skill("perception",65);
    set_wc(25);
    set_new_ac(25);
    add_money(random(100));
    make(ARMOUR + "dark_scalemail");
    make(WEAPON + "dark_broadsword");
    make(ARMOUR + "dark_sshield");
    make(ARMOUR + "dark_lhelmet");
    init_command("wear all");
    init_command("wield sword");

    load_a_chat(15,({ "The soldier shouts: Intruder! Die!\n" }));
}
