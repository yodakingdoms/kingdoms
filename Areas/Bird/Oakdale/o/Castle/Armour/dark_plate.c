#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("plate");
    add_id("darkling plate");
    set_short("a darkling plate");
    set_long("A breastplate made of black steel. The steel is smooth and " +
             "hard and the armour looks very well made. A mark of a black " +
             "dragon is engraved on the breastplate.\n");
    set_type("armour");
    set_weight(5);
    set_value(235);
    set_new_ac(25);
    set_material("steel");
    set_property("good");
}
