#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;
inherit CHECK_FIRE_MODULE;

int blown_up = 0;
int barrel_taken = 0;

void create_object(void);
void reset(int arg);
void init(void);
string long_fun(void);
int do_check_fire(string str);
void blow_up(object igniter);
int do_get_barrel(string str);
int query_blown_up_and_barrel_taken(void);
int query_blown_up(void);

void create_object(void)
{
    ::create_object();
    set_short("Dry storage room (e)");
    set_long("#long_fun");
    // This room is supposed to be dark, so you will get here, *hmm*,
    // light a torch, see the sign and blow up! Any special magic
    // fires guilds can have should have the same effect. Light is set
    // to -1 since the master room sets it to 1
    set_new_light(-1);

    add_item("room|underground room|storage room|underground storage room",
             "It is a small underground storage room");
    add_func_item("wall|walls|floor|ceiling|stone wall|stone walls|" +
                 "stone floor|stone ceiling","#query_blown_up",({
                 "Made of stone",
                 "Made of stone, scorched black as if there has been a " +
                 "fire or explosion here"
                }));
    add_func_item("air","#query_blown_up",({
                 "The air is very dry and something in it stings your " +
                 "nostrils",
                 "There's smoke in the air and there is a burnt smell here"
                }));
    add_item("smell","You can't see it but maybe you can smell it");
    add_func_item("%|%air|%smell","#query_blown_up",({
                 "There's a strange smell in the air, it stings your nostrils",
                 "There's a horrible burnt smell in the air, it stings your " +
                 "nostrils"
                 }));
    add_item("nostril|nostrils","You can't see your nostrils from here");
    add_func_item("barrels|wooden barrels","#query_blown_up_and_barrel_taken",
                 ({
                 "Many wooden barrels are piled up against the walls. " +
                 "Almost all of them seem to have cracks where some black " +
                 "powder has seeped out, covering the barrels and the " +
                 "floor. You can only spot one single barrel that looks as " +
                 "if it's not broken",
                 "There's lots of debris here that seems to have been " +
                 "barrels once, but now there's only one whole barrel left",
                 "Many wooden barrels are piled up against the walls. " +
                 "Almost all of them seem to have cracks where some black " +
                 "powder has seeped out, covering the barrels and the " +
                 "floor",
                 "There's lots of debris here that seems to have been " +
                 "barrels once, but now there are no whole barrels left"
                 }));
    add_func_item("barrel|wooden barrel","#query_blown_up_and_barrel_taken",({
                 "A wooden barrel standing in a corner by itself. Maybe " +
                 "it's been separated from the others because it is the " +
                 "only one that doesn't look broken. You could pick it up " +
                 "if you wanted to",
                 "There is one intact wooden barrel standing in one corner. " +
                 "For a moment you thought it looked as if it was trembling " +
                 "in shock and horror, but that was probably just your " +
                 "imagination. You could pick it up if you wanted to",
                 "There are many wooden barrels piled up against the walls",
                 "There's not a single whole barrel left in the room"
                 }));
    add_func_item("crack|cracks","#query_blown_up",({
                 "The barrels have cracked, allowing the powder inside them " +
                 "to spill out on the floor",
                 "There is a big crack in the northwest corner of the room, " +
                 "you can go there and see if you find something interesting"
                 }));
    add_func_item("corner|corners","#query_blown_up",({
                 "There are corners to the northeast,southeast,southwest " +
                 "and northwest. None of them look particularily interesting",
                 "There are corners in to the northeast,southeast,southwest " +
                 "and northwest. The only one that looks interesting is the " +
                 "northwest one, since there's a big crack in it"
                }));
    add_item("northeast corner|southeast corner|southwest corner","It is " +
             "not interesting at all");
    add_func_item("northwest corner","#query_blown_up",({
                 "It is not interesting at all",
                 "There's a big crack in the wall there. The crack is big " +
                 "enough for you to go that way if you want to"
                 }));
    add_func_item("sign|wooden sign|@sign|@wooden sign","#query_blown_up",({
                 "A wooden sign hangs on the wall. On it is written with " +
                 "huge letters: NO TORCHES IN THIS ROOM!!! You wonder why " +
                 "not, and what would happen if you were to light a torch",
                 "A wooden sign lies among the debris on the floor. On it " +
                 "is written with huge letters: NO TORCHES IN THIS ROOM!!! " +
                 "You wonder if the current state of the room has something " +
                 "to do with someone disregarding those instructions",
                 }));
    add_item("letters|huge letters","NO TORCHES IN THIS ROOM!!!");

    add_exit(PCROOM + "lev1_ns_corridor1","east");

    reset(0);
}

