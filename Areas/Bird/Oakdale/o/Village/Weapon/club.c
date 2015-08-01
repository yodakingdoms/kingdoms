#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);

void create_object(void)
{
    set_name("club");
    add_id("wooden club");
    set_short("a wooden club");
    set_long("A wooden club used by the warden to keep the lunatics under " +
             "control.\n");
    set_value(7);
    set_weight(3);
    set_type("blunt");
    set_class(8);
    set_material("wood");
    set_property("poor");
}
