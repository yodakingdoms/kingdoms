//====================================================================
// Quest object for the scarecrow quest
// Flag 235 allocated to this quest by Yoda
//====================================================================
#pragma strict_types
#include "../def.h"
inherit "/std/obj/quest_obj";

void create_object(void);
int query_experience(int level);

void create_object(void)
{
    set_name("The scarecrow");
    set_hint("There's a crow problem at Bumbleroot Farm. Can you go there " +
             "and help the farmer save his corn from the nasty birds?\n");
    set_level(2);
    set_flag(235);
}

int query_experience(int level)
{
    return 20000;
}
