//====================================================================
// stone_troll - Cloned into a room when a troll happens to turn to
//               stone - Set_long() is called by the troll itself when
//               it is destroyed to set the proper long description
//--------------------------------------------------------------------
// Added crumble function to remove them in case they get too many.
// Might remove it in the future if the trolls work as planned and
// don't get stoned too often.
// Yoda - 990416
//====================================================================
#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void);
void crumble(void);

void create_object(void)
{
  set_name("stone troll");
  add_id("troll");
  add_id("statue");
  set_short("A stone troll");
  set_weight(35);
  set_value(250);
  set_material("stone");

  set_alarm(300.0,0.0,"crumble");
} 

void crumble(void)
{
  tell_room(ENV(TO),"The stone troll crumbles to dust and disappears.\n");
  destroy();
}
