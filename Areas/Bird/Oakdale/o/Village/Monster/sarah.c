#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_woman";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a sewing woman");
    set_long("Sarah Sylifin is a pretty lady with dark hair and blue eyes. "+
             " She is sewing clothes, something she is very good at.\n");
    set_name("sarah");

    //make(OBJECT + "needle");
    //make(ARMOUR + "shirt");

    load_chat(4,({ "Sarah sews, trying to repair the shirt.\n",
                   "Sarah holds the shirt up, examining it.\n" }));
}
