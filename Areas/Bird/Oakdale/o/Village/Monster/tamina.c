#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_woman";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("A sick woman");
    set_long("Tamina Moloran has dark hair and sad eyes. She is lying in "+
             "bed, looking very pale.\n");
    set_name("tamina");
    add_id("sick woman");

    make(ARMOUR + "amulet");
    init_command("wear amulet");
    load_chat(4,({ "The woman mumbles: Why is it so dark in here?\n",
                   "The woman coughs violently.\n" }));

    load_a_chat(25,({ "The poor sick woman coughs up blood.\n" }));
}
