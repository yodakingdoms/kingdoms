#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

int vial_found;

void create_object(void);
void reset(int arg);
void init(void);
int do_search(string str);
int query_vial_found(void);

void create_object(void)
{
    set_short("First floor of tower (out/u)");
    set_long("The bottom floor of a tower that seems to have been abandoned " +
             "for a long time. There is dust everywhere and the floor is " +
             "covered with dirt. The wooden furniture in the room looks as " +
             "if it could crumble anytime and the walls, floor and ceiling " +
             "have large cracks in them. There's an empty fireplace in the " +
             "south wall and a window with broken glass in the north wall. " +
             "You see a bookshelf with old books on it by another wall and " +
             "an open wooden chest stands next to the empty doorway that " +
             "leads outside. Some stairs go up from here.\n");
    add_property("indoors");
    set_new_light(5);

    add_item("bottom floor","The bottom floor of an apparently abandoned " +
             "tower");
    add_item("tower|abandoned tower","You are standing in it");
    add_item("dust","The dust covers the floor and the furniture");
    add_item("floor","Covered with dust and dirt");
    add_item("dirt","It covers the floor");
    add_item("furniture|wooden furniture","A bookshelf, a table, some " +
             "chairs and a bed");
    add_item("table|chair|chairs|bed","The furniture doesn't look like if " +
             "it has been used in a long time");
    add_item("shelf|bookshelf","There are some old looking books in the " +
             "bookshelf");
    add_item("book|books","Most of them seem to be about birds, others " +
             "are written in strange runes you've never seen before");
    add_item("rune|runes","Very strange runes");
    add_item("wall|walls","The walls look cracked and old");
    add_item("north wall","There is a broken window in the north wall");
    add_item("south wall","There is an empty fireplace in the south wall");
    add_item("ceiling","The ceiling looks cracked and old");
    add_item("crack|cracks|large crack|large cracks","The cracks are large");
    add_item("fireplace|empty fireplace","It doesn't look like it's been " +
             "used in a long time");
    add_item("window|broken window","The glass in the window has been broken");
    add_item("glass|broken glass","The broken glass that used to be in the " +
             "window now lies on the floor below the window");
    add_item("doorway","The door that probably used to be in the doorway " +
             "is now gone");
    add_item("stair|stairs","They go up");
    add_func_item("chest|open chest|wooden chest|open wooden chest",
                 "#query_vial_found",({
                 "An open wooden chest. There are some glass vials in " +
                 "there. Most of them seem broken but maybe you'd find some " +
                 "that aren't if you searched the chest?",
                 "An open wooden chest. There's nothing in it but some " +
                 "broken glass vials"
                 }));
    add_func_item("vial|vials|glass vial|glass vials|broken glass vial|" +
                 "broken glass vials",
                 "#query_vial_found",({
                 "Most of the vials seem to be broken but maybe you'd find " +
                 "some who are not if you searched the chest?",
                 "They are all broken"
                 }));

    add_exit(PCROOM + "bird_tower_clearing","out");
    add_exit(PCROOM + "bird_tower_top","up");

    reset(0);
}

void reset(int arg)
{
    add_monster(PCMONSTER + "bird_tower_pirate",1);
    vial_found = 0;
}

void init(void)
{
    add_action("do_search","search");
}

int do_search(string str)
{
    object vial;

    if(str == "chest" || str == "vial" || str == "vials")
    {
        if(!query_vial_found() &&
           TP->query_skill("perception") > 20 + random(20))
        {
            W("You search through the chest and find one single vial " +
              "that isn't broken.\n");
            S(TP->QN + " searches through the chest and seems to find " +
              "something.\n");
            vial = make(PCOBJECT + "birdvial");
            if(transfer(vial,TP))
            {
                W("You carry too much to pick it up so you gently put " +
                  "it down on the floor.\n");
                S(TP->QN + " gently puts a small vial down on the floor.\n");
            }
            vial_found = 1;
            return 1;
        }
        W("You search through the chest but only find broken vials.\n");
        S(TP->QN + " searches through the chest but seems disappointed.\n");
        return 1;
    }
    return 0;
}

int query_vial_found(void)
{
    return vial_found;
}
