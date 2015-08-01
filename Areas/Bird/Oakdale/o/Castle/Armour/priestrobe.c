#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("robe");
    add_id("black robe");
    set_short("a black robe");
    set_long("A black, modest looking robe. It feels soft and nice.\n");
    set_type("armour");
    set_weight(1);
    set_value(80);
    set_new_ac(10);
    set_material("velvet");
    set_property("average");
}
