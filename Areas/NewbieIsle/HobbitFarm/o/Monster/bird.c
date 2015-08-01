#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    int i = random(4);
    string *colours = ({ "black","red","green","blue" });

    set_name("bird");
    add_id(colours[i] + " bird");
    set_short("a " + colours[i] + " bird");
    set_long("A small " + colours[i] + " bird hopping around on the " +
             "ground looking for things to eat.\n");
    set_race("bird");
    set_level(1);
    set_unarmed(1);
    set_type("wing");
    set_hp(10);

    load_chat(10,({ "The bird pulls a worm out of the ground and " +
                    "eats it.\n",
                    "The bird is searching the ground for food.\n",
                    "The bird makes funny little chirping noises.\n",
                    "The bird struts around on the ground.\n"
                  }));

    load_a_chat(20,({ "The bird flaps its wings, desperately trying to " +
                      "fly away.\n",
                      "The bird makes desperate noises.\n",
                      "The bird tries to fly away but fails.\n"
                    }));
}
