//===================================================================
// Object telling messages to players flying after drinking the
// birdvial, and keeping track of when they're done flying and should
// be moved to their destination.
//===================================================================
#pragma strict_types
#include "../def.h"
inherit STD_OBJ;
inherit "/std/modules/general/identity";

string *messages = ({ "You rise ever higher into the skies.",
                      "The winds carry you higher and further away from " +
                      "where you took off.",
                      "You level out, gliding effortlessly on the winds " +
                      "towards your destination.",
                      "The world glides by below you.",
                      "As you approach your destination, you begin to " +
                      "descend.",
                      "You fly ever closer to the ground, descending in " +
                      "wide circles.",
                      "You flap your strong wings, reducing your speed, as " +
                      "you drop down towards your destination.",
                      "Your flight is over, you prepare to land."
                    });

void create_object(void);
void tell_message(int index);
int drop(void);
int get(void);

void create_object(void)
{
    set_name("_pirate_caves_flying_obj_");
    set_alarm(1.0,0.0,"tell_message",0);
    set_material("none"); //Angelwings
}

void tell_message(int index)
{
    if(index < sizeof(messages))
    {
        tell_object(ENV(TO),messages[index] + "\n");
        ++index;
        set_alarm(15.0 + itof(random(10)),0.0,"tell_message",index);
    }
    else
    {
        ENV(ENV(TO))->land(ENV(TO));
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
