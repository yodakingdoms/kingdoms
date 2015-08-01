#pragma strict_types
#include "../def.h"
inherit SHIP_ROOM;

int flag_raised;

void create_object(void);
string long_fun(void);
void my_reset(void);
void init(void);
int do_raise(string str);
int query_flag_raised(void);

void create_object(void)
{
    ::create_object();
    set_short("Forecastle of the Black Skull (e)");
    set_long("#long_fun");

    add_item("forecastle|black skull","That's where you are right now");
    add_item("space","Most of it is taken up by rolls of ropes and piles" +
             "of folded sails");
    add_item("roll|rolls","Rolls of ropes");
    add_item("ropes","Rolls of them take up much of the space here");
    add_func_item("rope","#query_flag_raised",({
                  "It looks as if you could use it to raise a flag here",
                  "It's been used to raise a Jolly Roger flag" }));
    add_func_item("flag|jolly roger|jolly roger flag","#query_flag_raised",({
                  "",
                  "It looks terrifying" }));
    add_item("pile|piles","Piles of folded sails");
    add_item("sail|sails|folded sail|folded sails","Piles of them take up " +
             "much of the space here");
    add_item("line|lines","They hang down from the rigging");
    add_item("hook|hooks","Lines and ropes hanging down from the rigging " +
             "are tied to them");
    add_item("railing","It goes round the forecastle");
    add_item("deck","Much of the space on it is take up by rolls of rope " +
             "and piles of folded sails");
    add_item("rigging","It's high above you in the mast behind you");
    add_item("mast","It is one of the two masts of the Black Skull");
    add_item("masts","The Black Skull has two of them");
    add_func_item("cave|huge cave","#query_location",({
                  "It is huge, and there's a huge crack to the west that " +
                  "you can sail out through" }));
    add_func_item("cave|huge cave","#query_location",({
                  "It is huge, and there's a huge crack to the west that " +
                  "you can sail out through" }));
    add_func_item("crack|huge crack","#query_location",({
                  "It's big enough to sail a ship through" }));
    add_func_item("sea|gray sea","#query_location",({
                  "You can see the gray sea outside the crack",
                  "It rages around the ship",
                  "It rages around the ship"
                 }));
    add_func_item("side|starboard side","#query_location",({
                  "",
                  "",
                  "There's another ship on that side, currently under " +
                  "attack from the Black Skull"
                 }));
    add_func_item("another ship","#query_location",({
                  "",
                  "",
                  "You are currently attacking it"
                 }));

    add_exit(PCROOM + "black_skull_deck","east");
}

string long_fun(void)
{
    string desc = "The forecastle of the Black Skull. Most of the space " +
                  "here is taken up by rolls of ropes and piles of folded " +
                  "sails. Lines and ropes tied to hooks in the railing and " +
                  "the deck go up into the rigging in the mast behind " +
                  "you. ";
    if(!flag_raised)
    {
        desc += "One rope looks like it's supposed to be used to " +
                "raise a flag. ";
    }
    else
    {
        desc += "A Jolly Roger flag has been raised with one of " +
                "the ropes. It flutters in the wind and looks " +
                "terrifying. ";
    }

    if(query_location() == 0)
    {
        desc += "The cave arcs high above you and you see the sea outside " +
                "the huge crack to the west.\n";
    }
    else if(query_location() == 1)
    {
        desc += "The gray sea rages around the ship.\n";
    }
    else
    {
        desc += "On the starboard side is the ship you are attacking.\n";
    }
    return desc;
}

void my_reset(void)
{
    flag_raised = 0;
}

void init(void)
{
    add_action("do_raise","raise");
}

int do_raise(string str)
{
    object flag;
    if(str == "flag")
    {
        if(flag_raised)
        {
            W("The flag has already been raised.\n");
            return 1;
        }
        flag = present("_pirate_quest_jolly_roger_",TP);
        if(flag)
        {
            if(SHIP_OBJ->query_is_at_sea())
            {
                if(SHIP_OBJ->query_ship_spotted())
                {
                    W("You raise the flag and the wind takes it, showing " +
                      "the grinning skull and crossed bones to the crew " +
                      "of the ship you are pursuing.\n");
                    S(TP->QN + " raises the flag and the wind takes it, " +
                      "showing the grinning skull and crossed bones to " +
                      "the crew of the ship you are pursuing.\n");
                    flag->destroy();
                    flag_raised = 1;
                    SHIP_OBJ->tell_black_skull_rooms("The Black Skull " +
                                      "catches up to the other ship and " +
                                      "sails into a good position for " +
                                      "firing long distance weapons at it.\n");
                    return 1;
                }
                else
                {
                    W("There's no point in raising the flag until you've " +
                      "spotted a ship to plunder.\n");
                    return 1;
                }
            }
            else
            {
                W("There's no point in raising the flag before the ship is " +
                  "at sea.\n");
                return 1;
            }
        }
        W("You need to be holding a flag to do that.\n");
        return 1;
    }
    return notify_fail("Raise what?\n");
}

int query_flag_raised(void)
{
    return flag_raised;
}