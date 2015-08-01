//======================================================================
// This is the cannon ball needed for the piracy quest
//======================================================================
#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void);

void create_object(void)
{
    set_name("stone");
    add_id("round stone");
    add_id("cannonball");
    add_id("_pirate_quest_cannonball_");
    set_short("A black round stone");
    set_long("A black stone that's almost perfectly round like a " +
             "ball. It's very heavy.\n");
    set_weight(6);
    set_value(20);
    set_material("stone"); //Angelwings
}

