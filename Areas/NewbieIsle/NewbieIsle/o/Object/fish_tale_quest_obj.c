//====================================================================
// fish_tale_quest_obj - Quest object for the Fish Tales quest
//====================================================================
#pragma strict_types
#include "../def.h"
inherit "/std/obj/quest_obj";

void create_object(void);
int  query_experience(int lv);

void create_object(void)
{
  set_name("Fish Tales");
  set_hint("Find the old fisherman on Newbie Island and impress him with "+
           "your own fish tales.\n");
  set_level(3);
  set_flag(188);
}

int query_experience(int lv)
{
  return 15000;
}
