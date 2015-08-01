#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("The south end of the second floor landing");
    set_long("The south end of the landing on the second floor. The big " +
             "hall is silent, and the ceiling is lost in the darkness " +
             "above you. Two flickering torches on the walls provide the " +
             "only light in the room. The hall continues to the north, and " +
             "an impressive set of stairs go up to the third floor. The " +
             "stairs are flanked by two statues, one on each side. There " +
             "is a modest looking archway in the east wall.\n");
    set_new_light(5);
    add_property("indoors");
    add_property("allow_horse");

    add_item("room|hall|landing","A big, silent hall. It continues to the " +
             "north");
    add_item("ceiling","The light from the torches does not reach all the " +
             "way up there, so you can't see it");
    add_item("darkness","Pretty scary. You have an unpleasant feeling that " +
             "someone or something is watching you from up there");
    add_item("torch|torches","There are two flickering torches on the walls");
    add_item("wall|walls|floor","Smooth, black stone");
    add_item("stairs","Smooth, black stone steps that will take you up to " +
             "the third floor. The stairs are flanked by two stone statues");
    add_item("statue|statues","Look at the right statue or the left statue");
    add_item("right statue|man","A black stone statue depicting a man " +
             "dressed in robes. His features can not be seen, as his face " +
             "is covered by his hood");
    add_item("left statue|dragon","A black stone statue depicting a dragon " +
             "standing on it's hind legs, wings folded");
    add_item("archway","A modest looking archway with a silent chamber " +
             "beyond");
    add_item("chamber","You can't really look at it from here");

    add_exit(ROOM + "lev2_landing","north");
    add_exit(ROOM + "lev2_chapel","east");
    add_exit(ROOM + "lev3_landing","up");
}
