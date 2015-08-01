#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_cross(string str);

void create_object(void)
{
    set_short("A path through the forest. There's a bridge to the west");
    set_long("The forest is very thick here, and the trees reach out " +
             "across the path, leaving you in shadow and almost creating " +
             "a ceiling over your head. The creaking rope bridge is to the " +
             "west, and the river flows beneath it. The path continues to " +
             "the east, down the side of a ravine. The castle is no longer " +
             "in sight, and you feel relieved to have escaped it's " +
             "attention. A low rumbling sound can be heard from the " +
             "southeast.\n");
    set_new_light(3);

    add_item("bridge","A swaying, creaking rope bridge. It held while " +
             "you came to this side of the river, but there are no " +
             "guarantees it'll hold to take you back. Still, you could " +
             "cross it if you wanted to get back to the other side");
    add_item("forest","A very thick forest of oak trees. Nothing can be " +
             "seen or heard in there");
    add_item("tree|trees|oak|oaks","The ancient oaks reach out over the " +
             "path, their branches almost creating a ceiling above you");
    add_item("branch|branches","Thick branches reaching out across the path");
    add_item("path","A barely noticable path going east, down the side of " +
             "a ravine");
    add_item("side","The side of the ravine. It is pretty steep, but the " +
             "path continues down there");
    add_item("shadow","You are standing in it");
    add_item("ceiling","A sort of a ceiling formed by the branches of the " +
             "trees");
    add_item("river","A fast flowing river crossed at this point by a " +
             "rope bridge");
    add_item("ravine","You stand at the top of a narrow ravine. The " +
             "path continues down the side of it");
    add_item("$|$creaking|$bridge|$rumble|$waterfall","You hear the " +
             "creaking of the bridge and the low rumble of a waterfall " +
             "somewhere to the southwest");

    add_exit(ROOM + "river_path4","eastdown");
}

void init(void)
{
    add_multi_action("do_cross","cross|w|west");
}

int do_cross(string str)
{
    W("You carefully step out onto the bridge, which sways and creaks as " +
      "you cross it. You feel relieved when you're back on the village " +
      "side of the river.\n\n");
    TP->move_player("steps out onto the bridge, which sways violently and " +
                    "creaks loudly as " + TP->QPR + " crosses it. " +
                    "Eventually " + TP->QPR + " reaches the other side, " +
                    "looking very relieved",
                    ROOM + "river_bridge",
                    "comes walking across the bridge",1);
    return 1;
}
