#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    string colour = "white";
    if(!random(6)) colour = "black";

    set_name("sheep");
    add_id(colour + " sheep");
    set_short("a " + colour + " sheep");
    set_long("A " + colour + " sheep that strangely enough is of normal " +
             "size and not a small version of the animal, like most other " +
             "animals here. You can only conclude that sheep don't come in " +
             "hobbit sizes.\n");
    set_race("sheep");
    set_level(2);
    set_unarmed(1);
    set_type("hoof");
    set_hp(18);
    set_gender(1 + random(1));

    load_chat(5,({ "The sheep chews on some grass.\n",
                   "The sheep lies down for a while.\n",
                   "The sheep drinks some water.\n",
                   "The sheep shakes its head.\n"
                  }));

    load_a_chat(20,({ "The sheep tries to kick you.\n",
                      "The sheep baahs in horror.\n",
                      "The sheep tries to run away but fails.\n"
                    }));
}
