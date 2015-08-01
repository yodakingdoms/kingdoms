#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);
void init(void);
int do_stop(string str);
int do_leave(string str);
int second_life(object corpse);

void create_object(void)
{
    set_name("spirit");
    add_id("guardian");
    add_id("guardian spirit");
    set_short("a guardian spirit");
    set_long("A black spirit floating in the air before you. It looks as " +
             "if the surrounding darkness has taken the shape of a light, " +
             "black mist. The mist seems to pulsate slowly, and in it's " +
             "centre you see two glowing red lights, almost like flames " +
             "on a candle. Somehow you know that they are two eyes, and " +
             "that they are focused on you.\n");
    set_level(18);
    set_unarmed(0);
    set_db(20);
    set_al(-400);
    set_hp(800);
    set_gender(0);
    set_int(25);
    set_race("darkspirit");
    set_skill("combat",100);
    set_skill("resist",70);
    set_skill("perception",90);
    set_spell_mess1("The spirit swirls round it's foe, suffocating him");
    set_spell_mess2("The spirit swirls around you, choking and suffocating " +
                    "you!\nThe spirit damages you.");
    set_chance(40);
    set_spell_dam(40);
    set_no_corpse(1);
    add_property("no_flee");
    set_wc(40);
    set_type("blunt");
    set_new_ac(50);
    set_aggressive(1);
    set_type("spirit");
    set_weapon_desc("choking mist");

    load_a_chat(30,({ "Your weapon sweeps right through the mist without "+
                      "damaging it!!\n",
                      "The spirit tries to enter your body!!\n" }));
}

void init(void)
{
    add_multi_action("do_leave","w|west");
    add_multi_action("do_stop","e|east");
    ::init();
}

int do_leave(string str)
{
    if(random(TP->query_int()) < random(TO->query_int()))
    {
        W("The black mist is swirling around you and you can't find the " +
          "exit!!\n");
        return 1;
    }
    W("The black mist is swirling around you but you manage to find the " +
      "exit!!\n");
    TP->command("heave");
    return 0;
}

int do_stop(string str)
{
    W("The black mist is swirling around you and you can't find the " +
      "exit!!\n");
    return 1;
}

int second_life(object corpse)
{
    tell_room(ENV(TO),"The spirit dissolves and vanishes from this " +
              "astral plane.\n");
    return ::second_life();
}
