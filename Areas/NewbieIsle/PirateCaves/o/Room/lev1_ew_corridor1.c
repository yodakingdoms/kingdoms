#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

void create_object(void);
void init(void);
int  do_listen(string str);
int  do_smell(string str);
int  do_feel(string str);

void create_object(void)
{
    ::create_object();
    set_short("An underground corridor (w/e/s)");
    set_long("An underground corridor going west and east, with a "+
             "doorway to the south. To the west you see some stairs "+
             "going down to the floor below, and you can hear sounds "+
             "and smell strange things from down there. East of here "+
             "the corridor seems to turn north and you can feel air "+
             "flow into the corridor from there. There is enough light "+
             "coming from the room to the south for you to be able to "+
             "see here.\n");

    add_item("corridor","It is a cramped underground corridor with stone "+
             "walls, floor and ceiling");
    add_item("doorway","There is no door in the doorway and there seems "+
             "to be a room behind it. Light from that room lets you see "+
             "properly in this room");
    add_item("door","The door seems to have been ripped from its hinges "+
             "by someone or something");
    add_item("hinge|hinges","The hinges are still in the doorway but "+
             "there is no door attached to them");
    add_item("room","Well, to see this room, type 'look'. To see the room "+
             "to the south, type 'look south'");
    add_item("light","The light in this room comes from the room to the "+
             "south");
    add_item("air","You can't see it, but you can feel it");
    add_item("sound|sounds","You can't see the sounds, but you can hear "+
             "them");
    add_item("thing|things","You can't see the things, but you can smell "+
             "them");
    add_item("stair|stairs","You can't see the stairs from here");

    add_exit(PCROOM + "lev1_kitchen_stairs","west");
    add_exit(PCROOM + "lev1_wn_corridor","east");
    add_exit(PCROOM + "lev1_south_guardroom","south");

    add_sounds(30,80, ({ "You hear noises from the west.\n",
                         "You feel a soft wind from the east.\n" }));
}

void init(void)
{
    add_action("do_listen","listen");
    add_multi_action("do_smell","smell|sniff");
    add_action("do_feel","feel");
    ::init();
}

int do_listen(string str)
{
    if(str == "noises")
    {
        W("The usual noises heard from a kitchen when someone is "+
        "using it.\n");
    }
    else
    {
        W("You can hear noises indicating there is a kitchen somewhere "+
          "to the west, down the stairs.\n");
    }
    S(TP->QN + " listens carefully.\n");
    return 1;
}

int do_smell(string str)
{
    if(str == "things" || str == "strange things" || str == "food" ||
       str == "strange food" || str == "alcohol")
    {
        W("Judging by the smell, the food being prepared somewhere to "+
          "the west is spiked with enough alcohol to stun a medium sized "+
          "bull.\n");
    }
    else
    {
        W("You feel the smell of strange food mixed with the smell "+
          "of alcohol coming from the stairs to the west.\n");
    }
    S(TP->QN + " sniffs the air.\n");
    return 1;
}

int do_feel(string str)
{
    if(str == "air" || str == "breeze")
    {
        W("It seems as if there is an opening where the breeze is entering "+
          "the corridor somewhere around the corner to the east.\n");
    }
    else
    {
        W("The air flowing into the corridor from the east feels like "+
          "a soft breeze on your skin.\n");
    }
    S(TP->QN + " seems to daydream a bit.\n");
    return 1;
}
