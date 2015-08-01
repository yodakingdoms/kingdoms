// This room is inherited by tunnel1 - tunnel8
#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void set_long(string str);

void create_object(void)
{
    set_short("A dark, narrow corridor");
    set_new_light(0);
    add_property("indoors");
        
    add_item("corridor","A dark corridor, dug through the living rock");
    add_item("floor|ceiling|wall|walls","Smooth, black stone");
    add_item("£","You can hear absolutely nothing");
}

void set_long(string str)
{
    ::set_long("A dark, narrow corridor with a smooth stone floor and " +
               "ceiling and smooth stone walls. You can't see much further " +
               "than a few feet in front of you and behind you. Nothing can " +
               "be heard. " + str);
}
