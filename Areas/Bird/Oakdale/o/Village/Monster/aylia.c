#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_woman";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a pregnant woman");
    set_long("Aylia Niriol is making dinner. She is pregnant with her and " +
             "her husband's second child.\n");
    set_name("aylia");

    make(OBJECT + "bowl");

    load_chat(4,({ "Aylia mumbles: What will happen when my child is " +
                   "born...\n",
                   "The woman rubs her tummy.\n" }));
    load_a_chat(25,({ "The woman screams: Hurting a pregnant woman?! " +
                      "Have you no decency?!\n"}));
}
