#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);

void create_object()
{
    set_short("A road leading down into a village");
    set_long("The trees stand close to the road, which slopes downward " +
             "here. It is leading down into a valley, where there seems " +
             "to be a village. Thin pillars of smoke rise up from the " +
             "chimneys, and you hear dogs barking and people talking. On " +
             "the other side of the valley a high cliff where a dark " +
             "castle looms.\n");
    set_new_light(5);

    add_exit(ROOM + "road2","east");
    add_exit(OLD_FOREST,"northwest");

    add_item("trees","The firs have given way to oaks");
    add_item("valley","A peaceful valley. There is a village down there, " +
             "and a river flows through it");
    add_item("village","A small, peaceful village");
    add_item("smoke","Thin pillars of smoke rising up into the air, " +
             "only to slowly dissolve");
    add_item("cliff","A high cliff, rising straight up into the air. A " +
             "castle is built upon it");
    add_item("castle","A dark castle. It looms on a cliff high above the " +
             "village. You get an uneasy feeling looking at it. Large " +
             "birds circle the towers of the castle");
    add_item("birds|towers","You are too far away to see them clearly");
    add_item("river","It flows from the north to the south, between the " +
             "village and the cliff");
    add_item("$|$dogs|$dog|$people","You hear dogs barking and the sound " +
             "of people talking coming from the village");
}

void init(void)
{
    SYS_ADMIN->visit(277);
}
