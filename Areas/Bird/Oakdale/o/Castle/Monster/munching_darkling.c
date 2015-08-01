#pragma strict_types
#include "../def.h"
inherit MONSTER + "darkling_sentry";

void create_object(void);

void create_object(void)
{
    ::create_object();
    add_id("munching darkling");
    set_short("a munching darkling");
    set_long("A sentry who's hungry and who has come down here to the " +
             "food storage to grab a bite to eat before dinner.\n");
    make(WEAPON + "bone");
    init_command("wield bone");

    load_chat(4,({ "The darkling munches happily on a bone.\n" }));
}
