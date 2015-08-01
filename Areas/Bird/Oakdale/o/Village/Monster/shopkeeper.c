#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_woman";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("Alara the shopkeeper",1);
    set_long("Alara is a pretty lady with dark hair and brown eyes. She " +
             "looks a bit worried.\n");
    set_name("alara");
    add_id("shopkeeper");
    add_money(200);

    load_chat(5,({ "Alara says: There's nothing you can do for us. If you " +
                   "cause trouble, the villagers are the ones who will " +
                   "suffer.\n" }));
}
