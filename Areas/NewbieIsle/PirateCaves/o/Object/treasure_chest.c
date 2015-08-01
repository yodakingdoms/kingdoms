//======================================================================
// This is the treasure chest that completes the piracy quest
//======================================================================
#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

int open;

void create_object(void);
string long_fun(void);
void init(void);
int do_open(string str);
int do_close(string str);

void create_object(void)
{
    set_name("chest");
    add_id("treasure chest");
    add_id("_pirate_quest_treasure_chest_");
    set_short("A treasure chest");
    set_long("#long_fun");
    set_weight(4);
    set_value(300);
    set_material("oak"); //Angelwings
}

string long_fun(void)
{
    if(!open)
    {
        return "A wooden chest that looks like the kind that hold " +
               "treasures.\nIt is closed.\n";
    }
    else
    {
        return "A wooden chest containing a few hundred strange, shining " +
               "circular discs! You have no idea what they are but " +
               "Captain Jack wants them badly so they must be worth a " +
               "fortune. Better get this chest back to him as quickly as " +
               "possible.\nIt is open.\n";
    }
}

void init(void)
{
    add_action("do_open","open");
    add_action("do_close","close");
}

int do_open(string str)
{
    if(id(str))
    {
        if(!open)
        {
            W("You open the treasure chest.\n");
            S(TP->QN + " opens a treasure chest.\n");
            open = 1;
            return 1;
        }
        else
        {
            W("The chest is already open.\n");
            return 1;
        }
    }
}

int do_close(string str)
{
    if(id(str))
    {
        if(open)
        {
            W("You close the treasure chest.\n");
            S(TP->QN + " closes a treasure chest.\n");
            open = 0;
            return 1;
        }
        else
        {
            W("The chest is already closed.\n");
            return 1;
        }
    }
}
