#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("shield");
    add_id("large shield");
    add_id("darkling shield");
    add_id("large darkling shield");
    set_short("a large darkling shield");
    set_long("A large shield made of black steel. It feels well balanced " +
             "and remarkably light. It is engraved with a mark of a black " +
             "dragon.\n");
    set_type("shield");
    set_weight(1);
    set_value(19);
    set_new_ac(5);
    set_db(3);
    set_material("steel");
    set_property("average");
}
