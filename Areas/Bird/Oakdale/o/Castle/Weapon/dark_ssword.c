#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);

void create_object(void)
{
    set_name("shortsword");
    add_id("sword");
    add_id("darkling shortsword");
    set_short("a darkling shortsword");
    set_long("A well made short sword with a small steel plate engraved " +
             "with a mark of a black dragon on it's pommel.\n");
    set_value(10);
    set_weight(2);
    set_type("shortblade");
    set_class(12);
    set_material("steel");
    set_property("average");
}
