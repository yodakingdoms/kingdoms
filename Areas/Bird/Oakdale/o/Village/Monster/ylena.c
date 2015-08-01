#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_woman";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a woman");
    set_long("Ylena Tiralam has long, red hair and brown eyes. She is " +
             "taking care of her newborn baby.\n");
    set_name("ylena");

    make(ARMOUR + "dress");
    init_command("wear dress");

    load_chat(4,({ "Ylena frowns as she examines her baby's diaper.\n",
                   "The woman whispers to herself: Will Nirach ever let you " +
                   "grow up, little one...\n" }));
}
