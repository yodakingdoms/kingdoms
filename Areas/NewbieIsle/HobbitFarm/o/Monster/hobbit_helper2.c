#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_short("Drido Brownlock",1);
    set_long("Drido Brownlock is a young hobbit who looks like he enjoys " +
             "food more than work as he has quite a tummy. He lives in " +
             "Hazeldown and walks here and back each day to work at the " +
             "farm, a walk he doesn't enjoy. He's currently busy organising " +
             "the haybales in the loft.\n");
    set_name("drido");
    add_id("drido brownlock");
    add_id("hobbit");

    set_level(2);
    set_hp(30);
    set_unarmed(1);
    set_race("hobbit");
    set_al(200);
    add_money(random(25));
    set_gender(1);

    load_chat(3,({
        "Drido lifts a haybale and puts it on top another one.\n",
        "Drido mumbles: The loft is almost full, we'll have to take some " +
        "of the hay to Hazeldown.\n",
        "Drido says: I need a rest.\n",
        "Drido wipes some sweat from his brow.\n",
        "Drido notes: Some of these haybales would be nice to build a " +
        "scarecrow with.\n",
    }));
}
