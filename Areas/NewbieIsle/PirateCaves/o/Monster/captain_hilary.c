#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void)
{
    set_short("Captain Hilary Rosen",1);
    set_long("Hilary is the captain of the Riaa. She rules it with an " +
             "iron hand. She has made it her mission in life to end piracy " +
             "and protect the bards who trust the Riaa to distribute " +
             "their goods around the world. She's not doing very well " +
             "at this particular moment.\n");
    set_name("hilary");
    add_id("captain"); //Added by Angelwings
    add_id("captain hilary");
    add_id("captain hilary rosen");
    add_id("hilary rosen");

    set_level(2);
    set_race("human");
    set_hp(80 + random(25));
    set_al(0);
    add_money(100 + random(20));
    set_gender(2);
    set_skill("combat",20 + random(10));

    make(PCWEAPON + "sword");
    make(PCARMOUR + "leather_armour");
    init_command("wield sword");
    init_command("wear armour");

    load_chat(10,({
        "Hilary says: Sign on to my crew and I'll make you rich and famous.\n",
        "Hilary says: All I do, I do for the bards.\n",
    }));
}
