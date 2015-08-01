#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_smell(string str);

void create_object(void)
{
    set_short("A small, round cave");
    set_long("A small, round cave with a low ceiling. It is difficult to " +
             "stand up straight in here without bumping your head. The " +
             "gray stone walls are rough, and a bit to close to each " +
             "other for you to feel completely at ease. To the northeast " +
             "is another, larger cave. A disgusting smell is coming from " +
             "that direction. South is an opening that will take you out " +
             "into the open air again. The smell and cramped nature of " +
             "this cave makes that opening look very inviting\n");
    set_new_light(0);
    add_property("indoors");
    
    add_item("cave","A small, round cave with rough stone walls, floor and " +
             "ceiling. You feel cramped in here, and you'd rather leave");
    add_item("floor|ceiling","Rough, gray stone");
    add_item("wall|walls","The rough stone walls seem to close in on " +
             "you, giving you a most unpleasant feeling");
    add_item("opening","It will take you back out into the quarry");    
    
    add_exit(ROOM + "stone_quarry","out");
    add_exit(ROOM + "dgcave_dump","northeast");
}

void init(void) 
{
    add_action("do_smell","smell");
}

int do_smell(string str)
{
    W("BLEEARGH! It smells like a garbage dump!\n");
    S(TP->QN + " smells the air, turns green and goes: BLEEARGH!\n");
    return 1;
}
