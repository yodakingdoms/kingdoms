#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
string long_fun(void);
void init(void);
int do_climb(string str);
int do_swim(string str);
int do_drink(string str);
int query_rope_tied(void);

void create_object(void)
{
    set_short("Bottom of a gully (w/e)");
    set_long("#long_fun");

    set_new_light(5);

    add_item("bottom|grassy bottom|dry bottom","The bottom of the gully is " +
             "dry and grassy. It looks as if it was a long time since the " +
             "big stream that created the gully turned into the small brook " +
             "that flows here now");
    add_item("gully|deep gully|wide gully|deep, wide gully","A deep, wide " +
             "gully cutting through the woods");
    add_item("forest|wood|woods","You can't see much of the woods from down " +
             "here but it seems like you might be able to do that if you " +
             "go down to the east");
    add_item("stream|big stream","Judging by how wide and deep the gully " +
             "is it must have been created by a big stream. Something must " +
             "have happened further upstream because now there's only a " +
             "small brook at the bottom of the gully here");
    add_item("brook|small brook","The small brook trickles gently down " +
             "towards the east. The water is clear");
    add_item("water","The water is clear and clean");
    add_func_item("sides","#query_rope_tied",({
                  "The sides of the gully are steep and grassy. There are " +
                  "some stones sticking out of the north side",
                  "The sides of the gully are steep and grassy. There are " +
                  "some stones sticking out of the north side and there is " +
                  "also a rope hanging down from above there"
                  }));
    add_func_item("rope","#query_rope_tied",({
                  "",
                  "A rope hanging down from above. You could climb it to " +
                  "get up from here"
                  }));
    add_item("stone|stones","White stones sticking out of the north side " +
             "of the gully. You could climb the stones to get out of the " +
             "gully");
    add_item("side","There is a north side and a south side of the gully");
    add_item("south side","The south side of the gully is steep and grassy");
    add_func_item("north side","#query_rope_tied",({
                  "The north side of the gully is steep and grassy. There " +
                  "are some stones sticking out of it",
                  "The north side of the gully is steep and grassy. There " +
                  "are some stones sticking out of it and there is also a " +
                  "rope hanging down from above there"
                  }));
    add_item("branch|branches","They reach out over the gully, pretty high " +
             "above you");
    add_item("tree|trees","You don't see much of the trees next to the " +
             "gully, only their branches. You see more trees down towards " +
             "the east where the brook seems to run out into a pond");
    add_item("ground","The ground slopes down towards the east. There are " +
             "several large white rocks sticking out of it. They look like " +
             "strange large eggs sticking out of the ground");
    add_item("egg|eggs|large egg|large eggs|strange large egg|" +
             "strange large eggs","They're not really eggs, they just " +
             "look kind of like eggs");
    add_item("rock|rocks|large rock|large rocks|white rock|white rocks|" +
             "large white rock|large white rocks","The white rocks seem to " +
             "be remnants of the bridge that once crossed the gully");
    add_item("remnant|remnants","The bridge seems to have collapsed, and " +
             "the remnants have fallen down into the stream and been " +
             "dragged down towards the east");
    add_item("bridge","Only remnants remain of the bridge");
    add_item("cliff|steep cliff","You'd have to go west to get a better look");
    add_item("pond","There seems to be a small pond down towards the east, " +
             "where the brook trickles out");
    add_item("grass","It grows on the ground and on the sides of the gully");
    add_item("glen","You would have to go there to get a better look");

    add_exit(ROOM + "gully_bottom1","west");
    add_exit(ROOM + "forest_glen","east");

    add_sounds(10,10,({ "The brook trickles gently down towards the east.\n",
                        "You hear the soothing sound of running water from " +
                        "the brook.\n",
                        "You hear the wind in the trees above the gully.\n"
                      }));
}

void init(void)
{
    add_action("do_climb","climb");
    add_multi_action("do_swim","swim|dive");
    add_multi_action("do_drink","drink|taste");
    SYS_ADMIN->visit(1106);
    ::init();
}

int do_climb(string str)
{
    if(str == "rope" && query_rope_tied())
    {
        W("You climb the rope.\n");
        TP->move_player("grabs the rope and climbs up the side of the gully",
                        ROOM + "forest_path2",
                        "comes climbing up from the gully",1);
        return 1;
    }
    else if(str == "stone" || str == "stones")
    {
        W("You grab the stones and climb up the side of the gully.\n");
        TP->move_player("grabs the stones and climbs up the side of the gully",
                        ROOM + "forest_path2",
                        "comes climbing up from the gully",1);
        return 1;
    }
    return notify_fail("Climb what?\n");
}

int do_swim(string str)
{
    if(str == "water" || str == "brook" || str == "in water" ||
       str == "in brook" || str == "into water" || str == "into brook")
    {
        W("The brook is far too shallow for you to be able to swim in it. " +
          "You walk around in it for a while, splashing water everywhere.\n");
        S(TP->QN + " walks around in to brook for a while, splashing water " +
          "at you!\n");
        return 1;
    }
    return notify_fail(C(query_verb()) + " where?\n");
}

int do_drink(string str)
{
    if(str == "water")
    {
        W("You " + query_verb() + " the water. It is very cold and tastes " +
          "good.\n");
        S(TP->QN + " bends down and drinks some water from the brook.\n");
        return 1;
    }
    return notify_fail(C(query_verb()) + " what?\n");
}

string long_fun(void)
{
    string long_desc = "You are at the bottom of a deep gully running in an " +
             "east-west direction through the forest. The sides of the " +
             "gully are grassy and steep and tower above you so you can't " +
             "see much of the surrounding woods except for the branches of " +
             "the trees on both sides reaching out over the gully. The " +
             "ground slopes down towards the east and a small brook in the " +
             "middle of the bottom trickles gently that way. The ground " +
             "beside the brook is pretty dry and in some places you see " +
             "large white rocks sticking out of it. There is a steep cliff " +
             "to the west, and to the east the gully seems to end as the " +
             "brook to runs out into a pond. There also seems to be a glen " +
             "in the forest there.";
    if(query_rope_tied())
    {
        long_desc += " There is a rope hanging down from above on the " +
                     "north side of the gully.";
    }
    return long_desc + "\n";
}

int query_rope_tied(void)
{
    return (ROOM + "forest_path2")->query_rope_tied();
}
