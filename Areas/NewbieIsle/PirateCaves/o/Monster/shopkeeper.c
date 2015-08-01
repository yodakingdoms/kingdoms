#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);
int is_unkillable(void);
string unkillable_string(object attacker);
int catch_tell(string str);

void create_object(void)
{
    set_short("Dithe the pirate shopkeeper",1);
    set_long("Dithe is a drunken slob of a shopkeeper. You feel your " +
             "trading skill increase every time he stumbles or bumps " +
             "into a shelf as he tries to move around his shop.\n");
    set_name("dithe");
    add_id("man");
    add_id("shopkeeper");
    add_id("dithe the shopkeeper");
    set_level(2);
    set_race("human");
    set_hp(80);
    set_al(0);
    set_gender(1);
    set_wc(1);
    set_ac(0);
    add_money(200);

    load_chat(1,({ "Dithe stumbles.\n",
                    "Dithe bumps into a shelf.\n",
                    "Dithe takes a small bottle from a pocket and drinks " +
                    "from it when he thinks you're not looking.\n",
                    "Dithe mumbles something incomprehensible.\n"
                }));
}

int is_unkillable(void)
{
    return 1;
}

string unkillable_string(object attacker)
{
    return "You won't be able to sell your loot here if you do this so " +
           "you change your mind.";
}


int catch_tell(string str)
{
    int tmp;
    string who,what;

    if(sscanf(str,"%s sells %s",who,what) == 2)
    {
        if(lower_case(what[0..1]) == "a ")
            what = what[2..strlen(what)];

        if(lower_case(what[0..2]) == "an ")
            what = what[3..strlen(what)];

        tmp = random(5);

        if(!tmp)
            tell_room(environment(),"Dithe says: What a lousy "+
                      lower_case(what[0..strlen(what)-3]) + ".\n");
        if(tmp == 2)
            tell_room(environment(),"Dithe says: Why do I bother buying " +
                      "these " + lower_case(what[0..strlen(what)-3]) +
                      "s?\n");
        if(tmp == 4)
            tell_room(environment(),"Dithe says: I'll never get rid of " +
                      "this " + lower_case(what[0..strlen(what)-3]) + ".\n");
        return 1;
    }

    if(sscanf(str,"%s buys %s",who,what) == 2)
    {
        if(lower_case(what[0..1]) == "a ")
            what = what[2..strlen(what)];

        if(lower_case(what[0..2]) == "an ")
            what = what[3..strlen(what)];

        tmp = random(5);

        if(!tmp)
            tell_room(environment(),"Dithe says: I don't think you will " +
                      "be very pleased, " + capitalize(who) + ".\n");

        if(tmp == 2)
            tell_room(environment(),"Dithe says: Not a pleasure doing " +
                      "business with you, "+capitalize(who) + ".\n");

        if(tmp == 4)
            tell_room(environment(),"Dithe says: Why do I bother with " +
                      "customers like " + capitalize(who) + "?\n");

        return 1;
    }
}
