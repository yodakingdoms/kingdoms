#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("robe");
    add_id("small robe");
    set_short("a small robe");
    set_long("A small robe made of black cloth.\n");
    set_type("armour");
    set_weight(2);
    set_value(41);
    set_new_ac(5);
    set_material("cloth");
    set_property("average");
}
