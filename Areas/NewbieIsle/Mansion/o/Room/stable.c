#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

int torch_found;

void create_object(void);
void reset(int arg);
void init(void);
int do_use(string str);
int do_search(string str);

void create_object(void)
{
    set_short("A ruined stable (out)");
    set_long("The ruined remains of what once used to be a stable. The " +
             "roof has fallen in a long time ago and only two of the " +
             "stone walls are still standing. The ground is covered with " +
             "stones from the walls and wooden debris from the roof. In one " +
             "corner is a wooden wagon, but everything else that might have " +
             "been of some use is long gone. The trees of the surrounding " +
             "forest tower above you.\n");

    set_new_light(10);

    add_item("remains|ruined remains","Only two of the walls still stand");
    add_item("wall|walls|stone wall|stone walls","Only two of them still " +
             "stand. They don't look very sturdy either, and they could " +
             "crumble at any moment");
    add_item("stable","There's not much left of it now. It was probably " +
             "pretty nice once upon a time");
    add_item("roof","There's not much left of the roof now, it has fallen " +
             "in and it looks like it did so a long time ago. There's " +
             "only one wooden beam left of what once was the roof");
    add_item("beam|wooden beam","It too looks like it could join the rest " +
             "of what once was the roof on the floor sometime soon");
    add_item("ground|floor","It is covered with stones and wooden debris");
    add_item("stone|stones","Stones that used to be in the now crumbled " +
             "walls");
    add_item("crumbled wall|crumbled walls","Two of the walls have crumbled " +
             "a long time ago");
    add_item("standing wall|standing walls","Two walls remain, although " +
             "barely standing");
    add_item("debris|wooden debris","It's what is left of the roof and " +
             "looks like it fell in a long time ago");
    add_item("corner","There's a wooden wagon standing there");
    add_item("wagon|wooden wagon","It looks to be the only useful thing " +
             "left in this stable");
    add_item("tree|trees","They tower above the ruined stable");
    add_item("forest|surrounding forest","The trees in it tower above you");

    add_exit(ROOM + "outside_house","out");

    reset(0);
}

void reset(int arg)
{
    torch_found = 0;
    add_monster(MONSTER + "stable_goblin");
}

void init(void)
{
    add_action("do_use","use");
    add_action("do_search","search");
}

int do_use(string str)
{
    if(str == "wagon" || str == "wooden wagon")
    {
        W("It might be the only useful thing left here but that does " +
          "not mean it's of any use to you.\n");
        S(TP->QN + " looks at the wagon in the corner, pondering.\n");
        return 1;
    }
    // It's not a useful action so don't mess up 'use' for objects or
    // skills or whatever
    return 0;
}

int do_search(string str)
{
    object torch;

    if(str == "debris" || str == "wooden debris")
    {
        if(!torch_found)
        {
            W("You search through the debris but the only thing you " +
              "find is a piece of wood that can be used as a torch.\n");
            S(TP->QN + " searches the debris and finds a torch.\n");
            torch = make(STD_TORCH);
            if(!transfer(torch,TP))
            {
                W("You pick it up.\n");
                S(TP->QN + " picks up the torch.\n");
            }
            torch_found = 1;
            return 1;
        }
    }
}
