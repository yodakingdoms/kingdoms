#pragma strict_types
#include "../def.h"
inherit STD_MOV_MONSTER;

void create_object(void);

void create_object(void)
{
    set_name("rat");
    set_short("a rat");
    set_long("A small, disgusting rat. It tries to squrry away from you.\n");
    set_level(1);
    set_race("rat");
    set_hp(30);
    set_al(0);
    set_gender(0);
    set_skill("unarmed",10);
    set_time_slice(7 + random(4));
    set_walking();

    load_chat(30,({ "The rat squeaks.\n",
                    "The rat scurries away from you.\n"}));
    load_a_chat(30,({ "The rat squeaks loudly!\n" }));
}
