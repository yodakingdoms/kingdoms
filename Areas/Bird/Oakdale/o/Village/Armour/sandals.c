#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("sandals");
    add_id("pair");
    set_short("a pair of sandals");
    set_long("A pair of light sandals.\n");
    set_type("boot");
    set_weight(1);
    set_value(4);
    set_new_ac(1);
    set_material("leather");
    set_property("poor");
}
