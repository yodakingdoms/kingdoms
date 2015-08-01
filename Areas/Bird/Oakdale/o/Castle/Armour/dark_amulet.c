#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("amulet");
    add_id("steel amulet");
    add_id("black steel amulet");
    set_short("a black steel amulet");
    set_long("A small steel plate hanging from a chain of black steel " +
             "rings. The steel plate is engraved with a mark of a black " +
             "dragon.\n");
    set_type("amulet");
    set_weight(1);
    set_value(7);
    set_material("steel");
    set_property("poor");
}
