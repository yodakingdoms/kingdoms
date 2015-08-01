#pragma strict_types
#include "../def.h"
inherit SHIP_ROOM;
inherit MOD_DOOR;
inherit CHECK_FIRE_MODULE;

int cannon_loaded,cannon_fired;
string *torch_takers = ({});

void create_object(void);
void my_reset(void);
void reset(int arg);
int load_doors(void);
void init(void);
int do_move(string str);
int do_load(string str);
int do_fire(string str);
int do_take(string str);
int query_cannon_fired(void);

void create_object(void)
{
    ::create_object();
    set_short("Below deck of the Black Skull");
    set_cave_long("You are below deck on the Black Skull. The ceiling is " +
                  "low and you have to walk crouched to avoid bumping your " +
                  "head on the wooden beams above you. There are openings " +
                  "in the walls and by one of them is a strange contraption " +
                  "that looks like a small wagon with a big metal pipe on " +
                  "it. There's not a lot else down here, it seems the ship " +
                  "hasn't been out to sea for a long time. There's a basket " +
                  "next to the contraption.\n");
    set_sea_long("You are below deck on the Black Skull. The ceiling is " +
                 "low and you have to walk crouched to avoid bumping your " +
                 "head on the wooden beams above you. There are openings in " +
                 "the walls and by one of them is a strange contraption " +
                 "that looks like a small wagon with a big metal pipe on " +
                 "it. The floor rolls under your feet and you see the " +
                 "waves outside the openings in the walls. There's a basket " +
                 "next to the contraption.\n");
    set_attacking_long("You are below deck on the Black Skull. The ceiling " +
            "is low and you have to walk crouched to avoid bumping your " +
            "head on the wooden beams above you. There are openings in the " +
            "walls and by one of them is a strange contraption that " +
            "looks like a small wagon with a big metal pipe on it. " +
            "The floor rolls under your feet and you see the waves outside " +
            "the openings in the walls to one side and another ship on " +
            "the other side. There's a basket next to the contraption.\n");
    add_property("indoors");
    set_skip_obvious(1);

    add_item("deck","You are below it");
    add_item("ship","It is the Black Skull");
    add_item("black skull","You are below deck on the Black Skull");
    add_item("ceiling","It's pretty low, be careful not to bump your head");
    add_item("beam|beams|wooden beam|wooden beams","They are threatening " +
             "to bump your head. Be careful");
    add_item("wall|walls|side|sides","There are openings in the wall on " +
             "both sides of the ship");
    add_item("opening|openings","Looks like they're used to point the " +
             "metal pipes of the strange looking contraptions out of");
    add_item("contraptions","Well, there's only one left here now but it " +
             "looks as if there's been more of there here at one time or " +
             "another");
    add_func_item("contraption|strange contraption|cannon",
                 "#query_cannon_loaded",({
                 "A metal pipe on top of a wooden wagon, is what it looks " +
                 "like. The word 'Cannon' is scratched into the pipe",
                 "A metal pipe on top of a wooden wagon, is what it looks " +
                 "like. The word 'Cannon' is scratched into the pipe. " +
                 "There's a fuse sticking out of a small hole on top of " +
                 "the pipe"
                 }));
    add_func_item("fuse",
                 "#query_cannon_loaded",({
                 "",
                 "Maybe you could fire the cannon?"
                 }));
    add_func_item("hole",
                 "#query_cannon_loaded",({
                 "A small, empty hole",
                 "There's a fuse sticking out of the hole"
                 }));
    add_item("pipe|metal pipe|long metal pipe","A long metal pipe, " +
             "sticking out of an opening in the side of the ship. It looks " +
             "to be empty. You wonder if you could load the cannon " +
             "with something");
    add_item("wagon|wooden wagon|small wagon|small wooden wagon",
             "It looks like a small wooden wagon used to move the " +
             "contraption around");
    add_func_item("floor|wooden floor",
                 "#query_location",({
                 "A wooden floor",
                 "A wooden floor rolling beneath you. It's enough to make " +
                 "you seasick",
                 "A wooden floor rolling beneath you. It's enough to make " +
                 "you seasick",
                 }));
    add_func_item("wave|waves",
                 "#query_location",({
                 "",
                 "You can see them outside",
                 "You can see them outside"
                 }));
    add_func_item("another ship",
                 "#query_location",({
                 "",
                 "",
                 "It looks like it is under attack... From this ship"
                 }));
    add_item("basket","There are some torches in the basket, you can take " +
             "one from the basket if you need one");
    add_item("torches","You can take a torch from the basket if you need " +
             "one");

    load_doors();
    reset(0);
}

