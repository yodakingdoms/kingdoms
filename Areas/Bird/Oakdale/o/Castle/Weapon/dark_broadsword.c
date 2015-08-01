#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);

void create_object(void)
{
    set_name("sword");
    add_id("broadsword");
    add_id("darkling broadsword");
    set_short("a darkling broadsword");
    set_long("A well made broadsword made of black steel. The blade shines " +
             "in the light and on it's pommel is a small steel plate " +
             "engraved with a mark of a black dragon.\n");
    set_value(23);
    set_weight(2);
    set_type("longblade");
    set_class(15);
    set_material("steel");
    set_property("average");
}
