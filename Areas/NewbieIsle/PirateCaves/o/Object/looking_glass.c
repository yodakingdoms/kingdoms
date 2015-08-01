//======================================================================
// This is the looking glass needed for the piracy quest
//======================================================================
#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void);

void create_object(void)
{
  set_name("looking glass");
  add_id("glass");
  add_id("_pirate_quest_looking_glass_");
  set_short("A looking glass");
  set_long("A long tube with a glass lens in each end. This thing " +
           "could probably be used to spot things from large distances.\n");
  set_weight(1);
  set_value(60);
  set_material("glass"); //Angelwings
}

