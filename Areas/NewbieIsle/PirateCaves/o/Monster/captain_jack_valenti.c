#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void)
{
    set_short("Captain Jack Valenti",1);
    set_long("Jack Valenti does not belong to the crew of the Riaa. He's " +
             "the commander for the Mpaa, another ship that has had " +
             "problems with pirates lately. He's onboard to study how " +
             "the crew of the Riaa deals with the problem of piracy, but " +
             "he doesn't look terribly impressed at the moment.\n");
    set_name("jack");
    add_id("captain");
    add_id("captain jack");
    add_id("captain jack valenti");
    add_id("jack valenti");

    set_level(2);
    set_race("human");
    set_hp(80 + random(25));
    set_al(0);
    add_money(100 + random(20));
    set_gender(1);
    set_skill("combat",20 + random(10));

    make(PCWEAPON + "sword");
    make(PCARMOUR + "leather_armour");
    init_command("wield sword");
    init_command("wear armour");

    load_chat(10,({
        "Jack says: Stop them, Hilary. If they take the Riaa, the Mpaa " +
        "might be next.\n",
    }));
}
