#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);
int is_unkillable(void);
string unkillable_string(object attacker);

void create_object(void)
{
    set_short("Chubby the pirate apothecary",1);
    set_long("Chubby is the genious apothecary who discovered the secret " +
             "of the healing properties of alcohol. The fact that he can " +
             "turn ale and rum into healing potions has made him a sort " +
             "of deity to the rest of the pirates.\n");
    set_name("chubby");
    add_id("man");
    add_id("apothecary");
    set_level(2);
    set_race("human");
    set_hp(80);
    set_al(0);
    set_gender(1);
    set_wc(1);
    set_ac(0);
    add_money(200);

    load_chat(1,({ "Chubby rubs his belly.\n",
                   "Chubby gulps down an alepotion.\n",
                   "Chubby mumbles: Now, if I could just split this beer " +
                   "atom...\n"
                }));
}

int is_unkillable(void)
{
    return 1;
}

string unkillable_string(object attacker)
{
    return "You won't be able to buy healing potions here if you do this " +
           "so you change your mind.";
}
