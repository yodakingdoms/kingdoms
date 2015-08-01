#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_search(string str);

void create_object(void)
{
    set_short("A small, dark cave");
    set_long("A small cave with a smooth stone floor. There is a hole in " +
             "one wall, and inside of the hole you notice a vertical shaft. " +
             "Fresh air is entering this otherwise damp cave through the " +
             "shaft. Water is dripping from the ceiling, forming small " +
             "puddles on the floor.\n");
    set_new_light(0);
    add_property("indoors");
    
    add_item("hole|oven","A hole in the wall, from which a vertical shaft " +
             "leads out into the open air. There are some ashes in the " + 
             "hole. It looks like an oven");
    add_item("shaft","A vertical shaft. You feel fresh air flowing from it, " +
             "and when you stick your head inside the hole and look up, you " +
             "see the sky");
    add_item("sky","You see it through the shaft");
    add_item("remains","Just ashes");
    add_item("ashes","The remains of burnt firewood");
    add_item("water","The water is dripping from the ceiling, forming small " +
             "puddles on the floor");
    add_item("puddle|puddles","Small puddles of water dripping from the " +
             "ceiling");
    add_item("floor","An uneven stone floor");
    add_item("ceiling","A rough stone ceiling");
    
    add_sounds(05,80,({ "Drip, drop...\n" }));

    add_exit(ROOM + "wfallcave_tunnel3","east");    
}

void init(void)
{
    add_action("do_search","search");
    ::init();
}

int do_search(string str)
{
    if(str == "hole" || str == "oven" || str == "remains" || str == "ashes")
    {
        W("You search but find nothing. Guess it was just too obvious.\n");
        S(TP->QN+" searches the ashes in the hole.\n");
        return 1;
    }
}
