#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_name("prisoner");
    set_alt_name("woman");
    set_short("a sick prisoner");
    set_long("A woman who looks like she is dying. She is thin and frail, " +
             "and she's coughing and trembling convulivly. She has " +
             "festering wounds all over her body and she has repulsive " +
             "growths in her once probably beautiful face. You would not " +
             "want to catch the disease she is suffering from!\n");
    set_level(1);
    set_unarmed(1);
    set_db(1);
    set_al(300);
    set_hp(50);
    set_gender(2);
    set_race("human");
    set_skill("unarmed",1);
    set_wc(1);
    set_new_ac(1);

    load_chat(20,({ "The woman groans loudly.\n",
                    "The woman screams out in agony.\n",
                    "The woman vomits in her own lap.\n" }));
}
