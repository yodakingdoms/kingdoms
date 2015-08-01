#pragma strict_types
#include "../def.h"
inherit STD_MOV_MONSTER;

void create_object(void);

void create_object(void)
{
    add_id("darkling");
    set_race("darkling");
    set_al(-300);
    set_time_slice(7 + random(4));
    set_gender(1);
}
