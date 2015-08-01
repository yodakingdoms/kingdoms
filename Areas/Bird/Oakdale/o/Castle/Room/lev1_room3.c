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
    set_long("A small, dimly lit room. A large mural adorns the west wall, " +
             "and a large wooden desk stands by the east wall. A big wooden " +
             "chair with a dark blue cushion stands in front of the desk. " +
             "By the south wall stands a large bed covered with a black " +
             "sheet. The only light in the room comes from a flickering " +
             "candle on the desk.\n");
    set_new_light(5);
    set_skip_obvious(1);
    add_property("indoors");
    
    add_item("room","A room that looks as if it serves as living quarters " +
             "for a person of some rank");
    add_item("mural","A large mural depicting a huge black dragon in flight");
    add_item("dragon","A huge, black dragon flying over a forested valley " +
             "under a starlit sky. For a moment you thought you saw it's " +
             "eyes glow faintly");
    add_item("eyes|eye|glow","Nah, it couldn't have been..");
    add_item("valley","A beautiful valley. A river flows through it, and " +
             "there is a village and a castle there. It looks familiar " +
             "somehow..");
    add_item("river","It flows from the north to the south");
    add_item("village","A small, peaceful village");
    add_item("castle","A dark, eerie castle");
    add_item("sky","It is filled with stars");
    add_item("star|stars|dot|dots","Small, white dots on the mural");
    add_item("wall|walls","Smooth, black stone");
    add_item("desk","A heavy oak desk");
    add_item("chair","An oak chair with a dark blue cushion in it");
    add_item("cushion","A soft, dark blue cushion");
    add_item("bed","A heavy oak bed, neatly made");
    add_item("sheet","A black velvet sheet");
    add_item("candle","A flickering wax candle");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_officer",1)->set_aggressive(1);
}

int load_doors(void)
{
    string dir1 = "north";
    string dir2 = "south";
    string next_room = ROOM + "lev1_corridor6";
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
