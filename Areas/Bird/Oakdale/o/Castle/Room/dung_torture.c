#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_smell(string str);

void create_object(void)
{
    set_short("A torture chamber");
    set_long("A warm dungeon chamber with long, strange shadows dancing " +
             "on the rough stone walls. A fire is burning in the fireplace " +
             "in the north wall, and an odd table stands in the centre of " +
             "the room. There are chains and manacles on the walls, and all " +
             "around the room are strange tools and instruments. An " +
             "unpleasant smell is coming from the west.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("room|chamber","A dungeon room that looks very much like a " +
             "torture chamber");
    add_item("shadow|shadows","Eerie shadows created by the fire in the " +
             "fireplace");
    add_item("wall|walls","Rough, black stone. The walls are lined with " +
             "chains with manacles on them");
    add_item("chain|chains|manacle|manacles","Probably used for chaining " +
             "prisoners to the walls with");
    add_item("fire|fireplace","A hot fire is burning in the fireplace");
    add_item("table","A table that can be tilted in several directions. " +
             "There are iron 'bracelets' with locks on them in various " +
             "strategic positions on the surface of the table. It is quite " +
             "obvious that this table is used for other things tan eating " +
             "from..");
    add_item("lock|locks","Complex iron locks");
    add_item("bracelet|bracelets","It looks like they could be used for " +
             "fixating limbs, i.e locking arms and legs in different " +
             "configurations on the table");
    add_item("tool|tools|instrument|instruments","Equipment of the kind " +
             "you'd use if you really wanted to torture the crap out of " +
             "someone. And I mean litterally!");
    add_item("equipment","Nasty tools indeed");

    add_exit(ROOM + "dung_guardroom3","east");
    add_exit(ROOM + "dung_meatroom","west");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_torturer",1);
}

void init(void)
{
    add_action("do_smell","smell");
}

int do_smell(string str)
{
    W("You smell a disgusting, putrid smell of decay coming from the room " +
      "to the west.\n");
    S(TP->QN + " smells the air and looks appaled.\n");
    return 1;
}
