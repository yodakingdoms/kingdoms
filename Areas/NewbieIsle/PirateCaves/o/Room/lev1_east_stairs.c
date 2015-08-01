#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    ::create_object();
    set_short("Stairs (w/eu)");
    set_long("An underground corridor going west. To the east are some " +
             "stairs going up to a doorway leading outside. You see trees " +
             "and bushes outside the doorway and it looks as if there's a " +
             "forest out there. There are carvings and drawings in the " +
             "wall around the doorway and the steps of the stairs are worn " +
             "but sculpted in a way that makes it look like you're walking " +
             "on leaves when you climb the stairs.\n");

    add_item("corridor|underground corridor","The corridor goes west " +
             "from here");
    add_item("stair|stairs","The stairs go up to an opening that leads " +
             "outside");
    add_item("opening|doorway","It leads outside");
    add_item("tree|trees|bush|bushes|forest","It looks as if you'll come " +
             "out into a forest if you climb the stairs and go outside");
    add_item("carving|carvings|drawing|drawings","They depict birds of " +
             "various sizes");
    add_item("bird|birds","Most of the birds are pretty small but there " +
             "are a few of them that seem to be larger birds of prey");
    add_item("small bird|small birds","Small birds flying around merrily");
    add_item("large bird|larger bird|large birds|larger birds|bird of prey|" +
             "birds of prey","They seem to be gliding around eyeing the " +
             "smaller birds hungrily");
    add_item("step|steps","They are worn but sculpted to look like they " +
             "are made of leafs");
    add_item("leaf|leafs","Stone leaves, worn by people walking on them");

    add_exit(PCROOM + "lev1_ew_corridor2","west");
    add_exit(PCROOM + "bird_tower_path1","eastup");

    reset(0);
}

void reset(int arg)
{
    add_monster(PCMONSTER + "pirate",1);
}