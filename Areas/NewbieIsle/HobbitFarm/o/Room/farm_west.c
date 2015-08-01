#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_climb(string str);

void create_object(void)
{
    set_short("West side of the farm (e/n/nw/w/sw)");
    set_long("The west side of the large yard in the middle of a small " +
             "farm. There's almost no grass on the ground here, just " +
             "trampled dirt with many different tracks in it. On the west " +
             "side of the yard is the big barn of the farm, a large wooden " +
             "building with two floors. There is a shed to the northwest " +
             "and a path goes north from here, between the shed and the " +
             "stable to the northeast. South of the yard is a fenced in " +
             "area and to the southeast is a grassy hill with a huge oak " +
             "growing on top of it. The yard continues east and another " +
             "path leads southwest from here.\n");

    set_new_light(5);

    add_item("west side|side","That's where you are now");
    add_item("yard|large yard","The yard is the centre of the farm. Most " +
             "activities take place there");
    add_item("farm|small farm|hobbit farm|small hobbit farm","A small " +
             "hobbit farm");
    add_item("grass","There's not much of it here, most of it has been " +
             "trampled");
    add_item("ground","The ground here is trampled dirt with many " +
             "different tracks in it");
    add_item("dirt|trampled dirt|firm dirt","Trampled and firm, but still " +
             "with plenty of tracks in it");
    add_item("track|tracks","Tracks from different kinds of animals, and " +
             "also from boots and wagons");
    add_item("barn|big barn|building|wooden building|large wooden building",
             "A big wooden building with two floors. The doors are wide " +
             "open and on the second floor is a large opening from which " +
             "a wooden beam sticks out");
    add_item("floor|floors","There are two of them in the barn");
    add_item("doors","They are wide open, it looks like the whole wall is " +
             "open, really");
    add_item("wall","The doors in the wall of the barn are so big it " +
             "looks as if the whole wall has been taken out");
    add_item("second floor","It's on top of the first floor");
    add_item("first floor","It's below the second floor");
    add_item("opening|large opening","A large opening probably used to " +
             "haul hay in and out through");
    add_item("beam|wooden beam|rope|pulleys|system|system of pulleys",
             "There's a rope tied to a system of pulleys at the end of " +
             "the wooden beam. The rope goes into the barn through the " +
             "opening");
    add_item("rope|system of pulleys|pulley|pulleys|end|end of the beam",
             "A rope and a system of pulleys probably used to lift " +
             "bales of hay up to the second floor of the barn");
    add_item("shed|wooden shed|small shed|small wooden shed","A small " +
             "wooden shed with no windows and no door. You can't see " +
             "what's inside it from here");
    add_item("stable","The stable is northeast of here but you would have " +
             "to go east to enter it");
    add_item("path","The north path or the southwest path?");
    add_item("north path","The path goes north between the shed and the " +
             "stable towards a rather large field on the north side of " +
             "the farm");
    add_item("field|large field","You'd have to go north to get a better " +
             "look");
    add_item("southwest path","The path goes southwest to what appears " +
             "to be a cornfield");
    add_item("cornfield","You'd have to go southwest to get a better look " +
             "at it");
    add_item("area|fenced in area|small area|small fenced in area","A " +
             "small area surrounded by a wooden fence. You might be able " +
             "to get inside if you follow the path to the southwest");
    add_item("fence|wooden fence|normal fence|normal wooden fence",
             "Just a normal wooden fence, not at all as delicately carved " +
             "as the one surrounding the farm. It would be pretty high " +
             "for someone the size of a hobbit, but it's pretty small to " +
             "you. Maybe you could try to climb it?");
    add_item("hill|grassy hill","There are windows and a round door in " +
             "the sides of the hill");
    add_item("sides|grassy sides","The sides of the hill are grassy and " +
             "there are windows and a door in them");
    add_item("door|round door","It is east of here");
    add_item("window|windows|small window|small windows|round window|" +
             "round windows|small, round window|small, round windows",
             "Small round windows with there curtains open");
    add_item("curtain|curtains","They are open, giving the hill a " +
             "welcoming look");
    add_item("top|top of the hill","A huge oak tree grows there, looming " +
             "over the farm");
    add_item("tree|oak|huge tree|huge oak|oak tree|huge oak tree","A huge " +
             "oak tree grows on top of the hill. The oak seems to be the " +
             "only thing on the farm that doesn't look smaller than it " +
             "should normally be");
    add_item("$|$sound|$sounds|$animal|$animals","You hear the sounds of " +
             "farm animals coming from all around you");
    add_item("%|%smell|%animal|%animals","You feel the smell of farm " +
             "animals. It is strong here");

    add_exit(ROOM + "farm_center","east");
    add_exit(ROOM + "farm_path1","north");
    add_exit(ROOM + "farm_shed","northwest");
    add_exit(ROOM + "farm_barn_floor1","west");
    add_exit(ROOM + "farm_path2","southwest");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "pig",4);
}

void init(void)
{
    add_action("do_climb","climb");
}

int do_climb(string str)
{
    if(str == "fence")
    {
        if(TP->QS("climb") >= 15)
        {
            W("You climb the fence with ease.\n");
            TP->move_player("climbs the fence on the south side of the yard",
                            ROOM + "farm_sheep_field",
                            "comes climbing over the fence on the north " +
                            "side of the field",1);
        }
        else
        {
            W("You're not a good enough climber to climb even this small " +
              "fence. Maybe raising your climb skill would be in order?\n");
            S(TP->QN + " tries to climb the fence on the south side of the " +
              "yard but fails miserably.\n");
        }
        return 1;
    }
    return notify_fail("Climb what?\n");
}
