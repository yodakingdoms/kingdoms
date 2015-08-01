#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_child";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a playing child");
    set_long("Nirin Niriol is nine years old. He has brown hair and brown " +
             "eyes and he's playing with his friends.\n");
    set_name("nirin");
    add_id("boy");
    set_gender(1);

    make(OBJECT + "ball");

    load_chat(10,({ "The child asks: You are not going to take me to " +
                    "Nirach, are you?\n",
                    "Nirin says: Let's go play in the caves by the " +
                    "waterfall!!\n" }));
}
