#pragma strict_types
#include "../../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_short("Lallan the apothecary",1);
    set_long("Lallan is a man in his fifties with graying hair and blue " +
             "eyes.\n");
    set_name("apothecary");
    add_id("lallan");
    add_id("man");
    set_level(4);
    set_race("human");
    set_hp(100);
    set_al(200);
    set_gender(1);
    set_wc(6);
    set_ac(1);
    set_unarmed(1);
    add_property("no_flee");
    add_money(200 + random(200));

    load_chat(10,({ "Lallan says: Take my advice, leave while you still " +
                    "can.\n",
                    "Lallan says: If you're staying here, you'll be needing " +
                    "my wares.\n" }));
    load_a_chat(25,({ "Lallan shouts: Foul servant of Nirach!\n" }));
}
