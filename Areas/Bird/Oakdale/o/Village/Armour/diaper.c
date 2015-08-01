#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("diaper");
    add_id("a diaper");
    set_short("a diaper");
    set_long("A small, yellow diaper... Hmm... Yellow?!?! BLAEH!!!!!\n");
    set_type("armour");
    set_weight(1);
    set_value(1);
    set_new_ac(1);
    set_material("cloth");
    set_property("poor");
}
