#pragma strict_types
#include "../def.h"
#include <doorcontrol.h>
inherit DOOR_CONTROL;

void create_object(void);

void create_object()
{
  ::create_object();
  add_door_room("fence_gate","fence_gate","farm_gate",
                "west","in the fence", "gate",
                "A finely crafted wooden gate in the fence.\n",NOT_HIDDEN);
  add_door_room("fence_gate","farm_gate","fence_gate",
                "east","in the fence", "gate",
                "A finely crafted wooden gate in the fence.\n",NOT_HIDDEN);
  set_door_info("fence_gate",CLOSED,NO_LOCK,NO_KEY,50,UNPICKABLE);

  add_door_id("fence_gate","gate|wooden gate|finely crafted wooden gate");
}
