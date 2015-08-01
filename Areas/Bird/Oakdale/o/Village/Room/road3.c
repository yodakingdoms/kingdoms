#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A road leading down into the village");
    set_long("The road levels out and you are about to enter the " +
             "village. The air is clear and wonderful to breathe and the " +
             "trees still stand close to the road. To the east you see " +
             "the first houses and some people moving about. When you " +
             "look up, you see the castle towering above you. There is a " +
             "sign beside the road.\n");
    set_new_light(5);

    add_item("village","It is a small, peaceful village");
    add_item("trees","Strong, healthy oaks");
    add_item("castle","You get an uneasy feeling looking at it. You can't " +
             "help thinking that this would be a wonderful place if only " +
             "the castle wasn't there");
    add_item("sign|@sign","'Welcome to Oakdale.'");

    add_exit(ROOM + "road2","west");
    add_exit(ROOM + "road4","east");
}
