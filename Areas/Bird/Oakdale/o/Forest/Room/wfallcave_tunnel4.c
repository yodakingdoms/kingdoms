#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A dark, narrow tunnel");
    set_long("A dark, narrow tunnel sloping sharply downwards. The air is " +
             "cold and damp, and water is dripping from the ceiling, " + 
             "trickling down to the northwest when it hits the floor. The " +
             "ceiling is so low you can't stand up straight. You feel " +
             "uneasy here, and you can almost feel the weight of the hill " +
             "above pressing down upon the ceiling.\n");
    set_new_light(0);
    add_property("indoors");
        
    add_item("tunnel","The tunnel is steeply sloping downwards. It is " +
             "narrow and the ceiling is low. You get an unpleasant, " +
             "claustrophobic feeling in here.");
    add_item("water","Water dripping from the ceiling, slowly trickling " +
             "down to the northwest as it hits the floor");
    add_item("ceiling","The ceiling is so low you can't stand up straight");
    add_item("floor","The floor is sloping sharply downwards. It is quite " +
             "slippery from the water dripping from the ceiling");
    
    add_sounds(05,80,({ "Drip, drop...\n" }));

    add_exit(ROOM + "wfallcave_mainroom","southeast");
    add_exit(ROOM + "wfallcave_storage","northwest");
}
