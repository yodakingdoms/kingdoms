#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

int telling_story; // 0 = waiting to tell, 1 = telling, 2 = told

void create_object(void);
void init(void);
int do_sit(string str);
int do_light(string str);
void tell_story(int step);
void my_reset(void);

void create_object(void)
{
    set_short("an old storyteller");
    set_long("An old, grey haired man dressed in a grey tunic. His " +
             "features are sharp and his deep blue eyes are bright and " +
             "intelligent. His long, slender fingers trace intricate " +
             "patterns trough the air as he tells epic tales of heroes " +
             "and villains. Maybe he would tell you a story about the "+
             "valley if you sat down at his table and asked?\n");
    set_name("storyteller");
    add_id("man");
    set_level(4);
    set_race("human");
    set_hp(100);
    set_al(350);
    set_gender(1);
    set_wc(6);
    set_ac(1);
    set_unarmed(1);
    add_money(200 + random(200));
}

void init(void)
{
    add_action("do_sit","sit");
    add_action("do_light","light");
}

int do_sit(string str)
{
    if(!telling_story)
    {
        W("You sit down at the old man's table and ask him to tell you a " +
          "story about the valley. 'Hmm' he says. 'A story like this one " +
          "should not be told in front of a cold hearth. Would you be so " +
          "kind and light a fire in the fireplace?'\n");
        S(TP->QN + " sits down at the old man's table and asks him " +
          "something.\n");
        return 1;
    }
    else if(telling_story == 1)
    {
        W("The storyteller is already telling a story. Maybe, if you are " +
          "really quiet, you could stay and listen...\n");
        S(TP->QN + " walks over to the old man's table, sits down really " +
          "quietly and starts listening to the tale.\n");
        return 1;
    }
    else
    {
        W("You sit down next to the storyteller and ask him to tell you a " +
          "story about the valley. The old man smiles wearily and says: " +
          "'I have all ready told such a tale this night, and I have not " +
          "the strenght to retell it. Come back tomorrow, young one, and " +
          "you may get to hear it.'\n");
        S(TP->QN + " sits down next to the old man and asks him to tell " +
          TP->QPR + " a story. The old man smiles wearily and says that " +
          "he is too tired.\n");
        return 1;
    }
}

int do_light(string str)
{
    if(str == "fire")
    {
        if(!telling_story)
        {
            if(!TP->test_flag(QUEST_FLAG))
	    {
                W("You light a fire in the fireplace. The old man sighs " +
                  "contentedly as the fire begins to catch and throw " +
                  "strange, long shadows on the walls. 'Now gather round " +
                  "and listen well', he says. 'A tale like this should not " +
                  "be told in too loud a voice. The walls in these parts " +
                  "really do have ears...'\n");
                S(TP->QN + " lights a fire in the fireplace. The old man " +
                  "sighs contentedly and begins the telling of a tale.\n");
                telling_story = 1;
                set_alarm(7.0,0.0,"tell_story",0);
                set_alarm(300.0,0.0,"my_reset");
                return 1;
	    }
            else
            {
                tell_room(ENV(TO),"The storyteller smiles and says: Oh " +
                          "'tis you, " + TP->QN + ". You have already " +
                          "heard my tale. Methinks I will save my voice " +
                          "for some other young adventurer. Godspeed! ");
                W("The storyteller waves happily in your direction.\n");
                S("The storyteller waves happily in " + TP->QN + "'s " +
                  "direction.\n");
                return 1;
	    }
        }
        else if(telling_story == 1)
        {
            W("There is already a fire burning in the fireplace.\n");
            S(TP->QN + " walks over to the fireplace to warm " + TP->QPO +
              " hands.\n");
            return 1;
        }
        else
        {
            W("You try to light a fire but you can't get it started.\n");
            S(TP->QN + " tries to light a fire, but can't get it started.\n");
            return 1;
        }
    }
    return 0;
}

