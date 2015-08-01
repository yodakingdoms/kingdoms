#pragma strict_types
#include "../def.h"
inherit MONSTER + "darkling";

void create_object(void);
void cast_spell(void);

void create_object(void)
{
    ::create_object();
    set_name("cleric");
    add_id("darkling cleric");
    set_short("a darkling cleric");
    set_long("A darkling cleric. His skin is pale and he has small pieces " +
             "of bone tied into his long, black hair. His small, black " +
             "eyes lack pupils, and he has two long, protruding teeth in " +
             "his lower jaw. You have heard stories about evil clerics and " +
             "their powers, but you see no symbols or marks on his attire " +
             "that gives you any clue as to which evil go he draws his " +
             "powers from.\n");
    add_money(400);
    set_level(17);
    set_hp(600);
    set_chance(100);
    set_spell_dam(0);
    set_spell_mess1("#cast_spell");
    set_spell_mess2("");
    set_int(40);
    set_dic(40);
    set_skill("combat",85);
    set_skill("perception",85);
    set_skill("resist",85);
    set_skill("blunt",85);
    set_skill("devotion",96);
    set_skill("lightning",96);
    set_new_ac(1);
    set_db(20);
    set_wc(1);
    set_al(-1000);

    make(OBJECT + "key2");
    make(ARMOUR + "dark_platemail");
    make(ARMOUR + "dark_lshield");
    make(ARMOUR + "dark_helmet");
    make(ARMOUR + "dark_glove");
    make(ARMOUR + "dark_cloak");
    make(ARMOUR + "dark_boot");
    make(ARMOUR + "dark_amulet");
    make(WEAPON + "dark_mace");
    init_command("wear all");
    init_command("wield mace");

    load_chat(5,({ "The cleric mumbles soft prayers.\n" }));
    load_a_chat(5,({ "The cleric chants loudly and seems to regain " +
                     "strength.\n",
                     "The cleric starts a magical prayer.\n",
                     "The cleric mumbles a word and his mace begins to " +
                     "glow.\n" }));
}

void cast_spell(void)
{
    // Don't want the cleric to start using up hp for this
    if(query_sp() > 0)
    {
        if(!random(4))
        {
            (OBJECT + "black_lightning")->do_lightning(query_attack());
        }
    }
}
