#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
string long_fun(void);
void init(void);
int do_push(string str);
int do_open(string str);
int query_door_open(void);

void create_object(void)
{
    set_short("A dark tunnel");
    set_long("#long_fun");
    set_new_light(0);
    add_property("indoors");

    add_item("corridor","A dark coridor, dug through living rock");
    add_item("floor|ceiling|walls","Smooth, black stone");
    add_func_item("wall","#query_door_open",({
                  "There is a stone door in the wall",
                  "There is an opening in the wall" }));
    add_func_item("door|stone door","#query_door_open",({
                  "A stone door with no handle or lock",
                  "An open stone door" }));
    add_func_item("opening","#query_door_open",({
                  "",
                  "The door that used to cover it has swung open" }));

    add_exit(ROOM + "tunnel1","east");
}

string long_fun(void)
{
    if(!query_door_open())
    {
        return "You are at the beginning of a dark, narrow corridor with " +
               "a smooth stone floor and ceiling and smooth stone walls. " +
               "To the west is a wall with a closed stone door in it. To " +
               "the east, the corridor disappears into darkness.\n";
    }
    else
    {
        return "You are at the beginning of a dark, narrow corridor with a " +
               "smooth stone floor and ceiling and smooth stone walls. To " +
               "the west is an open stone door. A chamber lies beyond it. " +
               "To the east, the corridor disappears into darkness.\n";
    }
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
        if(!query_door_open())
        {
            W("You push the door open and manage to sneak through just " +
              "before it slams shut again.\n");
            tell_room(ROOM + "dgcave_shrine","The stone door opens briefly " +
                      "and " + TP->QN + " squeezes through the opening just " +
                      "before the door slams shut again.\n");
            TP->move_player("pushes the door, which opens briefly. " + TP->QN +
                            " sneaks through the opening just before the " +
                            "door slams shut again",
                            ROOM + "dgcave_shrine","",1);
            return 1;
        }
        else
        {
            W("The door is already open.\n");
            return 1;
        }
    }
    return notify_fail("Push what?\n");
}

int do_open(string str)
{
    if(str == "door")
    {
        if(!query_door_open())
        {
            W("You can't open it. It seems it would open if you would push " +
              "it, but you notice a mechanism that would cause it to swing " +
              "back again and close it. If you really want to leave, push " +
              "it, but you won't be able to come back without the key.\n");
            S(TP->QN + " tries to open the door.\n");
            return 1;
        }
        else
        {
            W("The door is already open.\n");
            S("Like the fool " + TP->QPR + " is, " + TP->QN + " tries to " +
              "open the door, even though it's already open.\n");
            return 1;
        }
    }
    return 0;
}

int query_door_open(void)
{
    return (ROOM + "dgcave_shrine")->query_door_open();
}
