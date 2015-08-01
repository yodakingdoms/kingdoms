#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_name("rat");
    add_id("small rat");
    set_short("a small rat");
    set_long("A small thing that looks like a rat but is the size of " +
             "a mouse. If you were the size of a hobbit, it would probably " +
             "seem like a normal rat.\n");
    set_race("rat");
    set_level(1);
    set_unarmed(1);
    set_type("bite");
    set_hp(10);

    load_chat(10,({ "The rat scurries about in the shed.\n",
                    "The rat twitches its nose.\n",
                    "The rat squeeks merrily.\n",
                    "The rat peers quizzically at you.\n"
                  }));

    load_a_chat(20,({ "The rat squeeks in terror.\n",
                      "The rat makes desperate noises.\n",
                      "The rat tries to run away but fails.\n"
                    }));
}
