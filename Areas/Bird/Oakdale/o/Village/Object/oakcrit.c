#pragma strict_types
#include "../def.h"
inherit STD_HEAL;

void create_object(void)
{
    set_name("oakcrit");
    add_id("potion");
    add_id("crit");
    add_id("anticrit");
    set_short("an Oakcrit");
    set_long("This is the weakest anticritical potion sold in the " +
             "Oakdale apothek.\n");
    set_value(10);
    set_weight(1);
    set_critical_strength(2);
    set_eater_mess("You drink the potion feeling how your critical damage " +
                   "melts away.\n");
    set_eating_mess(" drinks the potion and seems relieved from dangerous " +
                    "damage.\n");
}
