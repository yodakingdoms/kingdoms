#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_name("gnome");
    add_id("dark gnome");
    set_short("a dark gnome");
    set_long("A small, evil looking gnome with a black beard and small, " +
             "eyes. Dark gnomes are cousins of the gnomes, but nastier, " +
             "larger and more primitive.\n");
    set_level(9);
    set_unarmed(0);
    set_db(1);
    set_al(-200);
    set_hp(220);
    set_gender(1);
    set_race("dark gnome");
    set_skill("combat",70);
    set_skill("perception",60);
    set_skill("shortblade",60);
    set_wc(25);
    set_new_ac(25);
    add_money(100 + random(100));
    make(ARMOUR + "Gchainmail");
    make(ARMOUR + "Gboots");
    make(WEAPON + "Gshortsword");
    make(ARMOUR + "Ggloves");
    make(ARMOUR + "Ghood");
    make(ARMOUR + "Gnecklace");
    init_command("wear all");
    init_command("wield sword");

    load_chat(4,({ "The gnome peers quizzically at you.\n",
                   "The gnome asks: What are you doing here?\n",
                   "The gnome says: We need to get some dark gnome women " +
                   "here...\n" }));
    load_a_chat(10,({ "The gnome shouts: Pick on somebody your own " +
                      "size!!!!\n" }));
}
