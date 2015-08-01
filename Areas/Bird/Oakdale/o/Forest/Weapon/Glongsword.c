#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);

void create_object(void)
{
    set_name("sword");
    add_id("longsword");
    add_id("steel longsword");
    set_short("a longsword");
    set_long("A steel longsword. It is a bit shorter than they normally " +
             "are.\n");
    set_value(17);
    set_weight(2);
    set_type("longblade");
    set_class(14);
    set_material("steel");
    set_property("average");
}
