#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);

void create_object(void)
{
    set_name("knife");
    set_short("a knife");
    set_long("A dull, quite ordinary knife.\n");
    set_class(2);
    set_weight(1);
    set_value(3);
    set_type("dagger");
    set_material("iron");
    set_property("poor");
}
