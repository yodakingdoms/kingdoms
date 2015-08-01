#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);

void create_object(void)
{
    set_name("sword");
    add_id("bastardsword");
    add_id("darkling bastardsword");
    set_short("a darkling bastardsword");
    set_long("A black steel bastardsword that looks very sharp. The blade " +
             "shines in the light and the sword feels very well balanced. " +
             "This is truly a magnificent weapon. On it's pommel is a small " +
             "steel plate engraved with a mark of a black dragon.\n");
    set_value(51);
    set_weight(3);
    set_type("longblade");
    set_class(26);
    set_material("steel");
    set_property("good");
}
