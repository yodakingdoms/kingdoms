#pragma strict_types
#include "../def.h"
inherit STD_INN;

void create_object(void);

void create_object(void)
{
    set_short("Oakdale inn");
    set_long("This is the Oakdale inn. This is the main room of the inn. " +
             "There is a counter here, on which you see a sign. In this " +
             "room you also see a table and two benches where people can " +
             "sit and talk in the evenings before they retire to their " +
             "rooms. A small lamp is hanging from the rafters and the " +
             "stone walls will keep the storm out tonight, should you " +
             "choose to stay here. Some stairs in the back of the room go " +
             "up to the rooms on the second floor.\n");
    set_new_light(10);
    add_property("indoors");

    add_item("sign","#read_sign");
    add_item("fine print","Perhaps you should try reading it");
    add_item("print","Perhaps you should try reading it");
    add_item("counter","A wooden counter with a sign on it");
    add_item("table","A heavy wooden table");
    add_item("bench|benches","Two sturdy wooden benches");
    add_item("lamp","A small oil lamp");
    add_item("rafter|rafters","They support the ceiling");
    add_item("ceiling","The owners of the inn guarantee that it won't " +
             "fall down tonight");
    add_item("owner|owners","Well, they're not around right now");
    add_item("wall|walls","Thick stone walls");
    add_item("stair|stairs","Some stairs go up to the rooms on the second " +
             "floor. You have to pay for your room and quit to go up there");
    add_item("rooms","They are on the second floor");

    add_exit(ROOM + "road13","west");
}
