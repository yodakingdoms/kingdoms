#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void create_object(void);
void init(void);
int do_drink(string str);

void create_object(void)
{
    set_short("A waterbottle");
    set_long("A disgusting leather waterbottle. It is dirty and it smells " +
             "and the liquid inside does not look like something that " +
             "should go in the mouth, but something that's passed through " +
             "and come out the other end.\n");
    set_name("waterbottle");
    add_id("bottle");
    set_weight(1);
    set_value(10);
    set_material("leather");
}

void init(void)
{
    add_action("do_drink","drink");
}

int do_drink(string str)
{
    if(str == "water" || str == "water from bottle" || str == "from bottle")
    {
        W("There is NO way you want to drink whatever it is that's in the " +
          "bottle.\n");
        S(TP->QN + " looks suspiciously at a waterbottle.\n");
        return 1;
    }
    return 0;
}
