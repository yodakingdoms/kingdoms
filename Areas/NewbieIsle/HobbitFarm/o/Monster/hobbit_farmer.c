// ==================================================================
// The hobbit farmer. Unkillable because the tells players about
// the quest
// ==================================================================
#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

int talking;
string *greeted;

void create_object(void);
void reset(int arg);
void init(void);
void greet(object player);
int do_help(string str);
void tell_story(int step);
int is_unkillable(void);
string unkillable_string(object attacker);

void create_object(void)
{
    set_short("Ferdirand Bumbleroot",1);
    set_long("Ferdirand Bumbleroot is a hobbit who operates the farm " +
             "that provides Hazeldown with most of the town's food. As " +
             "the major provider of such things, he's held in high regard " +
             "in the town. It is well deserved since he's good at what he " +
             "does. However, he currently has a problem with his farm. " +
             "Maybe he'd tell you about it if you would let him know " +
             "you're willing to <help> him with it?\n");
    set_name("ferdirand");
    add_id("ferdirand bumbleroot");
    add_id("hobbit");
    add_id("farmer");

    set_level(4);
    set_race("hobbit");
    set_al(300);
    add_money(100 + random(20));
    set_gender(1);

    load_chat(5,({
        "Ferdirand ponders deeply.\n",
        "Ferdirand mumbles: Everything must be perfect before Weeangel " +
        "gets here.\n",
        "Ferdirand says: Those damn crows...\n",
        "Ferdirand scratches his head.\n"
    }));

    reset(0);
}

void reset(int arg)
{
    greeted = ({});
}

void init(void)
{
    add_action("do_help","help");
    // He recognizes people who've done the quest
    if(TP->test_flag(235) && member_array(TP->QRN,greeted) == -1 && !talking)
    {
        set_alarm(1.0,0.0,"greet",TP);
        greeted += ({ TP->QRN });
    }
}

void greet(object player)
{
    if(present(player,ENV(TO)))
    {
        tell_room(ENV(TO),"Ferdirand smiles happily.\n" +
                  "Ferdirand says: Nice to see you again, " + player->QN +
                  ".\n");
    }
}

int do_help(string str)
{
    if(id(str))
    {
        if(!talking)
        {
            W("You tell Ferdirand you can help him.\n");
            S(TP->QN + " tells Ferdirand " + TP->QPR + " can help him.\n");
            talking = 1;
            set_alarm(1.0,0.0,"tell_story",0);
            return 1;
        }
        else
        {
            W("The hobbit is talking now. Listen to what he says instead.\n");
            return 1;
        }
    }
}

void tell_story(int step)
{
    switch(step)
    {
        case 0: tell_room(ENV(TO),"Ferdirand says: I have a problem. Crows " +
                          "are causing havoc in the corn field to the " +
                          "southwest.\n\n");
                set_alarm(5.0,0.0,"tell_story",1);
          break;
        case 1: tell_room(ENV(TO),"Ferdirand says: I chase them away but as " +
                          "soon as I leave the field they return. They are " +
                          "too quick for me to catch them :(\n\n");
                set_alarm(6.0,0.0,"tell_story",2);
          break;
        case 2: tell_room(ENV(TO),"Ferdirand says: I need to put a " +
                          "scarecrow in that field but I don't have one and " +
                          "I don't have time to build one now as I'm very " +
                          "busy with other things.\n\n");
                set_alarm(6.0,0.0,"tell_story",3);
          break;
        case 3: tell_room(ENV(TO),"Ferdirand says: I would be ever so " +
                          "grateful if someone would build a scarecrow " +
                          "for me and place it in the corn field. " +
                          "All the needed things can be found here on the " +
                          "farm.\n\nFerdirand goes back to his pondering.\n");
                talking = 0;
          break;
    }
}

int is_unkillable()
{
    return 1;
}

string unkillable_string(object attacker)
{
    return "Killing Ferdirand would mean the whole village of Hazeldown " +
           "will starve. You don't want that on your conscience.";
}
