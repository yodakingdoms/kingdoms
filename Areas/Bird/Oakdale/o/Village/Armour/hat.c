#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("hat");
    add_id("leather hat");
    set_short("a hat");
    set_long("A hat made out of leather.\n");
    set_type("helmet");
    set_weight(1);
    set_value(8);
    set_new_ac(2);
    set_material("leather");
    set_property("poor");
}
