#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("coat");
    add_id("white coat");
    set_short("a white coat");
    set_long("A white coat of the kind commonly worn by the staff at " +
             "mental institutions.\n");
    set_type("armour");
    set_weight(1);
    set_value(13);
    set_new_ac(3);
    set_material("cloth");
    set_property("poor");
}
