#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);

void create_object(void)
{
    set_short("The Oakdale tavern");
    set_long("You have entered the tavern in Oakdale. Faces turn to look " +
             "at you as you stand in the door, but soon people return to " +
             "their conversations. This is a big room with a low ceiling. " +
             "A few large wooden tables stand by the walls, and the roof " +
             "is supported by four wooden pillars. People are seated on " +
             "wooden benches around the tables and light is provided by " +
             "small lamps. A fireplace is in the north wall, but the fire " +
             "is not lit. The air is filled with smoke and the curtains " +
             "are drawn, making it hard to see clearly in here. The room " +
             "smells of beer, and you can hear people mumbling as they " +
             "look your way.\n");
    set_new_light(5);
    add_property("indoors");
    add_property("no_fight");

    add_item("ceiling","The ceiling is low, held up by thick roof beams " +
             "and four wooden pillars");
    add_item("beams","Strong wooden beams. Looks like oak beams");
    add_item("table|tables","Heavy oak tables");
    add_item("pillars|pillar","Thick wooden pillars with torch holders " +
             "attached to them");
    add_item("torch|torches","They are not lit at the moment");
    add_item("bench|benches","Wooden benches placed around the tables and " +
             "by the walls");
    add_item("wall|walls","Made of stone");
    add_item("lamp|lamps","Small oil lamps on the tables");
    add_item("fireplace","It is cold, as there's no fire burning in it at " +
             "the moment");
    add_item("smoke","Smoke from pipes, making it hard to see clearly into " +
             "all the corners");
    add_item("corner|corners","The smoke is making it hard to see clearly " +
             "into them");
    add_item("curtain|curtains","They are drawn, blocking out much of the " +
             "light");
    add_item("%|%beer|%smoke|%swear","You smell beer, smoke and sweat");
    add_item("$|$people","You hear the people saying things like: " +
             "Stranger. This will mean trouble for sure... They all eye " +
             "you suspiciously");

    add_exit(ROOM + "road6","south");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "storyteller",1);
}

void init(void)
{
    if(!TP->test_flag(QUEST_SUB_FLAG_1))
    {
        TP->add_exp(5000,1);
        TP->set_flag(QUEST_SUB_FLAG_1);
    }
}
