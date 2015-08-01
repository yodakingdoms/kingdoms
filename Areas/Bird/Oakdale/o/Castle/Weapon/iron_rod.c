#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);

void create_object(void)
{
    set_name("rod");
    add_id("iron rod");
    add_id("glowing iron rod");
    set_short("a glowing iron rod");
    set_long("A redglowing iron rod that has been heated up over a fire. " +
             "It's cooling down a bit now, but it is still hot to the " +
             "touch.\n");
    set_value(10);
    set_weight(3);
    set_type("blunt");
    set_class(17);
    set_material("iron");
    set_property("average");
}
