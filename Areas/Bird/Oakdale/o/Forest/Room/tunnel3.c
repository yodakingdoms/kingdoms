#include "../def.h"
#pragma strict_types
inherit ROOM + "tunnel_room";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_long("The corridor goes southeast and up to the north.\n");

    add_exit(ROOM + "tunnel2","northup");
    add_exit(ROOM + "tunnel4","southeast");
}
