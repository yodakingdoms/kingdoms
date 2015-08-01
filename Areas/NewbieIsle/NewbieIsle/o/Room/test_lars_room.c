//==================================================================
// den_room - Room to store the animals during the night when they 
//            hide from the trolls. At dawn they will return to the
//            rooms they were before they came here at dusk to hide
//            from the trolls
//==================================================================
#pragma strict_types
#include "../def.h"
inherit STD_ROOM;

void create_object(void)
{
  set_short("Den room");
  set_long("This is supposed to be the Larstown harbour. I only use this "+
           "room to test while the area is closed.\n");
  set_new_light(5);
  set_skip_obvious(1);
  add_property("indoors");

  add_item("den","You are in it");
  add_item("ground","You are under it");
}
