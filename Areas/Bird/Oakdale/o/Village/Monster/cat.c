#pragma strict_types
#include "../def.h"
inherit STD_MOV_MONSTER;

void create_object(void);

void create_object(void)
{
    set_name("cat");
    add_id("kitten");
    add_id("small cat");
    set_short("a small cat");
    set_long("A cute, cuddly little kitten. Looking into its eyes just " +
             "melts your heart.\n");
    set_level(1);
    set_race("cat");
    set_hp(30);
    set_al(200);
    set_gender(2);
    set_skill("unarmed",10);
    set_time_slice(7 + random(4));
    set_walking();

    load_chat(30,({ "The kitten purrs contentedly.\n",
                    "The kitten licks its paws.\n" }));
    load_a_chat(30,({ "The poor little kitten whimpers loudly.\n" }));
}
