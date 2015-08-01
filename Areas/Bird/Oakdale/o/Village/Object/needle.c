#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void);

void create_object(void)
{
    set_name("needle");
    add_id("steel needle");
    set_short("a steel needle");
    set_long("A small needle made of steel. This is the type of thing " +
             "commonly used for sowing.\n");
    set_value(60);
    set_weight(1);
    set_material("steel");
}
