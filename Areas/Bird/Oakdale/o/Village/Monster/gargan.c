#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_man";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a man");
    set_long("Gargan Niriol is a man in his early thirties. He has brown " +
             "hair and brown eyes. He looks worried.\n");
    set_name("gargan");
    set_walking();

    make(ARMOUR + "hat");
    init_command("wear hat");

    load_chat(4,({ "The man says: Nirach can't be defeated.\n",
                   "The man looks at you with a mixture of hope " +
                   "and fear in his eyes.\n" }));
}
