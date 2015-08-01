#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_name("horse");
    add_id("small horse");
    set_short("a small horse");
    set_long("A small horse that's just that and not a pony. It's small " +
             "in your eyes but from the perspective of a hobbit, it would " +
             "be rather impressive.\n");
    set_race("horse");
    set_level(2);
    set_unarmed(1);
    set_type("hoof");
    set_wc(15);
    set_hp(20);
    set_gender(1 + random(1));

    load_chat(5,({ "The horse chews on something.\n",
                    "The horse swats some flies away with its tail.\n",
                    "The horse makes funny noises.\n",
                    "The horse shakes its head.\n"
                  }));

    load_a_chat(20,({ "The horse tries to kick you.\n",
                      "The horse tries to run away but fails.\n"
                    }));
}
