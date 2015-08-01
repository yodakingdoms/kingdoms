#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_short("Elanor Bumbleroot",1);
    set_long("Elanor is the wife of Ferdirand Bumbleroot who runs this " +
             "farm. Elanor is walking around in the garden, tending to " +
             "the different things growing here.\n");
    set_name("elanor");
    add_id("elanor bumbleroot");
    add_id("hobbit");
    add_id("wife");

    set_level(2);
    set_hp(30);
    set_unarmed(1);
    set_race("hobbit");
    set_al(300);
    add_money(random(20));
    set_gender(2);

    load_chat(5,({
        "Elanor tends to the carrots.\n",
        "Elanor mumbles: These carrots are a bit too small to eat.\n",
        "Elanor says: Ferdirand needs some help with the corn field.\n",
        "Elanor smiles happily.\n",
        "Elanor muses: This carrot would make a nice nose for a scarecrow.\n",
    }));
}
