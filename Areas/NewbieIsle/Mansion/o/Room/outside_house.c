#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
string long_fun(void);
void init(void);
int do_climb(string str);
void tower_falls(void);
int query_tower_destroyed(void);

void create_object(void)
{
    set_short("Outside an abandoned mansion (s/house/stable)");
    set_long("#long_fun");

    set_new_light(5);

    add_item("mansion|old mansion|building","More of a ruin now, really. " +
             "The stone walls are crumbling and the roof is falling in. " +
             "It must have been magnificent once, but no longer");
    add_item("wall|walls|stone wall|stone walls","They look as if they " +
             "could fall apart at any time. They are covered with ivy");
    add_item("roof","It has already fallen in in some places");
    add_item("ruin|magnificent mansion","The once magnificent mansion is " +
             "now little more than a ruin");
    add_item("forest","You are deep inside the forest. You hope you " +
             "can get out of it by going back the way you came");
    add_item("house","It is in a state of disrepair, you feel a bit " +
             "sad looking at it");
    add_item("porch|once magnificent porch","It probably looked very " +
             "impressive to visitors once but now it looks as if it could " +
             "fall apart at any time");
    add_item("door|doorway","There is a doorway you can walk through to " +
             "enter the house but the door is missing");
    add_item("hole|holes|gaping hole|gaping holes|window|windows","Not " +
             "only is the glass long gone from the windows but the elements " +
             "have chewed away on the walls to make huge gaping holes " +
             "where the windows used to be");
    add_item("element|elements","Wind and rain, mostly");
    add_item("wind|rain|wind and rain","There's not a lot of that here at " +
             "the moment, thankfully");
    add_item("second floor","There are gaping holes in the walls where the " +
             "windows used to be. The windows have obviously been broken " +
             "but you can't tell how");
    add_func_item("tower|three story tower","#query_tower_destroyed",({
                    "A tower rising above the glen. It is covered with " +
                    "ivy and looks as if it could crumble at any time",
                    "It used to be a tower but now there's not much left " +
                    "of it"
                  }));

    add_func_item("ivy","#query_tower_destroyed",({
                    "Green ivy covers the whole building. Maybe you could " +
                    "climb the ivy to get up into the tower? You're not " +
                    "quite sure you will be safe up there though",
                    "Green ivy covers the whole building"
                  }));
    add_item("stable|remains|ruined remains","The roof has fallen in, only " +
             "the walls are standing and they too look like they could " +
             "fall in at any moment");
    add_item("glen","The glen is surrounded by trees. It continues to the " +
             "south. The atmosphere here is very quiet and peaceful");
    add_item("tree|trees","Most of them are large pine trees, towering " +
             "high above you");
    add_item("pine tree|pine trees|large pine tree|large pine trees","They " +
             "tower high above you and you feel like they are leaning in " +
             "over you");

    add_exit(ROOM + "forest_glen","south");
    add_exit(ROOM + "house_floor1_entrance","house");
    add_exit(ROOM + "stable","stable");
}

string long_fun(void)
{
    string long_desc = "You are outside an old mansion in the forest. " +
             "The house is in a state of disrepair and looks as if it " +
             "has been abandoned for a long time. In fact, it's more of " +
             "a ruin than a building now. The once magnificent porch is " +
             "crumbling and the door is missing. There are gaping holes " +
             "where the windows on the second floor used to be and the ";
    if(!query_tower_destroyed())
    {
        long_desc += "three story tower in the southwest corner " +
                     "looks like it could fall apart at any moment. ";
    }
    else
    {
        long_desc += "tower that used to stand in the southwest corner " +
                     "looks like it has fallen apart pretty recently. ";
    }
    long_desc += "The whole building is covered with ivy that looks like " +
           "it is slowly devouring the house. East of here is the ruined " +
           "remains of what seems to have been a stable. The glen " +
           "continues to the south and the trees of the forest tower " +
           "above you in all other directions.\n";
    return long_desc;
}

void init(void)
{
    add_action("do_climb","climb");
}

int do_climb(string str)
{
    if(str == "ivy")
    {
        if(TP->QS("climb") >= 15)
        {
            W("You grab hold of the ivy and climb up into the tower.\n");
            TP->move_player("grabs hold of the ivy on the tower wall " +
                            "and climbs up into the tower",
                            ROOM + "house_tower_top",
                            "climbs in from the outside",1);
            return 1;
        }
        else
        {
            W("You try to climb but you're simply not good enough at " +
              "climbing to get up there. Maybe if you had higher climb " +
              "skill?\n");
            S(TP->QN + " tries to climb the ivy on the tower wall but " +
              "fails pretty miserably.\n");
            return 1;
        }
    }
    return notify_fail("Climb what?\n");
}

void tower_falls(void)
{
    tell_room(TO,"Suddenly you hear some noises that sound like they're " +
              "coming from a collapsing building from inside the house.\n");
    if(present("goblin",find_object(ROOM + "house_floor1_entrance")))
    {
        tell_room(TO,"You hear horrible, terrified screams from inside the " +
                  "house!\n");
    }
}

int query_tower_destroyed(void)
{
    //return (ROOM + "house_tower_top")->query_tower_destroyed();
    return 0;
}
