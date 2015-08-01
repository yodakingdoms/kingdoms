#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void)
{
    set_short("A leather armour");
    set_long("A scruffy looking leather armour that looks as if it has "+
             "seen its fair share of battles.\n");
    set_name("armour");
    add_id("leather armour");
    set_value(25);
    set_weight(2);
    set_material("leather");
    set_new_ac(5);
    set_type("armour");
    set_property("poor");
}
