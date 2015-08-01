#pragma strict_types
#include "../def.h"
inherit STD_MONSTER;

int telling_story,departing,shouting,abort_quest_alarm_id;

void create_object(void);
void long_fun(void);
void init(void);
int do_ask(string str);
int do_join(string str);
void tell_story(int step);
void tell_ship_state(void);
void go_to_aft_deck(void);
void go_to_cabin(void);
void shout_orders(void);
void abort_quest(void);
void shout(string str);
int deny_object(object obj);
void solve_quest(void);
void log_quest_solved(void);
int is_unkillable(void);
string unkillable_string(object attacker);
void scare_attacker(object attacker);
object get_ship_obj(void);

void create_object(void)
{
    set_short("Captain Jack Hummingbird",1);
    set_long("#long_fun");
    set_name("jack");
    add_id("jack hummingbird");
    add_id("captain jack hummingbird");
    add_id("man");
    add_id("captain");
    add_id("hummingbird");
    add_id("pirate");
    set_race("newbie island pirate");
    set_al(-300);
    set_gender(1);

    // Just to make 'check' more interesting
    set_level(50);
    set_hp(8000);
    set_wc(100);
    set_ac(100);
    add_money(30000 + random(30000));
}

void init(void)
{
    add_action("do_ask","ask");
    add_action("do_join","join");
}

int do_ask(string str)
{
    string junk;

    if(!str) return 0;

    if(SHIP_OBJ->query_ship_at_sea())
    {
        // When the ship is at sea the captain will be shouting out
        // orders, no need for asking about anything
        return 0;
    }

    if(SHIP_OBJ->query_ready_to_disembark())
    {
        if(departing)
        {
            W("The captain says: There's no problem, the ship is ready to " +
              "leave and will depart shortly, aarrr. Better get off if yer " +
              "not planning on coming along, arr!\n");
            return 1;
        }
    }

    if(sscanf(str,"captain %s",junk) == 1 || sscanf(str,"jack %s",junk) == 1)
    {
        if(!telling_story)
        {
            W("You ask the captain what the problem is.\n");
            S(TP->QN + " asks the captain what the problem is.\n");
            set_alarm(1.0,0.0,"tell_story",0);
            telling_story = 1;
            return 1;
        }
        else
        {
            W("The captain is already talking about what's bothering him.\n");
            return 1;
        }
    }
    else if(str == "for orders")
    {
        if(SHIP_OBJ->query_is_at_sea())
        {
            W("You don't have to ask for orders when the ship is at sea, " +
              "the captain will be shouting them at you.\n");
        }
        else if(telling_story)
        {
            W("The captain is telling a story. Wait until he's done...\n");
        }
        else
        {
            set_alarm(1.0,0.0,"tell_ship_state");
        }
        return 1;
    }
}

int do_join(string str)
{
    if(str == "crew")
    {
        if(SHIP_OBJ->query_ship_at_sea())
        {
            W("The ship is at sea and you've already joined the crew, " +
              "whether you wanted to or not!\n");
            return 1;
        }
        if(!telling_story)
        {
            W("You tell the captain you'd be willing to join his crew.\n");
            S(TP->QN + " tells the captain " + TP->QPR + " would be willing " +
              "to join his crew.\n");
            tell_room(ENV(TO),"The captain says: Excellent!\n");
            tell_ship_state();
            return 1;
        }
        else
        {
            W("The captain is busy telling his story. Wait until he has " +
              "finished.\n");
            return 1;
        }
    }
}

