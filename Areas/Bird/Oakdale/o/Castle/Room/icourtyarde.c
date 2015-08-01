#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("The east side of the inner courtyard");
    set_long("The east side of the inner courtyard of the castle. The " +
             "cobblestoned yard is buzzing with activity. Troops are " +
             "running around, marching and excercising. It seems like " +
             "chaos, but noone is colliding or fumbling. Everything is " +
             "happening with machine-like precision. To the east are the " +
             "massive inner gates of the castle and the third gate tower " +
             "looming over the courtyard. The courtyard continues to the " +
             "west, and to the north and south are the cold, black walls " +
             "of the inner castle. Dark clouds are gathering in the sky " +
             "above you.\n");
    set_new_light(5);

    add_item("yard|courtyard","It's the inner courtyard of the castle, " +
             "crawling with activity");
    add_item("troops","Darkling troops running and marching around. Most " +
             "of them do not seem to notice you, and those who do don't " +
             "seem to care");
    add_item("gate|gates","Massive wooden gates. It would be a very " +
             "difficult task to force them open when shut and barred");
    add_item("tower","The gate tower looms over the courtyard. There are " +
             "plenty of arrowslits in it's wall through which defenders " +
             "could pour death upon attackers who reach the courtyard");
    add_item("arrowslit|arrowslits","Plenty of them high up on all the " +
             "walls surrounding the courtyard");
    add_item("wall|walls","High, black stone walls with no windows in " +
             "them, only arrowslits");
    add_item("window|windows","There are no real windows around here, only " +
             "arrowslits");
    add_item("cloud|clouds","Dark, threatening clouds are gathering over " +
             "the castle");

    add_exit(ROOM + "gatetower3","east");
    add_exit(ROOM + "icourtyardw","west");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_soldier",2);
    foreach(object ob: all_inventory())
    {
        if(ob->id("darkling")) ob->set_walking();
    }
}
