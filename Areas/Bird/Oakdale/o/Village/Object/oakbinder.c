#pragma strict_types
#include "../def.h"
inherit STD_BLOODCLOT;

void create_object(void)
{
    set_name("oakbinder");
    add_id("clot");
    set_short("an oakbinder");
    set_long("This is the weakest of the bloodclotters sold in the " +
             "Oakdale apothek.\n");
    set_value(25);
    set_weight(1);
    set_strength(3);
    set_apply_mess("You apply the oakbinder on a bleeding wound.\n");
    set_applying_mess(" applies the oakbinder on a bleeding wound.\n");
}
