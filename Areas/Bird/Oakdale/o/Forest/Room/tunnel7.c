#include "../def.h"
#pragma strict_types
inherit ROOM + "tunnel_room";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_long("The corridor goes north and east.\n");
    
    add_exit(ROOM + "tunnel6","north");
    add_exit(ROOM + "tunnel8","east");
}
