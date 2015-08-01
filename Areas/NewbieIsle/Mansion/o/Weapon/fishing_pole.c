#pragma strict_types
#include "../def.h"
inherit STD_WEAPON;

void create_object(void);

void create_object(void)
{
  set_short("A substandard fishing pole");
  set_long("A short fishing pole that looks a bit weak. You doubt you'd " +
           "be able to catch many fish with this pole, but who knows?\n");
  set_name("fishingpole");
  add_id("fishing pole");
  add_id("pole");    
  set_value(3);
  set_weight(1);
  set_type("blunt");
  set_class(3);
  set_material("wood");
  set_property("poor");
}
