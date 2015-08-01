#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("shield");
    add_id("small darkling shield");
    add_id("small shield");
    set_short("a small darkling shield");
    set_long("A small shield made of black steel. It feels very well " +
             "balanced and it is engraved with a mark of a black dragon.\n");
    set_type("shield");
    set_weight(1);
    set_value(18);
    set_new_ac(5);
    set_db(1);
    set_material("steel");
    set_property("average");
}
