#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_child";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a playing child");
    set_long("Tyron Tiralam is eight years old. He has red hair and brown " +
             "eyes. He is playing with his friends.\n");
    set_name("tyron");
    add_id("boy");
    set_gender(1);

    make(OBJECT + "ball");

    load_chat(10,({ "The child asks: You are not going to take me to " +
                    "Nirach, are you?\n",
                    "Tyron looks at you with a mixture of hope and " +
                    "fear in his eyes.\n" }));
}
