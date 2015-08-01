#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("By a well in the village");
    set_long("You are by the village well. The well is made out of stone " +
             "and looks very deep. There are four houses here, but only " +
             "one has a door in this direction. The other houses are the " +
             "back walls to the Restaurant, the Bank and the Guild. To " +
             "the east you can see the castle loom over the village.\n");
    set_new_light(5);

    add_item("well","The well is very deep. You see the dark water down " +
             "there");
    add_item("water|dark water","Dark water rising up into the well " +
             "from some underground spring");
    add_item("spring|underground spring","You would have to burrow deep " +
             "into the earth to be able to see that");
    add_item("stones","Fist sized pieces carefully fitted together");
    add_item("stone","A small, grey stone");
    add_item("houses","Small houses with stone chimneys");
    add_item("house","A small stone house with a wooden roof and a stone " +
             "chimney");
    add_item("chimneys","Stone chimneys. Smoke is rising from a few of them");
    add_item("chimney","A nice stone chimney");
    add_item("smoke","Maybe there's a fire in the fireplaces of those houses");
    add_item("castle","The castle looms high over the village to the east");

    add_exit(ROOM + "road19","south");

    (ROOM + "house12")->load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "nanicia",1);
    ::reset(arg);
}
