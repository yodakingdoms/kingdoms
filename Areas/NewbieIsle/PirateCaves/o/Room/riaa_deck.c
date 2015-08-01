#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
string long_fun(void);
void init(void);
int do_board(string str);
int do_walk(string str);
int query_under_attack(void);

void create_object(void)
{
    set_short("The deck of the Riaa");
    set_long("#long_fun");
    set_new_light(10);
    set_skip_obvious(1);

    add_func_item("deck","#query_under_attack",({
                  "The deck of the Riaa. It seems to have been under attack",
                  "The deck of the Riaa. It seems to be under attack",
                 }));
    add_item("ship|riaa","It is a mighty ship, but now it is crippled");
    add_func_item("another ship","#query_under_attack",({
                  "Whichever ship it was that attacked the Riaa, it is long " +
                  "gone now. Looks like you've been left behind!",
                  "It looks like the feared Black Skull. It was thought the " +
                  "captain of that ship had retired, but obviously not!",
                 }));
    add_item("smoke","It is everywhere, stinging your eyes and nostrils");
    add_item("fire|fires","They're burning in what's left of the masts and " +
             "below deck");
    add_item("mast|masts","The masts are broken, only a few sails are still " +
             "hanging in what's left of them");
    add_item("sail|sails|burning sail|burning sails","They're hanging from " +
             "what's left of the masts burning");
    add_item("ropes","They look like ropes that have fallen down from the " +
             "rigging when the masts where destroyed");
    add_item("rigging","There's not a lot left of the rigging now");
    add_item("wood|broken wood|debris","Debris from destroyed bits of the " +
             "ship");
    add_item("stairs","The stairs are destroyed so you can't get to the " +
             "rudder");
    add_item("trapdoor","It is covered by debris and can't be opened. You " +
             "can't get down and anyone trapped below can't get out");
    add_item("decks|decks below","You can't get to the decks below, the " +
             "way down there is covered by debris");
    add_func_item("hook|grappling hook|rope","#query_under_attack",({
                  "",
                  "A hook with a rope tied to it. You can use that rope to " +
                  "board the ship attacking this one if you want",
                 }));
    add_item("opening|railing","There's an opening in the railing where " +
             "someone has placed a plank going out into nowhere");
    add_item("plank","You could probably walk it if you want to escape from " +
             "the ship but you doubt you would be able to get back so be " +
             "careful");

    (PCROOM + "riaa_cabin")->load_doors();

    add_sounds(30,80, ({ "You hear screams from trapped people below deck!\n",
                         "Smoke from the fires sting your eyes.\n",
                         "A burning piece of wood falls from above and " +
                         "lands inches away from you!\n",
                         "An explosion is heard from below deck and the " +
                         "ship shudders.\n" }));
    reset(0);
}

void reset(int arg)
{
    ::reset(arg);
    add_monster(PCMONSTER + "jars",1);
    add_monster(PCMONSTER + "lames",1);
}

string long_fun(void)
{
    if(query_under_attack())
    {
        return "You are on the deck of the Riaa. The ship is currently " +
               "under attack from another ship and everything is chaotic. " +
               "There's smoke everywhere from fires burning below deck and " +
               "in what's left of the masts. There are ropes and broken " +
               "wood everywhere. The stairs that once went up to the rudder " +
               "on the aft deck have been destroyed and debris covers the " +
               "trapdoor to the decks below. A grappling hook is stuck in " +
               "the railing and a rope from the other ship is tied to the " +
               "hook. There's an opening in the railing on the other side " +
               "of the deck where a plank leads out to nowhere.\n";
    }
    else
    {
        return "You are on the deck of the Riaa. The ship seems to have " +
               "been under attack from another ship and everything is " +
               "chaotic. There's smoke everywhere from fires burning below " +
               "deck and in what's left of the masts. There are ropes and " +
               "broken wood everywhere. The stairs that once went up to the " +
               "rudder on the aft deck have been destroyed and debris " +
               "covers the trapdoor to the decks below. There's not another " +
               "ship in sight as far as the eye can see. It looks as if you " +
               "have been left behind. There's an opening in the railing " +
               "on the other side of the deck where a plank leads out to " +
               "nowhere.\n";
    }
}

void init(void)
{
    ::init();
    add_action("do_board","board");
    add_action("do_walk","walk");
}

int do_board(string str)
{
    if(query_under_attack())
    {
        if(str == "ship")
        {
            W("You climb the rope over to the other ship.\n");
            TP->move_player("climbs the rope and boards the other ship",
                            PCROOM + "black_skull_deck",
                            "comes climbing the rope from the Riaa",1);
            return 1;
        }
        notify_fail("Board what?\n");
    }
}

int do_walk(string str)
{
    if(str == "plank")
    {
        if(!query_under_attack())
        {
            W("You walk the plank and fall into the water with a *SPLASH*!\n");
            S(TP->QN + " walks the plank and falls into the water with a " +
              "*SPLASH*!\n");
            make(PCOBJECT + "floating_obj",TP);
            TP->move_player("walks the plank and falls into the water with " +
                            "a *SPLASH*!",
                            PCROOM + "floating",
                            "falls into the water from above with a *SPLASH*!",
                            1);
            return 1;
        }
        W("It would probably be a better idea to board the Black Skull.\n");
        return 1;
    }
    return notify_fail("Walk what?\n");
}

int query_under_attack(void)
{
    return SHIP_OBJ->query_rope_thrown();
}
