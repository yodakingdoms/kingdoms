//====================================================================
// Quest object for the hobbithelper quest
// Flag 234 allocated to this quest by Yoda
//====================================================================
#pragma strict_types
#include "../def.h"
inherit "/std/obj/quest_obj";

void create_object(void);
int query_experience(int level);
void my_quest_solved(void);
void reset_quest(void);

void create_object(void)
{
  set_name("The missing hobbit");
  set_hint("A little hobbit girl has lost her friend somewhere in " +
           "the forest east of Hazeldown. Why don't you go there and " +
           "see if you can reunite the two?\n");
  set_level(3);
  set_flag(234);
}

int query_experience(int level)
{
  return 20000;
}

void my_quest_solved(void)
{
    // Reset the quest 5 minutes after it is done. This method is
    // called from hobbit boy when quest is done
    set_alarm(300.0,0.0,"reset_quest");
}

void reset_quest(void)
{
    (ROOM + "forest_path2")->my_reset();
    (ROOM + "house_cellar_room")->my_reset();
}
