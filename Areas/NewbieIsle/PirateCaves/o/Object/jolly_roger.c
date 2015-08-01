//======================================================================
// This is the Jolly Roger flag needed for the piracy quest
//======================================================================
#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;
inherit STD_LORE;

void   create_object(void);

void create_object(void)
{
  set_name("flag");
  add_id("jolly roger");
  add_id("pirate flag");
  add_id("_pirate_quest_jolly_roger_");
  set_short("A Jolly Roger flag");
  set_long("This is the legendary Jolly Roger flag pirates "+
           "use to strike fear into the crews they attack. It "+
           "is black, with two crossed white bones under a grinning "+
           "white skull.\n");
  set_weight(1);
  set_value(30);

  add_lore("This flag would only be used by a pirate.\n",1);
  add_lore("In fact, the Kingdoms Pirate's Union has decided "+
           "that this flag must _always_ be used by pirates on "+
           "the job. That means you're not allowed to attack any "+
           "ships unless you've brought this flag with you and "+
           "can raise it when you spot a suitable ship to "+
           "plunder.\n",20);
 set_material("canvas"); //Angelwings
}

