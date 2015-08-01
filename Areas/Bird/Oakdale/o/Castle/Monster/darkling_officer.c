#pragma strict_types
#include "../def.h"
inherit MONSTER + "darkling";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_name("officer");
    add_id("darkling officer");
    set_short("a darkling officer");
    set_long("An officer in Nirach's darkling army . He looks human, but " +
             "has pale skin and long, black hair. Long, He has two long, " +
             "protruding teeth in his lower jaw. He observes you coldy " +
             "with his small, black pupilless eyes.\n");
    set_level(12);
    set_unarmed(0);
    set_db(3);
    set_hp(230);
    set_skill("combat",80);
    set_skill("longblade",80);
    set_skill("resist",80);
    set_skill("perception",80);
    set_wc(20);
    set_new_ac(20);
    set_str(20);
    add_money(random(190));
    make(ARMOUR + "dark_plate");
    make(WEAPON + "dark_lsword");
    make(ARMOUR + "dark_shield");
    make(ARMOUR + "dark_helmet");
    make(ARMOUR + "dark_glove");
    make(ARMOUR + "dark_boot");
    init_command("wear all");
    init_command("wield sword");

    load_a_chat(15,({ "The officer shouts: Intruder! Die!\n" }));
}
