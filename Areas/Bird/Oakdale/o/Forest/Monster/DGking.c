#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_name("gnome");
    add_id("dark gnome");
    add_id("king");
    add_id("_dark_gnome_king_"); // Used to check for his presence in
                                 // the throne room
    set_short("The dark gnome king",1);
    set_long("The dark gnome king. He has a big problem. Morale in the " +
             "dark gnome caves is getting low, due to the fact that there " +
             "are no dark gnome women here. Day and night he tries to come " +
             "up with a way of solving that problem, but he hasn't had any " +
             "success so far.\n");
    set_level(11);
    set_unarmed(0);
    set_db(1);
    set_al(-200);
    set_hp(300);
    set_gender(1);
    set_race("dark gnome");
    set_int(15);
    set_skill("combat",70);
    set_skill("perception",78);
    set_skill("longblade",70);
    set_wc(25);
    set_new_ac(25);
    add_money(200 + random(100));
    make(ARMOUR + "Gchainmail");
    make(ARMOUR + "Gboots");
    make(WEAPON + "Glongsword");
    make(ARMOUR + "Ggloves");
    make(ARMOUR + "Ghood");
    make(ARMOUR + "Gnecklace");
    init_command("wear all");
    init_command("wield sword");

    load_chat(4,({ "The king glares at you: What do you want? I am a busy " +
                   "gnome.\n",
                   "The king mumbles: Women... Where can I find some " +
                   "women...?\n" }));
    load_a_chat(10,({ "The king shouts: Guards!! Guards!!\n" }));
}
