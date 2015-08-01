#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("The landing on the second floor");
    set_long("The landing on the second floor. The big hall is silent, and " +
             "the only light is coming from two flickering torches on the " +
             "walls. Stairs go down to the first floor here and the hall " +
             "continues to the south, where you think you see another set " +
             "of stairs going up. Large murals cover the smooth stone " +
             "walls. In the north wall is an archway, beyond which you see " +
             "a corridor. The ceiling is lost in the darkness above you.\n");
    set_new_light(5);
    add_property("indoors");
    add_property("allow_horse");

    add_item("room|landing|hall","A large, silent hall");
    add_item("torch|torches","Two flickering torches prodviding the room " +
             "with just enough light to make it possible to see in here");
    add_item("wall|walls","Smooth, black stone walls with large murals on " +
             "them");
    add_item("stairs","Black, smooth stone stairs going down");
    add_item("mural|murals","Large murals depicting a huge, black dragon " +
             "circling the towers of a dark castle under a starlit sky");
    add_item("dragon","A huge, black dragon in mid flight. For a moment you " +
             "thought you saw it's eyes glow faintly");
    add_item("eye|eyes","Nah, it was probably just a trick of the light... " +
             "Or was it?");
    add_item("towers|tower|castle","The dragon looks as if it is circling " +
             "the towers of a dark castle that stands upon a high cliff. " +
             "It looks familiar somehow..");
    add_item("cliff","A high, steep cliff");
    add_item("sky","A starlit night sky");
    add_item("archway","An archway in the north wall");
    add_item("corridor","It lies beyond the archway to the north");
    add_item("ceiling","It is so high you can't even see it. The torches " +
             "do not provide the room with enough light");
    add_item("darkness","An eerie darkness. It almost seems physical");

    add_exit(ROOM + "lev1_entr2","down");
    add_exit(ROOM + "lev2_landing2","south");
    add_exit(ROOM + "lev2_corridor1","north");
}