void tell_story(int step)
{
    float delay;
    switch(step)
    {
        case 0:
            tell_room(ENV(TO),"Captain Jack sighs.\n");
            delay = 2.0;
          break;
        case 1:
            tell_room(ENV(TO),"Captain Jack says: The problem is my crew, " +
                      "aarr. Them scurvy dogs just drink their days away " +
                      "and aarrren't interested in plundering no more, " +
                      "aarr.\n");
            delay = 3.0;
          break;
        case 2:
            tell_room(ENV(TO),"Captain Jack says: I've heard news of a fine " +
                      "catch leaving port in Kordar, heading for Lars Town, " +
                      "aarr. I can't capture her and her bounty alone, even " +
                      "I need a crew to do the dirty wo^H^H^H^H^H^H^H^H" +
                      "honorable battle with the other crew, arr.\n");
            delay = 3.0;
          break;
        case 3:
            tell_room(ENV(TO),"Captain Jack says: You don't look like " +
                      "much, I must admit, but I'm getting desperate, aarr. " +
                      "If the ship reaches Lars Town the treasure will be " +
                      "beyond my, err I mean _our_ grasp! If you would " +
                      "join my crew, maybe it could still be done without " +
                      "much of (my) blood being spilled, aarr!\n");
            delay = 4.0;
          break;
        case 4:
            tell_room(ENV(TO),"Captain Jack says: I'll make it worthwhile " +
                      "for you, I swear on my beard, aarr. Just " +
                      "<join crew> and I'll let ye know what needs to be " +
                      "done for the ship ere she can be taken out to sea.\n");
            delay = 3.0;
          break;
    }
    if(step < 4)
    {
        set_alarm(delay,0.0,"tell_story",++step);
    }
    else
    {
        telling_story = 0;
    }
}

void tell_ship_state(void)
{
    if(!telling_story)
    {
        if(SHIP_OBJ->query_ready_to_disembark())
        {
            // If all is ready the captain will go up to the aft deck and take
            // the ship out, players not onboard have 20 seconds to get there
            // or be left behind
            tell_room(ENV(TO),"The captain says: Excellent, aarr! We are " +
                      "ready to set sail.\n");
            shout("All hands on deck! We'll shortly depart, aaaaarrr!\n");
            departing = 1;
            set_alarm(20.0,0.0,"go_to_aft_deck");
            // Set a 20 minute time limit, that should be enough to complete
            // the quest and prevent it from being locked if people idle
            // and/or quit from the ship. The alarm will be removed if/when
            // the quest is solved
            abort_quest_alarm_id = set_alarm(1200.0,0.0,"abort_quest");
            return;
        }

        tell_room(ENV(TO),"The captain says: These are the things we still " +
                          "need ere we can take the ship to sea, aarr:\n");
        if(!SHIP_OBJ->query_flag_present())
        {
            tell_room(ENV(TO),"              A Jolly Roger flag in the " +
                      "forecastle, aarr.\n");
        }
        if(!SHIP_OBJ->query_looking_glass_present())
        {
            tell_room(ENV(TO),"              A looking glass in the " +
                      "crows nest, aarr.\n");
        }
        if(!SHIP_OBJ->query_sextant_present())
        {
            tell_room(ENV(TO),"              A sextant by the rudder, " +
                      "aarr.\n");
        }
        if(!SHIP_OBJ->query_barrel_present())
        {
            tell_room(ENV(TO),"              A barrel of black powder " +
                      "below deck, aarr.\n");
        }
        if(!SHIP_OBJ->query_cannonball_present())
        {
            tell_room(ENV(TO),"              A big round stone below " +
                      "deck, aarr.\n");
        }
        if(!SHIP_OBJ->query_grappling_rope_present())
        {
            tell_room(ENV(TO),"              A rope with a grappling " +
                      "hook on the deck, aarr.\n");
        }
        if(!SHIP_OBJ->query_sail_present())
        {
            tell_room(ENV(TO),"              A gaff sail on the deck, " +
                      "aarr.\n");
        }
        tell_room(ENV(TO),"The captain says: Just come back and <ask for " +
                  "orders> if yer a forgetful feller or when ye think ye've " +
                  "found all we need, aarr.\n");
    }
}

