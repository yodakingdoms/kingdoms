#pragma strict_types
#include "../def.h"
inherit STD_CONTAINER;

void create_object()
{
   set_short("A small pouch");
   set_long("A small leather pouch, used to keep money in.\n");
   set_name("pouch");
   set_material("leather");
   set_value(5);
   set_weight(1);
   set_max_weight(2);

   make(STD_MONEY)->set_money(50 + random(100));
}
