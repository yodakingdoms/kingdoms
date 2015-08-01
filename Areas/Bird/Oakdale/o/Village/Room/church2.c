#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_pray(string str);

void create_object(void)
{
    set_short("An inner room in the Oakdale church");
    set_long("This is a small, tranquil room in the church. The floor, " +
             "ceiling and walls are made of white marble. Four pillars " +
             "form a square on the floor, in the centre of which there " +
             "stands a small altar. There are windows on the north, west " +
             "and south walls, but the light entering this room seems dull. " +
             "There is dust on the floor, and the air feels empty. You " +
             "sense the absense of... something. Like the gods have " +
             "turned from this valley.\n");
    set_new_light(10);
    add_property("indoors");

    add_item("floor|wall|walls|ceiling","Made of white marble");
    add_item("marble","White marble, radiating a soft, dull light");
    add_item("pillar|pillars","They are made of white marble");
    add_item("altar","A small marble altar. You feel strangely unmoved when " +
             "you look at it. It is strangely obvious that it is just a " +
             "block of dead stone");
    add_item("light","The light in this room feels dull in a strange way. " +
             "Your vision is blurred when you look around");
    add_item("window|windows","The windows are decorated but the light " +
             "coming through them is somehow... dull");
    add_item("dust","A thin layer of dust");
    add_item("air","The air feels empty in a strange way");

    add_exit(ROOM + "church","east");
}

void init(void)
{
    add_action("do_pray","pray");
}

int do_pray(string str)
{
    W("You kneel down in front of the altar and lower your head in prayer. " +
       "Somehow you sense that noone is listening, and your prayer goes " +
       "unanswered.\n");
    S(TP->QN + " kneels down in front of the altar and lowers " + TP->QPO +
      " head in prayer. The prayer does not seem to be answered.\n");
    return 1;
}
