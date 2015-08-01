//===================================================================
// Gunpow^H^H^H^HMagic powder used to fire the cannons for the piracy
// quest. It's also has some pretty nifty other uses, if LAW agrees.
// You get powder by pouring it from a barrel (magic_powder_barrel.c)
// found in lev1_gunpowder_room. The barrel has 10 charges. It can be
// a pk toy I guess but the one using it will take as much of a
// beating as the victim(s). A nonpk use for it can be dealing with
// troublesome blocking monsters. It can't be used in no_fight rooms
// and unkillable/no_flee monsters will not be blown away
//===================================================================
#pragma strict_types
#include "../def.h"
inherit STD_STDOBJ;
inherit STD_LORE;
inherit CHECK_FIRE_MODULE;
inherit "/std/modules/general/identity";
inherit "/std/modules/general/description";
inherit "/std/modules/general/weight";

int wet; // This is set by the barrel if you pour the powder out
         // in a sea/underwater room

void create_object(void);
void init(void);
int get(string str);
void set_wet(int is_wet);
int do_ignite(string str);
void explode(object igniter);
void throw_object(object thing);
string opposite_dest_dir(string str);

void create_object(void)
{
    set_name("powder");
    add_id("black powder");
    add_id("magic powder");
    add_id("pile");
    set_short("A small pile of black powder");
    set_long("A small pile of black powder. The powder looks dry and has " +
             "a funny smell.\n");
    set_weight(1);

    add_property("magic");

    add_lore("You've heard stories about pirates using magic black powder " +
             "in some way when they capture ships.\n",1);
    add_lore("You think the pirates use the powder to fire missiles at " +
             "other ships. You wonder what would happen if you ignited " +
             "the powder.\n",10);
    set_material("magic"); //Angelwings
}

void init(void)
{
   add_multi_action("do_ignite","ignite|light");
}

void set_wet(int is_wet)
{
    wet = is_wet;
    set_long("The powder is wet and doesn't look interesting at all.\n");
}

int get(string str)
{
    notify_fail("You try to take the powder but it slips through your " +
                "fingers and back into a pile on the floor.\n");
}

int do_ignite(string str)
{
    int i;
    object *inventory = all_inventory(TP);

    if(wet)
    {
        return notify_fail("The powder is wet and can't be ingnited.\n");
    }
    if(str == "powder")
    {
        if(query_can_light_powder(TP))
        {
            if(!ENV(TP)->query_property("no_fight"))
            {
                W("You bend down and ignite the black powder.\n");
                S(TP->QN + " bends down and ignites the black powder on the " +
                  "ground.\n");
                explode(TP);
                return 1;
            }
            else
            {
                W("This room is too peaceful for you to do that.\n");
                return 1;
            }
        }
        W("You need some sort of fire to ignite the powder.\n");
        S(TP->QN + " bends down to study the powder.\n");
        return 1;
    }
    else if(query_verb() == "ignite")
    {
        return notify_fail("Ignite what?\n");
    }
    // Don't want to stop lighting other things here
    return 0;
}

