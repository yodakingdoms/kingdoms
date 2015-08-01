#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);

void create_object(void)
{
    set_name("staff");
    add_id("wooden staff");
    add_id("thin staff");
    add_id("thin wooden staff");
    set_short("a thin wooden staff");
    set_long("A short, slender staff made of oak wood.\n");
    set_value(16);
    set_weight(1);
    set_type("blunt");
    set_class(14);
    set_material("wood");
    set_property("average");
}
