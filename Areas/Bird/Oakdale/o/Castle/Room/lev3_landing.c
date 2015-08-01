#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("Third floor landing");
    set_long("The landing on the third floor. The hall is silent, and the " +
             "only light is coming from two flickering torches on the " +
             "black stone walls. The hall continues to the north. " +
             "Impressive looking stairs go down to the second floor. The " +
             "stairs are flanked by two stone statues, one on each side. " +
             "You are beginning to feel very uneasy here.\n");
    set_new_light(5);
    add_property("indoors");
    add_property("allow_horse");

    add_item("room|hall|landing","The landing is a dimly lit, silent room");
    add_item("torch|torches","There are two flickering torches on the walls");
    add_item("wall|walls","Smooth, black stone");
    add_item("stairs|step|steps","Smooth, black stone steps going down, " +
             "flanked by two stone statues");
    add_item("statue|statues","The right statue or the left statue?");
    add_item("right statue","The statue shows a man dressed in robes. His " +
             "fingers are long and slender, but his face cannot be seen");
    add_item("left statue","The statue shows a dragon standing on it's " +
             "hind legs with it's wings folded");
    add_item("man","You can't discern his face");
    add_item("dragon","A gruesome looking beast");

    add_exit(ROOM + "lev2_landing2","down");
    add_exit(ROOM + "lev3_landing2","north");
}
