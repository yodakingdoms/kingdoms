#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

int entered;

void create_object(void);
void reset(int arg);
void init(void);
int do_up(string str);
int load_doors(void);

void create_object(void)
{
    set_short("At the bottom of some stairs");
    set_long("You have entered the eerie tower. This is a cramped, dark " +
             "room with an empty holder for a torch on the wall. Dust " +
             "covers everything in the room, but there are no spiderwebs " +
             "here. A spiralling staircase disappeas up into the darkness " +
             "above you. You feel a strange power in the air, like " +
             "something up there is pressing down upon you.\n");
    set_new_light(0);
    add_property("indoors");

    add_item("room","A dark, cramped stairroom");
    add_item("holder","The torch holder is empty");
    add_item("wall|walls","Smooth, black stone");
    add_item("dust|layer","A thick, unmoving layer of dust");
    add_item("staircase","Smooth, black steps disappearing up inot the " +
             "darkness above you");
    add_item("darkness","A thick, almost unnatural darkness. You feel " +
             "like someone is up there, waiting for you");

    add_exit(ROOM + "lev5_stairroom","up");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    entered = 0;
    ::reset(arg);
}

void init(void)
{
    add_multi_action("do_up","u|up");
    tell_room(ROOM + "lev4_roof","As " + TP->QN + " enters the tower, " +
              "the eyes of the dragon's head over the door glow faintly, " +
              "and you could have sworn you heard it snarl.\n");
    if(!entered)
    {
        tell_room(ROOM + "lev4_roof","At the same time you hear a " +
                  "flapping, as if from huge wings from above, but you " +
                  "can't see anything because of the clouds. Suddenly " +
                  "you see a brief burst of light up there, and the " +
                  "noise seizes.\n");
        entered = 1;
    }
    ::init();
}

int do_up(string str)
{
    W("You begin to climb the stairs. With every step you take, the feeling " +
      "of foreboding evil gets stronger, and every step gets harder to take " +
      "than the last one. You feel like you've been climbing the stairs " +
      "for an eternity when you finally reach the top.\n");
    return 0;
}

int load_doors(void)
{
    string dir1 = "south";
    string dir2 = "north";
    string next_room = ROOM + "lev4_roof";
    string desc = "oak door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A black oak door.\n";
    string entercmd1 = "south";
    string entercmd2 = "north";
    int solidity = 10;
    int complex = 0;
    int hidden1 = 0;
    int hidden2 = 0;

    add_door(dir1, dir2, next_room, desc,  closed, locked, key_id,
             long_desc, entercmd1, entercmd2, solidity, complex,
             hidden1, hidden2 );
    return 1;
}
