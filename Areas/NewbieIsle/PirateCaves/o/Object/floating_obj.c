//====================================================================
// Object to keep track of players floating in the water after walking
// the plank from one of the ships.
//====================================================================
#pragma strict_types
#include "../def.h"
inherit STD_OBJ;
inherit "/std/modules/general/identity";

string *messages = ({ "Someone throws a wooden chair into the water " +
                      "beside you, you cling on to it and try your best " +
                      "to stay afloat.",    
                      "The waves carry you far from the ship but you don't " +
                      "see land.",    
                      "You see a huge shape in the water below you. It " +
                      "looks as if it is circling around you.",    
                      "Suddenly you see land on the horizon.",    
                      "The current carries you closer to land, you now see " +
                      "it is a small island.",    
                      "Using the last of your energy you let go of the " +
                      "chair and swim towards the beach.",
                    });

void create_object(void);
void tell_message(int index);
int drop(void);
int get(void);

void create_object(void)
{
    set_name("_pirate_caves_floating_obj_");
    set_alarm(1.0,0.0,"tell_message",0);
    set_material("none"); //Angelwings
}

void tell_message(int index)
{
    if(index < sizeof(messages))
    {
        tell_object(ENV(TO),messages[index] + "\n");
        ++index;
        set_alarm(5.0 + itof(random(5)),0.0,"tell_message",index);
    }
    else
    {
        ENV(ENV(TO))->float_ashore(ENV(TO));
        destroy();
    }
}

int drop(void)
{
    return 1;
}

int get(void)
{
    return 1;
}
