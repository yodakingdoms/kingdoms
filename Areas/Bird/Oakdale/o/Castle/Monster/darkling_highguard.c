#pragma strict_types
#include "../def.h"
inherit MONSTER + "darkling";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_name("guard");
    add_id("high guard");
    set_short("a darkling high guard");
    set_long("One of Nirach's personal bodyguards and the most skilled " +
             "fighters in his darkling army. His skin is pale and his " +
             "small, black eyes lack pupils. Two long teeth protrude from " +
             "his lower jaw. He stands motionless, but you know he is " +
             "aware of your every move.\n");
    set_level(16);
    set_unarmed(0);
    set_db(3);
    set_hp(240);
    set_skill("combat",90);
    set_skill("longblade",90);
    set_skill("resist",90);
    set_skill("perception",90);
    set_wc(1);
    set_new_ac(1);
    add_money(random(400));
    make(ARMOUR + "dark_platemail");
    make(WEAPON + "dark_bastsword");
    make(ARMOUR + "dark_lshield");
    make(ARMOUR + "dark_phelmet");
    make(ARMOUR + "dark_cloak");
    make(ARMOUR + "dark_glove");
    make(ARMOUR + "dark_boot");
    make(ARMOUR + "dark_amulet");
    init_command("wear all");
    init_command("wield sword");

    load_a_chat(15,({ "The high guard shouts: Intruder! Die!\n" }));
}
