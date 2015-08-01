#pragma strict_types
#include "../def.h"
inherit STD_CONTAINER;

void create_object(void);

void create_object(void)
{
    set_name("pouch");
    add_id("leather pouch");
    set_short("a black leather pouch");
    set_long("A small pouch of black leather. Two leather thongs are " +
             "fastened to it, apparently for hanging the pouch around " +
             "one's neck. However, they are broken and are now too " +
             "short.\n");
    set_weight(1);
    set_value(8);
    set_max_weight(2);
    set_material("leather");
    set_property ("poor");
}
