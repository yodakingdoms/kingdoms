#pragma strict_types
#include "../def.h"
inherit STD_ROPE;

void create_object(void)
{
    // Call reset in std_rope first and set our special things after that
    reset(0);

    set_short("A rope with a hook");
    set_long("A rope with a hook tied to one end. It looks as if it could " +
             "be used to throw at other ships to catch them and swing " +
             "across to board them when plundering on the high seas.\n");
    set_material("plant"); //Added by angelwings 20040905
}

int id(string str)
{
    if(str == "_pirate_quest_grappling_rope_")
    {
        return 1;
    }
    return ::id(str);
}
