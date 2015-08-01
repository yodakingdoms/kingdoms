#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);

void create_object(void)
{
    set_name("stick");
    add_id("walking stick");
    set_short("a walking stick");
    set_long("A finely crafted walking stick made of oak. It is thin and " +
             "slender and the 'knob' at the top of it is carved to resemble " +
             "the canopy of an oak.\n");
    set_value(10);
    set_weight(1);
    set_type("blunt");
    set_class(6);
    set_material("wood");
    set_property("poor");
}
