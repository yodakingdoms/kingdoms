#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("hood");
    add_id("leather hood");
    set_short("a leather hood");
    set_long("A small leather hood of the type commonly worn by gnomes.\n");
    set_type("helmet");
    set_weight(1);
    set_value(17);
    set_new_ac(4);
    set_material("leather");
    set_property("average");
}