void go_to_aft_deck(void)
{
    object sextant;
    if(name_file(ENV(TO)) != PCROOM + "black_skull_aft_deck")
    {
        tell_room(ENV(TO),"The captain leaves the room to go to the aft " +
                  "deck and man the rudder.\n");
        move_object(TO,PCROOM + "black_skull_aft_deck");
        tell_room(ENV(TO),"The captain arrives to man the rudder.\n");
        sextant = present("_pirate_quest_sextant_",ENV(TO));
        if(sextant)
        {
            tell_room(ENV(TO),"The captain takes sextant.\n");
            sextant->destroy();
        }
        SHIP_OBJ->set_at_sea();
        departing = 0;
        shouting = 1;
        shout_orders();
    }
}

void shout_orders(void)
{
    string *names = ({ "ye landlubbers",
                       "mateys",
                       "ye scurvy dogs" });
    string order;

    if(SHIP_OBJ->query_is_at_sea() && shouting)
    {
        if(!SHIP_OBJ->query_sail_raised())
        {
            order = "raise the gaff sail!";
        }
        else if(!SHIP_OBJ->query_ship_spotted())
        {
            order = "get up to the crows nest and look for our prey, arr!";
        }
        else if(!SHIP_OBJ->query_flag_raised())
        {
            order = "raise the Jolly Roger from the forecastle, time to " +
                    "strike some fear into them, aarr!";
        }
        else if(!SHIP_OBJ->query_cannon_fired())
        {
            order = "get below deck and fire the cannon at them, aarr!\n";
        }
        else if(!SHIP_OBJ->query_rope_thrown())
        {
            order = "throw the grappling rope and hook their railing so " +
                    "we... err.. YOU can board them, aarr!";
        }
        else
        {
            order = "board them, plunder, pillage, rob, aarr! Find the " +
                    "treasure chest, bring it back and give it to me!";
        }
        shout("Ahoy " +names[random(3)] + ", " + order + "\n");
        set_alarm(10.0 + itof(random(10)),0.0,"shout_orders");
    }
}

void go_to_cabin(void)
{
    if(name_file(ENV(TO)) != PCROOM + "black_skull_cabin")
    {
        tell_room(ENV(TO),"The captain leaves the rudder to go to his " +
                  "cabin.\n");
        move_object(TO,PCROOM + "black_skull_cabin");
        tell_room(ENV(TO),"The captain arrives in the cabin.\n");
        SHIP_OBJ->set_in_cave();
    }
}

void long_fun(void)
{
    string long_desc = "Jack Hummingbird is the legendary pirate captain of " +
             "Newbie Island. The tales of his deeds are many and each one " +
             "is more outrageous than the previous. Many of them concern " +
             "poor fools whose last action in life was making fun of his " +
             "name. He has long, unkept hair and an even longer red beard " +
             "with braids in it. He has a wooden peg at the end of his " +
             "right leg and a nasty looking hook at the end of his left " +
             "arm. ";
    if(!get_ship_obj()->query_is_at_sea())
    {
        if(get_ship_obj()->query_ready_to_disembark())
        {
            long_desc += "He looks very pleased as his ship is now ready to " +
                         "depart and will do so shortly. If you don't want " +
                         "to join his crew you'd better get off the ship " +
                         "now! If you want to stay, you might want to " +
                         "<ask for orders> and maybe be put to good use.\n";
        }
        else
        {
            long_desc += "He looks depressed. Maybe you could ask him what " +
                         "the problem is?\n";
        }
    }
    else
    {
        long_desc += "He laughs manically as he steers his ship across the " +
                     "raging sea!\n";
    }
    long_desc += "Jack has no visible wounds or injuries.\n" +
                 "He belongs to the newbie island pirate race.\n" +
                 "He is wielding an enchanted triple edged sword in his " +
                 "right hand.\n" +
                 "He parries attacks with a blacksteel shield dripping with " +
                 "blood.\n" +
                 "He is wearing the one ring, a diamond armband, an emerald " +
                 "earring, a tearshaped amulet and a silksteel headband, " +
                 "a green bow tie, and black dragonscale sleeves.\n" +
                 "He is clad in diamondsteel chainmail, bloodstone boots, " +
                 "an elfskin cloak, elvish gauntlets of power (dormant), " +
                 "and a horned crown.\n";
    W(long_desc);
}

