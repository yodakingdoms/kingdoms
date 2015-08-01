#pragma strict_types
#include "../def.h"
inherit MONSTER + "darkling";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_name("trooper");
    add_id("darkling trooper");
    set_short("a darkling trooper");
    set_long("A darkling trooper. He looks human, but has pale skin and " +
             "long, black hair. Long black hair also grows on his bared " +
             "feet, and he has two long, protruding teeth in his lower " +
             "jaw. He observes you coldly with his small, black, pupilless " +
             "eyes.\n");
    set_level(10);
    set_unarmed(0);
    set_db(3);
    set_hp(230);
    set_skill("combat",75);
    set_skill("longblade",75);
    set_skill("resist",75);
    set_skill("perception",75);
    set_wc(25);
    set_new_ac(25);
    add_money(random(100));
    make(ARMOUR + "dark_plate");
    make(ARMOUR + "dark_shield");
    make(ARMOUR + "dark_helmet");
    make(ARMOUR + "dark_glove");
    make(WEAPON + "dark_lsword");
    init_command("wear all");
    init_command("wield sword");

    load_a_chat(10,({ "The trooper shouts: Intruder! Die!!\n" }));
}
