#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);

void create_object(void)
{
    set_name("sword");
    add_id("twohanded sword");
    add_id("black twohanded sword");
    set_short("a black twohanded sword");
    set_long("A large twohanded sword made of shining black steel. It is " +
             "razor sharp and the blade reflects the light on an odd, " +
             "smooth way. Spidery runes run up and down the lenght of the " +
             "blade, and on it's pommel is a small steel plate engraved " +
             "with a mark of a black dragon. This is truly a magnificent " +
             "weapon.\n");
    set_value(76);
    set_weight(4);
    set_type("twohanded");
    set_class(26);
    set_material("steel");
    set_property("good");
}
