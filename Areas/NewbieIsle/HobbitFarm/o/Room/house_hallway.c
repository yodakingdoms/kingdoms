#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;
inherit MOD_DOOR;

void create_object(void);
int load_doors(void);

void create_object(void)
{
    ::create_object();
    set_short("A hallway (e/w/s)");
    set_long("A long hallway that looks more like a tunnel than a room " +
             "due to the way the walls and ceiling curve above your head. " +
             "The ceiling is pretty low and there's a small chandelier " +
             "hanging down from it. A nice green carpet covers most of the " +
             "wooden floor. Next to the door is an open chest filled with " +
             "clothes and next to that stands a coat stand. There is a " +
             "small round window with some small green curtains next to " +
             "the door and doorways leading into other rooms in the other " +
             "walls.\n");

    add_item("hallway|tunnel","The hallway looks like an almost circular " +
             "tunnel rather than a normal hallway");
    add_item("room|corridor|round corridor","It's more like a round " +
             "corridor than a room");
    add_item("wall|walls|ceiling","It's hard to tell where the wall ends " +
             "and the ceiling begins because they curve and give the " +
             "hallway the look of a tunnel");
    add_item("chandelier|small chandelier","A small chandelier hanging at " +
             "the same height as your head, better watch out or you might " +
             "bump your head");
    add_item("carpet|green carpet|nice green carpet","A green carpet that " +
             "feels nice to walk upon");
    add_item("floor|wooden floor|smooth floor","The floor is very smooth " +
             "but most of it is covered by the carpet");
    add_item("chest|open chest|clothes chest","It's an open clothes chest " +
             "filled with clothes");
    add_item("clothes","All kind of clothes have been stuffed into the " +
             "chest");
    add_item("stand|coat stand","A beautifully carved coat stand with a " +
             "few pegs for hanging clothes on");
    add_item("peg|pegs","The pegs are empty right now");
    add_item("window|small window|round window|small round window","The " +
             "curtains next to the window are the same colour as the " +
             "carpet");
    add_item("curtain|curtains","The curtains are open and are the same " +
             "colour as the carpet");
    add_item("doorway|doorways","The doorways to the west and east are " +
             "blocked off at the moment, you assume some sort of " +
             "construction work is being done there at the moment");
    add_item("$|$sounds|$sound","It sounds like someone is working hard " +
             "in the rooms behind the closed doorways");

    add_exit(ROOM + "house_living_room","south");

    add_sounds(30,20,({ "You hear the sound of someone hammering from " +
                        "behind the closed doorways.\n",
                        "You hear the sound of construction work going " +
                        "on from behind the closed doorways.\n"
                     }));
    load_doors();
    reset(0);
}

int load_doors(void)
{
    string dir1 = "to the north";
    string dir2 = "in the side of the hill";
    string next_room = ROOM + "farm_center";
    string desc = "green round door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A round wooden door painted green.\n";
    string entercmd1 = "north";
    string entercmd2 = "south";
    int solidity = 30;
    int complex = 20;
    int hidden1 = 0;
    int hidden2 = 0;

    add_door(dir1, dir2, next_room, desc,  closed, locked, key_id,
             long_desc, entercmd1, entercmd2, solidity, complex,
             hidden1, hidden2 );
    return 1;
}