void reset(int arg)
{
    if(blown_up)
    {
        tell_room(TO,"Drunk pirate arrives from the east.\n" +
                  "Drunk pirate groans loudly.\n" +
                  "Drunk pirate cleans up the mess.\n" +
                  "Drunk pirate leaves east.\n" +
                  "A group of drunk pirates arrive from the east.\n" +
                  "A group of drunk pirates stack a bunch of barrels " +
                  "against the walls.\n"+
                  "A group of drunk pirate leave east.\n");
    }
    else if(barrel_taken)
    {
        tell_room(TO,"Drunk pirate arrives from the east.\n" +
                  "Drunk pirate drops a barrel.\n" +
                  "Drunk pirate leaves east.\n");
    }
    remove_exit("crack");
    remove_item("smoke|veil");
    remove_item("wreckage|debris|wooden debris");
    add_item("powder|pile|piles","Small piles of a strange black " +
             "powder. You feel a bit uneasy looking at it... Maybe " +
             "there's some magic in it...?");
    add_item("magic","You're not sure if there is magic in the powder " +
             "but there is definitely something strange about it");

    blown_up = 0;
    barrel_taken = 0;
}

/**
* The barrel is needed for the quest, reset it separately when taken.
*/
void my_reset()
{
    barrel_taken = 0;
}

void init(void)
{
    add_action("do_check_fire","",1);
    add_multi_action("do_get_barrel","take|get|pick");
}

string long_fun(void)
{
    string my_long_desc;
    if(!query_blown_up())
    {
        my_long_desc = "A small underground room with a stone floor and " +
             "walls. This room looks like a storage room. It is cramped and " +
             "many wooden barrels are stacked against the walls. The " +
             "air is very dry and there are several small piles of a " +
             "strange black powder on the floor. It looks as if the " +
             "powder has leaked onto the floor from cracks in the " +
             "barrels. There is a strange smell in the air and " +
             "something seems to sting your nostrils. A wooden sign on " +
             "one wall loudly proclaims there should be: NO TORCHES IN " +
             "THIS ROOM!!!\n";
    }
    else
    {
        my_long_desc = "A small underground room with a stone floor and " +
               "walls. The room looks as if a disaster has occurred here. " +
               "There is wreckage everywhere and the floor, walls and " +
               "ceilings are scorched black as if there has been a fire or " +
               "explosion here. The floor is covered with wooden debris ";
        if(!barrel_taken)
        {
            my_long_desc += "and in one corner stands a single barrel " +
                   "that somehow seems to have survived whatever took " +
                   "place in the room. There ";
        }
        else
        {
            my_long_desc += "and there ";
        }
        my_long_desc += "is a big crack in the wall in the northwest " +
               "corner of the room. There is a horrible burnt smell here " +
               "and the smoke in the air stings your nostrils.\n";

    }
    return my_long_desc;
}

/**
* Checks player and room inventory for anything that can ignite
* the powder and blow the room to bits. Called at init and whenever
* a player does something so we can see if a player lights a torch,
* uses demon fire ability or whatever.
*/
int do_check_fire(string str)
{
    if(!blown_up && query_can_light_powder(TP))
    {
        // 2 means the room is currently blowing up
        blown_up = 2;
        set_alarm(0.5,0.0,"blow_up",TP);
    }
}

