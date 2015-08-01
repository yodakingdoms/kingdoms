#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_name("gnome");
    add_id("dark gnome");
    add_id("shaman");
    set_short("The dark gnome shaman",1);
    set_long("A small, evil looking gnome with a black beard and small, " +
             "eyes. Dark gnomes are cousins of the gnomes, but nastier, " +
             "larger and more primitive. This particular one looks smarter " +
             "than the others.\n");
    set_level(8);
    set_unarmed(0);
    set_db(1);
    set_al(-200);
    set_hp(200);
    set_gender(1);
    set_race("dark gnome");
    set_int(20);
    set_skill("combat",60);
    set_skill("perception",70);
    set_skill("blunt",60);
    set_skill("resist",60);
    set_wc(25);
    set_new_ac(25);
    add_money(100 + random(100));
    make(ARMOUR + "Grobe");
    make(WEAPON + "Gstaff");
    make(ARMOUR + "Gcloak");
    make(ARMOUR + "Ghood");
    make(ARMOUR + "Gnecklace");
    init_command("wear all");
    init_command("wield staff");

    load_chat(4,({ "The shaman chants softly...\n",
                   "The shaman yells: AGRUNIKKIE!!!!!\n" }));
    load_a_chat(10,({ "The shaman tries to cast a spell, but he's forgotten " +
                      "the words in this excitement!!\n" }));
}
