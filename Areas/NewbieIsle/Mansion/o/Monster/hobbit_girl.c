// ==================================================================
// A little hobbit girl waiting for the hobbit friend who's gone
// to the mansion to come back. Part of the quest in the area.
// ==================================================================
#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

int state; // 0 = waiting, 1 = talking, 2 = doing the quest end thing

void create_object(void);
void init(void);
int do_ask(string str);
void tell_story(int step);
void set_state(int arg);
int is_unkillable(void);
string unkillable_string(object attacker);

void create_object(void)
{
    set_short("A sad little hobbit girl");
    set_long("A sad little hobbit girl who seems very nervous about " +
             "something. She's sobbing softly and looking down the " +
             "gully to the east as if she's waiting for someone. Maybe " +
             "you could ask her what's wrong?\n");
    set_name("hobbit");
    add_id("girl");
    add_id("hobbit girl");
    add_id("_mansion_quest_hobbit_girl_");

    set_level(2);
    set_race("hobbit");
    set_al(300);
    add_money(100 + random(20));
    set_gender(2);

    load_chat(10,({
        "The hobbit sobs quietly.\n",
        "The hobbit looks nervous.\n",
        "The hobbit mumbles: He's been gone too long now...\n",
        "The hobbit stares down the gully to the east.\n"
    }));
}

void init(void)
{
    add_action("do_ask","ask");
}

int do_ask(string str)
{
    string junk;
    str = lower_case(str);
    if(!str ||
       sscanf(str,"hobbit%s",junk) == 1 ||
       sscanf(str,"girl%s",junk) == 1 ||
       sscanf(str,"hobbit girl%s",junk) == 1)
    {
        if(!state)
        {
            W("You ask the hobbit girl what's wrong.\n");
            S(TP->QN + " asks the hobbit girl what's wrong.\n");
            state = 1;
            set_alarm(1.0,0.0,"tell_story",0);
            return 1;
        }
        else if(state == 1)
        {
            W("The girl is talking now, just listen.\n");
            return 1;
        }
    }
    return 0;
}

void tell_story(int step)
{
    switch(step)
    {
        case 0: tell_room(ENV(TO),"The hobbit says: My friend went down " +
                          "the gully to find me a present from the " +
                          "abandoned mansion down there.\n\n");
                set_alarm(5.0,0.0,"tell_story",1);
          break;
        case 1: tell_room(ENV(TO),"The hobbit says: I told him there are " +
                          "rumours of goblins being there but he didn't " +
                          "listen. He's been gone for a long time now " +
                          ":(\n\n");
                set_alarm(6.0,0.0,"tell_story",2);
          break;
        case 2: tell_room(ENV(TO),"The hobbit says: I'm so worried.\n" +
                          "Hobbit girl sniffs sadly.\n");
                set_alarm(6.0,0.0,"tell_story",3);
          break;
        case 3: tell_room(ENV(TO),"The hobbit says: I would be ever so " +
                          "grateful if you could go there and find him and " +
                          "bring him back here safely.\n" +
                          "Hobbit girl looks at you with hope in her eyes.\n");
                state = 0;
          break;
    }
}

void set_state(int arg)
{
    state = arg;
}

int is_unkillable()
{
    return 1;
}

string unkillable_string(object attacker)
{
    return "You feel bad for the sad little hobbit and decide you can't " +
           "attack her.";
}
