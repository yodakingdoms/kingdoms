#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);

void create_object(void)
{
    set_short("A road through the village");
    set_long("A road through the village leading north and south. To the " +
             "west is a house, and on the east side of the road, an old " +
             "tree grows. Some distance to the north it seems the road is " +
             "leaving the village and entering the forest. You can hear a " +
             "bird singing somewhere. The castle looms over the village to " +
             "the east.\n");
    set_new_light(5);

    add_item("house","A normal house in the village. There is smoke " +
             "coming out of the chimney");
    add_item("smoke","Apparently there is a fire burning in the fireplace");
    add_item("tree","An old oak tree, spreading it's branches out over " +
             "the road");
    add_item("$|$bird","You hear a bird sing in the tree. When you look " +
             "more closely, you see a nest among the branches");
    add_item("nest","Disappointment! It is completely empty");
    add_item("branches","The branches look strong and healthy");
    add_item("castle","Looking at it gives you the creeps. It somehow " +
             "seems like it doesn't belong in this valley");

    add_exit(ROOM + "road10","south");
    add_exit(ROOM + "road12","north");

    (ROOM + "house4")->load_doors();
    reset(0);
}
