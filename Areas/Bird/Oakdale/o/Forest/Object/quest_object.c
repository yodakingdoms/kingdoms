//====================================================================
// Quest object for the quest
//====================================================================
#pragma strict_types
#include "../def.h"
inherit "/std/obj/quest_obj";

void create_object(void);
int query_experience(int level);

void create_object(void)
{
    set_name("The Orb of Nirach");
    set_hint("Travel to Oakdale and help the people rid themselves of " +
             "the oppressor holding them under his boot. An old storyteller " +
             "sitting in the tavern may give you valuable advice, should " +
             "he find you worthy.\n");
    set_level(18);
    set_flag(QUEST_FLAG);
}

int query_experience(int level)
{
    return 120000;
}
