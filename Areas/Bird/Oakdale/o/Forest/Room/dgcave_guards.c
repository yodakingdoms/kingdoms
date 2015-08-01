#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_drink(string str);

void create_object(void)
{
    set_short("A small, dimly lit cave");
    set_long("A small cave with a torch on the wall. This cave is warm " +
             "and almost cosy. A small fire burns in a circle of stones on " +
             "the floor, providing the room with warm light and making the " +
             "shadows dance on the wall. An opening to the north leads to " +
             "what seems to be a bigger cave. The stone floor is smooth " +
             "and in the east part of the cave is a small wooden table " +
             "and two stools.\n");
    set_new_light(10);
    add_property("indoors");
        
    add_item("cave","A small cave, apparently serving as a guardroom");
    add_item("torch","A torch providing light for the cave");
    add_item("opening","A larger cave seems to lie beyond that opening");
    add_item("floor|wall|walls","Smooth stone");
    add_item("fire","A small fire giving the room a pleasant atmosphere");
    add_item("table","A wooden table with a mug on it");
    add_item("mug","A wooden mug with some liquid in it that seems to have " +
             "pretty high alcohol content, judging by the smell");
    add_item("stools","Two wooden stools");
    add_item("stool","A wooden stool");
    add_item("$|$air|$smell","There is a strong smell of alcohol in the air");
    add_item("$liquid","Cough! This stuff seems strong enough to deck the " +
             "Dark Young!");
    
    add_exit(ROOM + "dgcave_kitchen","west");
    add_exit(ROOM + "dgcave_throne","north");
    
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "DGguard",2);
}

void init(void)
{
    add_multi_action("do_drink","drink|taste");
}

int do_drink(string str)
{
    if(str == "liquid")
    {
        W("You raise the mug and are hit by the strong smell of alcohol. " +
          "You carefully dip the tip of your tongue in the stuff and " +
          "smallow a drop. Holy Bithir! The room starts spinning, and your " +
          "stomach rebels!\n");
        S(TP->QN + " tastes the liquid in the mug carefully, looks up, " +
          "distressed, and wobbles around in the room in panic!\n");
        TP->command("wobble");
        TP->command("trip");
        TP->command("puke");
        return 1;
    }
    return notify_fail("Drink what?\n");
}
