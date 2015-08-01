#pragma strict_types
#include "../def.h"
inherit STD_HEAL;

void create_object(void)
{
    set_name("chlorofyl");
    add_id("potion");
    add_id("crit");
    add_id("anticrit");
    set_short("a vial of chlorofyl");
    set_long("This is the strongest anticritical potion sold in the " +
             "Oakdale apothek.\n");
    set_value(30);
    set_weight(1);
    set_critical_strength(6);
    set_eater_mess("You drink the potion feeling how your critical damage " +
                   "melts away.\n");
    set_eating_mess(" drinks the potion and seems relieved from dangerous " +
                    "damage.\n");
}
