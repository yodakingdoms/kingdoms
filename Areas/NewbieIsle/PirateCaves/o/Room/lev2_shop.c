#pragma strict_types
#include "../def.h"
//inherit MASTER_INDOORS_ROOM;
//inherit MOD_SHOP;
inherit STD_SHOP;

void create_object(void);
void reset(int arg);

void create_object(void)
{
//    ::create_object();
    set_short("A shop (w)");
    set_long("A messy shop. There are loads of shelves and boxes here " +
             "but everything seems to be in disarray. Half the things " +
             "you see on the shelves are broken or useless. There is a " +
             "counter here with a small note on it and a there's a sign " +
             "behind the counter that lets you know you are in: Dithes " +
             "Plunder Emporium.\n");
    set_new_light(1);
    add_property("indoors");

    add_item("stone|cold stone|grey stone|cold, grey stone|wall|"+
             "walls|floor|ceiling","Cold, grey stone");
    add_item("shop","That's what it looks like but you doubt you will find " +
             "anything useful here. Maybe you could at least sell off some " +
             "of your own loot?");
    add_item("shelf|shelves","There are loads of items on the shelves but " +
             "everything seems to have just been tossed there. There's no " +
             "organization here");
    add_item("box|boxes","Boxes filled with seemingly unrelated items");
    add_item("item|items|unrelated item|unrelated items|thing|things",
             "Strange items. You don't really have a clue what most of " +
             "them really are or where they came from");
    add_item("counter|wooden counter","A wooden counter with a small note " +
             "pinned to it");
    add_item("note|small note|@note|@small note","It says: type 'help " +
             "shop' to learn about the commands you can use here");
    add_item("sign|@sign","The sign says: Dithes Plunder Emporium");

    add_exit(PCROOM + "lev2_corridor2","west");

    store_room = PCROOM + "lev2_shop_storeroom";
    shopkeeper_file = PCMONSTER + "shopkeeper";

    reset(0);
}

void reset(int arg)
{
    add_monster(PCMONSTER + "trashcan",1);
    ::reset(arg);
}
