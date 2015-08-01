#pragma strict_types
#include "../def.h"
inherit STD_HEAL;

void create_object(void)
{
    set_name("saltwater");
    add_id("potion");
    add_id("crit");
    set_short("Saltwater");
    set_long("A potion made from saltwater. It's supposed to heal critical " +
             "damage but you are a bit sceptical about the healing powers " +
             "of saltwater.\n");
    set_value(30);
    set_weight(1);
    set_critical_strength(6);
    set_eater_mess("You drink the saltwater feeling how your critical " +
                   "damage melts away.\n");
    set_eating_mess(" drinks the saltwater and seems relieved from " +
                    "dangerous damage.\n");
}
