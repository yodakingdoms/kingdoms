#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);

void create_object(void)
{
    set_short("A short corridor");
    set_long("A dark, narrow corridor. The only light in here comes from a " +
             "flickering torch on one of the black stone walls. You detect " +
             "a strange smell, and hear noises from both the north and the " +
             "south. To the east is an archway, beyond which the main " +
             "entrance hall lies.\n");
    set_new_light(5);
    add_property("indoors");
        
    add_item("corridor","A dark, narrow corridor");
    add_item("torch","A single, flickering torch");
    add_item("wall|walls","Black stone walls");
    add_item("archway","The main entry hall lies beyond it");
    add_item("hall","It lies beyond the archway");
    add_item("%|%food","It smells like food. Not like nice food, though");
    add_item("$|$voices","You hear talking voices from both the north " +
             "and the south");
    
    add_exit(ROOM + "lev1_entr","east");

    (ROOM + "lev1_diner")->load_doors();
    (ROOM + "lev1_kitchen")->load_doors();
    reset(0);    
}
