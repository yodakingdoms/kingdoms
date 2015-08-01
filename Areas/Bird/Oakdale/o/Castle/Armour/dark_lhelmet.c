#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("helmet");
    add_id("darkling helmet");
    add_id("light helmet");
    add_id("light darkling helmet");
    set_short("a light darkling helmet");
    set_long("A light helmet made of black steel. On it's forehead is a " +
             "small steel plate engraved with a mark of a black dragon.\n");
    set_type("helmet");
    set_weight(1);
    set_value(16);
    set_new_ac(5);
    set_material("steel");
    set_property("average");
}
