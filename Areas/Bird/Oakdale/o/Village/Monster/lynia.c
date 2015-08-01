#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_woman";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a babysitter");
    set_long("Lynia Raellin is a babysitter. She's an elderly woman with " +
             "white hair. Her husband and son were taken away by Nirach's " +
             "minions and ever since, she has been taking care of those " +
             "children of the village who have had their parents taken " +
             "away.\n");
    set_name("lynia");
    add_id("babysitter");

    make(ARMOUR + "dress");
    init_command("wear dress");

    load_chat(4,({ "The babysitter smiles at the children.\n",
                   "The babysitter says: Please leave. You are scaring the " +
                   "children.\n" }));
    load_a_chat(25,({ "The woman pleads: Please, don't hurt the " +
                      "children.\n" }));
}
