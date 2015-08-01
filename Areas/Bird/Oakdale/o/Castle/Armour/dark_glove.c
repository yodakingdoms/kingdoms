#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("gloves");
    add_id("glove");
    add_id("black gloves");
    add_id("black glove");
    set_short("a pair of black gloves");
    set_long("A pair of black gloves made of black leather. The leather " +
             "feels unnaturally smooth and flexible, and looks almost like " +
             "human skin.\n");
    set_type("glove");
    set_weight(1);
    set_value(7);
    set_new_ac(3);
    set_material("leather");
    set_property("poor");
}
