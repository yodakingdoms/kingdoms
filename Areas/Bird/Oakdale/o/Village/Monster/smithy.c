#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_short("Arlon the Smithy",1);
    set_long("He is working diligently at his forge.\n");
    set_name("arlon");
    add_id("smithy");
    set_gender(1);
    set_level(4);
    set_hp(100);
    set_al(200);
    set_race("human");
    set_wc(5);
    set_ac(10);
    set_skill("smithing",65);
}
