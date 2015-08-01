#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_listen(string str);

void create_object(void)
{
    set_short("A small, damp cave");
    set_long("A small, damp cave dimly lit by a flickering torch hanging " +
             "on a wall. A narrow tunnel goes east from here and to the " +
             "southeast there seems to be another, larger cave. There is " +
             "a wooden table and two stools here. Strange shadows dance " +
             "on the walls and the dampness in the air seeps into your " +
             "clothes, making you feel sluggish. You hear voices coming " +
             "from some other room, but the echoes created in the caves " +
             "makes it hard to determine exactly which direction they " +
             "come from.\n");
    set_new_light(10);
    add_property("indoors");

    add_item("cave","A small cave, apparently a guardroom");
    add_item("torch","A flickering wooden torch hanging on a wall");
    add_item("wall|walls","Smooth stone");
    add_item("tunnel","You can't see where it leads from here");
    add_item("table","A wooden table");
    add_item("stools","Two small wooden stools");
    add_item("stool","A small wooden stool");

    add_exit(ROOM + "dgcave_throne","southeast");
    add_exit(ROOM + "dgcave_beds","southwest");
    add_exit(ROOM + "dgcave_tunnel","east");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "DGguard",2);
}

void init(void)
{
    add_action("do_listen","listen");
}

int do_listen(string str)
{
    if(TP->query_skill("perception") > (30+random(20)))
    {
        W("You think the voices are coming from the larger cave to the " +
          "southeast, but you can't be entirely sure.\n");
        S(TP->QN + " listens carefully.\n");
        return 1;
    }
    W("You can't discern where the sounds come from... Listening to them " +
      "only confuses you.\n");
    S(TP->QN + " listens carefully and seems a bit confused.\n");
    return 1;
}
