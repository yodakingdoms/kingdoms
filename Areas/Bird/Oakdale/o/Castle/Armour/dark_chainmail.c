#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("chainmail");
    add_id("darkling chainmail");
    set_short("a darkling chainmail");
    set_long("A chainmail made of rings of black steel carefully fitted " +
             "together. On it's chest is a small steel plate engraved with " +
             "a mark of a black dragon.\n");
    set_type("armour");
    set_weight(4);
    set_value(87);
    set_new_ac(12);
    set_material("steel");
    set_property("average");
}
