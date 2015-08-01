#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

object fetcher;

void create_object(void);
void set_fetcher(object player);
object query_fetcher(void);

void create_object(void)
{
    set_name("orb");
    add_id("_oakdale_quest_orb_");
    set_short("a shining orb");
    set_long("A shining white orb about the size of your fist. It shines " +
             "with a soothing bright light, chasing both the darkness and " +
             "your fears away. The milky white mist within it is swirling, " +
             "and you can feel the orb vibrate in your hands.\n");
    set_light(1);
    set_value(800);
    set_weight(1);
    set_material("crystal");
    add_property("quest");
}

void set_fetcher(object player)
{
    fetcher = player;
}

object query_fetcher(void)
{
    return fetcher;
}
