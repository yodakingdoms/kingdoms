#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A barely noticable path through the forest");
    set_long("You are on a barely noticable path through the forest. The " +
             "path turns to the northwest here, and you think you see a " +
             "clearing up ahead. The forest is dense and dark here, as only " +
             "a few rays of light find their way down between the branches. " +
             "The air is still and the forest is silent.\n");
    set_new_light(3);

    add_item("path","A barely noticable path. Seldom walked upon by the " +
             "looks of it");
    add_item("clearing","Yes, there is a clearing to the northwest. You " +
             "think you see a house there too..");
    add_item("house","Well, definetly a construction of some sort, but you " +
             "can't quite tell what it is from here");
    add_item("forest","A forest of oak trees. This part of the forest is " +
             "even darker and more uninviting than the rest of it");
    add_item("light|ray|rays","Only a few rays of light trickle down to the " +
             "path");
    add_item("tree|trees|oak|oaks","Huge, ancient oaks");
    add_item("branch|branches","Thick branches blocking out much of the " +
             "light");
    add_item("$|$heart|$sound","Everything is silent. The only sound you " +
             "hear is the sound of your own heart beating");

    add_exit(ROOM + "cottage_clearing","northwest");
    add_exit(ROOM + "cottage_path1","east");
}
