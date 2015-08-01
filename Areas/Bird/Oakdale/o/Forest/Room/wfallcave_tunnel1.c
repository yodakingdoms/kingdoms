#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A dark tunnel");
    set_long("A dark tunnel sloping gently downwards. The rough stone walls " +
             "are closing in, and you can almost feel the weight of the " +
             "hill above pressing down upon the ceiling. The air is damp " +
             "and water is dripping from the ceiling. To the west the " +
             "passage seems to be widening. It is rather chilly in here.\n");
    set_new_light(0);
    add_property("indoors");
        
    add_item("tunnel|passage","A dark, chilly tunnel sloping gently " + 
             "downwards");
    add_item("water","Water is dripping from the ceiling");
    add_item("wall|walls","Rough stone walls");
    add_item("ceiling","A rough stone ceiling");
    
    add_sounds(05,80,({ "Drip, drop...\n" }));    

    add_exit(ROOM + "wfallcave_mainroom","west");
    add_exit(ROOM + "wfallcave_entrance","east");
}
