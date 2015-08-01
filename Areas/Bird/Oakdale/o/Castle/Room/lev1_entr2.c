#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("The south end of the main entrance hall");
    set_long("The southern end of the main entrance hall of the castle. " +
             "The only light in the hall is coming from two flickering " +
             "torches on the walls. The ceiling is high above you, lost " +
             "in the darkness, and the hall is silent. Every step you take " +
             "on the smooth stone floor creates an eerie echo. A broad " +
             "staircase goes up from here. It is flanked by two statues, " +
             "one on each side.\n");
    set_new_light(5);
    add_property("indoors");
    add_property("allow_horse");

    add_item("room|hall","A majestic, silent hall");
    add_item("torch|torches","Two desperately flickering torches");
    add_item("wall|walls","Black stone walls");
    add_item("ceiling","The ceiling is somewhere in the darkness above you");
    add_item("darkness","The two torches do not do mch to keep it away");
    add_item("staircase","A staircase made of black stone, flanked by two " +
             "stone statues");
    add_item("statue|statues","Look at the left statue or the right statue");
    add_item("left statue|man","A black stone statue showing a man dressed " +
             "in robes with a hood covering his face");
    add_item("right statue|dragon","A black stone statue showing a dragon " +
             "on it's hind legs, wings folded");
    add_item("$|$footsteps","You only hear your own footsteps echo round " +
             "the hall..");

    add_exit(ROOM + "lev1_entr","north");
    add_exit(ROOM + "lev2_landing","up");
}
