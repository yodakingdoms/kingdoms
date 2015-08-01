#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void)
{
    set_short("Jars the Junior Rhymer",1);
    set_long("Jars is a small little bard with a very big mouth. His mouth " +
             "opens and closes constantly, letting an endless stream of " +
             "words escape. He is grinning confidently. He's not a part of " +
             "the crew of the Riaa, but the goods she's distributing are " +
             "his and Lames' and they hate to see them stolen by pirates.\n");
    set_name("jars");
    add_id("minstrel");
    add_id("bard");
    add_id("jars the minstrel");

    set_level(2);
    set_race("newbie island bard");
    set_hp(80 + random(25));
    set_al(0);
    add_money(100 + random(20));
    set_gender(1);
    set_skill("combat",20 + random(10));

    make(PCWEAPON + "drumstick");
    make(PCARMOUR + "black_shirt");
    init_command("wield drumstick");
    init_command("wear shirt");

    make(PCOBJECT + "trashcan");

    load_chat(10,({
        "Jars talks and talks and talks and never shuts up.\n",
        "Jars bangs his trashcan with his drumstick: *PING* *PING* *PING*\n",
        "Jars complains: You pirates are ruining me!\n",
        "Jars stomps his feet rapidly.\n",
    }));

    load_a_chat(30,({
        "Jars hits you in the head with his drumstick: *PING* *PING*\n",
        "Jars complains: You pirates are ruining me!\n",
        "Jars tries to throw his drumstick at you!\n",
    }));
}
