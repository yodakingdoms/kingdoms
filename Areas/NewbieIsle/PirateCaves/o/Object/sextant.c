//======================================================================
// This is the sextant needed for the piracy quest
//======================================================================
#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void);

void create_object(void)
{
  set_name("sextant");
  add_id("_pirate_quest_sextant_");
  set_short("A sextant");
  set_long("A sextant, an absolutely vital instrument for pirates who want " +
           "to be able to navigate as they sail the seas, plundering and " +
           "pillaging.\n");
  set_weight(1);
  set_value(60);
  set_material("brass"); //Angelwings
}