void tell_story(int step)
{
    switch(step)
    {
        case 0: tell_room(ENV(TO),"The storyteller lowers his voice...\n\n");
                set_alarm(3.0,0.0,"tell_story",1);
          break;
        case 1: tell_room(ENV(TO),"The storyteller says: Half a century " +
                          "ago this valley was ruled by the just and fair " +
                          "Duke Talanon, aided by his advisors, Alywin of " +
                          "the Cross, and Nirach of the Book. Nirach and " +
                          "Alywin were strong in magic, and the spells they " +
                          "worked together kept evil away from the valley " +
                          "and the people safe.\n");
                set_alarm(7.0,0.0,"tell_story",2);
          break;
        case 2: tell_room(ENV(TO),"The storyteller sighs heavily.\n\n");
                set_alarm(3.0,0.0,"tell_story",3);
          break;
        case 3: tell_room(ENV(TO),"The storyteller says: Times were good " +
                          "then, but that was soon to change. Talanon fell " +
                          "ill, and no healer could we find to save his " +
                          "life. We buried him in the shrine to the " +
                          "north...\n");
                set_alarm(5.0,0.0,"tell_story",4);
          break;
        case 4: tell_room(ENV(TO),"The storyteller stares blankly into " +
                          "space, seemingly lost in thought...\n\n");
                set_alarm(2.0,0.0,"tell_story",5);
          break;
        case 5: tell_room(ENV(TO),"The storyteller resumes: Talanon had no " +
                          "heir. It was decided that Alywin and Nirach " +
                          "would govern until a new duke had been found, " +
                          "as they both were loved and trusted by the " +
                          "people...'\n");
                set_alarm(4.0,0.0,"tell_story",6);
          break;
        case 6: tell_room(ENV(TO),"The storyteller shakes his head.\n\n");
                set_alarm(2.0,0.0,"tell_story",7);
          break;
        case 7: tell_room(ENV(TO),"The storyteller says: Oh, how he misled " +
                          "us. One night, but two weeks after Talanon was " +
                          "buried, Nirach left his tower in the castle to " +
                          "visit Alywin in the shrine. Oh, I remember that " +
                          "night. The moon was hidden behind dark clouds " +
                          "and the wolves howled like never before. Alywin " +
                          "greeted Nirach as a friend, but Nirach turned " +
                          "upon him. He bound Alywin's spirit within a " +
                          "magic orb he'd been crafting in secret, seeking " +
                          "to gain Alywin's powers for himself...\n");
                set_alarm(8.0,0.0,"tell_story",8);
          break;
        case 8: tell_room(ENV(TO),"The storyteller sighs heavily.\n\n");
                set_alarm(2.0,0.0,"tell_story",9);
          break;
        case 9: tell_room(ENV(TO),"The storyteller says: He turned the once " +
                          "beautiful castle into a dark fortress to " +
                          "practice his evil arts in. People in the " +
                          "village started disappearing and strange beasts " +
                          "roamed the forest at night. His darkling " +
                          "minions, a race he himself had created, began " +
                          "terrorizing the village, hunting down and " +
                          "killing all those who tried to leave. Nirach " +
                          "had not yet gained control over the orb, and " +
                          "he did not want the Kings to get word of his " +
                          "doings...\n");
                set_alarm(8.0,0.0,"tell_story",10);
          break;
        case 10: tell_room(ENV(TO),"The storyteller takes a deep " +
                           "breath.\n\n");
                 set_alarm(2.0,0.0,"tell_story",11);
          break;
        case 11: tell_room(ENV(TO),"The storyteller continues: But " +
                           "oppression breeds resistance. One night a band " +
                           "of brave young men gathered in the caves by " +
                           "the waterfall to the southeast. They followed " +
                           "a secret path into the castle dungeons, hoping " +
                           "to steal the orb and end Nirach's reign. They " +
                           "were betrayed. The one who led them to the " +
                           "chamber where the orb was kept was one of " +
                           "Nirach's men. In the chamber they encountered " +
                           "the guardian Nirach had summoned...\n");
                 set_alarm(8.0,0.0,"tell_story",12);
          break;
        case 12: tell_room(ENV(TO),"The storyteller shivers with " +
                           "fear...\n\n");
                 set_alarm(2.0,0.0,"tell_story",13);
          break;
        case 13: tell_room(ENV(TO),"The storyteller says: All but one of " +
                           "the brave men perished that night, and the sole " +
                           "survivor of the unfortunate raid was deprived " +
                           "of his sanity by what he saw. He is now to be " +
                           "found in our madhouse. The traitor serves " +
                           "Nirach still, Yzwul is his name.\n");
                 set_alarm(4.0,0.0,"tell_story",14);
          break;
        case 14: tell_room(ENV(TO),"The storyteller spits on the floor.\n\n");
                 set_alarm(2.0,0.0,"tell_story",15);
          break;
        case 15: tell_room(ENV(TO),"The storyteller finishes: These events " +
                           "occured some fifty years ago, and noone has " +
                           "stood up to Nirach since. We wait in terror " +
                           "for the day Nirach will gain control of the " +
                           "orb, for then he will bring death upon all of " +
                           "the Kingdoms. But one hope do we have. That " +
                           "someone will come here and steal the orb from " +
                           "Nirach and destroy it, for it is not only we " +
                           "who will suffer, should he gain it's powers, " +
                           "but the whole of the Kingdoms...\n\n");
                 set_alarm(10.0,0.0,"tell_story",16);
          break;
        case 16: tell_room(ENV(TO),"The storyteller goes quiet as his tale " +
                           "ends. Everything is silent. The fire in the " +
                           "fireplace has gone out. You notice the patrons " +
                           "in the tavern looking at you with hope in their " +
                           "eyes.\n");
                 telling_story = 2;
          break;
    }
}

void my_reset(void)
{
    telling_story = 0;
}
