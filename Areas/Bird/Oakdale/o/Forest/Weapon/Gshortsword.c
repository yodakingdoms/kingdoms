#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);

void create_object(void)
{
    set_name("sword");
    add_id("short sword");
    set_short("a short sword");
    set_long("A small sword of dark gnome make.\n");
    set_value(11);
    set_weight(2);
    set_type("shortblade");
    set_class(10);
    set_material("steel");
    set_property("average");
}
