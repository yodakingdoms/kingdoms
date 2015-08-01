#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void);

void create_object(void)
{
    set_name("ball");
    add_id("small ball");
    set_short("a small ball");
    set_long("A small ball made of leather. It looks as if it has seen "+
             "better days.\n");
    set_weight(1);
    set_value(30);
    set_material("leather");
}
