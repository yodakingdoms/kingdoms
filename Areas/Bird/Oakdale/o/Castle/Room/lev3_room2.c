#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A small, dimly lit room");
    set_long("A small, dimly lit room. A large wooden desk stands by the " +
             "south wall, and a wooden chair stands in front of it. A " +
             "warbanner hangs on one of the walls and the floor is covered " +
             "by a soft, black rug. By the west wall is a large bed, " +
             "covered by a black sheet. A wooden chest stands by the foot " +
             "of the bed. The room gives quite a luxurious impression.\n");
    set_new_light(5);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("wall|walls","Smooth, black stone");
    add_item("room","A room that looks as if it is serving as living " +
             "quarters for a person of a rather high rank");
    add_item("floor","Smooth, black stone covered by a black rug");
    add_item("rug","A soft, black rug that feels nice to walk upon");
    add_item("desk","A large, impressive looking oak desk");
    add_item("bed","A big, comfortable looking bed covered with a black " +
             "sheet");
    add_item("sheet","A black velvet sheet");
    add_item("chair","A nicely crafted oak chair with a dark blue cushion");
    add_item("cushion","A soft, dark blue cushion");
    add_item("warbanner|banner","A black banner with a symbol of a black " +
             "dragon");
    add_item("symbol|dragon","It is the heraldic symbol on the warbanner");
    add_item("chest","A wooden chest that looks like a clothes chest");

    (ROOM + "lev3_corridor1")->load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_commander",1)->set_aggressive(1);
    ::reset(arg);
}
