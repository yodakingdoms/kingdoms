#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void)
{
    set_short("A trashcan");
    set_long("A steel trashcan. It doesn't look as if it's useful for " +
             "anything but making noise.\n");
    set_name("trashcan");
    add_id("steel");
    add_id("steel trashcan");
    set_weight(1);
    set_value("10");
    set_material("steel");
}
