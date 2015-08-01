#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);

void create_object(void)
{
    set_name("spoon");
    add_id("wooden spoon");
    set_short("a wooden spoon");
    set_long("A wooden spoon made of oak.\n");
    set_value(3);
    set_weight(1);
    set_type("blunt");
    set_class(5);
    set_material("wood");
    set_property("poor");
}
