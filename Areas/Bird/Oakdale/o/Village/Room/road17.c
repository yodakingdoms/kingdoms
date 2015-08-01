#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A road leading south from the village");
    set_long("A road leading south from the village. The forest has closed " +
             "in around you, but to the south you can see a clearing where " +
             "the church stands. The church tower can be seen over the " +
             "treetops, slender and white. A bird is circling the tower " +
             "and you can hear it sing. To the northeast the castle looms " +
             "over the trees.\n");
    set_new_light(5);

    add_item("forest","A forest of oak trees. The vegetation on the " +
             "ground is lush and green, but not a sound can be heard from " +
             "within");
    add_item("clearing","The road seems to end in the clearing to the " +
             "south. A slender church tower rises over the treetops there");
    add_item("tower","A beautiful white construction");
    add_item("bird","A swallow circling the tower. It almost looks as if " +
             "it's waiting for someone or something");
    add_item("$|$bird|$swallow","You can hear the bird sing a sad song in " +
             "a voice that sounds almost human");
    add_item("castle","It stands there silent on it's cliff overlooking " +
             "the village");

    add_exit(ROOM + "road16","north");
    add_exit(ROOM + "clearing","south");
}
