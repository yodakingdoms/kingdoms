#pragma strict_types
#include "../def.h"
inherit MONSTER + "goblin";

void create_object(void);
void init(void);
int do_smell(string str);

void create_object(void)
{
    ::create_object();
    set_short("A smelly goblin searching the debris");
    set_long("A goblin that smells worse than any goblin you've ever " +
             "seen before. He's searching through the debris but doesn't " +
             "look as if he's putting too much effort into his work.\n");
    add_id("smelly goblin");

    load_chat(5,({ "Goblin searches through the debris.\n",
                   "Goblin mutters: There's nothing here, why can't we " +
                   "just go home?\n"
                }));

    load_a_chat(30,({
        "Goblin shouts: Take the wagon if you want, I don't care!\n",
        "Goblin shouts: Leave me alone!\n",
        "Goblin smells hideously!\n",
    }));
}

void init(void)
{
    add_action("do_smell","smell");
}

int do_smell(string str)
{
    W("All the other smells in this room are overwhelmed by the horrid " +
      "stench coming from the smelly goblin.\n");
    S(TP->QN + " sniffs the air and looks repulsed.\n");
    return 1;
}
