#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("boot");
    add_id("boots");
    add_id("darkling boots");
    set_short("a pair of darkling boots");
    set_long("A pair of black leather boots with a net of steel rings on " +
             "the outside. On the side of each boot is a small steel plate " +
             "engraved with a mark of a black dragon.\n");
    set_type("boot");
    set_weight(1);
    set_value(9);
    set_new_ac(2);
    set_material("leather");
    set_property("poor");
}
