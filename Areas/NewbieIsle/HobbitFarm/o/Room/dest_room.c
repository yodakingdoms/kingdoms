// Room to dest things in. Used for the scarecrow parts when they're made
// into a scarecrow. As the building code is in the parts, desting them
// from within doesn't always work. It does sometimes but sometimes one
// part is left there so we send them to be dested here instead
#pragma strict_types
#include "../def.h"
inherit STD_ROOM;

void create_object(void);
int deny_object(object arg);
void dest_object(object arg);

void create_object(void)
{
    set_short("Dest room");
    set_long("A room where things are destroyed. If you're a mortal, you " +
             "sure are in a place you shouldn't be.\n");

    set_new_light(5);
    set_skip_obvious(1);
}

int deny_object(object arg)
{
    if(!living(arg))
    {
        set_alarm(1.0,0.0,"dest_object",arg);
    }
    return 0;
}

void dest_object(object arg)
{
    tell_room(TO,arg->short() + " disappears in a puff of smoke.\n");
    arg->destroy();
}
