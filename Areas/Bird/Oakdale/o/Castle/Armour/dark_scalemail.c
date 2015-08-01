#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void create_object(void);

void create_object(void)
{
    set_name("scalemail");
    add_id("darkling scalemail");
    set_short("a darkling scalemail");
    set_long("A strange looking scalemail made of large, black scales. You " +
             "can't imagine what beast these scales came from, but the " +
             "armour looks quite comfortable and balanced. On its chest is " +
             "a small steel plate engraved with a mark of a black dragon.\n");
    set_type("armour");
    set_weight(3);
    set_value(111);
    set_new_ac(20);
    set_material("dragonscale");
    set_property("average");
}
