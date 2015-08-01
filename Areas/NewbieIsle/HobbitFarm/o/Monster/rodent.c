#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_name("rodent");
    add_id("small rodent");
    set_short("a small rodent");
    set_long("A small rodent, scurrying about beneath the leaves of " +
             "the pumpkin plants.\n");
    set_race("rodent");
    set_level(1);
    set_unarmed(1);
    set_type("bite");
    set_hp(10);

    load_chat(10,({ "The rodent scurries about under the leaves.\n",
                    "The rodent twitches its nose.\n",
                    "The rodent makes funny little chirping noises.\n",
                    "The rodent peers quizzically at you.\n"
                  }));

    load_a_chat(20,({ "The rodent squeeks in terror.\n",
                      "The rodent makes desperate noises.\n",
                      "The rodent tries to run away but fails.\n"
                    }));
}
