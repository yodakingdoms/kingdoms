#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void);

void create_object(void)
{
    set_name("pipe");
    add_id("wooden pipe");
    set_short("An small wooden pipe");
    set_long("A small wooden pipe. It does not appear to be in a very good " +
             "condition, and it does not look like you could use it.\n");
    set_value(30);
    set_weight(1);
    set_material("wood");
}
