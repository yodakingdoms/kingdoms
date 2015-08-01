#pragma strict_types
#include "../def.h"
inherit MONSTER + "darkling";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_name("torturer");
    add_id("darkling torturer");
    set_short("The darkling torturer",1);
    set_long("This is a particularly nasty and evil darkling. He has a " +
             "mad, haunting look in his eyes, and he mubles to himself. " +
             "You would not enjoy beeing at this darklings mercy, tied " +
             "to his rack!\n");
    set_level(8);
    set_al(-400);
    set_unarmed(0);
    set_db(1);
    set_hp(250);
    set_skill("combat",65);
    set_skill("blunt",65);
    set_skill("resist",65);
    set_skill("perception",65);
    set_wc(1);
    set_new_ac(1);
    add_money(random(100));
    make(ARMOUR + "dark_scalemail");
    make(WEAPON + "iron_rod");
    make(ARMOUR + "dark_lhelmet");
    init_command("wear all");
    init_command("wield rod");

    load_a_chat(15,({ "The torturer tries to tie you to the rack!!\n" }));
}
