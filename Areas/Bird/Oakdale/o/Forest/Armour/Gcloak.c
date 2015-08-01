#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("cloak");
    add_id("leather cloak");
    set_short("a leather cloak");
    set_long("A small cloak made of leather.\n");
    set_type("cloak");
    set_weight(1);
    set_value(17);
    set_new_ac(4);
    set_material("leather");
    set_property("average");
}
