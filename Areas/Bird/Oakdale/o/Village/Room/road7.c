#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("The main road through the village");
    set_long("You are on the main road through the village. There are " +
             "houses to the north and the south, but you can only enter " +
             "the one to the south. To the east is a square and some " +
             "distance to the west is a crossroad. The castle looms over " +
             "the village, the cliff standing more to the northeast now.\n");
    set_new_light(5);

    add_item("square","It appears to be the centre of the village, but " +
             "there does not seem to be much activity");
    add_item("crossroad","A huge tree stands there");
    add_item("castle","It is rising straight up into the air to the north" +
             "east");

    add_exit(ROOM + "road6","west");
    add_exit(ROOM + "square","east");

    (ROOM + "house1")->load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "lidyr",1);
    ::reset(arg);
}
