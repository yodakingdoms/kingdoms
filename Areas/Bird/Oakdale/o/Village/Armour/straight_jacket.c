#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("straight jacket");
    add_id("jacket");
    add_id("vest");
    set_short("A straight jacket");
    set_long("A white vest with straps round the back. The straps are " +
             "attached to the sleeves, and once you are trapped in this " +
             "thing, you'll never get out without help.\n");
    set_type("armour");
    set_weight(3);
    set_value(12);
    set_new_ac(5);
    set_material("leather");
    set_property("average");
}