void abort_quest(void)
{
    if(SHIP_OBJ->query_is_at_sea())
    {
        shout("You useless land lubbers, aarr, I'll be dead and buried " +
              "before you've managed to plunder this treasure. I'm sailing " +
              "home again aarr, aarr!\n");
        go_to_cabin();
        SHIP_OBJ->reset_ship();
    }
}

void shout(string str)
{
    int i;
    object *crew = SHIP_OBJ->find_crew();

    for(i = 0; i < sizeof(crew); ++i)
    {
        tell_object(crew[i],"Captain Jack shouts: " + str);
    }
}

int deny_object(object obj)
{
    set_alarm(1.0,0.0,"check_object",TP,obj);
    return 0;
}

void check_object(object player,object obj)
{
    set_this_player(player);
    if(!obj->id("_pirate_quest_treasure_chest_"))
    {
        W("Captain Jack does not want that, he's only interested in " +
          "the treasure chest from the ship he wants to plunder.\n");
    }
    else if(!SHIP_OBJ->query_rope_thrown())
    {
        W("Captain Jack says: I don't know where ye got that chest, " +
          "matey, but I don't think ye got it on my last trip with " +
          "the ship, aarr. It's probably not the right one, aarr.\n");
    }
    else
    {
        W("Captain Jack says: Excellent, aarr!\n");
        shout("The treasure is mine, err, I mean ours! All hands return to " +
              "the Black Skull, we'll go back shortly!\n");
        remove_alarm(abort_quest_alarm_id);
        shouting = 0;
        set_alarm(10.0,0.0,"solve_quest");
        return;
    }
    tell_room(ENV(TO),"Captain Jack drops " + obj->QN + ".\n");
    transfer(obj,ENV(TO));
}

void solve_quest(void)
{
    int i;
    object chest;
    object *crew = SHIP_OBJ->find_crew();

    tell_room(ENV(TO),"The Captain grins greedily and tucks the chest " +
              "away in a hidden compartment.\n");
    shout("Aarr mateys, well done indeed. Unfortunately I won't have " +
          "enough gold left after expenses have been paid to properly " +
          "reward ye that way, aarr. I'm sure the experience will be " +
          "it's own reward though, so spend it wisely, aarr!\n");
    SHIP_OBJ->tell_black_skull_rooms("The Black Skull turns around and " +
                                     "returns to Newbie Island.\n");
    for(i = 0; i < sizeof(crew); ++i)
    {
        if(!crew[i]->test_flag(222))
        {
            tell_object(crew[i],"You feel more experienced, aarr!\n");
            (PCOBJECT + "pirate_quest_obj")->quest_solved(crew[i],1);
        }
    }
    log_quest_solved();
    chest = present("_pirate_quest_treasure_chest_",TO);
    if(chest)
    {
        chest->destroy();
    }
    SHIP_OBJ->reset_ship();
    go_to_cabin();
}

void log_quest_solved(void)
{
    int i;
    object *crew = SHIP_OBJ->find_crew();
    write_file(QUEST_LOG,ctime(time()) +": Quest solved by the following " +
               "crew:\n");
    for(i = 0; i < sizeof(crew); ++i)
    {
        write_file(QUEST_LOG,"   " + C(crew[i]->QRN) + " at level " +
                   crew[i]->query_level() + " in " + name_file(ENV(crew[i])) +
                   "\n");
    }
}

int is_unkillable(void)
{
    return 1;
}

string unkillable_string(object attacker)
{
    // Setting alarm just so that the flee thing will happen after
    // the unkillable string is written, not before ...
    set_alarm(0.0,0.0,"scare_attacker",attacker);
    return "Jack scowls and you put your tail between your legs and " +
           "run away.\n";
}

void scare_attacker(object attacker)
{
    attacker->run_away();
}

object get_ship_obj(void)
{
    return find_object(SHIP_OBJ);
}
