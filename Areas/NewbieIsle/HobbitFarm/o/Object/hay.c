//======================================================================
// Hay to use for the scarecrow
//======================================================================
#pragma strict_types
#include "../def.h"
inherit OBJECT + "scarecrow_part";

void create_object(void);

void create_object(void)
{
    set_name("hay");
    add_id("bale");
    add_id("bale of hay");
    add_id("_scarecrow_quest_hay_");
    set_short("a small bale of hay");
    set_long("A small bale of hay. Just enough to put into a scarecrow " +
             "as long as the scarecrow is of hobbit size rather than " +
             "your size. Maybe you could try to make a scarecrow with it?\n");
    set_weight(3);
    set_value(25);
    set_material("plant"); //Angelwings
}
