#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void   create_object(void);
int    is_unkillable(void);
string unkillable_string(object attacker);

void create_object(void)
{
  set_name("spirit");
  add_id("water spirit");
  set_short("A shining water spirit");
  set_long("A shining spirit that seems to be made of water. It smiles "+
           "at you in a friendly way, and you don't feel at all threatened "+
           "by it.\n");
  set_race("water spirit");
  set_al(900);
  set_level(4);
  set_wc(10);
  set_new_ac(10);
  set_unarmed(1);
}

int is_unkillable(void)
{  
  return 1;
}

string unkillable_string(object attacker)
{
  return "You can't bring yourself to attack this magnificent being of "+
         "light and water.";
}
