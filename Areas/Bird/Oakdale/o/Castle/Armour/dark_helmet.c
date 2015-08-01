#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("helmet");
    add_id("darkling helmet");
    set_short("a darkling helmet");
    set_long("A helmet made of black steel. The steel is smooth and hard, " +
             "and on it's forehead is a small steel plate engraved with a " +
             "mark of a black dragon.\n");
    set_type("helmet");
    set_weight(1);
    set_value(18);
    set_new_ac(4);
    set_material("steel");
    set_property("average");
}
