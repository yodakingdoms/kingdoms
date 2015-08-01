#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("leggings");
    add_id("darkling leggings");
    set_short("a pair of darkling leggings");
    set_long("Platemail leggings made of black, shining steel. They are " +
             "engraved with a mark of a black dragon.\n");
    set_type("legging");
    set_weight(1);
    set_value(16);
    set_new_ac(4);
    set_material("steel");
    set_property("average");
}
