//====================================================================
// Woody the magic powder barrel. He is a living barrel that contains
// magic powder players can use for many different things. One of them
// is firing the cannons for the piracy quest, but he's not totally
// useless even after players complete the quest. If a player idles
// with him he'll leave, jump around the mud until some other player
// takes care of him.
//====================================================================
#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

// How many piles worth of powder are left in the barrel
int charges;

// Things Woody says and/or does every now and then
string *chats = ({ "Woody wiggles nervously.",
                   "Woody shakes vigorously.",
                   "Woody says: Let's blow something up!",
                   "Woody says: Light fuse and run away!" });

void create_object(void);
void init(void);
string long_fun(void);
int can_get_and_put(void);
int do_pour(string str);
void check_idle(void);
void chat(void);
void wander(void);
mixed query_prevent_login(void);
string opposite_dest_dir(string str);

void create_object(void)
{
    set_name("barrel");
    add_id("woody");
    add_id("magic barrel");
    add_id("_pirate_quest_powder_barrel_");
    set_short("Woody, the magic barrel");
    set_long("#long_fun");
    set_value(50);
    set_weight(4);

    charges = 5;
    // Check to see if Woodys current owner is idle every 10 minutes
    set_alarm(600.0,600.0,"check_idle");
    // Woody considers doing or saying something every minute
    set_alarm(1.0,60.0,"chat");
    // Woody tries to move around every minute
    set_alarm(1.0,60.0,"wander");
    set_material("oak"); //Angelwings
}

void init(void)
{
    add_action("do_pour","pour");
}

string long_fun(void)
{
    string my_long = "Woody is a small magic wooden barrel. The main thing " +
                     "that sets him apart from normal barrels is that he " +
                     "lives and talks.\n";
    switch(charges)
    {
        case 5:
            my_long += "Woody is full of some strange looking black " +
                       "powder. Maybe you could pour some of it on the " +
                       "ground?\n";
          break;
        case 4:
            my_long += "Woody is almost full of some strange looking " +
                       "black powder. Maybe you could pour some of it on " +
                       "the ground?\n";
          break;
        case 3:
            my_long += "Woody is half full of some strange looking black " +
                       "powder. Maybe you could pour some of it on the " +
                       "ground?\n";
          break;
        case 2:
            my_long += "Woody contains some strange looking black powder. " +
                       "Maybe you could pour some of it on the ground?\n";
          break;
        case 1:
            my_long += "Woody is almost empty, but there's a small ammount " +
                       "of a strange looking black powder in him. Maybe " +
                       "you could pour some of it on the ground?\n";
          break;
        default:
            my_long += "Woody is empty.\n";
          break;
    }
    return my_long;
}

int can_get_and_put(void)
{
    W("Woody refuses to be put in a container. He wants to see where you " +
      "are taking him.\n");
    return 0;
}

int do_pour(string str)
{
    object powder,corpse;

    if(str == "powder" || str == "powder from barrel" ||
       str == "powder from woody" || str == "powder on ground")
    {
        if(ENV(TO) != TP)
        {
            return notify_fail("You must carry the barrel to be able to " +
                               "pour powder from it.\n");
        }
        if(charges <= 0)
        {
            return notify_fail("Woody is empty.\n");
        }

        powder = ENV(TP)->make(PCOBJECT + "magic_powder");
        --charges;

        if(ENV(TP)->query_property("water") ||
           ENV(TP)->query_property("under_water"))
        {
            W("You pour some powder from your barrel into a pile on the " +
              "bottom.\nIt turns into a wet mess. Damn.\n");
            S(TP->QN + " pours some powder from a barrel into a pile on " +
              "the bottom.\n" + TP->QN + " doesn't look very pleased.\n");
            powder->set_wet(1);
        }
        else if(ENV(TP)->query_property("indoors"))
        {
            W("You pour some powder from your barrel into a pile on the " +
              "floor.\n");
            S(TP->QN + " pours some powder from a barrel into a pile on " +
              "the floor.\n");
        }
        else
        {
            W("You pour some powder from your barrel into a pile on the " +
              "ground.\n");
            S(TP->QN + " pours some powder from a barrel into a pile on " +
              "the ground.\n");
        }

        // If Woody is empty he withers to dust, this is to stop multiple
        // woodies jumping around the mud, especially since he jumps out
        // of shop store rooms
        if(charges <= 0) {
            W("As you pour the last of the powder out of the barrel it " +
              "falls out of your hands and onto the ground.\n");
            S("As " + TP->QN + " pours the last of the powder out of the " +
              "barrel it falls out of " + TP->QPO + " hands and onto the " +
              "ground.\n");
            transfer(TO,ENV(TP));
            tell_room(ENV(TO),"Woody gasps: I'm empty.. goodbye cruel " +
                      "world...\nWoody withers to dust.\n");
            corpse = make(PCOBJECT + "woody_corpse",ENV(TO));
            destroy();
        }
        return 1;
    }
    return 0;
}

void check_idle(void)
{
    object player;
    if(query_interactive(ENV(TO)) && query_idle(ENV(TO)) > 60)
    {
        player = ENV(TO);
        tell_object(player,"Woody tells you: You are dull, I want to be " +
                    "with someone else now.\nWoody jumps out of your " +
                    "inventory and onto the floor.\n");
        transfer(TO,ENV(player));
        tell_room(ENV(TO),"Woody jumps out of " + player->QN + "'s " +
                    "inventory, down on the floor.\n",player);
    }
    else if(ENV(TO)->id("corpse"))
    {
        tell_room(ENV(ENV(TO)),"Woody jumps from the corpse, down on the " +
                    "floor.\n");
        transfer(TO,ENV(ENV(TO)));
    }
}

void chat(void)
{
    int rand = random(3);
    if(!rand)
    {
        rand = random(sizeof(chats));
        if(query_interactive(ENV(TO)))
        {
            tell_object(ENV(TO),chats[rand] + "\n");
        }
        else
        {
            tell_room(ENV(TO),chats[rand] + "\n");
        }
    }
}

void wander(void)
{
    int rand = random(3);
    string *exits;
    object room;

    if(!rand && !living(ENV(TO)))
    {
        exits = ENV(TO)->query_dest_dir();
        if(sizeof(exits) > 0)
        {
            rand = (random(sizeof(exits) / 2) * 2);
            room = ENV(TO);
            if(!transfer(TO,find_object(exits[rand])))
            {
                tell_room(room,"Woody jumps " + exits[rand + 1] + ".\n");
                tell_room(ENV(TO),"Woody jumps in from " +
                          opposite_dest_dir(exits[rand + 1]) + ".\n");
            }
        }
        else
        {
            tell_room(ENV(TO),"Woody looks depressed.\n" +
                              "Woody exclaims: Don't fence me in!\n");
        }
    }
}

mixed query_prevent_login(void)
{
    // Don't want to let players inn with Woody
    return 1;
}

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

        default: return "somewhere";
    }
}
