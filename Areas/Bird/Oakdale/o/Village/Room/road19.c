#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);

void create_object(void)
{
    set_short("A cobblestoned yard");
    set_long("A cobblestoned yard in the village. The cobblestones on the " +
             "ground are round and smooth. To the north there is a well. " +
             "There are six houses built around the yard, but only two can " +
             "be entered from here. The castle looms high over the " +
             "village.\n");
    set_new_light(5);

    add_item("yard","A few houses are built around it, and there are " +
             "cobblestones on the ground");
    add_item("ground","Looking at the ground, you suddenly start thinking " +
             "about Mortal lord Korik the Vicious Bonecruncher");
    add_item("cobble|stone|cobbles|stones|cobblestone|cobblestones|" +
             "round stones","Round stones placed on the ground of the yard");
    add_item("well","You would have to go north to look at it more closely");
    add_item("houses","You can enter three of them from here");
    add_item("castle","The castle looms high over the village to the north" +
             "east");

    add_exit(ROOM + "road18","east");
    add_exit(ROOM + "well","north");

    (ROOM + "house7")->load_doors();
    (ROOM + "house13")->load_doors();
    reset(0);
}
