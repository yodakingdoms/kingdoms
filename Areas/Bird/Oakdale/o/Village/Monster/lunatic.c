#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_man";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a lunatic");
    set_long("A man who's been locked in because people thought he was a " +
             "lunatic. Well, even if he wasn't one when they locked him " +
             "up, the years spent in this dark room has turned him into " +
             "one.\n");
    set_name("lunatic");

    make(ARMOUR + "straight_jacket");
    init_command("wear armour");

    load_chat(15,({ "Lunatic says: In my fear of what's out there, cannot " +
                    "breathe the open air...\n",
                    "Lunatic says: No locked doors no windows barred, no " +
                    "things to make my brain seem scarred...\n" }));
    load_a_chat(10,({ "Lunatic tries to break free of the straightjacket " +
                      "but fails.\n"}));
}
