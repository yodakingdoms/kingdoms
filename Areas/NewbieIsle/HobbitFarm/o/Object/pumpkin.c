//======================================================================
// A pumpkin to use as head for the scarecrow
//======================================================================
#pragma strict_types
#include "../def.h"
inherit OBJECT + "scarecrow_part";

void create_object(void);
void init(void);
int do_eat(string str);

void create_object(void)
{
    set_name("pumpkin");
    add_id("_scarecrow_quest_pumpkin_");
    set_short("a pumpkin");
    set_long("A quite small, but nontheless juicy looking pumpkin. You " +
             "think it would make a good head for a somewhat small, but " +
             "nontheless scary scarecrow. Maybe you could try to make a " +
             "scarecrow with it?\n");
    set_weight(1);
    set_value(20);
    set_material("plant"); //Angelwings
}

void init(void)
{
    add_action("do_eat","eat");
    ::init();
}

int do_eat(string str)
{
    if(str == "pumpkin")
    {
        W("This pumpkin is not big enough to be a proper meal. You decide " +
          "to save it for something else instead.\n");
        return 1;
    }
}
