#pragma strict_types
#include "../def.h"
inherit MONSTER + "villager_child";

void create_object(void);

void create_object(void)
{
    ::create_object();
    set_short("a child running an errand");
    set_long("Lidyr Carelyn is ten years old. He is running an errand for " +
             "his mother.\n");
    set_name("lidyr");
    add_id("boy");
    set_gender(1);
    set_walking();
    add_money(25 + random(10));

    load_chat(4,({ "The child mumbles: Now what was it that I was supposed " +
                   "to do?\n",
                   "The child says: Sorry, I don't have time to talk " +
                   "right now.\n" }));
}
