#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void)
{
    set_short("A drumstick");
    set_long("A wooden drumstick with the word 'Zildjian' written on it.\n");
    set_name("drumstick");
    add_id("stick");
    add_id("wooden drumstick");
    set_class(5);
    set_weight(1);
    set_value(10);
    set_material("wood");
    set_type("blunt");
    set_property("poor");
}
