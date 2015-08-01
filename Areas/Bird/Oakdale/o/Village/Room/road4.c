#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("The main road through the village");
    set_long("You have entered the village. There are houses to the " +
             "north and the south, and the road leads west and east. The " +
             "air is filled with both weird and wonderful smells coming " +
             "from the two houses. Further east is a crossroad where a " +
             "huge tree stands. The castle looms above you.\n");
    set_new_light(5);

    add_exit(ROOM + "road3","west");
    add_exit(ROOM + "road5","east");
    add_exit(ROOM + "apothek","north");

    add_item("houses","A restaurant is to your south, and an apothec is " +
             "to your north. The restaurant is unfortunately closed");
    add_item("tree","It looks like a huge oak");
    add_item("apothec","It is north of here and looks open for business");
    add_item("restaurant","The restaurant looks permanently closed");
    add_item("castle","You quickly turn your eyes away. You wonder how " +
             "people can bear living in its shadow");
    add_item("%|%smells|%strange smells|%herbal smells|%strange herbal " +
             "smells","Strange herbal smells are coming from the north");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "cat",1);
}
