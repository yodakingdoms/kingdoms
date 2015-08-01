#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A dark, cold cave");
    set_long("A small, vaguely circular cave. Water is dripping from the " +
             "ceiling, forming small puddles on the rough stone floor. This " +
             "cave seems to be a dead end, and the only way out is the " + 
             "tunnel to the north. A tiny skeleton lies by one of the " +
             "walls.\n");
    set_new_light(0);
    add_property("indoors");
        
    add_item("cave","This cave is smaller than the one to the north, and " +
             "vaguely circular in shape");
    add_item("water","Water is dripping from the ceiling, forming small " +
             "puddles on the floor");
    add_item("puddle|puddles","Small puddles of water");
    add_item("wall","There is a skeleton lying by it");
    add_item("walls","There is a skeleton lying by one of them");
    add_item("ceiling","A rough stone ceiling");
    add_item("floor","A rough stone floor");
    add_item("tunnel","The tunnel goes north to the bigger cave");
    add_item("skeleton|remains","It appears to be the remains of a rat");
    
    add_sounds(05,80,({ "Drip, drop...\n" }));
    
    add_exit(ROOM + "wfallcave_tunnel2","north");
    
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "rat",1);
} 
