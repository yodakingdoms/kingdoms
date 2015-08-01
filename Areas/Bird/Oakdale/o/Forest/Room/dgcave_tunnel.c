#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A dark, damp corridor");
    set_long("You are in a dark, damp corridor going east and west. The " +
             "stone walls, ceiling and floor are smooth and black, " +
             "smoother here than in the rest of the caves. It seems this " +
             "tunnel has been more carefully dug out than the rest of the " +
             "caves, a fact that makes you doubt that it is the work of " +
             "the dark gnomes. There is a light to the east and you can " +
             "hear a low chanting from that direction, a sound made even " +
             "more eerie by the dimness in this corridor.\n");
    set_new_light(10);
    add_property("indoors");
        
    add_item("corridor|tunnel","A dark, narrow corridor. Quite " +
             "skillfully dug out of the rock");
    add_item("wall|walls|floor|ceiling","Smooth, black stone");
    add_item("light","A faint, flickering light, like from a candle");
    add_item("dimness","The corridor is not lit. The light here comes " +
             "from the east");  
    add_item("$|$chanting|$sound|$echoes","You can hear slow, monotonous " +
             "chanting from the east. An eerie sound, made even more eerie " +
             "by the echoes in the caves and the dimness of the tunnel");
    
    add_exit(ROOM + "dgcave_guards2","west");
    add_exit(ROOM + "dgcave_shrine","east");    
}
