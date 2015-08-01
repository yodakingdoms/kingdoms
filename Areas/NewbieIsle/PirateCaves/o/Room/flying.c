// =======================================================================
// This is the room the players are moved to when they drink the birdvial.
// The flying and landing bit is handled by ../Object/flying_obj.c
// =======================================================================
#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
int my_query_daylight(void);
string long_fun(void);
void init(void);
void land(object player);
int do_anything(string str);
int dump_inventory(void);

void create_object(void)
{
    set_short("Flying high above the world");
    set_long("#long_fun");
    set_skip_obvious(1);
    set_new_light(10);
    add_property("no_horse");
    add_property("no_steal");
    add_property("no_fight");
    add_property("no_special");

    add_item("world","The world lies spread out below you. You are so high " +
             "up, you can see almost all of it");
    add_item("wind|winds","You feel the strong winds in your feathers. They " +
             "are carrying you and lifting you high above the world");
    add_item("feather|feathers","Your feathers are long and dark");
    add_func_item("ocean|oceans","#my_query_daylight",({
                 "The vast oceans lie below you, their waters sparkling in " +
                 "the bright moonlight",
                 "The vast oceans lie below you, their waters sparkling in " +
                 "the light from the rising sun",
                 "The vast oceans lie below you, their waters sparkling in " +
                 "the bright sunlight",
                 "The vast oceans lie below you, their waters sparkling in " +
                 "the light from the setting sun",
                }));
    add_func_item("water|waters","#my_query_daylight",({
                 "The water in the oceans and rivers sparkles in the bright " +
                 "moonlight",
                 "The water in the oceans and rivers sparkles in the light " +
                 "from the rising sun",
                 "The water in the oceans and rivers sparkles in the bright " +
                 "sunlight",
                 "The water in the oceans and rivers sparkles in the light " +
                 "from the setting sun"
                }));
    add_item("continent|continents","The continents lie below you. You see " +
             "mountains and valleys, rivers and lakes, villages and cities");
    add_func_item("lake|lakes","#my_query_daylight",({
                 "Many lakes of different sizes. Their waters sparkle in " +
                 "the bright moonlight",
                 "Many lakes of different sizes. Their waters sparkle in " +
                 "the light from the rising sun",
                 "Many lakes of different sizes. Their waters sparkle in " +
                 "the bright sunshine",
                 "Many lakes of different sizes. Their waters sparkle in " +
                 "the light from the setting sun",
                }));
    add_func_item("mountain|mountains|snow capped mountain|" +
                 "snow capped mountains|high mountain|high mountains",
                 "#my_query_daylight",({
                 "You see high mountains to the north, they look like huge " +
                 "shadows on the horizon",
                 "You see high mountains to the north, the snow on their " +
                 "peaks sparkles in the light from the rising sun",
                 "You see high mountains to the north, the snow on their " +
                 "peaks sparkles in the sun",
                 "You see high mountains to the north, the snow on their " +
                 "peaks sparkles in the light from the setting sun",
                }));
    add_func_item("shadow|shadows|huge shadow|huge shadows",
                 "#my_query_daylight",({
                 "The mountains to the north look like huge shadows on the " +
                 "horizon",
                 "The mountains to the north cast huge shadows on the " +
                 "valleys below",
                 "The mountains to the north cast huge shadows on the " +
                 "valleys below",
                 "The mountains to the north cast huge shadows on the " +
                 "valleys below"
                }));
    add_item("horizon","It is very far away");
    add_func_item("snow|peak|peaks","#my_query_daylight",({
                 "There might be snow on the peaks of the mountains, but " +
                 "it's too dark even in the bright moonlight to see it now",
                 "The snow on the peaks of the mountains to the north " +
                 "sparkles in the light from the rising sun",
                 "The snow on the peaks of the mountains to the north " +
                 "sparkles in the sun",
                 "The snow on the peaks of the mountains to the north " +
                 "sparkles in the light from the setting sun"
                }));
    add_func_item("light|moonlight|sunlight","#my_query_daylight",({
                 "The moon and the stars shine brightly",
                 "The rising sun shines brightly",
                 "The sun shines brightly",
                 "The setting sun shines brightly"
                }));
    add_func_item("star|stars","#my_query_daylight",({
                 "The stars shine brightly",
                 "The sun is rising, but you still see some stars in the sky",
                 "The sun shines too bright for you to see the stars",
                 "The sun hasn't set, but some stars have already come out " +
                 "for the coming night"
                }));
    add_item("forest|forests|vast forest|vast forests","Vast forests cover " +
             "much of the world below you. They are teeming with life");
    add_func_item("life|creature|creatures","#my_query_daylight",({
                 "All kinds of creatures going about their nightly business",
                 "All kinds of creatures, some are just waking up, others " +
                 "are finding shelter for the day",
                 "All kinds of creatures going about their daily business",
                 "All kinds of creatures, some are just waking up, others " +
                 "are finding shelter for the night"
                }));
    add_func_item("rivers|river","#my_query_daylight",({
                 "Rivers of different sizes. Their waters sparkle in the " +
                 "light from the stars",
                 "Rivers of different sizes. Their waters sparkle in the " +
                 "light from the rising sun",
                 "Rivers of different sizes. Their waters sparkle in the " +
                 "sunlight",
                 "Rivers of different sizes. Their waters sparkle in the " +
                 "light from the setting sun",
                }));
    add_item("valley|valleys|deep valley|deep valleys","Deep valleys " +
             "teeming with life");
    add_func_item("village|villages|town|towns|city|cities|" +
                 "settlement|settlements","#my_query_daylight",({
                 "Settlements where people seem to be sleeping",
                 "Settlements where people are getting ready for the day " +
                 "that lies ahead of them",
                 "Settlements where people go about their daily business",
                 "Settlements where people are retiring for the night"
                }));
    add_item("people","The people of the Kingdoms");
    add_item("kingdom|kingdoms|Kingdom|Kingdoms","The Kingdoms lie spread " +
             "below you");
    add_func_item("cloud|clouds","#my_query_daylight",({
                 "There are hardly any clouds obscuring your view, looks " +
                 "like you picked a good night to go flying",
                 "There are hardly any clouds obscuring your view, looks " +
                 "like you picked a good morning to go flying",
                 "There are hardly any clouds obscuring your view, looks " +
                 "like you picked a good day to go flying",
                 "There are hardly any clouds obscuring your view, looks " +
                 "like you picked a good evening to go flying",
                }));
    add_item("view","It is breathtaking");
}

