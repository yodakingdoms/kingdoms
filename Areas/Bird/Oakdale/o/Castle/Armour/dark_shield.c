#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("shield");
    add_id("darkling shield");
    set_short("a darkling shield");
    set_long("A shield made of black steel. It feels well balanced and it " +
             "is engraved with a mark of a black dragon.\n");
    set_type("shield");
    set_weight(1);
    set_value(43);
    set_new_ac(6);
    set_db(6);
    set_material("steel");
    set_property("good");
}
