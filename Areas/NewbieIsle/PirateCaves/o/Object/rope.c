#pragma strict_types
#include "../def.h"
inherit STD_ROPE;

void create_object(void)
{
    // STD_ROPE uses reset to set its creation stuff. Call that first
    // and set our own short/long after that
    reset(0);

    set_short("A worn rope");
    set_long("A worn rope that's almost rotten. You think you might still " +
             "be able to use it for a while though.\n");
}
