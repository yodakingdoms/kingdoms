#pragma strict_types
#include "../def.h"
inherit MONSTER + "darkling";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_name("priest");
    add_id("darkling priest");
    set_short("a darkling priest");
    set_long("A darkling priest. He is different from the others in that " +
             "he is dressed in a robe, and that his hair is well combed. " +
             "He is much cleaner, but he looks much more evil as well.\n");
    set_level(12);
    set_al(-400);
    set_unarmed(1);
    set_db(35);
    set_hp(400);
    set_skill("unarmed",60);
    set_wc(15);
    set_new_ac(20);
    set_spell_mess1("The priest mumbles a silent prayer and his enemy " +
                    "is weakened.\n");
    set_spell_mess2("The priest mumbles a silent prayer and you feel a " +
                    "sharp pain in your heart!!\n");
    set_chance(20);
    set_spell_dam(20);
    add_money(300 + random(200));
    make(ARMOUR + "priestrobe");
    init_command("wear robe");

    load_chat(5,({ "The priest chants softly.\n" }));
    load_a_chat(20,({ "The priest mumbles a silent prayer and seems to " +
                      "regain strenght.\n\n",
                      "The priest curses your ancestors.\n\n" }));
}
