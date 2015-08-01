#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_name("rooster");
    add_id("small rooster");
    set_short("a small rooster");
    set_long("A small rooster that does not look very impressive to you. " +
             "He would, however, look pretty impressive to someone the size " +
             "of a hobbit, and more importantly to someone the size of " +
             "a small hen.\n");
    set_race("rooster");
    set_level(2);
    set_unarmed(1);
    set_type("wing");
    set_hp(20);
    set_gender(1);

    load_chat(10,({ "The rooster struts around on the ground.\n",
                    "The rooster looks like he is master of his domain.\n",
                    "The rooster clucks contentedly.\n",
                    "The rooster surveys the poultry yard.\n"
                  }));

    load_a_chat(20,({ "The rooster cackles angrily.\n",
                      "The rooster stares sternly at you.\n",
                      "The rooster tries to peck you with its beak.\n"
                    }));
}
