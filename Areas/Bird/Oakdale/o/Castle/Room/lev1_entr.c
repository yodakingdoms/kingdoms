#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("The main entrance hall of the castle");
    set_long("You are in the main entrance hall of the castle. The hall " +
             "is completely silent and the only light comes from two " +
             "flickering torches on the walls. The high ceiling is lost " +
             "in the darkness above you and every step you take creates " +
             "an eerie echo. The floor is cold, smooth and black, and " +
             "large murals hang on the walls. The hall continues to the " +
             "south, and archways in the east and west walls go into " +
             "corridors on both sides.\n");
    set_new_light(5);
    add_property("indoors");
    add_property("allow_horse");

    add_item("room|hall","A majestic, silent hall");
    add_item("torch|torches","Two desperately flickering torches. It almost " +
             "seems as if the air in here is trying to smother them");
    add_item("wall|walls","Cold, black stone walls");
    add_item("ceiling","The light from the torches does not reach all the " +
             "way up there, so you can't see it");
    add_item("darkness","An eerie, almost physical darkness. You can't " +
             "help feeling that someone or something is watching you from " +
             "up there");
    add_item("floor","A smooth, black stone floor");
    add_item("mural|murals","Murals depicting the image of a man, whose " +
             "face cannot be seen, sitting in front of a huge, black dragon");
    add_item("man","A man dressed in black robes, but his face cannot be " +
             "seen");
    add_item("face","It is obscured by the hood of his robe");
    add_item("robe|robes|hood","He is wearing black robes and a hood is " +
             "obscuring his face");
    add_item("dragon","A huge black dragon with it's wings folded. For a " +
             "moment you thought you saw its eyes glow faintly");
    add_item("wing|wings","The dragon has folded it's wings");
    add_item("eye|eyes","Nah, it must have been a trick of the light... or?");
    add_item("light","The hall is very dimly lit");
    add_item("archway|archways","A corridor lies beyond each archway");
    add_item("corridor|corridors","You can't see where any of the " +
             "corridors go");
    add_item("$|$echo","Your every move creates an eerie echo. Other than " +
             "that, nothing can be heard");

    add_exit(ROOM + "icourtyardw","north");
    add_exit(ROOM + "lev1_entr2","south");
    add_exit(ROOM + "lev1_corridor1","west");
    add_exit(ROOM + "lev1_corridor2","east");
}
