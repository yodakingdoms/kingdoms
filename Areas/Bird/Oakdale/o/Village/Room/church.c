#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_sit(string str);
int do_pray(string str);
int do_listen(string str);

void create_object(void)
{
    set_short("The main hall of the Oakdale church");
    set_long("You are in the main hall of the Oakdale church. The walls " +
             "and the floor are of shining white marble and the high domed " +
             "ceiling is supported by two rows of white marble pillars " +
             "forming an aisle between the door and a slightly raise part " +
             "of the floor in the west part of the hall. On the wall " +
             "behind the platform is a huge, beautifully painted window and " +
             "on the north and south walls are several smaller, decorated " +
             "windows. Four rows of wooden benches stands on each side of " +
             "the aisle. By the north wall you see some stairs leading up " +
             "to the bell tower, and an archway in the west wall leads into " +
             "an inner room. The hall is quiet and tranquil.\n");
    set_new_light(10);
    add_property("indoors");

    add_item("wall|walls|floor","Made of stainless, shining, white marble");
    add_item("marble","The whitest marble. It almost seems like it's " +
             "shining with some inner light");
    add_item("light","A soft, soothing light. Still, you feel a longing " +
             "feeling, like the light is dormant, waiting for someone or " +
             "something..");
    add_item("ceiling","A high, domed marble ceiling supported by pillars");
    add_item("rows","Look at the pillars or the benches");
    add_item("pillars","Two rows of round, undecorated pillars made of " +
             "white marble");
    add_item("aisle","An aisle leading from the door up to the raised " +
             "platform by the centre of the west wall");
    add_item("platform","A raised part of the floor. Probably where the " +
             "priest used to stand while preaching");
    add_item("window","The huge window takes up most of the wall. The " +
             "image is in a likeness of a god smiling down at you");
    add_item("god","Hmm, you really can't tell which one it is");
    add_item("windows","They are decorated with images of gods");
    add_item("gods","You can't really recognize them, or wait... The last " +
             "window seems to depict a familiar face");
    add_item("face","It looks like Yoda! Funny, you thought he was only a " +
             "[WIZ]..");
    add_item("benches","Wooden benches where the congregation used to sit");
    add_item("stairs","The stairs go up");
    add_item("archway","A modestly decorated archway leading west");

    add_exit(ROOM + "clearing","east");
    add_exit(ROOM + "church2","west");
    add_exit(ROOM + "church3","up");
}

void init(void)
{
    add_action("do_sit","sit");
    add_action("do_pray","pray");
    add_action("do_listen","listen");
}

int do_sit(string str)
{
    W("You sit down on one of the benches. It is hard and uncomfortable, a " +
      "sure way to keep the congregation alert and awake. You sit for a " +
      "while enjoying the tranquility of the hall, but you can't help " +
      "feeling a sense of loss. Something is missing...\n");
    S(TP->QN + " sits down on one of the benches, pondering deeply.\n");
    return 1;
}

int do_pray(string str)
{
    W("You bow your head in prayer, but you can't reach the divinity that " +
      "once resided in this building. Your prayer goes unanswered.\n");
    S(TP->QN + " begins to pray, but the prayer seems to go unanswered.\n");
    return 1;
}

int do_listen(string str)
{
    W("Not a sound can be heard. It is eerily quiet.\n");
    S(TP->QN + " listens carefully.\n");
    return 1;
}
