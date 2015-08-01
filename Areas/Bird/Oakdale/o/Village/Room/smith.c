#pragma strict_types
#include "../def.h"
inherit STD_SMITH;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("The Oakdale Smithworks");
    set_long("You stand in the Oakdale Smithworks, run by Arlon the " +
             "Smithy. An enormous, blazing forge, where Arlon does his " +
             "finest weapon mending, stands in the center of the room.\n");
    set_new_light(10);
    set_property("indoors");

    add_item("forge","It is a magnificient sight, in all its blazing glory");
    add_item("building","You stand within it");

    add_exit(ROOM + "road21","east");

    set_smithy("arlon");
    set_weapons(({ "greatchain", "greatblunt", "twohanded", "polearm",
                   "dagger", "shortblade", "longblade", "blunt",
                   "thrusting", "chain", "axe", "nukes" }));

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "smithy",1);
    ::reset(arg);
}
