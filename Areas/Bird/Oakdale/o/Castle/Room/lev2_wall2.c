#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    setuid();
    seteuid(getuid(this_object()));
    set_short("The battlements on the east wall");
    set_long("You are up on the battlements of the east wall of the " +
             "castle. The castle. The wind is howling and dark clouds are " +
             "gathering over the castle, slowly circling the highest tower " +
             "of the castle. The wall continues to the south, and to the " +
             "west is the third gate tower. To the east is the ravine that " +
             "separates the castle rock from the forested side of the " +
             "valley.\n");
    set_new_light(5);
    add_property("no_horse");

    add_item("battlements|wall","It is the outer line of defence for the " +
             "castle");
    add_item("cloud|clouds","Dark, sinister clouds, slowly circling the " +
             "highest tower of the castle");
    add_item("tower","The high tower or the gate tower?");
    add_item("high tower","A thin, black tower. There is something eerie " +
             "about that tower, and shivers run down your spine as you " +
             "look up at it");
    add_item("gate tower","It is to your west");
    add_item("ravine","A steep, deep ravine. Falling down there would mean " +
             "certain death");
    add_item("rock|cliff","The cliff the castle is built upon");
    add_item("valley|side","The valley is rising to the east. The forest " +
             "is dark and silent down there");
    add_item("forest","A dark, silent forest of oak trees");
    add_item("tree|trees|oak|oaks","Huge, ancient oak tres");

    add_exit(ROOM + "lev2_wall1","south");
    add_exit(ROOM + "lev2_tower2","west");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_sentry",2);
    foreach(object ob: all_inventory())
    {
        if(ob->id("darkling")) ob->set_walking();
    }
}
