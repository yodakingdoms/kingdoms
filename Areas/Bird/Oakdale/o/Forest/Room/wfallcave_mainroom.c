#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

int parchment_found;

void create_object(void);
void init(void);
void my_reset(void);
int do_search(string str);
int do_climb(string str);

void create_object(void)
{
    set_short("A dark, cavernous chamber");
    set_long("The floor levels out and the passage opens abruptly into a " +
             "cavernous chamber with a high ceiling. The chamber is vaguely " +
             "circular and tunnels lead away from it in four directions. " +
             "The floor is smoother here, and in the centre of the chamber " +
             "is a small circle of blackened stones. In the ceiling above " +
             "the stones is a small hole. Water is dripping from the " +
             "ceiling, forming small puddles on the floor.\n");
    set_new_light(0);
    add_property("indoors");

    add_item("floor","The floor is quite smooth here, and covered with " +
             "small puddles and other debris");
    add_item("debris","Small pieces of rotted wood... In one corner you " +
             "spot a piece of cloth.");
    add_item("cloth|blanket","An almost rotten blanket. It is useless");
    add_item("chamber|cave","An almost circular cave");
    add_item("tunnel|tunnles","There are four of them, but you can't see " +
             "where any of them lead.\n");
    add_item("circle|stones|stone","A small circle of blackened stones. " +
             "Looks like a fireplace that hasn't been used in quite a " +
             "while. There are still some remnants of a fire there..");
    add_item("remnants|mess","The remnants look really gooey. You wouldn't " +
             "want to stick your hands into that mess and search it");
    add_item("ceiling","The ceiling is pretty high above you. There is a " +
             "small hole in it");
    add_item("hole","Probably for letting the smoke from the fire out");
    add_item("water","Water dripping from the ceiling and seeping through " +
             "the walls");
    add_item("puddle|puddles","Small puddles of water on the floor");

    add_sounds(05,80,({ "Drip, drop...\n" }));

    add_exit(ROOM + "wfallcave_tunnel1","east");
    add_exit(ROOM + "wfallcave_tunnel2","south");
    add_exit(ROOM + "wfallcave_tunnel3","west");
    add_exit(ROOM + "wfallcave_tunnel4","northwest");
}

void init(void)
{
    add_action("do_search","search");
    add_action("do_climb","climb");
    SYS_ADMIN->visit(300);
    ::init();
}

void my_reset(void)
{
    parchment_found = 0;
}

int do_search(string str)
{
    object parchment;

    if(str == "remnants" || str == "mess")
    {
        if(!parchment_found)
        {
            W("You search through the gooey remnants. Yick! The black stuff "+
              "gets on your hands and sleeves, but hey! You find a piece of "+
              "parchment! For some reason it hasn't decayed at all.\n");
            S(TP->QN + " searches through the gooey remnants in the " +
              "fireplace and finds a scroll.\n");
            parchment = make(OBJECT + "parchment");
            parchment_found = 1;
            if(transfer(parchment,TP))
            {
                W("You drop it on the ground.\n");
                say(TP->QN + " drops it on the ground.\n");
            }
            // This is a quest thing so we reset it a bit quicker
            set_alarm(600.0,0.0,"my_reset");
            return 1;
        }
        else
        {
            W("You search through the gooey remnats. Yick! The black stuff " +
              "gets on your hands and sleeves. You find nothing.\n");
            S(TP->QN + " searches through the gooey remnants in the " +
              "fireplace but finds nothing.\n");
            return 1;
        }
    }
    return 0;
}

int do_climb(string str)
{
    if(str == "hole" || str == "to hole" || str == "through hole")
    {
        if(TP->query_siz() > 20)
        {
            W("You are tall enough to reach the hole, but that means you're " +
              "too big to climb through it!\n");
            S(TP->QN + " studies the hole in the ceiling carefully.\n");
            return 1;
        }
        W("You are not tall enough to reach the hole. You jump as high as " +
          "you can, but to no avail.\n");
        S(TP->QN + " jumps up and down, trying to reach the hole in the " +
          "ceiling.\n");
        return 1;
    }
    return notify_fail("Climb where?\n");
}
