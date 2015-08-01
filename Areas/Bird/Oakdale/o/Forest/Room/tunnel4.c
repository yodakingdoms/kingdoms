#include "../def.h"
#pragma strict_types
inherit ROOM + "tunnel_room";

void create_object(void);

void create_object(void)
{
    set_long("The corridor goes northwest and southeast.\n");
    
    add_exit(ROOM + "tunnel3","northwest");
    add_exit(ROOM + "tunnel5","southeast");
}
