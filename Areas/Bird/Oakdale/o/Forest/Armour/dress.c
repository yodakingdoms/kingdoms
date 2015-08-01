#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("dress");
    add_id("green dress");
    set_short("a green dress");
    set_long("A pretty green dress that would have looked good on any woman " +
             "ten years ago. It is a bit old fashioned.\n");
    set_type("armour");
    set_weight(1);
    set_value(41);
    set_new_ac(4);
    set_material("cotton");
    set_property("average");
}
