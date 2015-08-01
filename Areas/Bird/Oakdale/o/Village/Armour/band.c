#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("band");
    add_id("hairband");
    add_id("velvet band");
    add_id("black velvet band");
    set_short("A black velvet band");
    set_long("A beautiful black velvet hairband. This would look good in " +
             "anyones hair.\n");
    set_type("helmet");
    set_weight(1);
    set_value(6);
    set_new_ac(2);
    set_material("velvet");
    set_property("poor");
}
