#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_enter(string str);

void create_object(void)
{
    set_short("A road leading south from the square");
    set_long("You are on a road leading south from the main square of the " +
             "village. The square is to the north, and the road continues " +
             "to the south. There is a house to the west and to the east " +
             "you see a grove of oak trees. Further south the road turns " +
             "to the west. To the east the cliff towers above the village. " +
             "The castle stands there silent, overlooking the village.\n");
    set_new_light(5);

    add_item("square","It appears to be the centre of the village, but " +
             "there does not seem to be much activity");
    add_item("house","A small house with a red roof and a stone chimney");
    add_item("grove","A grove of oak trees. You can hardly see anything " +
             "in there, as very little light comes through the branches of " +
             "the trees. You think you can hear something from inside the " +
             "grove, though..");
    add_item("cliff","Dark and threathening it looms over the village");
    add_item("castle","The castle stands there on it's cliff. It looks " +
             "spooky and you soon turn away from the sight");
    add_item("$|$melody|$flute|$grove","You think you hear someone playing " +
             "a sad melody on a flute in there. Maybe you could enter the " +
             "grove and investigate?");

    add_exit(ROOM + "square","north");
    add_exit(ROOM + "road23","south");
}

void init(void)
{
    add_action("do_enter","enter");
}

int do_enter(string str)
{
    if(str == "grove")
    {
        W("You enter the grove to investigate.\n");
        TP->move_player("enters the grove",
                        ROOM + "grove",
                        "comes walking into the grove from the road " +
                        "outside",1);
        return 1;
    }
    return notify_fail("Enter what?\n");
}
