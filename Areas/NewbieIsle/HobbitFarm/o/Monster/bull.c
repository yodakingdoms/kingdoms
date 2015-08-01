#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_name("bull");
    add_id("huge bull");
    set_short("a HUGE black bull");
    set_long("A huge bull, even to someone of your size. It has long, " +
             "sharp horns and a big metal ring in its nose. You feel " +
             "a bit sorry for the small cows when you see him. It stares " +
             "evilly at you and you feel like it would be a very bad idea " +
             "to attack him without being skilled in fighting and having " +
             "very good equipment.\n");
    set_race("bull");
    set_level(4);
    set_unarmed(1);
    set_wc(20);
    set_type("horn");
    set_gender(1);

    load_chat(5,({ "The bull stares evilly at you.\n",
                   "The bull swats some flies away with its tail.\n",
                   "The bull drinks some water from the pond.\n",
                   "The bull eats some grass.\n"
                  }));

    load_a_chat(20,({ "The bull tries to impale you with its horns.\n",
                      "The bull moos in triumph.\n",
                      "The bull tries to kick you.\n"
                    }));
}
