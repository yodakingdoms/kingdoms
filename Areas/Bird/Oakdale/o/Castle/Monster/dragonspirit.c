// The whole point of the quest is that players have to destroy the orb
// to defeat Nirach, that's why this monster is (or at least should be)
// invulnerable
#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);
void target_died(object target);
int second_life(object corpse);
void fire_breath(void);
// We mask these to make the spirit invulnerable
int hit_living(object weapon, mixed damage_type, int damage);
int do_spell_damage(int dam,mixed type);
int reduce_hit_point(int dam);
void show_health(void);

void create_object(void)
{
    set_name("spirit");
    add_id("black spirit");
    add_id("_oakdale_dragon_spirit_");
    set_short("a huge black spirit in the shape of a dragon");
    set_long("A huge, black spirit looking like a dragon with spread " +
             "wings, huge claws and a long tail. Beautiful and terrifying " +
             "it glares at you with shining, almond shaped eyes. Somehow " +
             "you know that the mind behind those eyes is not the mind of " +
             "a dragon, but that of a dark elf.\n");
    set_level(50);
    set_unarmed(0);
    set_db(20);
    set_chance(10);
    set_spell_dam(0);
    set_spell_mess1("#fire_breath");
    set_spell_mess2("");
    set_al(-1000);
    set_hp(2000);
    set_gender(0);
    set_race("dragonspirit");
    set_new_ac(0);
    set_no_corpse(1); // This shouldn't matter but who knows
    set_aggressive(1);
    add_property("no_flee");
    set_wc(65);
    set_type("spirit");
    set_weapon_desc("ethereal claws");

    load_a_chat(10,({ "The dragon spirit roars with rage!\n",
                      "The dragon spirit charges with renewed vigour and " +
                      "strength!\n",
                      "You hear a voice in your head, saying: Now you will " +
                      "perish... Nirach's voice!\n" }));
}

void target_died(object target)
{
    if(target != TO)
    {
        write_file(DRAGON_SPIRIT_LOG,"Spirit slayed " + C(target->QRN) +
                   ", level " + target->query_level() + ". Time : " +
                   ctime(time()) + ".\n");
        tell_room((ENV(TO)),"The spirit makes a horrible sound as it sends " +
                   target->query_name() + "'s spirit to the otherworld.\n");
    }
}

int second_life(object corpse)
{
    // Just in case, to find out if I've missed a way to kill the thing
    write_file(DRAGON_SPIRIT_LOG,"Spirit was killed by " + C(TP->QRN) +
               " at level " + TP->query_level() + ". Time: " + ctime(time()) +
               ".\n");
    ::second_life();
}

void fire_breath(void)
{
    // We don't really want this thing to kill players, just beat them
    // up so this attack makes sure it does lots of damage but not enough
    // to make someone dead, and then makes the victims flee out of the room.
    tell_room(ENV(TO),"The spirit opens its mouth and breathes fire into " +
              "the room. You and everything in it are engulfed by searing " +
              "white-hot flames!\n");
    foreach(object victim: all_inventory(ENV(TO)))
    {
        if(living(victim) && victim != TO)
        {
            if(!victim->query_animate())
            {
                victim->do_spell_damage(victim->query_hp() / 2 +
                                        random(victim->query_hp() / 4),
                                        "fire");
                tell_object(victim,"You are burnt alive! Your skin is " +
                            "melting and your lungs are on fire! Panicking, " +
                            "you stumble blindly in any direction you can " +
                            "to escape the flames!\n");
                victim->run_away();
            }
        }
    }
}

int hit_living(object weapon, mixed damage_type, int damage)
{
    if(weapon->query_wield()->query_animate())
    {
        S(weapon->query_wield()->query_caster()->QN + "'s animated " +
          weapon->short() + " passes straight through the spirit!\n");
    }
    else
    {
        switch(random(5))
        {
            case 0: W("Your weapon passes straight through the spirit!\n");
                    S(TP->QN + "'s weapon passes straight through the " +
                      "spirit!\n");
              break;
            case 1: W("The spirit blurs and your blow passes straight " +
                      "through it.\n");
                    S("The spirit blurs and " + TP->QN + "'s blow passes " +
                      "straight through it.\n");
              break;
        }
    }
    return 0;
}

int do_spell_damage(int damage,mixed type)
{
    tell_room(ENV(TO),"The huge spirit is unaffected by the magic!\n");
    return 0;
}

int reduce_hit_point(int dam)
{
    // And just to be absolutely sure we mask this as well
    return ::reduce_hit_point(0);
}

void show_health(void)
{
    W("The spirit is not corporeal and cannot be harmed physically.\n");
}
