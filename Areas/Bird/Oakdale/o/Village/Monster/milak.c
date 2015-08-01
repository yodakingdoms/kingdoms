#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_man";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a merchant");
    set_long("Milak Tiralam is a merchant. He is selling groceries at the " +
             "square, but it does not look like he has much to sell.\n");
    set_name("milak");
    add_id("merchant");

    make(WEAPON + "carrots");
    init_command("wield carrots");

    load_chat(4,({ "The merchant says: These are very high quality carrots.\n",
                   "The merchant says: Business has never been this " +
                   "bad.\n" }));
}
