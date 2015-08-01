#include "../def.h"
#pragma strict_types
inherit ROOM + "tunnel_room";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_long("The corridor goes northwest and down to the south.\n");

    add_exit(ROOM + "tunnel1","northwest");
    add_exit(ROOM + "tunnel3","southdown");
}
