#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

int rope_tied;

void create_object(void);
void my_reset(void);
void init(void);
int do_climb(string str);
int tie(string str);
void untie(void);
int query_rope_tied(void);

void create_object(void)
{
    set_short("End of a forest path (n)");
    set_long("The path through the forest ends here. In front of you is " +
             "a wide gully cutting its way through the woods. The gully " +
             "runs from the west down towards the east, where the ground " +
             "slopes down steeply. The gully is wide and deep but almost " +
             "dry. There is only a small brook on the bottom, gently " +
             "trickling down towards the east. The forest on the other " +
             "side of the gully is even denser than on this side and you " +
             "think you see the path continue to the south there. There " +
             "are some remnants of what looks to have been a stone bridge " +
             "across the gully here but there is no way to cross it now.\n");

    set_new_light(5);

    add_item("path","It ends abruptly here in front of the gully. It seems " +
             "to continue on the other side but since the bridge is gone " +
             "there's no way to cross the gully and get there");
    add_item("ground","The ground slopes down steeply to the east");
    add_item("forest","The forest is dense on this side of the gully, and " +
             "even denser on the other side. You can see the path going " +
             "into the forest on the other side but you can't cross here");
    add_item("tree|trees","There are plenty of them on this side of the " +
             "gully, and even more of them on the other side");
    add_item("gully|wide gully|deep gully|wide and deep gully|" +
             "deep and wide gully","The gully is deep and wide and it looks " +
             "like there's been quite an impressive stream running through " +
             "the forest here at one time. The sides of the gully are " +
             "steep but it doesn't look like it would be impossible " +
             "to climb down to the bottom of it");
    add_item("stream","There's not much of a stream here now, just a small " +
             "brook trickling quietly down towards the east at the bottom " +
             "of the gully");
    add_item("side|sides","The sides of the gully are pretty steep but it " +
             "might be worth it to try to climb them to get down to the " +
             "bottom");
    add_item("bottom","There's a small brook trickling down towards the " +
             "east at the bottom of the gully. If you could climb down " +
             "there, you could follow it in that direction");
    add_item("brook","A small brook at the bottom of the gully, gently " +
             "trickling down towards the east. If you could climb down " +
             "there, you could follow it in that direction");
    add_item("remnant|remnants","Some remnants of what seems to have been " +
             "a stone bridge across the gully once. You could tie a rope " +
             "to them to help you climb down if you wanted to");
    add_func_item("bridge|stone bridge","#query_rope_tied",({
                  "There's not a lot of it left, only " +
                  "some remnants on this side of the gully remain",
                  "There's not a lot if it left, only some remnants on this " +
                  "side of the gully remain. There's a rope tied to them"
                  }));

    add_exit(ROOM + "forest_path1","north");

    add_sounds(30,20,({
                "You hear the soft sound of running water from the brook " +
                "at the bottom of the gully.\n",
                "You hear the wind in the trees around you.\n",
                "You think you hear a howl from somewhere in the forest on " +
                "the other side of the gully.\n"
              }));

    my_reset();
}

void my_reset()
{
    add_monster(MONSTER + "hobbit_girl",1);
}

void init(void)
{
    add_action("do_climb","climb");
    ::init();
}

int do_climb(string str)
{
    if(str == "side" || str == "down" || str == "gully" || str == "bottom" ||
       str == "sides" || (str == "rope" && query_rope_tied()))
    {
        if(query_rope_tied())
        {
            W("You grab the rope and climb down to the bottom of the " +
              "gully.\n");
            TP->move_player("grabs the rope and climbs down to the bottom " +
                            "of the gully",
                            ROOM + "gully_bottom2",
                            "comes climbing down the rope",1);
            return 1;
        }
        else if(TP->QS("climb") >= 20)
        {
            W("You climb down the side and get to the bottom of the " +
              "gully.\n");
            TP->move_player("climbs down the side to the bottom of the gully",
                            ROOM + "gully_bottom2",
                            "comes climbing down the side of the gully",1);
            return 1;
        }
        else
        {
            W("The sides are a bit too steep for you to climb. Maybe if " +
              "you were better at climbing, or if there was a rope tied " +
              "to the remnants of the bridge that you could use?\n");
            S(TP->QN + " looks down towards the bottom of the gully.\n");
            return 1;
        }
    }
    return notify_fail("Climb where?\n");
}

/**
* Called by the standard ropes when tying rope to items.
*/
int tie(string str)
{
    if((str == "remnants" || str == "remnant") && !rope_tied)
    {
        tell_room(ROOM + "gully_bottom2","The end of a rope falls down " +
                  "from above. The rope is now dangling down from there.\n");
        rope_tied = 1;
        return 1;
    }
    return 0;
}

/**
* Called by ropes.
*/
int untie(void)
{
    if(rope_tied)
    {
        tell_room(ROOM + "gully_bottom2","The rope is pulled up from " +
                  "above.\n");
        rope_tied = 0;
        return 1;
    }
    return 0;
}

int query_rope_tied(void)
{
    return rope_tied;
}
