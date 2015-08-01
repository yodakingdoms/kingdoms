#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
void init(void);
int do_taste(string str);
int do_sleep(string str);

void create_object(void)
{
    set_short("A small guardroom");
    set_long("A small room, lit by a flickering torch on the west wall. " +
             "There is a wooden table here, and a few stools are placed " +
             "round it. A few mugs are on the table, and a barrel stands " +
             "in one of the corners. Two beds are by the north wall. There " +
             "is a strange smell in the air here, but the odor seems to " +
             "come from the room to the south.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("room","There's no doubt about it. This is a guardroom");
    add_item("guardroom","This is a guardroom if you've ever seem one");
    add_item("torch","A lone torch, flickering desperatly");
    add_item("wall|walls","Smooth, black stone");
    add_item("table","A heavy oak table with a few mugs on it");
    add_item("mugs","Some wooden mugs. They are all empty");
    add_item("mug","A wooden mug. It is empty");
    add_item("stool|stools","A few hard wooden stools are placed around " +
             "the table");
    add_item("barrel","A wooden barrel. It's lid is open and it contains " +
             "red wine");
    add_item("wine","It looks like wine at least. Do you want to taste it?");
    add_item("corner","The corner that draws your attention is the one " +
             "with the barrel in it");
    add_item("beds","Two uncomfortable looking beds");
    add_item("bed","A bed that does not look very comfortable");
    add_item("%|%stench","Gnurr... The stench of putrid flesh seeps into " +
             "this room as well");

    add_exit(ROOM + "dung_meatroom","south");

    (ROOM + "dung_clericroom")->load_doors();

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_blocking_dung_guard",3);
    ::reset(arg);
}

void init(void)
{
    add_action("do_taste","taste");
    add_multi_action("do_sleep","sleep|nap|lie");
    ::init();
}

int do_taste(string str)
{
    if(str == "wine")
    {
        W("Hmm, doesn't taste like wine at all... Oh, no! Just as you " +
          "swallow you have an unpleasant thought. You sure hope this " +
          "red liquid is not what you suspect it was...\n");
        S(TP->QN + " tastes the liquid in the barrel.\n");
        return 1;
    }
    return notify_fail("Taste what?\n");
}

int do_sleep(string str)
{
    W("Oh, come on! You have more important things to do right now!\n");
    return 1;
}
