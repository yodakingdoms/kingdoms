#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);

void create_object(void)
{
    set_short("A bridge crossing the river");
    set_long("You are on the bridge crossing the river running through " +
             "the valley. The river is wild, roaring below you and " +
             "showering you with drizzle as it crashes into the bridge. On " +
             "the other side the road continues into the forest, as it " +
             "slowly begins to slope upwards again. The cliff is towering " +
             "over you to the northeast, and the castle now seems to turn " +
             "it's back on you as you leave the village.\n");
    set_new_light(5);

    add_item("bridge","A strong stone bridge obviously built by skilled " +
             "craftsmen");
    add_item("river","It is not very wide, but it flows rapidly to the " +
             "south. It would be very hard to swim across it");
    add_item("road","The road continues into the forest on the other side");
    add_item("forest","A forest of oaks");
    add_item("cliff","You will soon be passing to the south of it. It " +
             "looks impossible to climb");
    add_item("castle","As you cross the bridge, the presence of the castle " +
             "does not seem as oppressive. It still looks sinister, but " +
             "you feel as you've escaped it's attention");

    add_exit(ROOM + "road9","west");
    add_exit(FOREST + "Room/castle_road1","east");

    add_sounds(10,45,({ "The bridge trembles under your feet, as the river " +
                        "crashes into it.\n",
                        "You are covered with drizzle as the river slams " +
                        "into the bridge.\n" }));
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "marmon",1);
}

void init(void)
{
    SYS_ADMIN->visit(280);
    ::init();
}
