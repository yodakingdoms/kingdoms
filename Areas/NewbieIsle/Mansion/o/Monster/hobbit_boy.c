// ==================================================================
// A little hobbit boy who went to the mansion to explore and who
// got caught in the cellar with no more heals.
// ==================================================================
#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

int state; // 0 = waiting, 1 = talking, 2 = following
           // 3 = checking for goblin in the other room
           // 4 = Quest done, doing finishing speech things
string helper; // Name of player who's leading the hobbit away
object torch;

void create_object(void);
void init(void);
void my_reset(void);
void light_torch(void);
int do_comfort(string str);
int do_help(string str);
void tell_story(int step);
void catch_tell(string str);
void follow_helper(string exit);
void end_quest(int step);
int is_unkillable(void);
string unkillable_string(object attacker);

void create_object(void)
{
    set_short("A scared little hobbit boy");
    set_long("A scared little hobbit boy who looks bruised and battered. " +
             "He's obviously been in a fight and although he survived " +
             "he came out worse for wear. He's shaking with fear, maybe " +
             "you could <comfort> him and ask him what's wrong?\n");
    set_name("hobbit");
    add_id("boy");
    add_id("hobbit boy");

    set_level(2);
    set_race("hobbit");
    set_al(300);
    add_money(100 + random(20));
    set_gender(1);

    load_chat(5,({
        "The hobbit sobs quietly.\n",
        "The hobbit whispers: Please don't hurt me.\n",
        "The hobbit tries to stop the bleeding from a wound.\n"
    }));

    torch = make(STD_TORCH);
    init_command("light torch");
}

void init(void)
{
    add_action("do_comfort","comfort");
    add_action("do_help","help");

    // See wounded_goblin.c
    if(query_hp() > 40)
    {
        set_this_player(0);
        reduce_hit_point(40);
        stop_fight();
    }
    set_alarm(1.0,0.0,"light_torch");
}

void my_reset(void)
{
    state = 0;
    helper = 0;
}

void light_torch(void)
{
    object torch = present("torch",TO);
    if(!torch)
    {
        torch = make(STD_TORCH);
    }
    if(!torch->query_lighted())
    {
        init_command("light torch");
    }
}

int do_comfort(string str)
{
    if(str == "boy" || str == "hobbit" || str == "hobbit boy")
    {

        if(!state)
        {
            W("You comfort the hobbit. He looks up and starts talking.\n");
            S(TP->QN + " comforts the hobbit. The hobbit looks up and " +
              "starts talking.\n");
            state = 1;
            set_alarm(1.0,0.0,"tell_story",0);
            return 1;
        }
        else if(state == 1)
        {
            W("The hobbit is talking now. Listen to what he says instead.\n");
            return 1;
        }
    }
}

int do_help(string str)
{
    if(str == "boy" || str == "hobbit" || str == "hobbit boy")
    {

        if(!state)
        {
            W("You tell the hobbit you will help him.\n" +
              "The hobbit says: Thank you! Lead the way back and make " +
              "sure there are no goblins in the way, and I will follow!\n");
            S(TP->QN + " tells the hobbit " + TP->QPR + " will help him.\n" +
              "The hobbit says: Thank you! Lead the way back and make " +
              "sure there are no goblins in the way, and I will follow!\n");
            state = 2;
            helper = TP->QN;
            (ROOM + "house_cellar_room")->start_quest();
            set_alarm(900.0,0.0,"my_reset");
            return 1;
        }
        else if(state == 1)
        {
            W("The hobbit is talking now. Listen to what he says instead.\n");
            return 1;
        }
        else
        {
            W("Hobbit tells you: I'm already being helped by " + helper +
              ":)\n");
            return 1;
        }
    }
}

