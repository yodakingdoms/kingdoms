#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A dungeon cell");
    set_long("A cold, damp dungeon cell. There is a heap of straw on the " +
             "floor, and a chain is attached to the rough stone wall. Water " +
             "is seeping through the walls and gathering in small puddles " +
             "as it trickles down to the floor. The smell here is awful.\n");
    set_light(0);
    add_property("indoors");
    set_skip_obvious(1);

    add_item("cell","A cold, damp cell. You shiver when you think about " +
             "how it would feel to be locked up in here ");
    add_item("heap|straw","A small heap of damp, rotting straw");
    add_item("chain","A thick iron chain. Probably for chaining prisoners " +
             "to the wall with");
    add_item("wall|walls","Rough, black stone");
    add_item("water","Water is seeping through the walls and trickling to " +
             "the floor, gathering in small puddles");
    add_item("floor","A rough, black stone floor");
    add_item("puddles|puddle","Small puddles of dirty water");
    add_item("%|%cell","It reeks of vomit and disease. The occupant of " +
             "this cell can't be very healthy");

    (ROOM + "dung_corridor4")->load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "sick_prisoner",1);
    ::reset(arg);
}
