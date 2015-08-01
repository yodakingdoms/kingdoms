#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    int i = random(7);
    string *colours = ({ "black","red","green","blue","yellow",
                         "purple","pink" });

    set_name("butterfly");
    add_id(colours[i] + " butterfly");
    set_short("a " + colours[i] + " butterfly");
    set_long("A small " + colours[i] + " butterfly flying around in the " +
             "bushes, fluttering from flower to flower.\n");
    set_race("butterfly");
    set_level(1);
    set_unarmed(1);
    set_type("wing");
    set_hp(10);

    load_chat(10,({ "A butterfly flutters to another flower.\n",
                    "A butterfly lands on a flower for a little while " +
                    "before flying away.\n",
                    "A butterfly flies close to your nose.\n",
                    "A butterfly lands on the ground for a short while.\n"
                  }));
}
