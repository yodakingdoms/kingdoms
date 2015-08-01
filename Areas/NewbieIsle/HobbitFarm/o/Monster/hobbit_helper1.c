#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

void create_object(void);

void create_object(void)
{
    set_short("Seredic Deepdelver",1);
    set_long("Seredic Deepdelver is a young, strong hobbit who is helping " +
             "Ferdirand to run the farm. He lives in Hazeldown and walks " +
             "here and back each day. Right now he's trying to deal with " +
             "the rodents threatening to cause trouble in the pumpkin " +
             "field.\n");
    set_name("seredic");
    add_id("seredic deepdelver");
    add_id("hobbit");

    set_level(2);
    set_hp(30);
    set_unarmed(1);
    set_race("hobbit");
    set_al(200);
    add_money(random(25));
    set_gender(1);

    load_chat(3,({
        "Seredic tends to the pumpkins.\n",
        "Seredic mumbles: These pumpkins will have to grow a lot before " +
        "I can take them to Hazeldown to sell them.\n",
        "Seredic says: I need to get rid of these damn rodents before they " +
        "eat all the pumpkins.\n",
        "Seredic tries to catch a rodent hiding under the leaves.\n",
        "Seredic suggests: This pumpkin would make a nice head for a " +
        "scarecrow.\n",
    }));
}
