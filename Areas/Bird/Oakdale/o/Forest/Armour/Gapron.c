#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("apron");
    add_id("leather apron");
    set_short("a leather apron");
    set_long("A black leather apron. It is absolutely filthy!!\n");
    set_type("armour");
    set_weight(1);
    set_value(30);
    set_new_ac(5);
    set_material("leather");
    set_property("average");
}
