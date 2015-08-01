//==========================================================================
// master_indoors_room - The master room for the rooms in the caves. Just so
//                       I won't have to set descs for floor walls etc in
//                       each separate room.
// Yoda - 030925
//==========================================================================
#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

// Function declarations----------------------------------------------------

void create_object(void);

// Functions all rooms should have------------------------------------------

void create_object(void)
{
   set_new_light(1);
   add_property("indoors");

   add_item("stone|cold stone|grey stone|cold, grey stone|wall|"+
            "walls|floor|ceiling","Cold, grey stone");
}

//============================================================================
