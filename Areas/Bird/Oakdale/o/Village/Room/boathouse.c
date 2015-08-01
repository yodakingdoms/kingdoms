#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

int oar_taken = 0;

void create_object(void);
void init(void);
int do_follow(string str);
int do_take(string str);
int query_oar_taken(void);

void create_object(void)
{
    set_short("A boathouse down by the river");
    set_long("You are in a boathouse in the village. The walls in this " +
             "house are covered with nets, lines, holders for oars and " +
             "shelves with boating equipment. There are only three walls " +
             "here, and where the east wall is supposed to be is a big " +
             "opening through which a slide leads straight down into the " +
             "river. The river flows swiftly past this point, and on the " +
             "other side you see the forest.\n");
    set_new_light(10);
    add_property("indoors");

    add_item("boathouse","You are in it. It's a house down by the river " +
             "where boats and boating equipment is kept");
    add_item("wall|walls","They are covered with various fishing equipment");
    add_item("nets","Nets hung up to dry");
    add_item("lines","Ropes and fishing lines");
    add_item("holders","Holders for oars");
    add_func_item("oars","#query_oar_taken",({
                  "Hmm, most of the oars seem to be in pretty bad shape. " +
                  "However, you do spot one oar that may be usable",
                  "The oars are in pretty bad shape, none of them are " +
                  "usable" }));
    add_func_item("oar","#query_oar_taken",({
                  "It looks as if it might be usable. You could take it if " +
                  "you wanted to",
                  "The oars are in pretty bad shape, none of them are " +
                  "usable" }));
    add_item("shelves","They are filled with boating equipment");
    add_item("equipment","Equipment like ropes, anchors and sails");
    add_item("ropes","Yes, ropes");
    add_item("anchors","Small anchors, suitable for anchoring a small boat");
    add_item("sails","They don't look like they've been used much. Makes " +
             "sense as it is not common practice to sail down rivers of " +
             "the kind flowing through this valley");
    add_item("opening","Big enough to push a boat in and out through. You " +
             "think you see a path outside, following the river to the " +
             "south and west");
    add_item("path","Maybe you could follow it and see where it takes you?");
    add_item("slide","A thing used to slide a boat into the river. " +
             "Basically the floor slopes down into the water");
    add_item("river","A swiftly flowing river. It would be very difficult " +
             "to try and swim across it");
    add_item("forest","A dark forest on the other side of the river");

    add_exit(ROOM + "road23","north");
}

void init(void)
{
    add_action("do_follow","follow");
    add_multi_action("do_take","take|get");
}

int do_follow(string str)
{
    if(str == "path")
    {
        W("You leave the house through the opening and follow the path " +
          "south. It turns immediately to the southwest, taking you to a " +
          "spot south of the boathouse.\n");
        TP->move_player("leaves through the opening and follows the path " +
                        "downstream",
                        FOREST + "Room/river_path1",
                        "comes walking here from inside the boathouse",1);
        return 1;
    }
    return notify_fail("Follow what?\n");
}

int do_take(string str)
{
    object oar;

    if(str == "oar")
    {
        if(!oar_taken)
        {
            W("You take the oar down from the holders on the walls.\n");
            S(TP->QN + " takes down an oar from the holders on the " +
              "walls.\n");
            oar_taken = 1;
            oar = make(WEAPON + "oar");
            if(transfer(oar,TP))
            {
                W("It's too heavy to pick up so you leave it on the floor.\n");
                S(TP->QN + " seems to be unable to carry it.\n");
            }
            return 1;
        }
    }
    return 0;
}

int query_oar_taken(void)
{
    return oar_taken;
}
