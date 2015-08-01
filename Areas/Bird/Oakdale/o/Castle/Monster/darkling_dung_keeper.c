#pragma strict_types
#include "../def.h"
inherit MONSTER + "darkling";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_name("keeper");
    add_id("dungeon keeper");
    set_short("a dungeon keeper");
    set_long("One of the darklings serving in the dungeons of the castle. " +
             "He looks human, but has pale skin and long, black hair. Long, " +
             "He has two long, protruding teeth in his lower jaw. He " +
             "observes you coldy with his small, black, pupilless eyes.\n");
    set_level(14);
    set_unarmed(0);
    set_db(3);
    set_hp(210);
    set_skill("combat",85);
    set_skill("longblade",85);
    set_skill("resist",85);
    set_skill("perception",85);
    set_aggressive(1);
    set_walking();
    set_wc(25);
    set_new_ac(25);
    add_money(random(200));
    make(ARMOUR + "dark_plate");
    make(WEAPON + "dark_lsword");
    make(ARMOUR + "dark_lshield");
    make(ARMOUR + "dark_helmet");
    make(ARMOUR + "dark_glove");
    make(ARMOUR + "dark_boot");
    make(ARMOUR + "dark_amulet");
    init_command("wear all");
    init_command("wield sword");
    make(OBJECT + "cell_key");

    load_a_chat(15,({ "The darkling tries to bite you!\n" }));
}
