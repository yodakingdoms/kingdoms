//==========================================================================
// master_indoors_room - Master room for indoors rooms.
//==========================================================================
#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_new_light(1);
    add_property("indoors");
}
