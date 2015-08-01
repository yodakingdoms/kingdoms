#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_follow(string str);
int do_squint(string str);

void create_object(void)
{
    set_short("An oak grove");
    set_long("You are in a grove. Old oaks grow all around you and very " +
             "little light finds its way down through the branches and " +
             "leaves. The undergrowth is thick. From the east you can hear " +
             "the sound of the river, and you also hear a flute being " +
             "played somewhere. You can only go back to the road to the " +
             "north or the west.\n");
    set_new_light(1);

    add_item("trees","Old oak trees. They are still strong and healhty");
    add_item("light","There is not much of it here. You have to squint to " +
             "see properly in here");
    add_item("squirrel","As you try to get a closer look, it scurries away");
    add_item("leaf|leaves","They grow on the branches");
    add_item("branches","Leaves grow on the branches. The branches grow on " +
             "trees");
    add_item("undergrowth","It is very thick. You can't discern any paths " +
             "or trails");
    add_item("$|$flute|$sound|$river","You hear the river to the east, and " +
             "a flute being played somewhere vaguely in the same " +
             "direction. Maybe you could follow the sound of the flute?");
    add_item("river|flute","You can't see it, only hear it");

    add_exit(ROOM + "road8","north");
    add_exit(ROOM + "road22","west");
}

void init(void)
{
    add_action("do_follow","follow");
    add_action("do_squint","squint");
}

int do_follow(string str)
{
    if(str == "sound" || str == "flute")
    {
        W("You follow the sound of the flute deeper into the grove.\n");
        TP->move_player("walks deeper into the grove",
                        ROOM + "grove2",
                        "comes walking here from the outside",1);

        return 1;
    }
    return notify_fail("Follow what?\n");
}

int do_squint(string str)
{
    W("You see a small squirrel peering quizzically at you from one of " +
      "the branches.\n");
    S(TP->QN + " squints.\n");
    return 1;
}
