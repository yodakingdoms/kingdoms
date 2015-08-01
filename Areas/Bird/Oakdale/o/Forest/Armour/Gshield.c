#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("shield");
    add_id("small shield");
    set_short("a small shield");
    set_long("A small wooden shield.\n");
    set_type("shield");
    set_weight(1);
    set_value(18);
    set_new_ac(4);
    set_material("wood");
    set_property("average");
}
