#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("apron");
    add_id("velvet apron");
    add_id("blue velvet apron");
    set_short("a blue velvet apron");
    set_long("An apron made of blue velvet. You marvel at the " +
             "unpracticallity of having an apron made of such a delicate " +
             "material.\n");
    set_type("armour");
    set_weight(1);
    set_value(25);
    set_new_ac(1);
    set_material("velvet");
    set_property("poor");
}
