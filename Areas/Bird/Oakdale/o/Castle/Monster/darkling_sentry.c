#pragma strict_types
#include "../def.h"
inherit MONSTER + "darkling";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_name("sentry");
    add_id("darkling sentry");
    set_short("a darkling sentry");
    set_long("A darkling sentry. He looks human but has pale skin and " +
             "long, black hair. Long, black hair grows on the back of his " +
             "hands and on his bare feet. He has two long, protruding " +
             "teeth in his lower jaw, and his eyes are small, black and " +
             "lack pupils.\n");
    set_level(4);
    set_hp(150);
    add_money(25 + random(100));
    set_skill("combat",50);
    set_skill("shortblade",50);
    set_str(10);
    set_wc(10);
    set_new_ac(10);
    make(ARMOUR + "dark_leather");
    make(ARMOUR + "dark_sshield");
    make(WEAPON + "dark_ssword");
    init_command("wear all");
    init_command("wield sword");

    load_chat(4,({ "The sentry snarls: Get out of here! You have no " +
                   "business here!\n",
                   "The sentry peers suspiciously at you.\n" }));
    load_a_chat(10,({ "The darkling screams: Our Master will hear about " +
                      "this, and then he'll have your soul!!!\n" }));
}
