#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);

void create_object(void)
{
    set_short("A small supply room");
    set_long("A small supply room. The floor is filled with wooden crates " +
             "and barrels, and in one corner is a stacked heap of firewood. " +
             "On shelves lining the walls you see many sacks, bottles and " +
             "cans. There is a flickering torch on one of the walls.\n");
    set_new_light(5);
    set_skip_obvious(1);
    add_property("indoors");
    
    add_item("room","This is a small supply room");
    add_item("floor","A cold, smooth stone floor");
    add_item("crate|crates","Wooden crates containing supplies");
    add_item("barrel|barrels","Wooden barrels containing supplies");
    add_item("supply|supplies","Wares neede to keep this castle running");
    add_item("ware|wares","Food, water, that sort of thing");
    add_item("food|water|floir|grain","It would probably be better if you " +
             "went down to the village to get that");
    add_item("corner","A heap of firewood is stacked there");
    add_item("heap|firewood","A large heap of firewood stacked in a corner");
    add_item("shelf|shelves","Wooden shelves lining the walls");
    add_item("wall|walls","Cold, black stone walls");
    add_item("sack|sacks","Several sacks, probably containing flour, grain " +
             "and such things");
    add_item("bottle|bottles|can|cans","Looks like they contain wine, " +
             "medicine and things like that");
    add_item("wine|medicine","Don't bother. What ever works for the people " +
             "in this castle will probably not work for you");
    add_item("torch","A single, flickering torch");

    (ROOM + "stable")->load_doors();
    reset(0);
}
