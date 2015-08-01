#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_push(string str);
int do_open(string str);

void create_object(void)
{
    set_short("A dark tunnel");
    set_long("You are at the end of a dark, narrow corridor with a " +
             "smooth stone floor and ceiling and smooth stone walls. To the " +
             "east is a wall with a closed stone door in it. To the west " +
             "and up, the corridor disappears into darkness.\n");
    set_new_light(0);
    add_property("indoors");

    add_item("corridor","A dark coridor, dug through living rock");
    add_item("floor|ceiling|walls","Smooth, black stone");
    add_item("wall","There is a stone door in the wall");
    add_item("door","A stone door with no handle or lock");

    add_exit(ROOM + "tunnel8","westup");
}

void init(void)
{
    add_action("do_push","push");
    add_action("do_open","open");
}

int do_push(string str)
{
    if(str == "door")
    {
        W("You push the door open and squeeze through into the room " +
          "on the other side before it slams shut again.\nYou catch a " +
          "glimpse of the mechanism and believe it looks like you'll be " +
          "able to get back here by pushing the wall in the room on the " +
          "other side.\n");
        TP->move_player("pushes the stone door open and squeezes through " +
                        "before it slams shut again",
                        CASTLE + "Room/dung_bottom2",
                        "squeezes into the room through a suddenly opening " +
                        "door in the west wall before it slams shut again",1);
        return 1;
    }
    return notify_fail("Push what?\n");
}

int do_open(string str)
{
    if(str == "door")
    {
        W("You can't open it. It seems it would open if you would push " +
          "it, and you notice a mechanism that will shut it again. You " +
          "believe it looks like you'd be able to open this door again " +
          "from the other side, simply by pushing the wall in that room if " +
          "you want to get back in here.\n");
        S(TP->QN+" tries to open the door.\n");
        return 1;
    }
    return 0;
}
