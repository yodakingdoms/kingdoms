#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_man";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a grumpy old man");
    set_long("Arkam Farenhil is a grumpy old man. He has a pointy nose " +
             "and small, black eyes. He looks at you with disgust.\n");
    set_name("arkam");
    add_id("old man");

    make(WEAPON + "walking_stick");
    init_command("wield stick");

    load_chat(4,({ "The man says: You should leave while you still can. It " +
                   "is just a matter of time before Nirach takes us all " +
                   "away.\n",
                   "The man hits you in the ribs with his stick.\n",
                   "The man says: Go away. I don't want to talk to you. I " +
                   "know a troublemaker when I see one.\n" }));
}
