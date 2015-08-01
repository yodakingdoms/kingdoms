#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_man";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a man with a bandaged leg");
    set_long("Dylon Aragel is a lumberjack. He's at home resting after an " +
             "accident in the forest that nearly cost him his leg.\n");
    set_name("dylon");

    make(ARMOUR + "bandage");
    init_command("wear bandage");

    load_chat(4,({ "The man says: You should leave while you still can. " +
                   "There is nothing you can do for us.\n",
                   "The man hums: I'm a lumberjack and I'm okay...\n",
                   "The man says: Nirach's guards took our sheep last " +
                   "week.\n" }));
}
