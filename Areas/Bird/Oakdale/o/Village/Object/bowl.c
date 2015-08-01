#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void);

void create_object(void)
{
    set_name("bowl");
    add_id("wooden bowl");
    set_short("a wooden bowl");
    set_long("A small bowl made out of oak wood. It is very well made.\n");
    set_value(35);
    set_weight(1);
    set_material("wood");
}
