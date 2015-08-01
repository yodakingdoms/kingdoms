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
    set_long("A dimly lit room with cold, bare stone walls. There is a " +
             "large wooden desk by the west wall and a wooden stool in " +
             "front of it. On the east wall is a wooden shelf with a few " +
             "books on it. A large wooden bed with a dark blue sheet on " +
             "it stands by the south wall. The only light in the room " +
             "comes from a small lamp on the desk.\n");
    set_new_light(5);
    set_skip_obvious(1);
    add_property("indoors");
    
    add_item("room","A room that looks as if it serves as living quarters " +
             "for a person of some rank");
    add_item("wall|walls","Smooth, black stone");
    add_item("desk","A beautifully crafted oak desk. There is a small lamp " +
             "on it");
    add_item("stool","A wooden stool that does not look very comfortable");
    add_item("shelf","A nicely crafted oak shelf. There are a few " +
             "leatherbound books on it");
    add_item("book|books","There are a few leatherbound books on the " +
             "shelf. They all seem to be written in a strange language " +
             "you don't understand, so they are not of much use to you");
    add_item("language","A strange, ugly language you don't understand");
    add_item("bed","A large, neatly made bed. There is a dark blue velvet " +
             "sheet on it");
    add_item("sheet","A dark blue velvet sheet");
    add_item("lamp","A small oil lamp on the desk");
    
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
    string next_room = ROOM + "lev1_corridor5";
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
