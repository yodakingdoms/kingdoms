#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("amulet");
    add_id("dragontooth amulet");
    set_short("a dragontooth amulet");
    set_long("A long, black tooth hanging from a silver chain. The tooth " +
             "is warm to the touch, and you think you can feel it pulsate " +
             "with power. It shines with a dull light.\n");
    set_type("amulet");
    set_weight(1);
    set_value(50);
    set_light(1);
    set_db(5);
    set_material("tooth");
    set_property("good");
}
