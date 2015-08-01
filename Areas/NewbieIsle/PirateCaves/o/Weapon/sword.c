#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void)
{
    set_short("A sword");
    set_long("A pretty normal looking sword.\n");
    set_name("sword");
    set_class(5);
    set_weight(1);
    set_value(10);
    set_material("iron");
    set_type("longblade");
    set_property("poor");
}
