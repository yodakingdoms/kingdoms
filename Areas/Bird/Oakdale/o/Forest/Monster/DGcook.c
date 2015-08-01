#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_name("gnome");
    add_id("dark gnome");
    add_id("cook");
    add_id("chef");
    set_short("The dark gnome cook",1);
    set_long("The dark gnome chef. He is smaller than the others, almost " +
             "as small as a normal gnome. Maybe that's why he had to learn " +
             "how cook, since he could have no hope of becoming a fighter.\n");
    set_level(5);
    set_unarmed(0);
    set_db(1);
    set_al(-200);
    set_hp(170);
    set_gender(1);
    set_race("dark gnome");
    set_skill("combat",30);
    set_skill("blunt",60);
    set_skill("cooking",20);
    set_wc(40);
    set_new_ac(40);
    make(ARMOUR + "Gapron");
    make(WEAPON + "Gspoon");
    init_command("wear apron");
    init_command("wield spoon");
    add_money(100 + random(100));

    load_chat(4,({ "The cook stirs as ghastly smelling soup.\n",
                   "The cook mumbles: More testicles means more iron...\n"}));
    load_a_chat(10,({ "The gnome shouts: What!?!? Was there a fly in your " +
                      "soup!?!?\n" }));
}
