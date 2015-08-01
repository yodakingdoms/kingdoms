#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
int load_doors(void);

void create_object(void)
{
    set_short("A dining hall for the troops");
    set_long("A large room that apparently serves as a dining hall for the " +
             "troops. A few flickering torches hang on the black stone " +
             "walls, providing some sparse light. The only furniture in the " +
             "room are the wooden tables and benches.\n");
    set_new_light(10);
    set_skip_obvious(1);
    add_property("indoors");
    
    add_item("room|hall","This must be where the ordinary soldiers of the " +
             "castle eat");
    add_item("torch|torches","There are a few of them here. They all " +
             "flicker as if they're not getting enough air somehow");
    add_item("furniture","Wooden tables and benches");
    add_item("table|tables","Heavy oak tables. There are plates on a few " +
             "of them");
    add_item("plate|plates","The plates are very empty. It seems like the " +
             "inhabitants of the castle have very good apetites");
    add_item("bench|benches","Wooden benches. It seems like not too much " +
             "attention has been given to comfort when these benches were " +
             "constructed");
           
    (ROOM + "lev1_latrine")->load_doors();           
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_guard",2);
    add_monster(MONSTER + "darkling_soldier",2);
    ::reset(arg);
}

int load_doors(void)
{
    string dir1 = "north";
    string dir2 = "south";
    string next_room = ROOM + "lev1_corridor1";
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
