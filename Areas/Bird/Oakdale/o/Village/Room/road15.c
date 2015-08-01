#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("An intersection in the village");
    set_long("An intersection in the village. Roads lead north, south " +
             "and west. To the east is a house. To the west there seems " +
             "to be some sort of yard, and you can hear people talking " +
             "from that direction. Some distance to the south there " +
             "appears to be a church. You can see the bell tower above the " +
             "rooftops of the nearby houses. The castle looms over the "+
             "village, more to your northeast now.\n");
    set_new_light(5);

    add_item("house","An older house that does not seem to be in very " +
             "good condition");
    add_item("yard","It looks like a larger open area in the midst of a " +
             "group of houses");
    add_item("church|tower","The bell tower of the church can be seen over " +
             "the roofs of the houses. A bird is circling the tower");
    add_item("bird","It appears to be a swallow. You assume it has it's " +
             "nest in the tower");
    add_item("castle","It looks eerie");

    add_exit(ROOM + "road14","north");
    add_exit(ROOM + "road16","south");
    add_exit(ROOM + "road18","west");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "gargan");
}
