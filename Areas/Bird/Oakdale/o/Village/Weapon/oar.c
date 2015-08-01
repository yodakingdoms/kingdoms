#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);

void create_object(void)
{
    set_name("oar");
    add_id("wooden oar");
    add_id("heavy oar");
    add_id("heavy wooden oar");
    set_short("an oar");
    set_long("A heavy wooden oar that could be used as quite a formiddable "+
             "weapon.\n");
    set_value(6);
    set_weight(6);
    set_type("twohanded");
    set_class(5);
    set_material("wood");
    set_property("poor");
}
