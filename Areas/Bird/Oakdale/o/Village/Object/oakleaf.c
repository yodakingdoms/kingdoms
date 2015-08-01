#pragma strict_types
#include "../def.h"
inherit STD_BLOODCLOT;

void create_object(void)
{
    set_name("oakleaf");
    add_id("clot");
    set_short("an oakleaf");
    set_long("This is the best of the bloodclotters sold in the " +
             "Oakdale apothek.\n");
    set_value(50);
    set_weight(1);
    set_strength(8);
    set_apply_mess("You apply the oakleaf on a bleeding wound.\n");
    set_applying_mess(" applies the oakleaf on a bleeding wound.\n");
}
