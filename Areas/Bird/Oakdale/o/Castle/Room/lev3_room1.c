#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A small, dimly lit room");
    set_long("A small, dimly lit room. The floor is covered by a soft, " +
             "black rug. A large wooden desk stands by the east wall, and " +
             "a wooden chair stands in front of it. A small lamp and " +
             "several documents are on the table. By the south wall is a " +
             "large bed covered by dark blue sheets. The room gives quite " +
             "a luxurious impression.\n");
    set_new_light(5);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("wall|walls","Smooth, black stone");
    add_item("room","A room that looks as if it is serving as living " +
             "quarters for a person pf a rather high rank");
    add_item("floor","Smooth, black stone covered by a black rug");
    add_item("rug","A soft, black rug that feels nice to walk upon");
    add_item("desk","A large, nicely crafted oak desk. It is covered with " +
             "papers, and there is a small lamp on it");
    add_item("lamp","A small oil lamp");
    add_item("paper|papers|document|documents","They look like letters, but " +
             "they are written in a strange language you don't understand");
    add_item("letter|letters","That's what it looks like. You can't " +
             "understand what is written in them, though");
    add_item("language","A strange, ugly language");
    add_item("bed","A big, comfortable looking bed covered with a dark " +
             "blue sheets");
    add_item("sheet","A dark blue velvet sheet");
    add_item("chair","A nicely crafted oak chair");

    (ROOM + "lev3_corridor1")->load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_commander",1)->set_aggressive(1);
    ::reset(arg);
}
