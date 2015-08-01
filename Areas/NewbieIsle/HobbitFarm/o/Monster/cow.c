#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_name("cow");
    add_id("small cow");
    set_short("a small cow");
    set_long("A small cow that looks like it's fully grown even though " +
             "it's only the size of a calf. It would seem be of normal " +
             "for someone the size of a hobbit.\n");
    set_race("cow");
    set_level(2);
    set_unarmed(1);
    set_type("horn");
    set_wc(15);
    set_hp(20);
    set_gender(2);

    load_chat(5,({ "The cow chews on something.\n",
                   "The cow swats some flies away with its tail.\n",
                   "The cow moos contentedly.\n",
                   "The cow shakes its head.\n"
                  }));

    load_a_chat(20,({ "The cow tries to kick you.\n",
                      "The cow moos in horror.\n",
                      "The cow tries to run away but fails.\n"
                    }));
}
