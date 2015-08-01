#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

int state = -1; // -1 = Waiting for player,0 = playing,1 = telling story

void create_object(void);
int is_unkillable();
string unkillable_string(object attacker);
void init(void);
int do_like(string str);
int do_dislike(string str);
void play_flute(int step);
void tell_story(int step);

void create_object(void)
{
    set_short("Gavin the Piper",1);
    set_long("Gavin is a teenage boy with blond hair and freckles. He " +
             "sits here all day playing his flute and enjoying nature. " +
             "People in the village think he is a bit odd.\n");
    set_name("gavin");
    add_id("boy");
    add_id("piper");
    set_level(3);
    set_unarmed(1);
    set_db(5);
    set_al(300);
    set_hp(80);
    set_gender(1);
    set_race("human");
    set_skill("unarmed",45);
    set_wc(14);
    set_new_ac(30);

    make(OBJECT + "flute");
}

int is_unkillable() { return 1; }

string unkillable_string(object attacker)
{
    return "As you approach Gavin, he leaps away and jumps onto a boulder " +
           "out in the river where you can't reach him. He laughs at your " +
           "feeble attempts to get to him, and when you give up, he " +
           "returns to the shore and continues to play.\n";
}

void init(void)
{
    if(state == -1)
    {
        state = 0;
        set_alarm(1.0,0.0,"play_flute",0);
    }
    add_action("do_like","nod");
    add_action("do_dislike","shake");
}

int do_like(string str)
{
    if(!state)
    {
        W("\nYou let Gavin know that you liked his tune very much.\n");
        S(TP->QN + " tells Gavin that " + TP->QPR + " liked the tune " +
          "very much.\n");
        tell_room(ENV(TO),"Gavin smiles happily.\n Gavin says: Thank you.\n" +
                  "Gavin says: That song has words too, but since they " +
                  "praise the brave men who tried to steal Nirach's orb, " +
                  "the song has been forbidden. The only one who still " +
                  "knows the words is my grandmother, who wrote it. She " +
                  "won't teach it to me, though. She says I'll just get " +
                  "into trouble singing resistance songs...'\n");
        state = 1;
        set_alarm(10.0,0.0,"tell_story",0);
        return 1;
    }
    else
    {
        W("Gavin smiles gratefully at you.\n");
        return 1;
    }
}

int do_dislike(string str)
{
    W("You shake your head at Gavin.\nGavin says: Well, there's no " +
      "pleasing some people.\nGavin goes hrumph and continues to play.\n");
    S(TP->QN + " shakes " + TP->QPO + " head towards Gavin. Apparently " +
      TP->QPR + " didn't like the tune.\nGavin says: Well, there's no " +
      "pleasing some people I guess. He goes hrumph and continues to " +
      "play.\n");
    return 1;
}


void tell_story(int step)
{
    switch(step)
    {
        case 0: tell_room(ENV(TO),"Gavin shrugs and says: Well, if you " +
                          "want to know more about Nirach and the Orb, you " +
                          "could always go see my grandmother. Ask her " +
                          "about the orb and tell her I sent you. She lives " +
                          "in a cottage in the forest. Look for the path " +
                          "there by the boulder and the strange bush by the " +
                          "side of the north road.\n");
                set_alarm(8.0,0.0,"tell_story",1);
          break;
        case 1: tell_room(ENV(TO),"Gavin puts his flute back into his " +
                          "mouth and starts playing again.\n");
                state = 0;
                set_alarm(3.0,0.0,"play_flute",0);
          break;
    }
}

void play_flute(int step)
{
    if(!present_player(ENV(TO)))
    {
        state = -1;
    }
    else if(!state)
    {
        switch(step)
        {
            case 0: tell_room(ENV(TO),"Gavin is playing his flute. The " +
                              "sad melody touches your heart.\n");
                    set_alarm(3.0,0.0,"play_flute",1);
              break;
            case 1: tell_room(ENV(TO),"The sweet tones of Gavin's flute " +
                              "drift out across the raging waters of the " +
                              "river...\n");
                    set_alarm(3.0,0.0,"play_flute",2);
              break;
            case 2: tell_room(ENV(TO),"You wipe a tear from your cheek as " +
                              "the last notes float away over the " +
                              "treetops...\n");
                    set_alarm(3.0,0.0,"play_flute",3);
              break;
            case 3: tell_room(ENV(TO),"Gavin stops playing for a moment. " +
                              "He smiles melancholically and asks you: Did " +
                              "you like my tune? Just nod if you did. ;)\n");
                    set_alarm(4.0,0.0,"play_flute",4);
              break;
            case 4: tell_room(ENV(TO),"Gavin starts playing again.\n");
                    set_alarm(3.0,0.0,"play_flute",0);
              break;
        }
    }
}
