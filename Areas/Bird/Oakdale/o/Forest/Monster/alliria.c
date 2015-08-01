#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

int telling;

void create_object(void);
int is_unkillable(void);
string unkillable_string(object attacker);
void catch_tell(string message);
void asked_about_orb(object player);
void tell_story(int step);

void create_object(void)
{
    set_name("alliria");
    add_id("woman");
    add_id("grandmother");
    set_short("Grandmother Alliria",1);
    set_long("An old woman clad in a green dress. Her hair is somewhat " +
             "stripy but still brown, and her eyes are bright. Age has " +
             "made her body frail, but it is evident her mind is still " +
             "clear. She looks at as if she's expecting you to ask her " +
             "something.\n");
    set_level(4);
    set_unarmed(0);
    set_db(1);
    set_al(300);
    set_hp(200);
    set_gender(0);
    set_race("human");
    set_skill("lore",100);
    set_wc(1);
    set_new_ac(1);
    add_money(random(100));

    make(ARMOUR + "dress");
    init_command("wear dress");
}

int is_unkillable() { return 1; }

string unkillable_string(object attacker)
{
    return "As you approach the old woman she lifts her head and gazes " +
           "into your eyes. Suddenly all thoughts of murder disappear from " +
           "your mind. Filled with shame you put your weapon away.\n";
}

void catch_tell(string message)
{
    object player;
    string name,junk;

    if(sscanf(message,"%s says:%s gavin%s",name,junk,junk) == 3 ||
       sscanf(message,"%s hisses:%s Gavin%s",name,junk,junk) == 3)
    {
        if(!telling)
        {
            telling = 1;
            find_player(lower_case(name[1 .. (strlen(name))]));
            if(!player->test_flag(QUEST_SUB_FLAG_5))
            {
                player->add_exp(10000);
                player->set_flag(QUEST_SUB_FLAG_5);
            }
            set_alarm(1.0,0.0,"tell_story",0);
        }
        else
        {
            tell_object(player,"Alliria says: Yes, yes, now pay " +
                        "attention.\n");
        }
    }
    else if(sscanf(message,"%s asks you:%s orb%s",name,junk,junk) == 3)
    {
        if(!telling)
        {
            player = find_player(lower_case(name[1 .. (strlen(name))]));
            set_alarm(1.0,0.0,"asked_about_orb",player);
        }
        else
        {
            W("Sssh, don't disturb her now, she's talking.\n");
        }
    }
}

void asked_about_orb(object player)
{
    if(present(player,ENV(TO)))
    {
        set_this_player(player);
        W("Alliria peers suspiciously at you and whispers: Say the " +
          "name of the one who told you to ask me. Nirach has many " +
          "spies...\n");
        S("Alliria peers suspiciously at " + TP->QN + " and " +
          "whispers something in " + TP->QPO + " ear.\n");
    }
    else
    {
        tell_room(ENV(TO),"Alliria says: Why does " + player->QN +
                  " ask me things if there's no time to wait for the " +
                  "answer?\n");
    }
}

void tell_story(int step)
{
    switch(step)
    {
        case 0: tell_room(ENV(TO),"Alliria smiles and says: I see. Young " +
                          "Gavin has always been a good judge of character " +
                          "so I guess you're not one of Nirach's henchmen. " +
                          "I have knowledge you will need if you have come " +
                          "to stop Nirach's reign...\n");
                set_alarm(5.0,0.0,"tell_story",1);
	  break;
        case 1: tell_room(ENV(TO),"Alliria says: Sit down and listen. " +
                          "Nirach is far too powerful to be defeated by " +
                          "physical force. Even if you were to slay his " +
                          "flesh, you would not banish his soul. The one " +
                          "way to destroy him is to retrieve the orb from " +
                          "his dungeon and free Alywin's spirit.\n");
                set_alarm(5.0,0.0,"tell_story",2);
          break;
        case 2: tell_room(ENV(TO),"Alliria ponders deeply and says: To do " +
                          "this you must take the orb to the ruin of " +
                          "Alywin's shrine. The holy altar still stands " +
                          "there, and what you must do, is place the orb " +
                          "upon the altar. The holy power of the altar " +
                          "should shatter the orb and set Alywin's spirit " +
                          "free.\n");
                set_alarm(6.0,0.0,"tell_story",3);
          break;
        case 3: tell_room(ENV(TO),"Alliria sighs heavilly and says: It is " +
                          "a momentous task, and little can I offer to " +
                          "help. Know this, that the guardian of the orb " +
                          "is powerful, and once you have entered it's " +
                          "chamber, you may not be able to leave until " +
                          "you have defeated it. Should you succeed in " +
                          "this quest, the people of this valley would " +
                          "praise your name in songs for ages to come. Go " +
                          "now, my prayers go with you.\n");
                set_alarm(6.0,0.0,"tell_story",4);
          break;
        case 4: tell_room(ENV(TO),"Alliria sits down and continues with " +
                          "what she was doing.\n");
                telling = 0;
          break;
        default: telling = 0; // In case something goes wrong
            break;
    }
}
