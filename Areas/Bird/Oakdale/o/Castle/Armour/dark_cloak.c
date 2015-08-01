#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("cloak");
    add_id("velvet cloak");
    add_id("black velvet cloak");
    set_short("a black velvet cloak");
    set_long("A long, flowing cloak made of black velvet with steel threads " +
             "sown into it. This cloak is both protective and elegant and a " +
             "mark of a black dragon is sown into it's back with black " +
             "steel threads.\n");
    set_type("cloak");
    set_weight(1);
    set_value(7);
    set_new_ac(3);
    set_material("velvet");
    set_property("poor");
}
