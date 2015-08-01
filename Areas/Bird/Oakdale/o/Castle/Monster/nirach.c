#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;
inherit STD_ARRAYS;

int greeted; // -1 = waiting to start, 0 = greeting, 1 = greeted

void create_object(void);
void init(void);
int do_anything(string str);
int is_unkillable(void);
string unkillable_string(object attacker);
void cast_spell(void);
int query_enemy_count(void);
void target_died(object target);
int second_life(object corpse);
void start_hunting(object hunted);
void taunt_hunted(object hunted);
void taunt_attacker(void);
void greet_player(int step,object player);

void create_object(void)
{
    set_name("nirach");
    add_id("sorcerer");
    add_id("nirach the sorcerer");
    add_id("_oakdale_nirach_the_sorcerer_");
    set_short("Nirach the Sorcerer",1);
    set_long("A tall, slender man dressed in dark blue, almost black robes. " +
             "He has long, black hair and long, slender fingers. His eyes " +
             "are almond shaped and he has long, pointed ears. His features " +
             "are elvish, but his eyes are unspeakably evil.\n");
    set_race("darkelf");
    set_gender(1);
    add_money(2000 + (random(500)));
    set_level(35);
    set_hp(1500);
    set_chance(100);
    set_spell_dam(0);
    set_spell_mess1("#cast_spell");
    set_spell_mess2("");
    set_skill("magic",100);
    set_skill("attune",100);
    set_skill("combat",100);
    set_skill("perception",100);
    set_skill("resist",100);
    set_skill("concentrate",100);
    set_skill("blunt",100);
    set_skill("targeting",100);
    set_new_ac(1);
    set_db(20);
    set_wc(1);
    set_al(-1100);
    add_property("no_flee");

    make(ARMOUR + "dragonrobe");
    make(ARMOUR + "dark_cloak");
    make(ARMOUR + "dragonamulet");
    make(WEAPON + "dragonstaff");
    init_command("wear all");
    init_command("wield staff");

    make(OBJECT + "spellbook");
    make(OBJECT + "fake_magebook");

    greeted = -1;
    load_a_chat(50,({ "#taunt_attacker" }));
}

void init(void)
{
    if(TP->query_level() < LEVELS_NEWBIE)
    {
        add_action("do_anything","",1);
    }
    if(greeted < 0)
    {
        greeted = 0;
        set_alarmv(1.0,0.0,"greet_player", ({ 0, TP }));
    }
    ::init();
}

int do_anything(string str)
{
    if(!greeted && !is_in(query_verb(),({ "look","l","examine","glance" })))
    {
        W("You are spellbound!! You cannot move!\n");
        return 1;
    }
}

int is_unkillable(void)
{
    return !greeted;
}

string unkillable_string(object attacker)
{
    return "You are spellbound!! You cannot move!\n";
}

