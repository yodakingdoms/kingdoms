#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("necklace");
    set_short("a necklace");
    set_long("A small stone hanging in a steel chain.\n");
    set_type("amulet");
    set_weight(2);
    set_value(18);
    set_db(2);
    set_material("steel");
    set_property("average");
}
