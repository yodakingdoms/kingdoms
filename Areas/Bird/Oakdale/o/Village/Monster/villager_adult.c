// Inherited by adult villagers
#pragma strict_types
#include "../def.h"
inherit STD_MOV_MONSTER;

void create_object(void);

void create_object(void)
{
    set_level(2);
    set_unarmed(1);
    set_skill("unarmed",20);
    set_race("human");
    set_hp(80);
    set_al(200);
    set_wc(1);
    set_ac(1);
    set_time_slice(7 + random(4));
}
