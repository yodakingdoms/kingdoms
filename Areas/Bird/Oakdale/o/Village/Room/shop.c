#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM room;
inherit MOD_SHOP shop;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("The shop");
    set_long("The Oakdale Shop. A stone house with a wooden ceiling. " +
             "Shelves with items line the walls. There is a counter here, " +
             "with a sign saying:\nDo 'help shop' to learn the commands\n" +
             "To the south is Village road.\n\n");
    add_property("indoors");
    add_property("no_steal");
    set_new_light(10);

    add_item("shop|house","It is the oakdale shop");
    add_item("ceiling","It is made of wood");
    add_item("shelf|shelves","Wooden shelves covering the walls");
    add_item("walls|wall","Stone walls covered by wooden shelves");
    add_item("items|item","All sorts of strange items of the type an " +
             "adventurer would love to have");
    add_item("counter","A wooden counter with a sign on it");
    add_item("sign|@sign","'Do 'help shop' for the commands'");

    add_exit(ROOM + "road5","south");

    store_room = ROOM + "store";
    shopkeeper_file = MONSTER + "shopkeeper";

    reset(0);
}

void reset(int arg)
{
    ::reset(arg);
    add_monster(TRASHCAN,1);
}

void exit()
{
    room::exit();
    shop::exit();
}
