#pragma strict_types
#include "../def.h"
inherit STD_HEAL;

void create_object(void)
{
    set_name("alepotion");
    add_id("potion");
    add_id("medicine");
    set_short("Alepotion");
    set_long("A potion made from ale. You feel a bit sceptical about the " +
             "healing powers of ale but if the apothekary says it works...\n");
    set_value(20);
    set_weight(1);
    set_strength(25);
    set_eater_mess("You drink the alepotion and feel a bit better.\n");
    set_eating_mess(" drinks the alepotion and seems to regain strength.\n");
}
