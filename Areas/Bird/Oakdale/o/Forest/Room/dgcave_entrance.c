#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A small cave dug out of the hill");
    set_long("A small cave that has been dug out of the hill. The walls " +
             "and ceiling are smooth, and so is the packed dirt floor. " +
             "There is a wooden bench and a small table with two mugs " +
             "and two plates on it by the west wall. Behind the bench is " +
             "a wooden barrel. Two openings go further into the hill.\n");
    set_new_light(10);
    add_property("indoors");
        
    add_item("cave","This cave has been dug out by someone. It is not " +
             "natural");
    add_item("wall|walls","Smooth stone");
    add_item("ceiling","The ceiling is smooth stone");
    add_item("floor","The floor is smooth, packed dirt");
    add_item("bench","A small wooden bench");
    add_item("table","A small wooden table with two mugs and two plates " +
             "on it");
    add_item("mug|mugs","The mugs are empty");
    add_item("plate|plates","There's only some leftovers left on the plate");
    add_item("leftovers","What's been left over after a recently had meal");
    add_item("barrel","The barrel contains water");
    add_item("water","It does not look very clean. You shouldn't drink " +
             "something like that");
    add_item("opening|openings","Going through any one of them would take " +
             "you further into the hill");
    
    add_exit(ROOM + "stone_quarry","out");
    add_exit(ROOM + "dgcave_beds","north");
    add_exit(ROOM + "dgcave_kitchen","east");
    
    reset(0); 
}

void reset(int arg)
{
    add_monster(MONSTER + "DGnome",2);
}
