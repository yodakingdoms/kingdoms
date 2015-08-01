#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("leather");
    add_id("darkling leather");
    add_id("armour");
    set_short("a darkling leather armour");
    set_long("A leather armour with a mark of a black dragon on it's chest. " +
             "The leather feels unnaturally smooth and flexible, and looks " +
             "almost like human skin.\n");
    set_type("armour");
    set_weight(3);
    set_value(83);
    set_new_ac(6);
    set_material("leather");
    set_property("good");
}
