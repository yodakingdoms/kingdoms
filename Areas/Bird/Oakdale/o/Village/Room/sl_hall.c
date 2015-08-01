#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_quit(string str);
int query_ok_to_login(object arg);

void create_object()
{
    set_short("Sleeping hall");
    set_long("This is the Oakdale sleeping hall. The walls are of stone " +
             "with two windows in them. The curtains are drawn and thus " +
             "this room is rather dark. The floor and ceiling is made of " +
             "wood and there are a few comfortable looking beds here. " +
             "This would be just the place to quit if you want to reenter " +
             "here.\n");
    add_property("no_special");
    add_property("indoors");
    set_new_light(10);

    add_item("hall|place","If you quit here you will also log in here");
    add_item("walls|wall","Made of stone");
    add_item("windows|window","The curtains are drawn so you can't look out");
    add_item("curtains|curtain","Dark blue curtains");
    add_item("floor|ceiling","Made of wood");
    add_item("beds|bed","They look VERY comfortable");

    add_exit(ROOM + "apothek","down");
}

void init(void)
{
    add_action("do_quit","quit");
}

int do_quit(string str)
{
    W("You jump into one of the beds and sigh contentedly as the sandman " +
      "carries you off to never-never land.\n");
    TP->set_optional_login_room(name_file(TO));
    return 0;
}

int query_ok_to_login(object arg)
{
    if(name_file(arg)[0..11] == "/sys/player/")
    {
        return 1;
    }
    return 0;
}
