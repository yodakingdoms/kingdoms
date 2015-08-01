#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);

void create_object(void)
{
    set_name("mace");
    add_id("black mace");
    add_id("black steel mace");
    set_short("a black steel mace");
    set_long("An impressive looking mace made of black steel, It feels very " +
             "well balanced and on the handle is a mark of a black dragon.\n");
    set_value(18);
    set_weight(3);
    set_type("blunt");
    set_class(15);
    set_material("steel");
    set_property("average");
}
