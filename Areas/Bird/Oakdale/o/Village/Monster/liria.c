#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_woman";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a woman who's shopping");
    set_long("Liria Aragel is a pretty woman with blond hair and blue eyes. " +
             "She's at the square buying groceries.\n");
    set_name("liria");

    make(OBJECT + "basket");

    load_chat(4,({ "Liria asks: How much for these carrots?\n" }));
}
