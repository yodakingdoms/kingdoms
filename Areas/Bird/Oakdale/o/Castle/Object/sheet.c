#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void);

void create_object(void)
{
    set_short("a black velvet sheet");
    set_long("A nice, soft, black velvet sheet. It looks pretty valuable.\n");
    set_name("sheet");
    set_value(450);
    set_weight(1);
    set_material("cloth");
}