void cast_spell(void)
{
    object weapon;
    // If he has no shield he starts by casting that, otherwise he
    // checks his hitpoints. If he has lots left he uses mainly offensive
    // spells and if he's getting low he uses more defensive ones
    if(!present("magisk_skold",TO))
    {
        init_command("shield VII");
    }
    else if(!random(4))
    {
        if(query_hp() < 500)
        {
            // First he gets rid of any earthwalls so players can run away
            // now that he'd rather not fight them
            if(present("earthwall",ENV(TO))->query_block_dir() == "south")
            {
                present("earthwall",ENV(TO))->unmake(TO);
            }
            else
            {
                switch(random(10))
                {
                    case 0: // Nirach disarms the player and activates the
                            // mirror to get rid of the weapon. If the player
                            // looks at the mirror she should be able to
                            // figure out where the weapon went if she knows
                            // the area well enough
                            if((weapon = query_attack()->query_weapon()) ||
                               (weapon = query_attack()->query_weapon(2)))
                            {
                                tell_room(ENV(TO),"Nirach chants an evil " +
                                          "spell.\n");
                                tell_object(query_attack(),"Suddenly your " +
                                            "weapon turns white hot! You " +
                                            "burn your hand and drop it!\n");
                                query_attack()->do_spell_damage(5 + random(10),
                                                                "fire");
                                tell_room(ENV(TO),query_attack()->QN +
                                          " yells in pain and drops  " +
                                          query_attack()->QPO + " weapon.\n");
                                query_attack()->command("drop " + weapon->QN);
                                tell_room(ENV(TO),"Nirach chants another " +
                                          "spell, a beautiful spell. The " +
                                          "surface of the mirror becomes " +
                                          "blurry.\nNirach kicks " +
                                          weapon->short() + " into the " +
                                          "mirror. It disappears in a flash " +
                                          "of light and the surface of the " +
                                          "mirror returns to normal.\n");
                                transfer(weapon,ROOM + "dung_orbchamber");
                            }
                      break;
                    default: tell_room(ENV(TO),"Nirach whispers evil words " +
                                       "and one of the half-imaginary " +
                                       "shapes in the air in the room "+
                                       "disappears into his body with a " +
                                       "scream!\nNirach looks invigorated.\n");
                             reduce_hit_point(-50 - random(25));
                      break;
                }
            }
        }
        else
        {
            switch(random(5))
            {
                case 0: if(present("earthwall",ENV(TO))->query_block_dir() !=
                           "south")
                        {
                            init_command("earthwall south");
                        }
                  break;
                case 1: init_command("flechette " + query_attack()->QRN);
                  break;
                case 2: // This is not a real spell but it's a special attack
                        // so we put it here anyway
                        tell_room(ENV(TO),"Nirach closes his eyes and " +
                                  "mumbles a spell. Suddenly the floor " +
                                  "comes alive and turns into a horde of " +
                                  "leeches. The leeches crawl up over you " +
                                  "sink their teeth into you before they " +
                                  "disappear in a million puffs of smoke!\n");
                        foreach(object ob: all_inventory(ENV(TO)))
                        {
                            if(ob != TO && living(ob))
                            {
                                for(int i = 0; i < 3 + random(3); ++i)
                                {
                                    ob->add_bleeding(6 + random(6));
                                }
                            }
                        }
                  break;
                case 3: // Same here
                        tell_object(query_attack(),"\nNirachs huge dragon " +
                                    "shadow dives at you and the immaterial " +
                                    "jaws snap shut around you!!!! You feel " +
                                    "like you're being torn to pieces!!!!\n");
                        tell_room(ENV(TO),"\nNirachs huge shadows " +
                                  "immaterial jaws snap shut around " +
                                  query_attack()->QN + ", who screams out " +
                                  "in agony!!\n", ({ query_attack() }));
                        query_attack()->do_spell_damage(50 + random(50),
                                                        "spirit");
                  break;
                case 4: if(query_enemy_count() > 1)
                        {
                            init_command("powerball");
                        }
                        else
                        {
                            init_command("essencebolt");
                        }
                  break;
            }
        }
    }
}

int query_enemy_count(void)
{
    int count = 0;
    foreach(object ob: all_inventory(ENV(TO)))
    {
        if(ob != TO && living(ob)) ++count;
    }
    return count;
}

void target_died(object target)
{
    if(target != TO)
    {
        write_file(KILLED_BY_NIRACH_LOG,"Nirach slayed " + target->QRN +
                   ", level " + target->query_level() + ". Time : " +
                   ctime(time()) + ".\n");
        tell_room((ENV(TO)),"Nirach grins as he slays " +
                  target->query_name() + " and snarls: That is what " +
                  "happens to all who oppose me.\n");
    }
}

int second_life(object corpse)
{
    W("Nirach falls to the floor! He curses you with his dying breath.\n" +
      "Nirach says: You have not defeated me, you shall suffer the horror " +
      "of a thousand deaths for this!.\n");
    S("Nirach falls to the floor and curses " + TP->QN + " with his dying " +
      "breath!\n");
    write_file(NIRACH_KILLER_LOG,"Nirach was killed by " + TP->QRN + " at " +
               "level " + TP->query_level() + ". Time: " + ctime(time()) +
               ".\n");
    TP->add_fame(1000);
    TP->add_reputation(1000);
    TP->add_exp(30000);
    (ROOM + "lev5_nirachs_study")->summon_spirit(0);
    ::second_life();
}

void start_hunting(object hunted)
{
    set_alarm(1.0,0.0,"taunt_hunted",hunted);
    ::start_hunting(hunted);
}

