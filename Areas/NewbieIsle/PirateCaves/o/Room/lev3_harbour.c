#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

void create_object(void);
string long_fun(void);
void init(void);
int do_swim(string str);
int do_board(string str);
int query_ship_at_sea(void);

void create_object(void)
{
    ::create_object();
    set_short("A balcony (e)");
    set_long("#long_fun");

    add_item("sight|magnificent sight","It is magnificent");
    add_item("cave|underground cave|huge cave|huge underground cave",
             "The lagoon in the cave forms a natural hidden harbour");
    add_item("ceiling|domed ceiling","It curves up above you. The shining " +
             "stones in it make it look like a starlit night sky");
    add_item("lagoon|underground lagoon","It forms a natural harbour " +
             "hidden from the outside");
    add_item("sea","You can see it as you look out the crack. The sea is " +
             "raging but the water below you in the cave is calm");
    add_item("water","The water in the lagoon is calm, there must be a " +
             "breakwater somewhere near. It sparkles in the light from " +
             "stones in the ceiling above. The water doesn't seem cold, " +
             "maybe you could jump in and take a swim? It might be a good " +
             "idea to remove your armour and weapons and drop all heavy " +
             "things here first so you don't accidentally drown");
    add_item("breakwater","You can't see one, but there probably is one " +
             "somewhere near");
    add_item("west wall","There's a huge crack in it");
    add_item("crack","It's high and wide enough to sail a ship through " +
             "but narrow enough to be difficult to see from the outside");
    add_item("ledge|wide ledge","It goes around the lagoon, forming a " +
             "natural dock. There's a ladder going down into the water " +
             "on one side of the ledge");
    add_item("ladder","You could use it to climb out of the water if you " +
             "would fall in");
    add_item("dock|natural dock","That's where you are standing");
    add_item("box|boxes|sack|sacks|supplies","They're stacked against the " +
             "walls. They seem to be empty");
    add_func_item("ship|big ship","#query_ship_at_sea", ({
                 "A ship with two masts. The sails are furled and there is " +
                 "nobody on deck. It looks as if it was quite a while " +
                 "the ship was last out at sea. You could board the ship " +
                 "if you wanted to. The name of the ship is written on " +
                 "the side of the hull" }));
    add_func_item("side|hull|side of the hull","#query_ship_at_sea", ({
                 "The name of the ship is written there" }));
    add_func_item("name|name of the ship|@name|@name of the ship",
                  "#query_ship_at_sea", ({
                  "The name of the ship is 'The Black Skull'" }));
    add_func_item("mast|masts","#query_ship_at_sea", ({
                  "The ship has two masts. There's a crows nest in one of " +
                  "them" }));
    add_func_item("nest|crows nest","#query_ship_at_sea", ({
                  "The place where the lookout sits when the ship is at " +
                  "sea. It is empty now" }));
    add_func_item("sail|sails","#query_ship_at_sea", ({
                  "The sails are furled now and don't look as if they've " +
                  "been used in quite a long time" }));
    add_func_item("deck","#query_ship_at_sea", ({
                  "That's where you'd probably be if you were on the ship " +
                  "and the ship was at sea" }));
    add_func_item("ring|rings|iron ring|iron rings","#query_ship_at_sea", ({
                  "Iron rings. The ship is moored to the with thick lines",
                  "Iron rings that you can probably use when mooring a " +
                  "ship here"
                  }));
    add_func_item("line|lines|thick line|thick lines","#query_ship_at_sea",({
                  "Thick lines used to moor the ship in the harbour" }));
    add_item("stone|stones|small stone|small stones|shining stone|" +
             "shining stones|small shining stone|small shining stones",
             "There are hundreds of them in the ceiling of the cave");
    add_item("light","Light from the stones");
    add_item("harbour|natural harbour|proper harbour|hidden harbour",
             "A hidden harbour formed by mother nature");

    add_exit(PCROOM + "lev3_stairs","east");
    add_exit(PCROOM + "lev3_storage_room","north");
}

string long_fun(void)
{
    string desc = "A magnificent sight meets you. A domed ceiling curves " +
        "above you and in front of you is an underground lagoon, opening " +
        "up into the sea through a huge crack in the west wall. A wide " +
        "ledge goes around the cave and boxes, sacks and other supplies " +
        "are stacked against the walls. ";
    if(!query_ship_at_sea())
    {
        desc += "Moored in the hidden harbour lies a big ship! It is tied " +
                "to rings in the wall by thick lines and the sails are " +
                "furled. The two masts rise high above you but the cave " +
                "is so high and crack to the west is so big it easily " +
                "fits in here. ";
    }
    desc += "The cave is lit by many small shining stones in the walls and " +
            "ceiling, and the water below sparkles magically in the light.\n";
    return desc;
}

void init(void)
{
    add_multi_action("do_swim","swim|jump|dive");
    add_action("do_board","board");
    "/sys/admin/room/admin_room"->visit(1098);
}

int do_swim(string str)
{
    if(str == "water" || str == "in water" || str == "into water")
    {
        W("You jump into the water.\nYou land with a *SPLASH*!\n");
        TP->move_player("jumps into the water and lands with a *SPLASH*!",
                        PCROOM + "lev3_harbour_water",
                        "jumps into the water from the dock above and " +
                        "lands with a *SPLASH*!",1);
        return 1;
    }
    return notify_fail(C(query_verb()) + " where?\n");
}

int do_board(string str)
{
    if(!query_ship_at_sea())
    {
        if(str == "ship")
        {
            W("You walk up the gangway and board the ship.\n");
            TP->move_player("walks up the gangway and boards the ship",
                            PCROOM + "black_skull_deck",
                            "walks up the gangway up onto the deck",1);
            return 1;
        }
        return notify_fail("Board what?\n");
    }
}

int query_ship_at_sea(void)
{
    return SHIP_OBJ->query_is_at_sea();
}
