#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void);

void create_object(void)
{
    set_name("cloth");
    add_id("damp cloth");
    set_short("a damp cloth");
    set_long("A piece of damp cloth.\n");
    set_value(25);
    set_weight(1);
    set_material("cloth");
}
