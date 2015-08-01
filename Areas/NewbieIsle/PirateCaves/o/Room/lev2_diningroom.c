#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_sit(string str);
int do_eat(string str);
int do_drink(string str);
int do_swing(string str);

void create_object(void)
{
    ::create_object();
    set_short("A dining room (w)");
    set_long("An extremely messy dining room. The only furniture here are " +
             "two long tables with benches next to them in the middle of " +
             "the room. There's a fireplace in the east wall and the other " +
             "walls are painted with images of feasting pirates. Broken " +
             "tankards, plates and other utensils lie all over the room " +
             "and the floor and walls are practically covered with spilled " +
             "food and drink. A chandelier hanging from the ceiling is " +
             "providing light for the room.\n");

    add_item("room|dining room","It's extremely messy, it almost looks as " +
             "if there has been a battle here");
    add_item("furniture","There are two tables and four benches here");
    add_item("table|tables|long table|long tables","The tables are long " +
             "and covered with spilled food and drink. It's a real mess");
    add_item("bench|benches|wooden bench|wooden benches","Wooden benches " +
             "next to the tables. Used for sitting on while eating, " +
             "probably");
    add_item("mess","It's horrible, you can't understand why anyone would " +
             "want to live like this");
    add_item("fireplace","There's no fire in it at the moment, only " +
             "broken plates and tankards");
    add_item("east wall","There's a fireplace in it");
    add_item("wall|walls","All the walls except for the east one are " +
             "painted with images of feasting pirates. This room certainly " +
             "looks as if it's seen its fair share of those");
    add_item("image|images|pirates","The pirates in the images do seem to " +
             "be having a great time");
    add_item("tankard|broken tankard|tankards|broken tankards","Tankards " +
             "lying everywhere. Most of them are broken and useless");
    add_item("plate|broken plate|plates|broken plates","Plates lying " +
             "everywhere. Most of them are broken and useless");
    add_item("utensil|utensils|other utensil|other utensils","They're " +
             "lying everywhere in the room");
    add_item("floor","Practically covered in food and drink");
    add_item("food","Food spilled or thrown on the floor and the walls. " +
             "You wouldn't want to eat that");
    add_item("drink","Drink spilled or thrown on the floor and the walls. " +
             "You wouldn't want to drink that");
    add_item("chandelier","It hangs from the ceiling, letting you see " +
             "the horrible mess before you");
    add_item("ceiling","A chandelier hangs from it");


    add_exit(PCROOM + "lev2_corridor1","west");
    reset(0);
}

void reset(int arg)
{
    add_monster(PCMONSTER + "pirate",4);
}

void init(void)
{
    add_action("do_sit","sit");
    add_action("do_eat","eat");
    add_action("do_drink","drink");
    add_action("do_swing","swing");
}

int do_sit(string str)
{
    if(str == "bench" || str == "on bench")
    {
        W("You sit down on one of the benches for a while and observe the " +
          "horrible mess before you.\n");
        S(TP->QN + " sits down on a bench and stares at the mess.\n");
        return 1;
    }
    return notify_fail("Sit where?\n");
}

int do_eat(string str)
{
    if(!str || str == "food")
    {
        W("Nooo no, you definitely don't want to chew down that sloppy, " +
          "disgusting mess.\n");
        S(TP->QN + " watches the food for a while.\n");
        return 1;
    }
    return 0;
}

int do_drink(string str)
{
    if(!str || str == "drink")
    {
        W("Nooo no, you definitely don't want to swallow that stinking, " +
          "disgusting mess.\n");
        S(TP->QN + " watches the spilled drink for a while.\n");
        return 1;
    }
    return 0;
}

int do_swing(string str)
{
    if(str == "chandelier" || str == "from chandelier")
    {
        W("You jump up and grab hold of the chandelier and start swinging!\n" +
          "*WHHHHHHHHHHHHEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE*\n" +
          "You drop the chandelier and land on the floor again. That " +
          "was fun even if it ultimately was not rewarding.\n");
        S(TP->QN + " jumps up and grabs hold of the chandelier and starts " +
          "swinging!\n" +
          TP->QN + " yells: WHHHHHEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE!!\n" +
          TP->QN + " drops the chandelier and lands on the floor again.\n");
        return 1;
    }
    return notify_fail("Swing from what?\n");
}
