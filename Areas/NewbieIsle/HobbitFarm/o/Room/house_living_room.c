#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;
inherit MOD_DOOR;

void create_object(void);
void init(void);
int do_sit(string str);
int do_light(string str);
int load_doors(void);

void create_object(void)
{
    ::create_object();
    set_short("A living room (n)");
    set_long("This room is pretty large for a hobbit house room. It " +
             "seems to fill most of the south side of the hill and there " +
             "are several larger windows in the south wall with green " +
             "curtains hanging next to them. There is a table in the " +
             "middle of the room with some chairs placed around it. A " +
             "comfortable looking couch stands behind the table, against " +
             "the south wall. There's a fireplace in the west wall with " +
             "a box containing firewood next to it.\n");

    add_item("room|hobbit house room","This room is larger than rooms " +
             "in this kind of house usually are. The ceiling is low but " +
             "you feel at home here anyway");
    add_item("hill","You are inside the hill now");
    add_item("side|south side","This room takes up most of it");
    add_item("window|windows|large window|large windows|larger window|" +
             "larger windows|wall","They take up most of the " +
             "wall. You see a garden outside them");
    add_item("south wall","Most of the south wall is taken up by the " +
             "large windows");
    add_item("garden","Why don't you go out and have a look?");
    add_item("ceiling","The ceiling curves softly above you, making the " +
             "room feel more like an animal den than a room");
    add_item("wall|walls","The walls curve around you, making the " +
             "room feel more like an animal den than a room");
    add_item("curtain|curtains","Green curtains, giving the room a cosy " +
             "look");
    add_item("table|wooden table","A wooden table with four short legs");
    add_item("leg|legs|short leg|short legs","The legs only lift the " +
             "table a little bit into the air");
    add_item("chair|chairs","The chairs placed round the table are meant " +
             "for hobbits. You would not fit in one");
    add_item("couch|comfortable looking couch","A couch made for hobbits " +
             "but it looks big enough that you can sit on it if you want " +
             "to");
    add_item("west wall","There's a fireplace there");
    add_item("fireplace","A fireplace where one can make a small fire. " +
             "There's no fire burning there at the moment");
    add_item("box|firewood","A box with firewood standing next to the " +
             "fireplace");
    add_item("floor|wooden floor","The floor is made of wood and feels " +
             "nice to walk upon");
    add_item("%|%room|%smell","The room smells fresh, like it was cleaned " +
             "not too long ago");

    add_exit(ROOM + "house_hallway","north");

    load_doors();
    reset(0);
}

void init(void)
{
    add_action("do_sit","sit");
    add_action("do_light","light");
    ::init();
}

int do_sit(string str)
{
    if(str == "couch" || str == "on couch" || str == "in couch")
    {
        W("You sit down on the couch and relax for a while. It's a bit " +
          "small but pretty comfortable nontheless.\n");
        S(TP->QN + " sits down in the couch and relaxes for a while.\n");
        return 1;
    }
    else if(str == "chair" || str == "in chair")
    {
        W("You are too big to sit in the hobbit sized chairs.\n");
        S(TP->QN + " tries to sit in one of the chairs, but the chair " +
          "is too small.\n");
        return 1;
    }
    return notify_fail("Sit where?\n");
}

int do_light(string str)
{
    if(str == "fire")
    {
        W("You think it would be rude to light a fire in someone elses " +
          "fireplace without asking so you decide against it.\n");
        return 1;
    }
}

int load_doors(void)
{
    string dir1 = "in the south wall";
    string dir2 = "in the side of the hill to the north";
    string next_room = ROOM + "house_garden";
    string desc = "small round back door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A round wooden door that is a bit smaller than " +
                       "the door you entered the house through, but " +
                       "you will still fit through it.\n";
    string entercmd1 = "south";
    string entercmd2 = "north";
    int solidity = 30;
    int complex = 20;
    int hidden1 = 0;
    int hidden2 = 0;

    add_door(dir1, dir2, next_room, desc,  closed, locked, key_id,
             long_desc, entercmd1, entercmd2, solidity, complex,
             hidden1, hidden2 );
    return 1;
}
