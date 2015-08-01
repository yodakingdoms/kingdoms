#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    string *color = ({ "blue","red","green" });
    int i = random(3);
    set_name("dress");
    add_id(color[i] + " dress");
    add_id("velvet dress");
    set_short("a " + color[i] + " dress");
    set_long("A nice " + color[i] + " dress made of velvet. This dress " +
             "would make anyone look beautiful.\n");
    set_type("armour");
    set_weight(2);
    set_value(16);
    set_new_ac(2);
    set_material("velvet");
    set_property("poor");
}
