//====================================================================
// Quest object for the Piracy quest
// Flag 222 allocated to this quest by Yoda
//====================================================================
#pragma strict_types
#include "../def.h"
inherit "/std/obj/quest_obj";

void create_object(void);
int  query_experience(int lv);

void create_object(void)
{
  set_name("Piracy Quest");
  set_hint("The pirates on Newbie Island were once the terror of the "+
           "seas, but the spoils of their piracy have turned them into "+
           "lazy slobs! Their captain is depressed over being unable "+
           "to get his crew together to take the ship to sea again. Go "+
           "there and help the captain rob just one more ship before he "+
           "retires.\nNOTE: This quest can be solved by more than one "+
           "player at a time.\n");
  set_level(4);
  set_flag(222);
}

int query_experience(int lv)
{
  return 100000;
}
