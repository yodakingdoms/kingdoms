#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_child";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a young child");
    set_long("A small child in the care of Lynia the babysitter.\n");
    set_name("young child");
    add_id("small child");
    set_gender(1 + random(2));

    make(OBJECT + "doll");

    load_chat(10,({ "The child sobs quietly.\n",
                    "The child plays with it's doll.\n" }));
}
