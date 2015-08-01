#pragma strict_types
#include "../def.h"
inherit MONSTER + "goblin";

void create_object(void);
void chat_func(void);

void create_object(void)
{
    int i;
    ::create_object();
    set_short("A whining goblin fetching water from the puddle");
    set_long("A small, whining goblin fetching water from the puddle. He " +
             "doesn't seem to be enjoying splashing around in the water. " +
             "He is shivering and complaining softly and looking like " +
             "he'd rather be anywhere but here.\n");
    set_name("whining goblin");

    load_chat(5,({ "#chat_func" }));

    load_a_chat(30,({
        "Whining goblin shouts: The others know where I am, they'll " +
        "come looking for me!\n",
        "Whining goblin shouts: Take the water, just leave me alone!\n",
        "Whining goblin tries to poke you in the eye!\n",
        "Whining goblin tires to knee you, without much effect.\n",
        "Whining goblin whines.\n",
    }));

    for(i = 0; i < 1 + random(2); ++i)
    {
        make(OBJECT + "waterbottle");
    }
}

/**
* Grovels before the hideous goblin (water_goblin1) and gives water
* bottles to him when he fills them, or chats generally if the hideous
* goblin is gone.
*/
void chat_func(void)
{
    int i = random(5);
    object bottle = present("waterbottle",TO);
    object goblin = present("hideous goblin",ENV(TO));

    if(goblin)
    {
        switch(i)
        {
            default:
                if(bottle && !transfer(bottle,goblin))
                {
                    tell_room(ENV(TO),"Whining goblin has filled one " +
                              "bottle.\n" +
                              "Whining goblin gives bottle to hideous " +
                              "goblin.\n");
                    if(!present("waterbottle",TO) && !transfer(bottle,TO))
                    {
                        // We want him to keep at least one bottle all
                        // the time
                        tell_room(ENV(TO),"Hideous goblin says: This " +
                            "bottle isn't completely full.\n" +
                            "Hideous goblin gives bottle to whining " +
                            "goblin.\n" +
                            "Whining goblin complains loudly.\n");
                    }
                }
              break;
            case 1: tell_room(ENV(TO),"Whining goblin fumbles and almost " +
                              "drops a bottle.\n" +
                              "Hideous goblin yells: Useless half elf!\n");
              break;
            case 2: tell_room(ENV(TO),"Whining goblin scurries too close " +
                              "to hideous goblin.\n" +
                              "Hideous goblin kicks whining goblin in the " +
                              "groin!\n");
              break;
            case 3: tell_room(ENV(TO),"Whining goblin looks dripping wet.\n" +
                              "Hideous goblin taunts: That bath you're " +
                              "getting is as thorough as if you were in " +
                              "Kordic bathhouse heh heh!\n");
              break;
            case 4: tell_room(ENV(TO),"Whining goblin grovels before " +
                              "hideous goblin.\n" +
                              "Hideous goblin throws his head back and " +
                              "cackles with glee!\n");
              break;
        }
    }
    else
    {
        switch(i)
        {
            case 0: tell_room(ENV(TO),"Whining goblin fills another water " +
                              "bottle from the puddle.\n");
              break;
            case 1: tell_room(ENV(TO),"Whining goblin spills all the water " +
                              "from one bottle and swears horribly.\n");
              break;
            case 2: tell_room(ENV(TO),"Whining goblin complains: He can " +
                              "come fetch water himself tomorrow.\n");
              break;
            case 3: tell_room(ENV(TO),"Whining goblin spits in one of the " +
                              "water bottles.\n");
              break;
            case 4: tell_room(ENV(TO),"Whining goblin whines: Why can't " +
                              "we get water from the pond instead of " +
                              "having to come all the way here to get it?\n");
              break;
        }
    }
}
