#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A tunnel through the outer gate tower");
    set_long("You are in a tunnel through the outer gate tower. The road " +
             "is cobblestoned and the ceiling is arched. The ceiling has " +
             "many holes and thin slits in it and in the middle of the " +
             "tunnel you see the sharp spikes of a raised portcullis " +
             "protrude from it. Through the opening to the west you see " +
             "the drawbridge.\n");
    set_new_light(5);
    add_property("indoors");
    add_property("allow_horse");

    add_item("road","A road paved with cobblestones");
    add_item("ceiling","It is high and arched, littered with slits and " +
             "holes");
    add_item("slit|slits","Thin slits, probably for firing nasty things at " +
             "attackers trying to enter the castle through the tower");
    add_item("hole|holes","Small holes, probably for pouring nasty things " +
             "down at attackers trying to enter the castle through the tower");
    add_item("spike|spikes","It is the bottom part of the portcullis that " +
             "is protruding from the ceiling");
    add_item("portcullis","The portcullis is raised at the moment, allowing " +
             "you to enter the castle");
    add_item("castle","You are in it's outer gate tower at the moment");
    add_item("tower","The outer gate tower is the castle's first line of " +
             "defence");
    add_item("defence|line","From the looks of it, the castle has a very " +
             "strong defence");
    add_item("tunnel","The tunnel passes through the tower");
    add_item("drawbride","The drawbridge seems to be lowered");

    add_exit(FOREST + "Room/front_of_castle","east");
    add_exit(ROOM + "drawbridge","west");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_guard",2);
}
