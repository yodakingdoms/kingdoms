#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_short("an infant");
    set_long("Alena Tiralam is about two months old. She lies in her crib " +
             "all day and just eats sleeps and cries.\n");
    set_name("alena");
    add_id("infant");
    set_level(1);
    set_race("human");
    set_hp(10);
    set_al(200);
    set_gender(2);
    set_wc(1);
    set_ac(0);
    make(ARMOUR + "diaper");
    init_command("wear diaper");
    set_unarmed(1);

    load_chat(10,({ "The infant cries: Waaaaaaaaaaaaaaaah!\n",
                    "The infant giggles merrily.\n" }));
    load_a_chat(40,({ "The helpless little baby wails loudly!\n" }));
}