int my_query_daylight(void)
{
    return query_daylight();
}

string long_fun(void)
{
    switch(query_daylight())
    {
        case 0: return "You are flying high above the world. You are " +
                       "floating on the winds, watching the oceans and " +
                       "continents spread out below you. The moon and the " +
                       "stars are shining and the waters below you sparkle " +
                       "in the light. You see forests, rivers and valleys " +
                       "teeming with life and villages, towns and cities " +
                       "where the people of the Kingdoms rest for the night " +
                       "There are hardly any clouds obscuring your view, " +
                       "what a glorious experience.\n";
          break;
        case 1: return "You are flying high above the world. You are " +
                       "floating on the winds, watching the oceans and " +
                       "continents spread out below you. The sun is rising " +
                       "and the waters below you sparkle in the light. " +
                       "You see forests, rivers and valleys teeming with " +
                       "life and villages, towns and cities where the " +
                       "people of the Kingdoms are preparing for the new " +
                       "day. There are hardly any clouds obscuring your " +
                       "view, what a glorious experience.\n";
          break;
        case 2: return "You are flying high above the world. You are " +
                       "floating on the winds, watching the oceans and " +
                       "continents spread out below you. The sun is shining " +
                       "and the waters below you and the snow capped " +
                       "mountains to the north sparkle in the light. You " +
                       "see forests, rivers and valleys teeming with life " +
                       "and villages, towns and cities where the people of " +
                       "the Kingdoms go about their daily business. There " +
                       "are hardly any clouds obscuring your view, what " +
                       "a glorious experience.\n";
          break;
        case 3: return "You are flying high above the world. You are " +
                       "floating on the winds, watching the oceans and " +
                       "continents spread out below you. The sun is setting " +
                       "and the waters below you sparkle in the light. " +
                       "You see forests, rivers and valleys teeming with " +
                       "life and villages, towns and cities where the " +
                       "people of the Kingdoms are preparing for the night. " +
                       "There are hardly any clouds obscuring your " +
                       "view, what a glorious experience.\n";

          break;
        default: return "Well, it's neither night, dawn, day nor dusk...\n";
    }
}

void init(void)
{
    if(present("_pirate_caves_flying_obj_",TP))
    {
        add_action("do_anything","",1);
    }
    else
    {
        // Should stop players going LD and coming back from getting
        // stuck here hopefully
        set_alarm(1.0,0.0,"land",TP);
    }
}

void land(object player)
{
    tell_object(player,"You land and black out for a moment. When you " +
                "regain your senses, you are yourself again.\n");
    player->move_player("x",PCROOM + "bird_tower_top");
    tell_room(ENV(player),"A huge falcon lands on the ground in front " +
              "of you. Suddenly it disappears in a puff of smoke and " +
              "instead of the bird, " + player->QN + " stands before " +
              "you.\n",player);
}

int do_anything(string str)
{
    if(query_verb() == "glance" || query_verb() == "l" ||
       query_verb() == "look" || query_verb() == "examine" ||
       // Let players do these things also, in case something goes wrong
       query_verb() == "tell" || query_verb() == "quit" ||
       TP->query_level() >= LEVELS_NEWBIE)
    {
        // Looks complicated but only catches players looking at themselves
        if((query_verb() == "examine" &&
            (lower_case(str) == lower_case(TP->QN) ||
             lower_case(str) == "me"))
            ||
           ((query_verb() == "look" || query_verb() == "l") &&
             (lower_case(str) == lower_case("at " + TP->QN) ||
              lower_case(str) == "at me")))
        {
            W("You are a majestic falcon, soaring high above the ground.\n");
            return 1;
        }
        return 0;
    }
    W("You are too busy flying...\n");
    return 1;
}

/**
* Mask dump inventory so other players and/or things that end up here
* aren't visible. It's supposed to feel like they're all alone here
* even if two players happen to drink a vial at the same time.
*/
int dump_inventory(void)
{
    return 1;
}