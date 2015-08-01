#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);

void create_object(void)
{
    set_short("A road leading out of the village");
    set_long("The road is leading out of the village. A house is to the " +
             "east and to the west the forest is closing in to the road. " +
             "The trees are tall and strong, and the vegetation is lush. " +
             "Further south you can see the bell tower of a church rising " +
             "over the trees. A small bird is circling the tower.\n");
    set_new_light(5);

    add_item("forest","A dense forest of oaks. The vegetation is lush and " +
             "the trees look healthy. You can't see or hear any animals " +
             "in there");
    add_item("house","A nice house with a white roof and a stone chimney");
    add_item("tower|church","You see the bell tower over the treetops. A " +
             "bird is circling the tower");
    add_item("tree|trees","The trees are tall and strong and stand close " +
             "together, making it hard to see very far into the forest");
    add_item("vegetation|lush vegetation","The vegetation is lush and looks " +
             "very healthy");
    add_item("bird","It looks like a swallow. You can almost hear it sing");
    add_item("$|$bird|$swallow","The bird twiddles a beautiful, sad melody");
    add_item("castle","You still can't see any movement up there");

    add_exit(ROOM + "road15","north");
    add_exit(ROOM + "road17","south");

    (ROOM + "house6")->load_doors();
    reset(0);
}
