#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    ::create_object();
    set_short("A corridor (w/n/e)");
    set_long("A corridor going north from here. The corridor is lit by " +
             "a small shining stone sitting in a niche in one of the walls. " +
             "There is a filthy carpet on the floor and plenty of rubbish " +
             "is piled high against the walls. West of here is what seems " +
             "to be a kitchen, and to the east is a dining room.\n");

    add_item("corridor|filthy corridor","A filthy corridor. Noone's been " +
             "cleaning here in a long time");
    add_item("stone|small stone|small shining stone","It shines with a " +
             "soft, yellow light");
    add_item("light|yellow light|soft, yellow light","It comes from the " +
             "stone in the niche in the wall");
    add_item("niche","There's a small shining stone in it");
    add_item("carpet","There's dirt and stains on the carpet");
    add_item("dirt","There's plenty of it in this corridor");
    add_item("stain|stains","Looks like stains from spilled alcohol and " +
             "maybe even worse things");
    add_item("rubbish","It's piled pretty high against the walls");
    add_item("kitchen","It's west of here");
    add_item("dining room","It's east of here");

    add_exit(PCROOM + "lev2_kitchen","west");
    add_exit(PCROOM + "lev2_diningroom","east");
    add_exit(PCROOM + "lev2_corridor2","north");

    reset(0);
}

void reset(int arg)
{
    add_monster(PCMONSTER + "pirate",1);
}