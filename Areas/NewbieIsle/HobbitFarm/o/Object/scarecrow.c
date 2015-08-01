//======================================================================
// The scarecrow used in the quest.
//======================================================================
#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

int placed;

void create_object(void);
void init(void);
int do_place(string str);
void place(void);
int get(int silently);

void create_object(void)
{
    set_name("scarecrow");
    add_id("_scarecrow_quest_scarecrow_");
    add_id("small scarecrow");
    add_id("scary scarecrow");
    set_short("a small but scary scarecrow");
    set_long("A small but scary scarecrow. It's made of some twigs " +
             "tied together with some hay with some leather straps. " +
             "A pumpkin has been stuck on top of it and a carrot " +
             "has been used for a nose. It's smaller than you but " +
             "would not look out of place on a hobbit sized farm. " +
             "To put it to use, you only have to find a suitable " +
             "spot and <place> the scarecrow in the ground there.\n");
    set_weight(4);
    set_value(50);
    set_material("plant"); //Angelwings
}

void init(void)
{
    add_action("do_place","place");
}

int do_place(string str)
{
    if(!ENV(TP)->query_is_quest_field())
    {
        W("This is probably not a good spot to place the scarecrow.\n");
        return 1;
    }
    return 0;
}

void place(void)
{
    set_short("A small but scary scarecrow stuck in the ground");
    set_long("A small but scary scarecrow. It's made of some twigs " +
             "tied together with some hay with some leather straps. " +
             "A pumpkin has been stuck on top of it and a carrot " +
             "has been used for a nose. It's smaller than you but " +
             "would not look out of place on a hobbit sized farm. " +
             "Someone has stuck it into the ground here not long ago.\n");
    placed = 1;
}

int get(int silently)
{
    if(placed)
    {
        return notify_fail("The scarecrow is stuck into the ground " +
                           "too hard to pull out.\n");
    }
    return 1;
}
