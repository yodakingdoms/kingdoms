// Sätt det här i rummen istället
#pragma strict_types
#include "../def.h"
inherit MONSTER + "darkling_dung_guard";

void create_object(void);
void init(void);
int do_block(string str);

void create_object(void)
{
    ::create_object();
    set_aggressive(1);
}

void init(void)
{
    add_multi_action("do_block","d|down");
    ::init();
}

int do_block(string str)
{
    W("A darkling grabs you and prevents you from going down!\n");
    S(TP->QN + " tries to go down but is stopped by a darkling.\n");
    return 1;
}
