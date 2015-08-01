#pragma strict_types
#include "../def.h"
inherit STD_MOV_MONSTER;

void create_object(void);

void create_object(void)
{
    set_name("dog");
    add_id("puppy");
    add_id("small dog");
    set_short("a small dog");
    set_long("A small, lovable puppy. It's looking adoringly at you " +
             "with it's big, wet eyes.\n");
    set_level(1);
    set_race("dog");
    set_hp(30);
    set_al(200);
    set_gender(1);
    set_skill("unarmed",10);
    set_time_slice(7 + random(4));
    set_walking();

    load_chat(30,({ "The puppy pants loudly.\n",
                    "The puppy humps your leg.\n" }));
    load_a_chat(30,({ "The poor little puppy whimpers loudly.\n" }));
}
