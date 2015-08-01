// Inherited by child villagers
#pragma strict_types
#include "../def.h"
inherit STD_MOV_MONSTER;

void create_object(void);

void create_object(void)
{
    add_id("child");
    set_level(1);
    set_unarmed(1);
    set_race("human");
    set_hp(30 + random(10));
    set_al(200);
    set_wc(1);
    set_ac(1);
    set_wimpy(50);
    set_time_slice(7 + random(4));

    load_a_chat(40,({ "The helpless little child screams: Mommy! Daddy! " +
                      "Help!\n"}));
}
