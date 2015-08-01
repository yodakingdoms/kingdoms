#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);

void create_object(void)
{
    set_name("sword");
    add_id("longsword");
    add_id("darkling longsword");
    set_short("a darkling longsword");
    set_long("A long sword made of black steel. The steel is smooth and " +
             "hard, and looks very sharp. On the pommel is a small steel " +
             "plate engraved with a mark of a black dragon.\n");
    set_value(20);
    set_weight(2);
    set_type("longblade");
    set_class(16);
    set_material("steel");
    set_property("average");
}
