#pragma strict_types
#include "../def.h"
inherit STD_CONTAINER;

void create_object(void);

void create_object(void)
{
    set_name("basket");
    add_id("whicker basket");
    set_short("a basket");
    set_long("A whicker basket of the kind people bring when they go " +
             "shopping.\n");
    set_material("wood");
    set_value(12);
    set_weight(1);
    set_max_weight(4);
    set_property("average");
}
