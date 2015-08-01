// ==================================================================
// A pirate bowling in the bowling hall.
// ==================================================================
#pragma strict_types
#include "../def.h"
inherit PCMONSTER + "pirate";

void create_object(void);
void bowl(void);

void create_object(void)
{
    ::create_object();
    // Want different descs for this one
    set_short("A drunk pirate playing a game");
    set_long("A drunk pirate playing a game where he's trying to " +
             "roll a round, black ball towards a bunch of bottles " +
             "in the other end of the room.\n");
    add_id("drunk pirate");
    // Don't want this one to walk
    stop_walking();
    // And want different chats
    load_chat(15,({
        "Pirate hums: Just watch me get a strike on the next one, arr.\n",
        "Pirate taps his foot impatiently waiting for the monkey to set " +
        "up the bottles for his next shot.\n",
        "Pirate wobbles around.\n",
    }));

    set_alarm(2.0,20.0,"bowl");
}

void bowl(void)
{
    object ball = present("_pirate_quest_cannonball_",ENV(TO));
    if(ball && !present("_pirate_quest_cannonball_",TO))
    {
        tell_room(ENV(TO),"Drunk pirate picks up a round stone from the " +
                  "floor.\n");
        move_object(ball,TO);
    }
    if(present("_pirate_quest_cannonball_",TO))
    {
        tell_room(ENV(TO),"Drunk pirate aims as carefully as his drunken " +
                  "state allows him to.\n");
        init_command("roll stone");
    }
    else
    {
        tell_room(ENV(TO),"Drunk pirate taps his foot impatiently.\n" +
              "Drunk pirate trips on his own two feet and falls FLAT on " +
              "his face!\n" +
              "Drunk pirate mutters: Arrr, damn monkey, how do I get him " +
              "to harrry up, arr?\n");
    }
}