#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_name("pig");
    add_id("small pig");
    set_short("a small pig");
    set_long("A small pig that looks as if it is fully grown despite " +
             "being so small. It would probably seem like it is of a " +
             "normal size to someone the size of a hobbit though.\n");
    set_race("pig");
    set_level(1);
    set_unarmed(1);
    set_type("hoof");
    set_hp(15);

    load_chat(10,({ "The pig oinks merrily.\n",
                    "The pig rolls around on the ground.\n",
                    "The pig bumps into you.\n",
                    "The pig peers quizzically at you.\n"
                  }));

    load_a_chat(20,({ "The pig squeals in terror.\n",
                      "The pig tries to run away but fails.\n"
                    }));
}
