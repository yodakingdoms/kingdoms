#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

string *searchers;

void create_object(void);
void reset(int arg);
void init(void);
int do_search(string str);
int do_rest(string str);
int do_pull(string str);

void create_object(void)
{
    ::create_object();
    set_short("A loft (d)");
    set_long("The loft on the second floor of the barn. Most of the space " +
             "of the loft is taken up by many haybales piled on top of " +
             "each other all around the room. The hay is dry and the air " +
             "makes your nose itch. There is a pitchfork stuck in one of the " +
             "haybales here, and a wooden bench stands against one wall. " +
             "The whole east wall is taken up by two big doors who are wide " +
             "open, letting you look out over the farm. A thick wooden beam " +
             "in the ceiling sticks out through the opening and a rope " +
             "is tied to a system of pulleys at the end of it.\n");

    add_item("loft|room|big room|single big room","A single big room takes " +
             "up the whole second floor");
    add_item("bottom floor","It is below the second floor");
    add_item("second floor","It is above the bottom floor");
    add_item("barn","You're on the second floor of the barn now");
    add_item("space","There's not much space here, the room is filled " +
             "with bales of hay");
    add_item("hay|bale|bales|haybales|bales of hay","Bales of different " +
             "sizes are piled on top of each other, filling the whole loft. " +
             "If you need some hay you can search the bales for one of " +
             "the right size");
    add_item("air","The air is very dry and with so much hay here, your " +
             "nose twitches");
    add_item("%|%air","You start sneezing uncontrollably for a little while");
    add_item("pitchfork","It's probably been used to stack the bales of hay " +
             "neatly on top of each other");
    add_item("bench|wooden bench","Probably used for resting during breaks " +
             "while stacking the bales of hay");
    add_item("wall|walls|wooden wall|wooden walls","The wooden walls look " +
             "like walls normally do");
    add_item("east wall","There is a big opening in it");
    add_item("opening","That's probably where the hay is brought into the " +
             "loft");
    add_item("door|doors","The doors are wide open");
    add_item("farm|little farm","A little farm tucked neatly into the " +
             "landscape");
    add_item("landscape|rolling landscape","A rolling landscape");
    add_item("ceiling","The ceiling is pretty low for a loft but it's still " +
             "high enough that you don't have to watch your head");
    add_item("beam|wooden beam|thick beam|thick wooden beam","A thick " +
             "beam going out through the opening, supporting the pulley " +
             "system used to bring hay into the loft");
    add_item("rope","By pulling that rope, something tied to the other " +
             "end down in the yard could easily be pulled up into the loft");
    add_item("yard","You can see it outside the opening");
    add_item("system|pulley|pulleys|system of pulleys","It makes it easier " +
             "to lift heavy things up here from the yard");

    add_exit(ROOM + "farm_barn_floor1","down");

    reset(0);
}

void reset(int arg)
{
    searchers = ({});
    add_monster(MONSTER + "hobbit_helper2");
}

void init(void)
{
    add_action("do_search","search");
    add_multi_action("do_rest","rest|relax|sit");
    add_action("do_pull","pull");
}

int do_search(string str)
{
    object hay;

    if(str == "hay" || str == "bales" || str == "haybales" ||
       str == "bales of hay")
    {
        if(member_array(TP->QRN,searchers) == -1)
        {
            W("You manage to find a suitable haybale.\n");
            S(TP->QN + " bends down and gets a haybale.\n");
            hay = make(OBJECT + "hay");
            if(transfer(hay,TP))
            {
                W("It is too heavy for you to pick up though.\n");
                S(TP->QN + " doesn't seem to be able to carry it.\n");
            }
            searchers += ({ TP->QRN });
        }
        else
        {
            W("You have already taken some hay, be nice " +
              "and leave some for the farmer.\n");
        }
        return 1;
    }
}

int do_rest(string str)
{
    if(str == "bench" || str == "on bench")
    {
        W("You sit down on the bench and rest your weary legs for a " +
          "while.\n");
        S(TP->QN + " sits down on the bench and rests for a while.\n");
        return 1;
    }
    return notify_fail(C(query_verb()) + " where?\n");
}

int do_pull(string str)
{
    if(str == "rope")
    {
        W("There's nothing tied to the other end of the rope for you " +
          "to pull up here.\n");
        S(TP->QN + " gives the rope a light tug.\n");
        return 1;
    }
    return notify_fail("Pull what?\n");
}
