#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);

void create_object(void)
{
    set_short("The main road through the village");
    set_long("The main road through the village leads west and east from " +
             "here. There is a house to the north and a grove to the " +
             "south. To the east is a bridge crossing the river. On the " +
             "other side, the ground is beginning to slope upwards again. " +
             "The cliff is now to your northeast, and the gloomy castle " +
             "seems to be watching you.\n");
    set_new_light(5);

    add_item("grove","A grove of healthy, strong oak trees");
    add_item("bridge","A sturdy stone bridge. It looks very well made");
    add_item("river","It flows swiftly from the north to the south, making " +
             "a loud noise and showering you with drizzle as it crashes " +
             "into the bridge");
    add_item("cliff","Almost completely vertical. From here it looks " +
             "impossible to climb");
    add_item("castle","Still no movement up there.. or wait! A lone sentry " +
             "is patrolling the battlements. For some reason you actually " +
             "feel better after noticing him. Whatever magic is laid upon " +
             "the castle seems to have weakened");

    add_exit(ROOM + "road8","west");
    add_exit(ROOM + "bridge","east");

    (ROOM + "house3")->load_doors();
    reset(0);
}
