#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void);

void create_object(void)
{
    set_name("flute");
    set_short("a white flute");
    set_long("A beautiful, slender flute made of oak. The flute is " +
             "decorated with exquisitly carved images of oakleafs.\n");
    set_value(300);
    set_weight(1);
    set_material("wood");
}



