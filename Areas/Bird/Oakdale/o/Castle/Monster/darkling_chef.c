#pragma strict_types
#include "../def.h"
inherit MONSTER + "darkling";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_name("chef");
    add_id("darkling chef");
    set_short("The darkling chef",1);
    set_long("The darkling chef. He looks pretty much like all the others, " +
             "except for his looong moustaches.\n");
    set_level(4);
    set_hp(220);
    add_money(25 + random(100));
    set_skill("combat",20);
    set_skill("blunt",30);
    set_wc(30);
    set_new_ac(30);
    set_str(20);
    make(ARMOUR + "apron");
    make(WEAPON + "spoon");
    init_command("wear all");
    init_command("wield spoon");

    load_chat(4,({ "The chef stirs in one of his pots.\n",
                   "The chef says: Ah, yez.. You could take ze roazted " +
                   "pig out now.\n" }));
    load_a_chat(10,({ "The chef screams: There'll be no dezzert for you " +
                      "thiz evening!!!\n" }));
}

void
start_hunting(object ob)
{
    find_player("yoda")->catch_tell("Foofaaa.\n");
    ::start_hunting(ob);
}

void remove_attacker(object attacker)
{
    find_player("yoda")->catch_tell("Foo.\n");
    ::remove_attacker(attacker);
}
