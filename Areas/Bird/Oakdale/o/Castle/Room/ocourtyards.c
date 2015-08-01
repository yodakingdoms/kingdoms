#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("The southern end of the outer courtyard");
    set_long("You are in the southern end of the outer courtyard. The road " +
             "turns north towards the third gate tower and to the east are " +
             "the huge wooden gates of the inner gate tower that towers " +
             "above you to the east. To the west and the south are the " +
             "high, black stone walls of the castle proper. The only " +
             "windows on those walls are a few thin arrowslits, high up " +
             "there.\n");
    set_new_light(5);
        
    add_item("courtyard|yard","A yard between the gate towers and walls, " + 
             "paved with cobblestones");
    add_item("towers|tower","The inner gate tower looms over the courtyard " +
             "to the east, and the third gate tower is at the north end of " +
             "the courtyard");
    add_item("wall","A high windowless wall");
    add_item("walls","High, windowless walls");
    add_item("road","A cobblestoned road going north and east");
    add_item("cobblestone|cobblestones","Round, smooth stones");
    add_item("gate|gates","Two huge wooden doors");
    add_item("door|doors","It would take an immense amount of force to " +
             "break down these doors");
    add_item("window|windows|arrowslit|arrowslits","Thin slits high up on " +
             "the walls");    
           
    add_exit(ROOM + "gatetower2","east");
    add_exit(ROOM + "ocourtyardn","north");
           
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_guard")->set_walking();
}
