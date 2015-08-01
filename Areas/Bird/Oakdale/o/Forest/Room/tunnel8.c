#include "../def.h"
#pragma strict_types
inherit ROOM + "tunnel_room";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_long("The corridor goes west and down to the east.\n");

    add_exit(ROOM + "tunnel7","west");
    add_exit(ROOM + "tunnel_castle_end","eastdown");
}
