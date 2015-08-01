#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

int barrel_taken;

void create_object(void);
void reset(int arg);
string long_fun(void);
void init(void);
int do_get_barrel(string str);
int query_barrel_taken(void);

void create_object(void)
{
    ::create_object();
    set_short("An storage room (out)");
    set_long("#long_fun");
    // This room is supposed to be dark also (see lev1_gunpowder_room)
    set_new_light(-1);

    add_item("room|storage room|hidden room|hidden storage room","It " +
             "looks as if it's been hidden for quite a long time");
    add_item("shelf|shelves","There's nothing on the shelves now, except " +
             "for a thick layer of dust and plenty of spiderwebs");
    add_item("box|boxes","The boxes are empty and look as if they could " +
             "fall apart any second now");
    add_item("dust|layer|thick layer|layer of dust|thick layer of dust","It " +
             "covers everything in the room. It's obvious noone's been here " +
             "in a long time");
    add_item("spiderweb|spiderwebs","They're hanging from the ceiling and " +
             "the shelves");
    add_item("sack","It stands in one of the corners of the room. It is " +
             "but you can't tell what the decomposed contents of it once " +
             "was");
    add_item("content|contents|decomposed content|decomposed contents","It " +
             "is simply far too decomposed for you to be able to tell what " +
             "it once was");
    add_func_item("corner|corners","#query_barrel_taken",({
                 "In one of the corners stand a sack and a wooden barrel, " +
                 "the other three are occupied by piles of dirt",
                 "In one of the corners stands a sack, the other three " +
                 "are occupied by piles of dirt"}));
    add_item("dirt|pile|piles|pile of dirt|piles of dirt|remains|supplies",
             "Probably the remains of some sort of supplies that have " +
             "decomposed");
    add_item("skeleton|small skeleton","Looks like some sort of rodent " +
             "crawled under the shelf and died");
    add_item("rodent","The skeleton is all that remains of it");

    add_exit(PCROOM + "lev1_gunpowder_room","out");

    reset(0);
}

void reset(int arg)
{
    add_item("barrel|wooden barrel","A wooden barrel standing in a corner " +
             "next to a sack. For a second you thought you saw it move... " +
             "Perhaps you could pick it up?");
    barrel_taken = 0;
}

string long_fun(void)
{
    if(!barrel_taken)
    {
        return "A hidden storage room. There are shelves on the walls and " +
            "boxes on the floor. It looks as if noone has been here in a " +
            "long time. There's a thick layer of dust covering everything " +
            "in the room and plenty of spiderwebs hang from the shelves and " +
            "the ceiling. A sack and a barrel stands in one corner and " +
            "piles of dirt lie in the other three. You see a small skeleton " +
            "on the floor by one of the shelves.\n";
    }
    else
    {
        return "A hidden storage room. There are shelves on the walls and " +
            "boxes on the floor. It looks as if noone has been here in a " +
            "long time. There's a thick layer of dust covering everything " +
            "in the room and plenty of spiderwebs hang from the shelves and " +
            "the ceiling. A sack stands in one corner and piles of dirt " +
            "lie in the other three. You see a small skeleton on the floor " +
            "by one of the shelves.\n";
    }
}

void init(void)
{
    add_multi_action("do_get_barrel","take|get|pick");
    "/sys/admin/room/admin_room"->visit(1105);
}

int do_get_barrel(string str)
{
    object barrel;

    if(str == "barrel" || str == "up barrel" || str == "barrel up")
    {
        if(!barrel_taken)
        {
            barrel = make(PCOBJECT + "magic_powder_barrel");
            if(!transfer(barrel,TP))
            {
                W("You pick the barrel up.\n");
                S(TP->QN + " gets a barrel.\n");
            }
            else
            {
                W("You try to pick the barrel up but it is too heavy " +
                  "for you to carry so you drop it back on the floor.\n");
                S(TP->QN + " tries to take a barrel but fails and drops " +
                  "it back on the floor.\n");
            }
            barrel_taken = 1;
            remove_item("barrel");
            return 1;
        }
    }
}

int query_barrel_taken(void)
{
    return barrel_taken;
}