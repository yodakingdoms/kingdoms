#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
void init(void);

void create_object(void)
{
    set_short("The second floor of the sanatarium");
    set_long("You are on the second floor of the sanatarium. This is a " +
             "dark, smelly room with a small barred window on the west " +
             "wall. There is no furniture in this room, only a bed of " +
             "straw in one corner of the room. You shiver when you think " +
             "about what it would be like to get locked inside a room " +
             "like this.\n");
    set_skip_obvious(1);
    set_new_light(10);
    add_property("indoors");

    add_item("window","A small barred window overlooking the road");
    add_item("bars|bar","Strong iron bars");
    add_item("road","You look out the window, but decide that you'd get a " +
             "better look of the road if you'd go down there");
    add_item("bed","Well, it's just a heap of straw, really");
    add_item("heap|straw","A heap of straw. It's a sorry excuse for a bed");
    add_item("%|%urin|%decay|%room","BLAEH! The room reeks of urin and decay");

    (ROOM + "sanatarium4")->load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "madman",1);
    ::reset(arg);
}

void init(void)
{
    if(!TP->test_flag(QUEST_SUB_FLAG_4))
    {
        TP->add_exp(10000,1);
        TP->set_flag(QUEST_SUB_FLAG_4);
    }
    ::init();
}
