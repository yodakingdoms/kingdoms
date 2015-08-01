//===================================================================
// Smoke made when you ignite the powder and it blows up. This object
// will be made in the room that's blown up and all adjacent rooms.
// It'll prevent players to see for 5 seconds, then it will disappear.
// It's just a special effect, really.
//===================================================================
#pragma strict_types
#include "../def.h"
inherit STD_OBJ;

string *commands = ({ "cough","sneeze","whine","groan","cry" });
string short_desc; // Store the short desc of the room so we can set
                   // it back when smoke clears
string long_desc;  // Ditto for long desc
int skip_obvious;  // And the skip_obvious status

void create_object(void);
void fill_room(void);
void annoy(int count);
void clear(void);

void create_object(void)
{
    set_alarm(1.0,0.0,"annoy",0);
    set_alarm(0.0,0.0,"fill_room");
    set_material("none"); //Angelwings
}

void fill_room(void)
{
    // Need an environment for this, so put it here and
    // call it with an alarm instead of doing it in create_object()
    tell_room(ENV(TO),"A thick, black smoke fills the room.\n");
    short_desc = ENV(TO)->query_short();
    long_desc = ENV(TO)->query_long_desc();
    skip_obvious = ENV(TO)->query_skip_obvious();

    ENV(TO)->set_short("A smoke filled room");
    ENV(TO)->set_long("The room is filled with a thick, black smoke. " +
                      "You can't see anything through it!\n");
    ENV(TO)->set_skip_obvious(1);
}

void clear(void)
{
    tell_room(ENV(TO),"The smoke clears and you can see again.\n");
    // Set the long, short and skip_obvious back to what it was before
    ENV(TO)->set_short(short_desc);
    ENV(TO)->set_long(long_desc);
    ENV(TO)->set_skip_obvious(skip_obvious);
    destroy();
}

void annoy(int count)
{
    int i = 0;
    object *players = ENV(TO)->query_players_here();
    if(count >= 5)
    {
        clear();
    } else {
        // Smoke is irritating. It only does this for 5 seconds
        for(i = 0; i < sizeof(players); ++i)
        {
            if(players[i]->query_con() < 10 + random(20))
            {
                players[i]->command(commands[random(sizeof(commands))]);
            }
        }
        set_alarm(1.0,0.0,"annoy",++count);
    }
}
