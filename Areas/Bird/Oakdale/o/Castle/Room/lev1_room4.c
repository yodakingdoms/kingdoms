#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
int load_doors(void);

void create_object(void)
{    
    set_short("A dimly lit room");
    set_long("A dimly lit room. The black stone walls are cold and bare, " +
             "while the floor is covered by a black bearskin rug. A " +
             "wooden desk stands by the east wall, and in front of that is " +
             "a big wooden chair with a dark blue cushion on it. On the " +
             "desk is a small lamp that is lit and that's providing the " +
             "room with some light. By the south wall is a bed.\n");
    set_new_light(5);
    set_skip_obvious(1);
    add_property("indoors");
    
    add_item("room","A room that looks as if it serves as living quarters " +
             "for a person of some rank");
    add_item("wall|walls","Black, cold stone walls");
    add_item("floor","A cold stone floor with a black rug on it");
    add_item("rug|skin|bearskin","A rug made from the skin of a huge, " +
             "black bear");
    add_item("desk","A beautiful oak desk. There is a small lamp on it");
    add_item("lamp","A small oil lamp providing the room with light");
    add_item("chair","A beautifully crafted oak chair, almost like a " +
             "wooden throne. There is a dark blue cushion on it");
    add_item("throne","Well, it's just a chair, but it almost looks like " +
             "a throne");  
    add_item("cushion","A nice, soft, dark blue cushion");
    add_item("bed","A large oak bed with as black sheet covering it");
    add_item("sheet","A black velvet sheet");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_officer",1)->set_aggressive(1);
    ::reset(arg);
}

int load_doors(void)
{
    string dir1 = "north";
    string dir2 = "south";
    string next_room = ROOM + "lev1_corridor7";
    string desc = "oak door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A strong oak door.\n";
    string entercmd1 = "north";
    string entercmd2 = "south";
    int solidity = 10;
    int complex = 0;
    int hidden1 = 0;
    int hidden2 = 0;

    add_door(dir1, dir2, next_room, desc,  closed, locked, key_id,
             long_desc, entercmd1, entercmd2, solidity, complex,
             hidden1, hidden2 );
    return 1;
} 
