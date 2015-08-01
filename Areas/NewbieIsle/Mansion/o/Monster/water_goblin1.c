#pragma strict_types
#include "../def.h"
inherit MONSTER + "goblin";

void create_object(void);
void chat_func(void);

void create_object(void)
{
    int i;
    ::create_object();
    set_short("A hideous goblin fetching water from the puddle");
    set_long("A goblin apparently sent here to fetch water from " +
             "the puddle. He smells bad and is extremely ugly, even " +
             "by goblin standards. He scurries about nervously and " +
             "impatiently and gives you the impression he feels he does " +
             "not deserve to be sent on simple errands such as this.\n");
    set_name("hideous goblin");

    load_chat(5,({ "#chat_func" }));

    load_a_chat(30,({
        "Goblin shouts: I'm hideous, you are wimpy!\n",
        "Goblin shouts: You're not taking our water!\n",
        "Goblin snarls hideously!\n",
    }));

    for(i = 0; i < 3 + random(2); ++i)
    {
        make(OBJECT + "waterbottle");
    }
}

/**
* Harasses the whining goblin (water_goblin2) and gives water bottles to
* him to fill, or chats generally if the whining goblin is gone.
*/
void chat_func(void)
{
    int i = random(5);
    object bottle = present("waterbottle",TO);
    object goblin = present("whining goblin",ENV(TO));

    if(goblin)
    {
        switch(i)
        {
            case 0:
                if(bottle && !transfer(bottle,goblin))
                {
                    tell_room(ENV(TO),"Hideous goblin spills all the water " +
                              "from one bottle and swears horribly.\n" +
                              "Hideous goblin growls: Fill this again.\n" +
                              "Hideous goblin gives water bottle to " +
                              "whining goblin.\n" +
                              "Whining goblin grumbles angrily.\n");
                }
              break;
            case 1: tell_room(ENV(TO),"Hideous goblin orders: Hurry up " +
                              "you useless piece of filth, I don't want " +
                              "to be here all day.\n" +
                              "Whining goblin grumbles: Yes sir, I'm doing " +
                              "my best sir.\n");
              break;
            case 2: tell_room(ENV(TO),"Hideous goblin bonks whining goblin " +
                              "on his head.\n" +
                              "Whining goblin whines loudly.\n");
              break;
            case 3: tell_room(ENV(TO),"Hideous goblin pushes whining " +
                              "goblin into the puddle.\n" +
                              "Whining goblin groans loudly.\n");
              break;
            case 4: tell_room(ENV(TO),"Hideous goblin fingers his weapon " +
                              "threateningly at whining goblin.\n" +
                              "Whining goblin starts working faster.\n");
              break;
        }
    }
    else
    {
        switch(i)
        {
            case 0: tell_room(ENV(TO),"Hideous goblin fills another water " +
                              "bottle from the puddle.\n");
              break;
            case 1: tell_room(ENV(TO),"Hideous goblin spills all the water " +
                              "from one bottle and swears horribly.\n");
              break;
            case 2: tell_room(ENV(TO),"Hideous goblin snarls: He can come " +
                              "fetch water himself tomorrow.\n");
              break;
            case 3: tell_room(ENV(TO),"Hideous goblin spits in one of the " +
                              "water bottles.\n");
              break;
            case 4: tell_room(ENV(TO),"Hideous goblin snarls: Why can't " +
                              "we get water from the pond instead of " +
                              "having to come all the way here to get it?\n");
              break;
        }
    }
}
