#pragma strict_types
#include "../def.h"
inherit STD_BLOODCLOT;

void create_object(void)
{
    set_name("sailclot");
    add_id("clot");
    set_short("Sailclot");
    set_long("A piece of cloth from a sail that you can use to cover " +
             "a wound and clot it.\n");
    set_value(30);
    set_weight(1);
    set_strength(3);
    set_apply_mess("You apply the sailclot on a bleeding wound.\n");
    set_applying_mess(" applies the sailclot on a bleeding wound.\n");
}
