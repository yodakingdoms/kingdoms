#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_name("gnome");
    add_id("dark gnome");
    add_id("guard");
    set_short("a dark gnome guard");
    set_long("A small, evil looking gnome with a black beard and small, " +
             "eyes. Dark gnomes are cousins of the gnomes, but nastier, " +
             "larger and more primitive. This one is bigger than the " +
             "others.\n");
    set_level(10);
    set_unarmed(0);
    set_db(1);
    set_al(-200);
    set_hp(250);
    set_gender(1);
    set_race("dark gnome");
    set_skill("combat",70);
    set_skill("perception",60);
    set_skill("longblade",60);
    set_wc(25);
    set_new_ac(25);
    add_money(100 + random(100));

    make(ARMOUR + "Gchainmail");
    make(ARMOUR + "Gboots");
    make(ARMOUR + "Gcloak");
    make(WEAPON + "Glongsword");
    make(ARMOUR + "Ggloves");
    make(ARMOUR + "Ghood");
    make(ARMOUR + "Gnecklace");
    init_command("wear all");
    init_command("wield sword");

    load_chat(4,({ "The guard snaps to attention.\n",
                   "The guard asks: Have you requested an audience with our " +
                   "king?\n" }));
    load_a_chat(10,({ "The guard shouts: We'll defend our king with our " +
                      "lives!!\n" }));
}
