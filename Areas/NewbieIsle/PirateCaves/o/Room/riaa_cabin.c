#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

int chest_found;

void create_object(void);
void my_reset(void);
void reset(int arg);
int load_doors(void);
void init(void);
int do_search(string str);

void create_object(void)
{
    set_short("The cabin of the Riaa");
    set_long("The cabin of the Riaa. The ceiling is low and the cabin " +
             "is quite small and filled with furniture so you feel rather " +
             "cramped. There's a big table with chairs around it in " +
             "the middle of the room and an a bed by the wall. Large " +
             "windows in one wall lets you look out at the sea behind " +
             "the ship. There's a cabinet and a bookshelf by the other " +
             "walls and a chandelier hangs from the ceiling above the " +
             "table.\n");
    set_new_light(10);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("cabin","You are in it, it is pretty cramped");
    add_item("ceiling","It is pretty low, watch out so you don't bump your " +
             "head");
    add_item("furniture","A table, some chairs, a bed, a cabinet and a " +
             "bookshelf");
    add_item("table|big table","A big table that takes up much of the space " +
             "in the room");
    add_item("chair|chairs","There are several of them placed around the " +
             "table");
    add_item("bed|spartan bed","A spartan looking bed, it doesn't look " +
             "very comfortable");
    add_item("wall|walls","They, like much of the ship, are made of wood");
    add_item("ship","You can't see much of the rest of the ship from in " +
             "here");
    add_item("window|windows","Big windows, offering a good view of " +
             "the sea behind the ship");
    add_item("view|sea","A gray, raging sea stretching as far as the eye " +
             "can see");
    add_item("cabinet|open cabinet|empty cabinet","The cabinet is open and " +
             "empty. Looks like someone has been taking out their " +
             "belongings in an attempt to escape from the attackers");
    add_item("bookshelf|empty bookshelf","The bookshelf is empty. There " +
             "is something strange about it. Maybe it would be worthwhile " +
             "to search it?");
    add_item("chandelier","It hangs from the ceiling above the table, " +
             "providing light to the cabin");

    load_doors();
    reset(0);
}

void my_reset(void)
{
    chest_found = 0;
}

void reset(int arg)
{
    ::reset(arg);
    chest_found = 0;
    add_monster(PCMONSTER + "captain_hilary",1);
    add_monster(PCMONSTER + "captain_jack_valenti",1);
}

int load_doors(void)
{
    string dir1 = "to the west";
    string dir2 = "to the east";
    string next_room = PCROOM + "riaa_deck";
    string desc = "wooden door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A sturdy wooden door.\n";
    string entercmd1 = "west";
    string entercmd2 = "east";
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
    add_action("do_search","search");
}

int do_search(string str)
{
    int bonus;

    if(str == "bookshelf" || str == "harder" || str == "bookshelf harder")
    {
        if(str == "harder" || str == "bookshelf harder")
        {
            bonus = 35;
        }
        if(!chest_found)
        {
            if(TP->query_skill("perception") + bonus > random(100))
            {
                W("You find a compartment behind the shelf. In the " +
                  "compartment is a chest!\nYou drag the chest out onto " +
                  "the floor.\n");
                S(TP->QN + " searches the bookshelf and seems to find " +
                  "something behind it.\n" + TP->QN + " drags a chest " +
                  "out from behind the bookshelf, out onto the floor.\n");
                make(PCOBJECT + "treasure_chest");
                chest_found = 1;
                return 1;
            }
            else
            {
                W("You can't seem to find anything... Maybe if you " +
                  "searched harder?\n");
                return 1;
            }
        }
        else
        {
            W("You don't find anything but it looks like someone has been " +
              "searching the bookshelf recently.\n");
            return 1;
        }
    }
}

