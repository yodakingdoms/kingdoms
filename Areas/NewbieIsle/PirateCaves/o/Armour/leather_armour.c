#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void)
{
    set_short("A leather armour");
    set_long("A pretty normal looking leather armour.\n");
    set_name("armour");
    add_id("leather armour");
    set_value(30);
    set_weight(2);
    set_material("leather");
    set_new_ac(6);
    set_type("armour");
    set_property("poor");
}
