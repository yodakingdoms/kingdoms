#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_name("kitten");
    add_id("small kitten");
    set_short("a small kitten");
    set_long("A small kitten, no a VERY small kitten. It would seem like " +
             "a normal kitten to a hobbit but to you it's about as big " +
             "as a small rat.\n");
    set_race("cat");
    set_level(1);
    set_unarmed(1);
    set_type("small_claw");
    set_hp(10);

    load_chat(10,({ "The kitten purrs contentedly.\n",
                    "The kitten meows.\n",
                    "The kitten turns around and lies down in a more " +
                    "comfortable position.\n",
                    "The kitten yawns lazily.\n"
                  }));

    load_a_chat(20,({ "The kitten hisses.\n",
                      "The kitten tries to scratch you with its claws.\n",
                      "The kitten tries to run away but fails.\n"
                    }));
}