void my_reset(void)
{
    cannon_loaded = 0;
    cannon_fired = 0;
    torch_takers = ({});
}

void reset(int arg)
{
    ::reset(arg);
    my_reset();
}

int load_doors(void)
{
    string dir1 = "above you";
    string dir2 = "in the deck";
    string next_room = PCROOM + "black_skull_deck";
    string desc = "trapdoor";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A trapdoor.\n";
    string entercmd1 = "up";
    string entercmd2 = "down";
    int solidity = 30;
    int complex = 20;
    int hidden1 = 0;
    int hidden2 = 0;

    add_door(dir1, dir2, next_room, desc,  closed, locked, key_id,
             long_desc, entercmd1, entercmd2, solidity, complex,
             hidden1, hidden2 );
    return 1;
}

void init(void)
{
    ::init();
    add_action("do_move","move");
    add_action("do_load","load");
    add_action("do_fire","fire");
    add_multi_action("do_take","take|get");
}

int do_move(string str)
{
    if(str == "wagon" || str == "contraption")
    {
        W("The " + lower_case(str) + " is probably standing where it's " +
          "supposed to be. You get the feeling moving it might not be " +
          "safe.\n");
        S(TP->QN + " looks thoughtfully at the contraption.\n");
        return 1;
    }
}

int do_load(string str)
{
    object barrel,cannonball;

    if(str == "cannon")
    {
        if(cannon_loaded)
        {
            W("The cannon is already loaded.\n");
            return 1;
        }
        if(cannon_fired)
        {
            W("The cannon has already been fired.\n");
            return 1;
        }
        barrel = present("_pirate_quest_powder_barrel_",TP);
        cannonball = present("_pirate_quest_cannonball_",TP);
        if(barrel && cannonball)
        {
            if(SHIP_OBJ->query_is_at_sea())
            {
                if(SHIP_OBJ->query_flag_raised())
                {
                    W("You pour powder from the barrel into the cannon " +
                      "and load it with the round stone. You put a fuse " +
                      "in the cannon and throw the empty barrel out " +
                      "the hatch.\n");
                    S(TP->QN + " loads the cannon and throws the empty " +
                      "barrel out the hatch.\n");
                    barrel->destroy();
                    cannonball->destroy();
                    cannon_loaded = 1;
                    (PCROOM+"lev3_bowling_hall")->quest_reset();
                    return 1;
                }
                else
                {
                    W("There's no point in loading the cannon until you've " +
                      "raised a pirate flag.\n");
                    return 1;
                }
            }
            else
            {
                W("There's no point in loading the cannon before the ship " +
                  "is at sea.\n");
                return 1;
            }
        }
        W("You need to carry a barrel with black powder and a suitable " +
          "stone to load the cannon.\n");
        return 1;
    }
    notify_fail("Load what?\n");
}

int do_fire(string str)
{
    if(str == "cannon")
    {
        if(cannon_fired)
        {
            W("The cannon has already been fired.\n");
            return 1;
        }
        if(cannon_loaded)
        {
            if(query_can_light_powder(TP))
            {
                W("You light the fuse and take a step back.\n");
                S(TP->QN + " lights the fuse and takes a step back.\n");
                SHIP_OBJ->tell_black_skull_rooms("A loud *BOOM* is heard " +
                                "as the cannon is fired and an explosion " +
                                "is heard from the other ship!\nCaptain " +
                                "Jack shouts: Good shot, arr! She is " +
                                "crippled, mateys!\nThe Black Skull comes " +
                                "up alongside the other ship.\n");
                cannon_fired = 1;
                return 1;
            }
            else
            {
                W("You need some sort of fire to light the fuse and fire " +
                  "the cannon.\n");
                return 1;
            }
        }
        W("You can't fire the cannon if it is not loaded.\n");
        return 1;
    }
}

int do_take(string str)
{
    object torch;

    if(str == "torch from basket" || str == "torch from the basket" ||
       str == "a torch from basket" || str == "a torch from the basket")
    {
        if(member_array(TP->QRN,torch_takers) == -1)
        {
            W("You take a torch from the basket.\n");
            S(TP->QN + " takes a torch from the basket next to the " +
              "contraption.\n");
            torch = make("/std/clone/torch");
            if(transfer(torch,TP))
            {
                W("You can't carry it so you drop it on the floor.\n");
                S(TP->QN + " drops a torch.\n");
            }
            torch_takers += ({ TP->QRN });
        }
        else
        {
            W("You have already taken a torch. Leave some for someone " +
              "else.\n");
        }
        return 1;
    }
    return 0;
}

int query_cannon_fired(void)
{
    return cannon_fired;
}

int query_cannon_loaded(void)
{
    return cannon_loaded;
}
