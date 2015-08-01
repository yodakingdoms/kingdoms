#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("gnomish chaimail");
    add_id("chainmail");
    set_short("a gnomish chainmail");
    set_long("An average looking steel chainmail.\n");
    set_type("armour");
    set_weight(3);
    set_value(83);
    set_new_ac(13);
    set_material("steel");
    set_property("average");
}