void taunt_hunted(object hunted)
{
    if(!present(hunted,ENV(TO)))
    {
        tell_object(hunted,"Nirach tells you: That's right, " + hunted->QN +
                    ", flee. Run far away and do not return. I know your " +
                    "strengths and weaknesses now, and you will never " +
                    "defeat me!\n");
    }
}

void taunt_attacker(void)
{
    object attacker = TO->query_attack();
    if(attacker)
    {
        switch(random(7))
        {
            case 0: tell_room(ENV(TO),"Nirach snarls: Coming here shall be " +
                              "your undoing, " + attacker->query_name() +
                              ".\n");
              break;
            case 1: tell_room(ENV(TO),"Nirach shouts: I will make you " +
                              "suffer eternal torment for this, " +
                              attacker->query_name() + ".\n");
              break;
            case 2: tell_room(ENV(TO),"Nirach cackles: Muahahahahaa... " +
                              attacker->query_name() + "'s soul will not be " +
                              "the first one I have devoured, nor will it " +
                              "be the last!\n");
              break;
        }
    }
    else
    {
        // If we're here we have a load_a_chat without Nirach fighting
        // someone, that should mean assassin(?). Make sure we have a
        // shield ready
        if(!present("magisk_skold",TO))
        {
            init_command("shield VII");
        }
        else
        {
            switch(random(7))
            {
                case 0: tell_room(ENV(TO),"Nirach says: I can sense your " +
                                  "presence, worm.\n");
                  break;
                case 1: tell_room(ENV(TO),"Nirach says: My splinters spell " +
                                  "will force you out in the open.\n");
                  break;
                case 2: tell_room(ENV(TO),"Nirach says: My earthwall spell " +
                                  "will trap you here like the rat you " +
                                  "are.\n");
                  break;
                case 3: if(present("earthwall",ENV(TO))->query_block_dir() !=
                           "south")
                        {
                            init_command("earthwall south");
                        }
                  break;
                case 4: init_command("splinters");
                  break;
            }
        }
    }
}

void greet_player(int step,object player)
{
    if(!greeted)
    {
        switch(step)
        {
            case 0: tell_room(ENV(TO),"Nirach spins around as you enter " +
                              "the room.\n");
                    set_alarmv(4.0,0.0,"greet_player", ({ 1,player }));
              break;
            case 1: tell_room(ENV(TO),"Nirach pulls back the hood of his " +
                              "robe, and you gasp in astonishment. He is " +
                              "elven!\n");
                    set_alarmv(4.0,0.0,"greet_player", ({ 2,player }));
              break;
            case 2: tell_room(ENV(TO),"Nirach smiles slyly and says: So... " +
                              "It is you, " + player->QN + ". You have " +
                              "made it all this way...\n");
                    set_alarmv(4.0,0.0,"greet_player", ({ 3,player }));
              break;
            case 3: tell_room(ENV(TO),"Nirach nods appreciatively as he " +
                              "looks you over.\n");
                    set_alarmv(3.0,0.0,"greet_player", ({ 4,player }));
              break;
            case 4: tell_room(ENV(TO),"Nirach smiles and says: Yes... I " +
                              "could find use for a person of your " +
                              "talents, but I gather you have not come " +
                              "to offer me your services.\n");
                    set_alarmv(5.0,0.0,"greet_player", ({ 5,player }));
              break;
            case 5: tell_room(ENV(TO),"Nirach grins: No, but you are far " +
                              "too dangerous. I cannot afford to have an " +
                              "enemy in you, now can I?\n");
                    set_alarmv(4.0,0.0,"greet_player", ({ 6,player }));
              break;
            case 6: tell_room(ENV(TO),"Nirach shrieks: So now you must " +
                              "die!!!\n");
                    set_alarmv(3.0,0.0,"greet_player", ({ 7,player }));
              break;
            case 7: tell_room(ENV(TO),"Nirach's shadow expands to fill up " +
                              "the whole room!!\nSmoke spews out of his " +
                              "nostrils as he approaches you with death in " +
                              "his eyes.\n");
                    set_alarmv(4.0,0.0,"greet_player",({ 8,player }));
              break;
            case 8: tell_room(ENV(TO),"The spell is broken as Nirach " +
                              "attacks! You can move again!\n");
                    greeted = 1;
                    set_aggressive(1);
              break;
            default: greeted = 1;
                     set_aggressive(1);
              break;
        }
    }
}
