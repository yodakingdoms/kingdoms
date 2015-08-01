#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);
int second_life(object corpse);

void create_object(void)
{
    set_name("prisoner");
    add_id("human");
    add_id("man");
    set_short("a prisoner");
    set_long("A dirty, ragged man who does not look as if he has long to " +
             "live if he doesn't get out of this dark cell.\n");
    set_level(2);
    set_unarmed(1);
    set_db(5);
    set_al(300);
    set_hp(200);
    set_gender(1);
    set_race("human");
    set_skill("unarmed",20);
    set_wc(10);
    set_new_ac(10);

    load_chat(20,({ "The prisoner whispers softly: Please... be merciful.. " +
                    "Put me out of my misery..\n" }));
}

int second_life(object corpse)
{
    W("The man dies, and a mist rises from the corpse. The spirit thanks " +
      "you and then it leaves...\n");
    S("As the man dies. his spirit rises from the corpse to thank his " +
      "killer before it leaves...\n");
    ::second_life();
}
