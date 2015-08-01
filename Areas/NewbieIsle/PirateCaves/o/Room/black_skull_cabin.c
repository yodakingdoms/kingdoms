#pragma strict_types
#include "../def.h"
inherit SHIP_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
int load_doors(void);

void create_object(void)
{
    ::create_object();
    set_short("The cabin of the Black Skull");
    set_cave_long("The cabin of the Black Skull. The cabin is filled " +
                  "with furniture, carpets and tapestries that look like " +
                  "they were once magnificent and expensive but are now " +
                  "old and worn. Big windows in the back of the room lets " +
                  "you look out at the cave outside. The ceiling is low " +
                  "and the glass in the windows is red, making the cabin " +
                  "feel cramped and dark.\n");
    set_sea_long("The cabin of the Black Skull. The cabin is filled " +
                 "with furniture, carpets and tapestries that look like " +
                 "they were once magnificent and expensive but are now " +
                 "old and worn. Big windows in the back of the room lets " +
                 "you look out at the sea outside. The ceiling is low " +
                 "and the glass in the windows is red, making the cabin " +
                 "feel cramped and dark.\n");
    set_attacking_long("The cabin of the Black Skull. The cabin is filled " +
                     "with furniture, carpets and tapestries that look like " +
                     "they were once magnificent and expensive but are now " +
                     "old and worn. Big windows in the back of the room " +
                     "lets you look out at the sea outside. The ceiling is " +
                     "low and the glass in the windows is red, making the " +
                     "cabin feel cramped and dark.\n");
    add_property("indoors");
    set_skip_obvious(1);

    add_item("cabin","The cabin of the Black Skull");
    add_item("ship|black skull","The ship you are on");
    add_item("furniture","It looks as if it used to be nice, but now it " +
             "just looks old and worn");
    add_item("carpet|carpets","Carpets that look as if they where nice at " +
             "one time, but now they just look old and worn");
    add_item("tapestry|tapestries","Tapestries that look as if they where " +
             "nice at one time, but now they just look old and worn");
    add_item("window|windows|big window|big windows","Big windows with red " +
             "glass in them");
    add_func_item("cave","#query_location",({
                  "The cave outside the ship","",""
                 }));
    add_func_item("sea","#query_location",({
                  "","The sea you're sailing on","The sea you're sailing on"
                 }));
    add_item("ceiling","It's low and you have to be careful not to bump " +
             "your head");
    add_item("glass|red glass","The glass in the windows is red, giving " +
             "a red tint to everything in the cabin");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    ::reset(arg);
    add_monster(PCMONSTER + "captain_jack",1);
}

int load_doors(void)
{
    string dir1 = "to the west";
    string dir2 = "to the east";
    string next_room = PCROOM + "black_skull_deck";
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