void blow_up(object igniter)
{
    int i;
    string junk;
    object *players,powder;

    if(igniter)
    {
        set_this_player(igniter);
        if(present(igniter,TO))
        {
            W("A spark from your fire lands on the powder on the floor. " +
              "The powder starts smoking, crackling and sizzling.\n");
            S("A spark from " + TP->QN + "s fire lands on the powder on " +
              "the floor. The powder starts smoking, crackling and " +
              "sizzling.\n");
            set_alarm(1.0,0.0,"blow_up");
        }
        else
        {
            // Phew! In and out of the room quick enough!
            blown_up = 0;
        }
    }
    else
    {
        tell_room(TO,"The powder in the room erupts in flames!\n");
        // There's a lot more powder here than in the small piles you get
        // from the barrel so we hurt them a bit more.
        players = query_players_here();
        for(i = 0;i < sizeof(players); ++i)
        {
            // 25% + random(25%) of players current hp will shake them up
            // without killing them (I think, if dividing an int rounds down)
            players[i]->do_spell_damage(players[i]->query_hp() / 4 +
                                        random(players[i]->query_hp() / 4),
                                        ({ "fire","blunt" }));
        }
        // Make powder and use that for the special effects instead of
        // duplicating the functionality here
        powder = make(PCOBJECT + "magic_powder");
        powder->explode(igniter);

        // There's a lot more powder here than in a small pile so this
        // explosion will be heard all over the Kingdoms. Anything to
        // attract attention and arouse curiosity *cough*

        players = users();
        for(i = 0; i < sizeof(players); ++i)
        {
            if(!sscanf(name_file(ENV(players[i])),PIRATECAVES + "%s",junk))
            {
                tell_object(players[i],"KABOOM!!\n" +
                            "A loud explosion is heard from somewhere in " +
                            "the general area of Newbie Island.\n");
            }
        }

        add_exit(PCROOM + "lev1_hidden_storage_room","crack");
        add_item("smoke|veil","A thin veil of smoke hangs over the room. It " +
                 "does not smell very nice at all");
        add_item("wreckage|debris|wooden debris","It's scattered around the " +
                 "room. There seems to have been some sort of disaster here");
        remove_item("powder|pile|piles");
        remove_item("magic");
        blown_up = 1;
    }
}

int do_get_barrel(string str)
{
    object barrel;

    if(str == "barrel" || str == "up barrel" || str == "barrel up")
    {
        if(!barrel_taken)
        {
            barrel = make(PCOBJECT + "powder_barrel");
            if(!transfer(barrel,TP))
            {
                W("You pick the barrel up.\n");
                S(TP->QN + " gets a barrel.\n");
            }
            else
            {
                W("You try to pick the barrel up but it is too heavy " +
                  "for you to carry so you drop it back on the floor.\n");
                S(TP->QN + " tries to take a barrel but fails and drops " +
                  "it back on the floor.\n");
            }
            barrel_taken = 1;
            // Reset the barrel after 10 minutes, since it's part of the
            // quest
            set_alarm(600.0,0.0,"my_reset");
        }
        else
        {
            if(!blown_up)
            {
                W("All the barrels here now have cracks in them and are " +
                  "pretty much useless.\n");
            }
            else
            {
                W("There is not one single intact barrel here for you " +
                  "to pick up.\n");
            }
        }
        return 1;
    }
}

/**
* 0: Not blown up, barrel not taken
* 1: Blown up, barrel not taken
* 2: Not blown up, barrel taken
* 3: Blown up, barrel taken
*/
int query_blown_up_and_barrel_taken(void)
{
    if(!query_blown_up())
    {
        if(!barrel_taken)
            return 0;
        else
            return 2;
    }
    else
    {
        if(!barrel_taken)
            return 1;
        else
            return 3;
    }
}

int query_blown_up(void)
{
    // Will return 0 when blown_up == 2 temporarily while the explosion
    // is starting so that the room will look intact if someone looks
    // while that happens
    return (blown_up == 1 ? 1 : 0);
}
