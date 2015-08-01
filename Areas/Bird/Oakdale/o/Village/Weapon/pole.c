#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);

void create_object(void)
{
    set_name("pole");
    add_id("fishing pole");
    set_short("a fishing pole");
    set_long("A thin, slender fishing pole made of oak.\n");
    set_value(9);
    set_weight(2);
    set_type("blunt");
    set_class(5);
    set_material("wood");
    set_property("poor");
}
