#include "../def.h"
#pragma strict_types
inherit ROOM + "tunnel_room";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_long("The corridor goes west and southeast.\n");
    
    add_exit(ROOM + "tunnel_cave_end","west");
    add_exit(ROOM + "tunnel2","southeast");
}
