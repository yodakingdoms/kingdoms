#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("A corridor (w/n/s/e)");
    set_long("A corridor going north and south from here. The corridor is " +
             "lit by a small shining stone sitting in a niche in one of " +
             "the walls. The floor is filthy and plenty of rubbish is " +
             "piled high against the walls. West of here are some living " +
             "quarters, and to the east is an apothek. North of here are " +
             "some stairs going down.\n");

    add_item("corridor|filthy corridor","A filthy corridor. Noone's been " +
             "cleaning here in a long time");
    add_item("stone|small stone|small shining stone","It shines with a " +
             "soft, yellow light");
    add_item("light|yellow light|soft, yellow light","It comes from the " +
             "stone in the niche in the wall");
    add_item("niche","There's a small shining stone in it");
    add_item("floor","There's dirt and stains on the floor");
    add_item("dirt","There's plenty of it in this corridor");
    add_item("stain|stains","Looks like stains from spilled alcohol and " +
             "maybe even worse things");
    add_item("rubbish","It's piled pretty high against the walls");
    add_item("living quarters|quarters","They're west of here");
    add_item("apo|apothek","It's east of here");
    add_item("stair|stairs","They go down");

    add_exit(PCROOM + "lev2_living_quarters","west");
    add_exit(PCROOM + "lev2_apo","east");
    add_exit(PCROOM + "lev2_corridor2","south");
    add_exit(PCROOM + "lev2_stairs","north");
}
