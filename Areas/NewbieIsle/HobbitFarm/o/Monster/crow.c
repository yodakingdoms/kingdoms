// ==================================================================
// A crow in the field. Unkillable since they must be scared away
// with the scarecrow for the quest
// ==================================================================
#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);
int is_unkillable(void);
string unkillable_string(object attacker);

void create_object(void)
{
    set_short("a nasty looking crow");
    set_long("A black crow that looks very nasty as it peers at you " +
             "with strangely intelligent looking eyes.\n");
    set_name("crow");
    add_id("black crow");
    add_id("bird");
    add_id("_scarecrow_quest_crow_");

    set_level(1);
    set_type("wing");
    set_race("crow");
    set_al(-300);
    set_gender(1);

    load_chat(5,({
        "A crow screeches in a nasty way.\n",
        "A crow lands on some corn and eats from it.\n",
        "A crow flies around, dangerously close to you.\n",
        "A crow lands on the ground and hops around.\n",
        "A crow peers evilly at you.\n"
    }));

}

int is_unkillable()
{
    return 1;
}

string unkillable_string(object attacker)
{
    return "The crow is flying around so quickly you can't attack it. " +
           "You need to get rid of it some other way. Perhaps by making " +
           "a scarecrow and placing it in the ground here.";
}
