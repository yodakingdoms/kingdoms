#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);
void init(void);
int do_kill(string str);
int second_life(object corpse);
void attacked_by(object who);

void create_object(void)
{
    set_name("yzwul");
    add_id("man");
    set_short("Yzwul, right hand to Nirach",1);
    set_long("Yzwul is Nirach's right hand and the commander of his " +
             "darkling army. He was the one who betrayed the band of " +
             "resistance fighters, and he has served Nirach ever since. He " +
             "is a huge, bearded man with deep dark eyes. He is observing " +
             "you coldly with a faint smile on his lips. He has a strange " +
             "aura about him.\n");
    set_level(18);
    set_unarmed(0);
    set_db(0);
    set_al(-500);
    set_hp(600);
    set_gender(1);
    set_race("darkman");
    set_skill("combat",95);
    set_skill("perception",95);
    set_skill("twohanded",95);
    set_skill("resist",80);
    set_skill("dodge",90);
    set_skill("magic",80);
    set_spell_mess1("A bolt of lightning from Yzwul's clenched fist strikes " +
                    "his foe!!.\n");
    set_spell_mess2("A bolt of lightning from Yzwul's clenched fist strikes " +
                    "you in the chest!!.\n");
    set_chance(35);
    set_spell_dam(40);
    set_str(25);
    set_int(20);
    set_dic(20);
    set_dex(25);
    set_qui(25);
    set_wc(1);
    set_new_ac(1);
    add_money(1500 + random(500));
    make(ARMOUR + "dark_platemail");
    make(ARMOUR + "dark_phelmet");
    make(ARMOUR + "dark_glove");
    make(ARMOUR + "dark_boot");
    make(ARMOUR + "dark_amulet");
    make(ARMOUR + "dark_cloak");
    make(ARMOUR + "dark_leggings");
    make(WEAPON + "dark_twohsword");
    make(OBJECT + "key");
    init_command("wear all");
    init_command("wield sword");

    load_chat(4,({ "Yzwul scratches his beard as he looks you over.\n",
                   "Yzwul says: So... What are we going to do with you..?\n",
                   "Yzwul says: I hope you realize that you will never " +
                   "defeat me or my master.\n" }));
    load_a_chat(20,({ "Yzwul parries your attacks with masterful skill!!\n\n",
                      "Your blows seem to bounce off Yzwul's armour!\n\n",
                      "Yzwul almost succeeds in disarming you!\n\n",
                      "Yzwul snarls: My master grants me strenght. You " +
                      "will never defeat me.\n\n" }));
}

void init(void)
{
    add_action("do_kill","kill");
    ::init();
}

int do_kill(string str)
{
    if(str == "yzwul")
    {
        tell_room(ENV(TO),"Yzwul snarls: Tonight your body will be fed to " +
                  "my soldiers, " + TP->QN + ".\n");
    }
    return 0;
}

int second_life(object corpse)
{
    tell_room(ENV(TO),"Yzwul falls to his knees. With blood flowing from " +
              "his mouth, he gasps: My master will destroy you.\n");
    return ::second_life();
}

void attacked_by(object ob)
{
    // This is a very simple defense thing, if more than one player attack
    // him at the same time it might result in chaos but that might be
    // fun too so let's not worry about that
    ::attacked_by(ob);
    if(present("darkling",ENV(TO)))
    {
        tell_room(ENV(TO),"Yzwul commands his troops to defend him!\n");
        foreach(object defender: all_inventory(ENV(TO)))
        {
            if(defender->id("darkling"))
            {
                defender->attacked_by(ob);
                ob->attack_object(defender);
            }
        }
    }
}
