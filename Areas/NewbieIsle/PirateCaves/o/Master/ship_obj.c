//===========================================================================
// ship_obj - A single object to keep track of the state of the ship.
//            The ship rooms query and set the state of the ship via this
//            object. The state of the quest is kept track of by the
//            captain monster.
//
// Yoda 990413
//============================================================================
#pragma strict_types
#include "../def.h";
inherit STD_STDOBJ;

object deck,cabin,crows_nest,forecastle,aft_deck,below_deck;
string DECK = PCROOM + "black_skull_deck",
       CABIN = PCROOM + "black_skull_cabin",
       CROWS_NEST = PCROOM + "black_skull_crows_nest",
       FORECASTLE = PCROOM + "black_skull_forecastle",
       AFT_DECK = PCROOM + "black_skull_aft_deck",
       BELOW_DECK = PCROOM + "black_skull_below_deck",
       RIAA_DECK = PCROOM + "riaa_deck",
       RIAA_CABIN = PCROOM + "riaa_cabin";

string *black_skull_rooms = ({ DECK, FORECASTLE, AFT_DECK, CABIN,
                               CROWS_NEST, BELOW_DECK });
int ship_is_at_sea;

void create_object(void);
void set_in_cave(void);
void set_at_sea(void);
void set_is_at_sea(int location);
int query_is_at_sea(void);
int query_flag_present(void);
int query_looking_glass_present(void);
int query_ready_to_disembark(void);
void tell_black_skull_rooms(string str);

void create_object(void)
{
    set_in_cave();
    (DECK)->load_me();
    (FORECASTLE)->load_me();
    (AFT_DECK)->load_me();
    (CABIN)->load_me();
    (CROWS_NEST)->load_me();
    (BELOW_DECK)->load_me();
    (RIAA_DECK)->load_me();
    (RIAA_CABIN)->load_me();
}

void set_at_sea(void)
{
    tell_room(PCROOM + "lev3_harbour","The ship slowly and silently glides " +
              "out of the cave to the sea.\n");
    tell_black_skull_rooms("The sails are unfurled and the ship slowly " +
                           "glides out of the cave to the sea.\n");
    set_is_at_sea(1);
}

void set_in_cave(void) {
    tell_room(PCROOM + "lev3_harbour","The ship slowly and silently glides " +
              "into the cave from the sea.\n");
    tell_black_skull_rooms("The sails are furled and the ship slowly " +
                           "glides into the cave from the sea.\n");
    set_is_at_sea(0);
}

void set_is_at_sea(int location)
{
    ship_is_at_sea = location;
}

int query_is_at_sea(void)
{
    return ship_is_at_sea;
}

int query_barrel_present(void)
{
    if(present("_pirate_quest_powder_barrel_",find_object(BELOW_DECK)))
    {
        return 1;
    }
    return 0;
}

int query_cannonball_present(void)
{
    if(present("_pirate_quest_cannonball_",find_object(BELOW_DECK)))
    {
        return 1;
    }
    return 0;
}

int query_grappling_rope_present(void)
{
    if(present("_pirate_quest_grappling_rope_",find_object(DECK)))
    {
        return 1;
    }
    return 0;
}

int query_flag_present(void)
{
    if(present("_pirate_quest_jolly_roger_",find_object(FORECASTLE)))
    {
        return 1;
    }
    return 0;
}

int query_sail_present(void)
{
    if(present("_pirate_quest_gaff_sail_",find_object(DECK)))
    {
        return 1;
    }
    return 0;
}

int query_looking_glass_present(void)
{
    if(present("_pirate_quest_looking_glass_",find_object(CROWS_NEST)))
    {
        return 1;
    }
    return 0;
}

int query_sextant_present(void)
{
    if(present("_pirate_quest_sextant_",find_object(AFT_DECK)))
    {
        return 1;
    }
    return 0;
}

int query_ready_to_disembark(void)
{
    return !query_is_at_sea() &&
           query_flag_present() &&
           query_looking_glass_present() &&
           query_barrel_present() &&
           query_cannonball_present() &&
           query_sail_present() &&
           query_grappling_rope_present() &&
           query_sextant_present();
}

int query_sail_raised()
{
    return find_object(DECK)->query_sail_raised();
}

int query_ship_spotted()
{
    return find_object(CROWS_NEST)->query_ship_spotted();
}

int query_flag_raised()
{
    return find_object(FORECASTLE)->query_flag_raised();
}

int query_cannon_fired()
{
    return find_object(BELOW_DECK)->query_cannon_fired();
}

int query_rope_thrown()
{
    return find_object(DECK)->query_rope_thrown();
}

void tell_black_skull_rooms(string str)
{
    int i;
    for(i = 0; i < sizeof(black_skull_rooms); ++i)
    {
        tell_room(black_skull_rooms[i],str);
    }
}

void reset_ship(void)
{
    int i;
    for(i = 0; i < sizeof(black_skull_rooms); ++i)
    {
        black_skull_rooms[i]->my_reset();
    }
    RIAA_CABIN->my_reset();
}

object *find_crew(void)
{
    int i;
    object *crew = ({});
    for(i = 0; i < sizeof(black_skull_rooms); ++i)
    {
        crew += find_object(black_skull_rooms[i])->query_players_here();
    }
    if(query_rope_thrown())
    {
        crew += find_object(RIAA_DECK)->query_players_here();
        crew += find_object(RIAA_CABIN)->query_players_here();
    }
    return crew;
}