#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("bandage");
    set_short("a bandage");
    set_long("White bandage. You wrap this around parts of your body that " +
             "get hurt\n");
    set_type("legging");
    set_weight(1);
    set_value(4);
    set_new_ac(2);
    set_material("cloth");
    set_property("poor");
}
