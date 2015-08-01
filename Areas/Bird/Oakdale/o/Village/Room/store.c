#pragma strict_types
#include "../def.h"
inherit STD_STORE;

void create_object(void);

void create_object(void)
{
    set_short("Shop storeroom");
    set_long("Storeroom for the shop. If you are a mortal you sure " +
             "are in a place you should not be.\n");
    set_new_light(10);
    add_property("indoors");

    add_exit(ROOM + "shop","south");

    reset(0);
}
