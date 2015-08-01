#include "../def.h"
#pragma strict_types
inherit ROOM + "tunnel_room";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_long("The corridor goes to the northwest and down to the south.\n");
    
    add_exit(ROOM + "tunnel4","northwest");
    add_exit(ROOM + "tunnel6","southdown");
}
