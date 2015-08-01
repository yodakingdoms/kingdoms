#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("helmet");
    add_id("plumed helmet");
    add_id("black plumed helmet");
    set_short("a black plumed helmet");
    set_long("A black steel helmet with a long plume of black hair. The " +
             "steel is smooth and hard and the plume adds to the impressive " +
             "look of the helmet. On it's forehead is a small steel plate " +
             "engraved with a mark of a black dragon.\n");
    set_type("helmet");
    set_weight(1);
    set_value(39);
    set_new_ac(7);
    set_material("steel");
    set_property("good");
}
