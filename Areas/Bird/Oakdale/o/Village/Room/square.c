#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("The village square");
    set_long("This is the main square of the village. There are some " +
             "people here, talking, haggling and shouting, but not as many " +
             "as you'd expect to find at the square. A few merchants are " +
             "here. But they do not seem to be doing much business. There " +
             "are roads going north,east,south and west from here, and " +
             "houses to the northeast,northwest and southwest. None of them " +
             "can be entered from here, though. To the southeast is a " +
             "grove. You are close to the castle now, the cliff towering " +
             "above you. You feel very small standing in it's shadow.\n");
    set_new_light(5);

    add_item("people","They all seem distressed as they look at you. They " +
             "mumble and whisper to each other");
    add_item("merchants","There are people selling fish, furs and things " +
             "like that. None of them seem to be doing very well");
    add_item("grove","A grove of oak trees. Maybe it would be fun to " +
             "investigate it, but you can't enter it from the square. You " +
             "could try from a spot further down the east or south road");
    add_item("castle","A strong keep indeed. It would be virtually " +
             "impossible to take by force. You still can't bear to look at " +
             "it for very long");
    add_item("cliff","It rises several hundred feet straight up into the " +
             "air. You see nothing growing on the smooth, almost vertical " +
             "cliff wall. It would probably be impossible to climb it");
    add_item("$|$talking|$people","You hear people whisper things like 'A " +
             "stranger... This will surely mean trouble...'");

    add_exit(ROOM + "road7","west");
    add_exit(ROOM + "road8","east");
    add_exit(ROOM + "road20","north");
    add_exit(ROOM + "road22","south");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "milak",1);
    add_monster(MONSTER + "liria",1);
}
