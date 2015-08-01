#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("gloves");
    add_id("leather gloves");
    set_short("a pair of leather gloves");
    set_long("A pair of small leather gloves.\n");
    set_type("glove");
    set_weight(1);
    set_value(15);
    set_new_ac(4);
    set_material("leather");
    set_property("average");
}
