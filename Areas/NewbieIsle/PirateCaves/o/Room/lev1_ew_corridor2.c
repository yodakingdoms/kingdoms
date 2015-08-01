#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("An underground corridor (e/w/s)");
    set_long("An underground corridor going east and west. South of here " +
             "is an opening that leads into a storage room and to the east " +
             "are some stairs going up. West of here is an opening that " +
             "seems to lead outside into the fresh air. Gusts of wind from " +
             "that direction blow into the corridor, making the air in here " +
             "quite fresh. The corridor is lit by a stone in the wall, " +
             "shining with a soft, yellow light.\n");

    add_item("corridor|underground corridor","An underground corridor with " +
             "stone walls, floor and ceiling");
    add_item("opening","It looks as if it leads into a storage room south " +
             "of here");
    add_item("room|storage room|storage room south of here","You'll have " +
             "to go south to get a closer look");
    add_item("stair|stairs","It looks as if the stairs go up but you'll " +
             "have to go east to get a better look");
    add_item("air|fresh air","You can't really get a good look at the air");
    add_item("wind|gusts|gust|gusts of wind|gust of wind","You can't " +
             "get a good look at the wind");
    add_item("stone","It sits in a niche in the wall, providing the " +
             "corridor with light");
    add_item("niche","There is a stone in it, shining with a soft, yellow " +
             "light");
    add_item("light","A soft, yellow light coming from a stone in a niche " +
             "in a wall");

    add_exit(PCROOM + "lev1_se_corridor","west");
    add_exit(PCROOM + "lev1_storeroom","south");
    add_exit(PCROOM + "lev1_east_stairs","east");
}
