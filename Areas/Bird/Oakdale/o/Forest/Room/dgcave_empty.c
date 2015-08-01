#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_sleep(string str);
int do_dig(string str);

void create_object(void)
{
    set_short("A small cave with a low ceiling");
    set_long("A small, oval shaped cave. The floor is packed dirt and the " +
             "walls and ceiling is rough stone. The ceiling is pretty low, " +
             "and you bump your head when you try to stand up straight. A " +
             "heap of leaves, twigs and branches lies in a corner.\n");
    set_new_light(0);
    add_property("indoors");

    add_item("cave","A small cave with just one exit, and that's back out " +
             "the way you came");
    add_item("floor","The floor in this cave is smooth packed dirt");
    add_item("dirt","Dirt that has been packed by people walking upon it. " +
             "It does not look too hard to dig in, though");
    add_item("wall|walls|ceiling","Rough, uneven stone");
    add_item("corner","It is occupied by a heap of leaves, twigs and " +
             "branches");
    add_item("heap","It looks like something an animal would pull together " +
             "to sleep upon");
    add_item("leaf|leaves|twigs|twig|branch|branches","There are plenty " +
             "of them in the heap in the corner");

    add_exit(ROOM + "stone_quarry","out");
}

void init(void)
{
    add_action("do_sleep","sleep");
    add_action("do_sleep","lie");
    add_action("do_dig","dig");
}

int do_sleep(string str)
{
    if(str == "in heap" || str == "on heap" || str == "on leaves" ||
       str == "in leaves")
    {
        W("You lie down on the heap to take a nap. You roll around in the " +
          "leaves for a while, but the branches and twigs keep poking you " +
          "in strategic places, preventing you from relaxing. After a " +
          "while you give up, just as well, as there probably are more " +
          "important things to do here.\n");
        S(TP->QN + " lies down on the heap and rolls around in it for a " +
          "while, seemingly unable to find a comfortable spot.\n");
        return 1;
    }
    return notify_fail("Where do you want to do that?\n");
}

int do_dig(string str)
{
    if(str == "in dirt" || str == "dirt")
    {
        W("The dirt is soft enough for you to be able to dig in it with " +
          "just your hands. You dig for a while, but the only thing you " +
          "manage to do is get dirty hands. Seems like nothing interesting " +
          "is buried here.\n");
        S(TP->QN + " starts playing in the dirt on the floor, looking just " +
          "like a little baby! How cute!:)\n");
        return 1;
    }
    return notify_fail("Dig where?\n");
}
