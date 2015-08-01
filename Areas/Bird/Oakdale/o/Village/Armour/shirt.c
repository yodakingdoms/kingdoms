#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("shirt");
    add_id("torn shirt");
    set_short("a torn shirt");
    set_long("A torn shirt that badly needs to be fixed.\n");
    set_type("armour");
    set_weight(1);
    set_value(4);
    set_new_ac(2);
    set_material("cloth");
    set_property("poor");
}
