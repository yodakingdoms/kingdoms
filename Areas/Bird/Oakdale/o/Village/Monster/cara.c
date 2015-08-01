#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_woman";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a woman");
    set_long("Cara Carelyn is waiting for her son to come home. He is " +
             "running an errand for her.\n");
    set_name("cara");

    load_chat(4,({ "The woman mumbles: Where is Lidyr? I sent him on that " +
                   "errand over an hour ago...\n",
                   "The woman looks out the window.\n" }));
}