void explode(object igniter)
{
    int i,mass;
    string junk,*exits = ENV(TO)->query_dest_dir();
    object *things = all_inventory(ENV(TO));
    object *players = users();

    set_this_player(igniter);

    tell_room(ENV(TO),"\n" +
                      "K  K  AAA  BBB   OOO   OOO  M   M ! !\n" +
                      "K K  A   A B  B O   O O   O MM MM ! !\n" +
                      "KK   AAAAA BBB  O   O O   O M M M ! !\n" +
                      "K K  A   A B  B O   O O   O M   M    \n" +
                      "K  K A   A BBB   OOO   OOO  M   M ! !\n\n");

    for(i = 0; i < sizeof(exits); ++i)
    {
        tell_room(exits[i],"KABOOOOOOOOMMMMMMMM!!!!!!!!!!!!!\n" +
                  "A loud explosion is heard from " +
                  opposite_dest_dir(exits[++i]) + "!\n");
    }

    if(igniter)
    {
        write_file(POWDER_LOG,"\n" + ctime(time()) +": " + C(TP->QRN) +
                   " lit the powder in:\n                          " +
                   name_file(ENV(TP)) + "\n");
    }
    else
    {
        write_file(POWDER_LOG,"\n" + ctime(time()) +": Powder combusted " +
                   "spontaneously in:\n                          " +
                   name_file(ENV(TO)) + "\n");
    }
    // Let all players in the same area but not in adjacent room hear the
    // explosion from somewhere as well
    for(i = 0; i < sizeof(players); ++i)
    {
        if(!present(players[i],ENV(TO)) &&
           member_array(name_file(ENV(players[i])),exits) == -1 &&
           ENV(TO)->query_area_name() == ENV(players[i])->query_area_name())
        {
            tell_object(players[i],"KABOOM!!\n" +
                        "A loud explosion is heard from somewhere in the " +
                        "area.\n");
        }
    }

    for(i = 0; i < sizeof(things); ++i)
    {
        // Stat check vs con & siz for living things. The bigger and tougher
        // you are the less risk you have of being thrown out of the room
        // by the explosion. The playing setting it off will always be thrown
        if(living(things[i]))
        {
            write_file(POWDER_LOG,"\n                          " +
                       things[i]->short() + " (" + things[i]->QRN + ")\n" +
                       "                          " + name_file(things[i]) +
                       "\n                          Con: " +
                       things[i]->query_con() + " Siz: " +
                       things[i]->query_siz() + "\n");

            mass = things[i]->query_con() + things[i]->query_siz();
            if(things[i] == TP || mass < 25 + random(25))
            {
                // We'll be nice and not blow away unkillable and/or
                // no_flee monsters even if they are puny
                if(!things[i]->is_unkillable() &&
                   !things[i]->query_property("no_flee"))
                {
                    throw_object(things[i]);
                }
            }
            // Players not thrown will fall over or at least wobble, depending
            // on how big they are
            else if(query_interactive(things[i]))
            {
                if(mass < 50)
                {
                    tell_object(things[i],"The force of the explosion " +
                                "knocks you off your feet!\n");
                    things[i]->command("trip");
                    things[i]->add_temporary_penalty(5 + random(5));
                }
                else
                {
                    tell_object(things[i],"The force of the explosion " +
                                "almost knocks you off your feet!\n");
                    things[i]->command("wobble");
                }
            }
        }
        // If it is an object and fragile, it is destroyed instead of thrown
        else if(things[i]->query_property("fragile"))
        {
            tell_room(ENV(TO),C(things[i]->short()) + " shatters from the " +
                      "force of the explosion!!!\n");
            things[i]->destroy();
        }
        // We only want to blow things that aren't stuck out of the room, it
        // would be pretty silly to blow away boards and things like that
        else if(things[i]->get())
        {
            throw_object(things[i]);
        }
    }

    // Make smoke in this and all adjacent rooms (as long as they
    // are not water/under water rooms)
    make(PCOBJECT + "magic_powder_smoke",ENV(TO));
    for(i = 0; i < sizeof(exits); ++i)
    {
        if(!exits[i]->query_property("water") &&
           !exits[i]->query_property("under_water"))
        {
            make(PCOBJECT + "magic_powder_smoke",exits[i]);
        }
        ++i;
    }
    destroy();
}

/**
* Throws an object into a random adjacent room.
*/
void throw_object(object thing)
{
    string *exits = ENV(TO)->query_dest_dir();
    int rand;
    object room;

    // Skip the throwing thing if the room doesn't have any exits
    if(sizeof(exits) <= 0) return;

    rand = (random(sizeof(exits) / 2) * 2);
    room = find_object(exits[rand]);

    write_file(POWDER_LOG,"                          Was thrown " +
               exits[rand + 1] + " out of the room.\n");

    if(query_interactive(thing))
    {
        tell_object(thing,"The force of the explosion throws you " +
                    exits[rand + 1] + " out of the room!\n");
        thing->move_player("is thrown " + exits[rand + 1] + " out of the " +
                           "room by the force of the explosion!",
                           room,
                           "comes flying in from " +
                           opposite_dest_dir(exits[rand + 1]) + "!",1);
    }
    else if(!transfer(thing,room))
    {
        tell_room(ENV(TO),C(thing->short()) + " is thrown " +
                  exits[rand + 1] + " out of the room by the force of the " +
                  "explosion!\n");
        tell_room(room,C(thing->short()) + " comes flying in from " +
                  opposite_dest_dir(exits[rand + 1]) + "!\n");
    }
    // Monsters can't see the messages or get temps (yet) but we want
    // the land on the floor/ground/water things to be seen for both
    // players and monsters so we do living() instead of
    // query_interactive() here
    if(living(thing))
    {
        if(ENV(thing)->query_property("water") ||
           ENV(thing)->query_property("under_water"))
        {
            tell_object(thing,"You land in the water with a *SPLASH*!\n");
            tell_room(ENV(thing),thing->QN + " lands in " +
                      "the water with a *SPLASH*!\n",thing);
            thing->add_temporary_penalty(5 + random(10));
        }
        else
        {
            if(ENV(thing)->query_property("indoors"))
            {
                tell_object(thing,"You land on the floor with a *THUD*!\n");
                tell_room(ENV(thing),thing->QN + " lands on " +
                          "the floor with a *THUD*!\n",thing);
            }
            else
            {
                tell_object(thing,"You land on the ground with a *THUMP*!\n");
                tell_room(ENV(thing),thing->QN + " lands on " +
                          "the ground with a *THUMP*!\n",thing);
            }
            thing->add_temporary_penalty(25 + random(25));
        }
    }
}

/**
* Returns the opposite direction to the one given. This functionality
* might be available elsewhere but I don't know where if that's the
* case so here it is.
*/
string opposite_dest_dir(string str)
{
    switch(str)
    {
        case "north": return "the south";
        case "east": return "the west";
        case "south": return "the north";
        case "west": return "the east";

        case "northeast": return "the southwest";
        case "southeast": return "the northwest";
        case "southwest": return "the northeast";
        case "northwest": return "the southeast";

        case "up": return "below";
        case "down": return "above";
        // Other exits are rare enough that we can just use 'somewhere'
        default: return "somewhere";
    }
}
