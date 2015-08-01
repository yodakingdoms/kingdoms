#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void)
{
    set_short("A black shirt");
    set_long("A black shirt with some strange white patterns on it.\n");
    set_name("shirt");
    add_id("black shirt");
    set_value(20);
    set_weight(2);
    set_material("cloth");
    set_new_ac(5);
    set_type("armour");
    set_property("poor");
}
