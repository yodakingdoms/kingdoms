#pragma strict_types
#include "../def.h"
inherit STD_HEAL;

void create_object(void)
{
    set_name("oakhealer");
    add_id("potion");
    add_id("medicine");
    set_short("an Oakhealer");
    set_long("This is the strong healing potion available in the " +
             "Oakdale apothek.\n");
    set_value(70);
    set_weight(1);
    set_strength(70);
    set_eater_mess("You drink the potion feeling how some of your " +
                   "concussion damage melts away.\n");
    set_eating_mess(" drinks the potion and seems to regain some strength.\n");
}
