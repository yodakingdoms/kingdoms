#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("cloak");
    add_id("bearskin");
    add_id("skin");
    add_id("bear skin");
    add_id("bearskin cloak");
    set_short("a bearskin cloak");
    set_long("A cloak sewn together from the skins of a few bears. It is " +
             "very thick and will protect you from both attacks and cold.\n");
    set_type("cloak");
    set_weight(2);
    set_value(17);
    set_new_ac(4);
    set_material("fur");
    set_property("average");
}
