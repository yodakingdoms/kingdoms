#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_follow(string str);

void create_object(void)
{
    set_short("A road throught the forest north of the village. " +
              "A boulder and a strange bush is here");
    set_long("You are on a road leading north and south through the " +
             "forest. The huge oak trees stand close to the road, their " +
             "branches reaching out over it, almost creating a ceiling " +
             "over your head. Only very little sunlight filters down " +
             "through the branches, so it is rather shadowy here. By " +
             "the side of the road lies a boulder, and on the other side " +
             "you see a strange bush.\n");
    set_new_light(3);

    add_item("forest","A dark, silent forest of oak trees");
    add_item("tree|trees","Huge, old oak trees");
    add_item("branch|branches","The branches of the trees seem thick and " +
             "strong");
    add_item("ceiling","The branches ALMOST create a ceiling, so there's " +
             "no ceiling here");
    add_item("light","Very little, only a few beams get through the " +
             "branches. As a result, there is a very moody atmosphere here");
    add_item("boulder","A boulder that looks as if it has fallen of a " +
             "wagon transporting rock from the quarry north of here to " +
             "the village. Noone has bothered to pick it up. Hmm... You " +
             "think you see something on the ground behind the boulder..");
    add_item("ground|something","It's a small path leading west! You could " +
             "follow it if you wanted to");
    add_item("path","A path leading into the forest to the west. You could " +
             "follow it and see where it leads");
    add_item("bush","It looks strange and it has no berries. You can't " +
             "quite put the finger on what's strange with it");
    add_item("$|$sound|$soft sound|$wind","The only thing you hear is " +
             "the soft sound of the wind in the trees");

    add_exit(ROOM + "north_road5","south");
    add_exit(ROOM + "north_road6","north");
}

void init(void)
{
    add_action("do_follow","follow");
}

int do_follow(string str)
{
    W("You step off the road and follow the path west.\n");
    TP->move_player("steps off the road and follows a path west into " +
                    "the forest",
                    ROOM + "cottage_path1",
                    "arrives from the east",1);
    return 1;
}
