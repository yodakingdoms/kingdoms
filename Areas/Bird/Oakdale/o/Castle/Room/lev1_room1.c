#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

int stuff_found;

void create_object(void);
void reset(int arg);
void init(void);
int do_bed(string str);
int do_sit(string str);
int do_search(string str);
int load_doors(void);

void create_object(void)
{
    set_short("A small living quarters");
    set_long("You are in a small, dark room. The black stone walls are cold " +
             "and bare and a wooden chandalier is hanging from the ceiling. " +
             "A wooden desk is standing by the east wall, and a wooden " +
             "chair is standing in front of it. A large bed is by the " +
             "south wall, and a wooden chest is by the foot of the bed.\n");
    set_new_light(0);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("room","A room that looks as if it serves as living quarters " +
             "for a person of some rank. That person is not here now, though");
    add_item("wall|walls","Smooth black stone");
    add_item("ring|chandalier","A wooden ring hanging from the ceiling. " +
             "There are some candles attached to the ring, but they are " +
             "not lit");
    add_item("candle|candles","Wax candles, unlit at the moment");
    add_item("desk","A nicely crafted wooden desk");
    add_item("chair","A wooden chair with a dark blue cushion");
    add_item("cushion","A soft, dark blue cushion");
    add_item("bed","A neatly made bed. A chest is standing by the foot of " +
             "the bed");
    add_item("chest","A clothes chest that is open. From what you can see, " +
             "it only contains clothes");
    add_item("clothes","That's all you see when you glance in the chest");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    stuff_found = 0;
    ::reset(arg);
}

void init(void)
{
    add_action("do_sit","sit");
    add_multi_action("do_bed","sleep|nap|lie");
    add_action("do_search","search");
    ::init();
}

int do_sit(string str)
{
    W("Aaah, yes. You could easily get used to sitting in chairs as " +
      "comfortable as this one.\n");
    S(TP->QN + " looks very pleased as " + TP->QPR + " sits down in the " +
      "chair for a little while.\n");
    return 1;
}

int do_bed(string str)
{
    W("Nah, the bed is so neatly made. You wouldn't want to mess it up.\n");
    S(TP->QN + " looks at the bed and admires how neatly made it is.\n");
    return 1;
}

int do_search(string str)
{
    if(str == "chest" || str == "clothes")
    {
        if(!stuff_found)
        {
            W("You start going through the things in the chest and you " +
              "feel something wrapped in a sheet. You pull the bundle out " +
              "and the contents fall out onto the floor. A sword and some " +
              "armour.\n");
            S(TP->QN + " pulls a bundle out of the chest. The contents " +
              "fall out onto the floor.\n");
            make(ARMOUR + "dark_plate");
            make(WEAPON + "dark_lsword");
            make(ARMOUR + "dark_shield");
            make(ARMOUR + "dark_helmet");
            make(ARMOUR + "dark_glove");
            make(ARMOUR + "dark_boot");
            make(OBJECT + "sheet");
            stuff_found = 1;
            return 1;
        }
        else
        {
            W("You look through the chest, but find nothing of interest. " +
              "You do notice, however, that it looks like someone else has " +
              "searched this chest not too long ago.\n");
            S(TP->QN + " searches the chest, but finds nothing of " +
              "interest.\n");
            return 1;
        }
    }
    return 0;
}

int load_doors(void)
{
    string dir1 = "north";
    string dir2 = "south";
    string next_room = ROOM + "lev1_corridor4";
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
