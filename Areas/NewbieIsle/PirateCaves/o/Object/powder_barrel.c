//====================================================================
// A normal powder barrel, to be used in the piracy quest
//====================================================================
#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void);
int can_get_and_put(void);
int query_allow_login(void);

void create_object(void)
{
    set_name("barrel");
    add_id("wooden barrel");
    add_id("_pirate_quest_powder_barrel_");
    set_short("A wooden barrel");
    set_long("A wooden barrel that contains a strange, black powder.\n");

    set_value(50);
    set_weight(4);
    set_material("oak"); //Angelwings
}

int can_get_and_put(void)
{
    W("Woody refuses to be put in a container. He wants to see where you " +
      "are taking him.\n");
    return 0;
}

int query_allow_login(void)
{
    return 0;
}
