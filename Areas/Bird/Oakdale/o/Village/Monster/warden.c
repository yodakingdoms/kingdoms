#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_short("The Warden",1);
    set_long("The warden is a middle aged man with grey beard and unkept " +
             "hair. His eyes are red and he stares blankly into space. It " +
             "looks like he may actually belong on the other side of the " +
             "door to the east.\n");
    set_name("warden");
    add_id("man");
    add_id("the warden");
    set_level(9);
    set_skill("combat",70);
    set_skill("blunt",40);
    set_skill("perception",50);
    set_wc(10);
    set_new_ac(13);
    set_db(3);
    set_al(50);
    set_hp(90);
    set_gender(1);
    set_race("human");
    add_money(random(100));

    make(WEAPON + "club");
    init_command("wield club");
    make(ARMOUR + "warden_coat");
    init_command("wear coat");

    load_chat(5,({ "Warden pulls his hair.\n",
                   "Warden mumbles: Uuuh.. I'm losing it...\n",
                   "Warden cackles strangely.\n" }));
    load_a_chat(10,({ "Warden cackles wierdly.\n" }));
}
