#pragma strict_types
#include "../def.h"
inherit STD_HEAL;

void create_object(void)
{
    set_name("rumpotion");
    add_id("potion");
    add_id("medicine");
    set_short("Rumpotion");
    set_long("A potion made from rum. You feel a bit sceptical about the " +
             "healing powers of rum but if the apothekary says it works...\n");
    set_value(35);
    set_weight(1);
    set_strength(45);
    set_eater_mess("You drink the rumpotion and feel a bit better.\n");
    set_eating_mess(" drinks the rumpotion and seems to regain strength.\n");
}
