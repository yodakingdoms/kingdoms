#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_push(string str);

void create_object(void)
{
    set_short("A cold dungeon room");
    set_long("A dark, cold dungeon room. Water is seeping through the " +
             "rough stone walls, gathering in small puddles as it trickles " +
             "to the floor. The air is absolutely still, and it's almost " +
             "as if you can see the waves you make in the air as you move " +
             "through the room. There is a doorway in the north wall, and " +
             "a dark opening in the east wall.\n");
    set_new_light(0);
    add_property("indoors");

    add_item("room","The air in this room is unnaturally still. It's like " +
             "noone's been here in a long time");
    add_item("air","It is very still and cold. Unnaturally still..");
    add_item("water","Water is seeping through the walls");
    add_item("wall|walls","Rough, black stone");
    add_item("puddle|puddles","Small puddles of dirty water");
    add_item("floor","A rough stone floor. There are small puddles of " +
             "dirty water on it");
    add_item("wave|waves","You can almost see them");
    add_item("doorway","A doorway in the north wall");
    add_item("opening","A very dark opening. You don't really like the " +
             "look of it. Maybe you should stay away from it?");

    add_exit(ROOM + "dung_bottom1","north");
    add_exit(ROOM + "dung_antechamber","east");
}

void init(void)
{
    add_action("do_push","push");
}

int do_push(string str)
{
    if(str == "wall" || str == "door")
    {
        W("You push the wall and it opens for a second. You manage to " +
        "squeeze through just before it closes.\n");
        TP->move_player("pushes the west wall. It opens, and " + TP->QPR +
                        " squeezes through just before it shuts again",
                        FOREST + "Room/tunnel_castle_end",
                        "The door opens, and " + TP->QN + " squeezes " +
                        "through just before it shuts again",1);
        return 1;
    }
}
