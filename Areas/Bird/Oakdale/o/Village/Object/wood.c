#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void);

void create_object(void)
{
    set_name("wood");
    add_id("piece");
    add_id("piece of wood");
    set_short("A piece of wood");
    set_long("A small piece of wood that has been carved into the form of " +
             "a fish.\n");
    set_value(30);
    set_weight(1);
    set_material("wood");
}