void tell_story(int step)
{
    switch(step)
    {
        case 0: tell_room(ENV(TO),"The hobbit says: Thank you *sniff* I " +
                          "came here to look for some nice treasure to give " +
                          "to my friend, but the goblins surprised me.\n\n");
                set_alarm(5.0,0.0,"tell_story",1);
          break;
        case 1: tell_room(ENV(TO),"The hobbit says: I managed to escape " +
                          "here and fight off the goblins with my torch " +
                          "but I'm hurt and I have no more fastpotions " +
                          ":(\n\n");
                set_alarm(6.0,0.0,"tell_story",2);
          break;
        case 2: tell_room(ENV(TO),"The hobbit says: Now I'm trapped down " +
                          "here. I need someone to help me and lead me " +
                          "back to my friend and protect me from the " +
                          "goblins on the way.\n\n");
                set_alarm(6.0,0.0,"tell_story",3);
          break;
        case 3: tell_room(ENV(TO),"The hobbit says: Will you help me? " +
                          "Please help me. Pleeease won't you help me?\n" +
                          "Hobbit gives you puppy dog eyes.\n\n");
                state = 0;
          break;
    }
}

void catch_tell(string str)
{
    string exit;

    // Setting state to 3 during the delay between when the player
    // leaves and the hobbit follows or complains about goblins in
    // the way prevents the hobbit from getting confused if the player
    // runs in and out of the room
    if(state == 2 && sscanf(str,helper + " leaves %s.",exit) == 1)
    {
        state = 3;
        set_alarm(1.0,0.0,"follow_helper",exit);
    }
    else if(state == 2 &&
            sscanf(str,helper + " grabs the %s and climbs up the " +
                       "side of the gully.",exit) == 1)
    {
        state = 3;
        set_alarm(1.0,0.0,"follow_helper","climb stones");
    }
}

void follow_helper(string exit)
{
    object girl;

    if(ENV(TO)->query_exit(exit) &&
       present("goblin",find_object(ENV(TO)->query_exit(exit))))
    {
        find_player(lower_case(helper))->catch_tell("Hobbit tells you: " +
                           "There are goblins that way! :(\n");
    }
    else
    {
        init_command(exit);
        girl = present("_mansion_quest_hobbit_girl_",ENV(TO));
        if(girl)
        {
            state = 4;
            // Set girl state so she can't tell her story while the
            // quest is ending
            girl->set_state(2);
            set_alarm(1.0,0.0,"end_quest");
        }
    }
    if(state == 3)
    {
        state = 2;
    }
}

void end_quest(int step)
{
    object girl = present("_mansion_quest_hobbit_girl_",ENV(TO));
    object player = find_player(lower_case(helper));

    switch(step)
    {
        case 0: tell_room(ENV(TO),"Hobbit boy screams with joy!\n" +
                                  "Hobbit girl screams with joy!\n");
                if(player)
                {
                    (OBJECT + "mansion_quest_obj")->quest_solved(player,1);
                    write_file(QUEST_LOG,C(player->QRN) + " solved the " +
                               "quest at level " + player->query_level() +
                               " Time: " + ctime(time()) + "\n");
                }
                girl->load_chat(1,({ "" }));
                load_chat(1,({ "" }));
                set_alarm(3.0,0.0,"end_quest",1);
          break;
        case 1: tell_room(ENV(TO),"Hobbit girl exclaims: I was so worried! " +
                                  "Promise you'll never go down there " +
                                  "again!\n" +
                                  "Hobbit boy hangs his head in shame.\n" +
                                  "Hobbit boy says: I promise.\n");
                set_alarm(6.0,0.0,"end_quest",2);
          break;
        case 2: tell_room(ENV(TO),"Hobbit girl says: Thank you for " +
                          "bringing him back to me, " + helper + ". " +
                          "Goodbye!\n" +
                          "Hobbit boy agrees wholeheartedly with hobbit " +
                          "girl.\n" +
                          "Hobbit boy and hobbit girl wave happily.\n");
                set_alarm(6.0,0.0,"end_quest",3);
          break;
        case 3: tell_room(ENV(TO),"Hobbit girl dances down the path " +
                          "toward Hazeldown.\n" +
                          "Hobbit boy dances down the path toward " +
                          "Hazeldown.\n");
                girl->destroy();
                (OBJECT + "mansion_quest_obj")->my_quest_solved();
                move_player("x",SYS_DESTRUCT);
          break;
    }
}

int is_unkillable()
{
    return 1;
}

string unkillable_string(object attacker)
{
    return "You feel bad for the scared little hobbit and decide you can't " +
           "attack him.";
}
