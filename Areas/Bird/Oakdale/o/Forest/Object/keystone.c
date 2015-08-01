#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void);

void create_object(void)
{
    set_name("jewel");
    add_id("strange jewel");
    add_id("_secret_door_keystone_");
    set_short("A strange jewel");
    set_long("A small, strange stone. One half of the stone looks like a " +
             "dull, ordinary, grey stone. The other half, however is a " +
             "shining white diamond, immaculately cut.\n");
    set_weight(1);
    set_value(350);
    set_material("diamond");
    add_property("quest");
}
