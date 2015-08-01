#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A guardroom on the second floor");
    set_long("A large room with many uncomfortable looking beds in it. In " +
             "the centre of the room is a wooden table with some wooden " +
             "stools placed around it. There are stairs in this room going " +
             "both up and down, and an archway leads to the southeast.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("room","A room that looks as if it serves as living quarters " +
             "for the common solidery");
    add_item("bed|beds|bunk|bunks","Uncomfortable looking wooden bunks");
    add_item("table","A small wooden table with stools placed around it");
    add_item("stool|stools","Several small wooden stools are placed around " +
             "the table");
    add_item("stair|stairs","Stairs go both up and down from this room");
    add_item("archway","An archway leading to a room to the southeast");

    add_exit(ROOM + "stable","down");
    add_exit(ROOM + "lev2_tower2","southeast");
    add_exit(ROOM + "lev3_tower","up");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_trooper",3);
    foreach(object ob: all_inventory())
    {
        if(ob->id("darkling")) ob->set_aggressive(1);
    }
}
