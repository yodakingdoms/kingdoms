#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_man";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a wierdo");
    set_long("A man who's been locked in because people thought he was a " +
             "wierdo. Well, even if he wasn't one when they locked him " +
             "up, the years spent in this dark room has turned him into " +
             "one.\n");
    set_name("wierdo");

    make(ARMOUR + "straight_jacket");
    init_command("wear armour");

    load_chat(15,({ "Wierdo says: Whisper words into my brain, assuring " +
                    "me that I'm insane...\n",
                    "Wierdo says: Sleep my friend and you will see, the " +
                    "dream is my reality...\n"}));
    load_a_chat(10,({ "Wierdo tries to break free of the straightjacket " +
                      "but fails.\n"}));
}
