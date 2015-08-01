#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);

void create_object(void)
{
    set_name("bone");
    add_id("gnawed bone");
    add_id("human bone");
    set_short("a gnawed on human bone");
    set_long("A human bone that someone has been gnawing on. There are " +
             "still some small pieces of flesh on it.\n");
    set_value(10);
    set_weight(1);
    set_type("blunt");
    set_class(10);
    set_material("bone");
    set_property("average");
}
