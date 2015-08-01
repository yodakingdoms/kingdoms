#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("platemail");
    add_id("darkling platemail");
    set_short("a darkling platemail");
    set_long("A magnificent platemail armour made of black steel. The " +
             "armour is ornamented with strange, engraved patterns and on " +
             "it's breastplate is a small steel plate engraved with a mark " +
             "of a black dragon.\n");
    set_type("armour");
    set_weight(4);
    set_value(126);
    set_new_ac(22);
    set_material("steel");
    set_property("average");
}
