#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_man";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a fool");
    set_long("A man who's been locked in because people thought he was a " +
             "fool. Well, even if he wasn't one when they locked him up, " +
             "the years spent in this dark room has turned him into one.\n");
    set_name("fool");
    add_id("man");

    make(ARMOUR + "straight_jacket");
    init_command("wear all");

    load_chat(15,({ "Fool says: Dream the same thing every night, see your " +
                    "freedom in my sight...\n",
                    "Fool says: No more can they keep us in, listen damn " +
                    "it, we will win...\n" }));
    load_a_chat(10,({ "Fool tries to break free of the straightjacket but " +
                      "fails.\n" }));
}
