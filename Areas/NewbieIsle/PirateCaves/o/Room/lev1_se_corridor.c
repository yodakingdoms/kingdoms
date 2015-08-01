#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;
inherit MOD_SOUND;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    ::create_object();
    set_short("An underground corridor (s/e/n)");
    set_long("An underground corridor going south and east, with an "+
             "opening to the north. The opening leads out onto something " +
             "that looks like a balcony. Air from the outside flows into " +
             "the corridor, making you feel less cramped than in the " +
             "rest of the corridors on this level. You see some vines " +
             "growing on the outside hanging down to cover the opening.\n");

    add_item("corridor","It is an underground corridor with stone walls, " +
             "floor and ceiling");
    add_item("corridors","They probably look like the corridor you are in " +
             "now");
    add_item("opening","It leads outside");
    add_item("balcony","That's what it looks like, you'd have to go out " +
             "there to get a better look");
    add_item("air","The air is fresher here than it seems to be on the rest " +
             "of this level");
    add_item("level|this level","The level you are on now");
    add_item("vine|vines","They grow outside the opening and hang down to " +
             "cover it");

    add_exit(PCROOM + "lev1_balcony","north");
    add_exit(PCROOM + "lev1_ew_corridor2","east");
    add_exit(PCROOM + "lev1_ns_corridor1","south");

    add_sounds(30,80, ({ "You feel a soft wind from the north.\n" }));

    reset(0);
}

void reset(int arg)
{
    add_monster(PCMONSTER + "pirate",2);
}
