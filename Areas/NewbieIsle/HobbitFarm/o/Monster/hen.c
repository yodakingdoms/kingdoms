#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_name("hen");
    add_id("small hen");
    add_id("bird");
    set_short("a small hen");
    set_long("A small hen, about the size of a chicken even though it " +
             "looks as if it's fully grown. If you were a hobbit, it would " +
             "probably seem like a normal hen.\n");
    set_race("hen");
    set_level(1);
    set_unarmed(1);
    set_type("wing");
    set_hp(15);
    set_gender(2);

    load_chat(5,({ "The hen struts around on the ground.\n",
                    "The hen makes a clucking noise.\n",
                    "The hen picks some seeds from the ground with its " +
                    "beak.\n",
                    "The hen peers quizzically at you.\n"
                  }));

    load_a_chat(20,({ "The hen cackles in terror.\n",
                      "The hen lays an egg which cracks as it falls on " +
                      "the ground!\n",
                      "The hen tries to fly away but fails.\n"
                    }));
}
