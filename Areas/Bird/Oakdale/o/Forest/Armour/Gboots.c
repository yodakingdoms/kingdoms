#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("boots");
    add_id("boot");
    add_id("leather boots");
    set_short("a pair of leather boots");
    set_long("A pair of small leather boots.\n");
    set_type("boot");
    set_weight(1);
    set_value(13);
    set_new_ac(4);
    set_material("leather");
    set_property("average");
}
