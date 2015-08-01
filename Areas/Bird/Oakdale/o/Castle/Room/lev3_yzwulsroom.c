#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void init(void);
int do_south(string str);

void create_object(void)
{
    set_short("A dimly lit chamber");
    set_long("A dimly lit chamber. A flickering candle provides just enough " +
             "light for you to see in here. There is a soft, dark blue rug " +
             "on the floor, and a wooden desk stands by the east wall. A " +
             "chair stands in front of the desk and a bed is by the north " +
             "wall. A chandelier hangs from the hammerbeam ceiling and a " +
             "large mural is on the north wall, above the bed. The room " +
             "gives a very luxurious impression. An archway in the south " +
             "wall leads back to the throne room.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("room|chamber","A luxurious room the apparently serves as " +
             "living quarters for a person of very high rank");
    add_item("candle","A small wax candle on the desk");
    add_item("rug","A soft, dark blue rug that feels nice to walk upon");
    add_item("floor","Most of the floor is covered by a rug");
    add_item("desk","A masterly crafted oak desk. There is a small, " +
             "flickering candle on it");
    add_item("wall|walls","Smooth, black stone");
    add_item("chair","A magnificently crafted oak chair with a dark blue " +
             "cushion on it");
    add_item("cushion","A soft, dark blue cushion");
    add_item("bed","A neatly made bed covered with a black sheet");
    add_item("sheet","A black velvet sheet");
    add_item("chandelier","A very nice chandelier. The candles in it are " +
             "not lit at the moment");
    add_item("candles","The candles in the chandelier are not lit");
    add_item("ceiling","A beautiful hammerbeam ceiling");
    add_item("mural","The image on the mural is strange. It shows a man " +
             "dressed in black robes. His fingers are long and slender, but " +
             "his face is hidden under his hood and cannot be seen. It also " +
             "shows a black dragon spreading it's wings preparing for " +
             "flight, but you can't tell one from the other. It's almost " +
             "like the being on the mural is both man and dragon at the " +
             "same time");
    add_item("man","Strange... You can't seem to focus on just the man in " +
             "the mural. You keep seeing both the dragon and the man..");
    add_item("dragon","Strange... You can't seem to focus on just the " +
             "dragon in the mural. You keep seeing both the dragon and " +
             "the man..");

    add_exit(ROOM + "lev3_throne","south");

    (ROOM + "lev3_stairroom")->load_doors();
    reset(0);
}

void init(void)
{
    add_multi_action("do_south","s|south");
    SYS_ADMIN->visit(344);
    ::init();
}

int do_south(string str)
{
    tell_room(ROOM + "lev3_throne",TP->QN + " arrives through the curtains " +
              "on the north wall.\n");
    return 0;
}
