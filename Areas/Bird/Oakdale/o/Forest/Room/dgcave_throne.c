#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_sit(string str);

void create_object(void)
{
    set_short("A larger cave with a high ceiling");
    set_long("A larger cave with a high ceiling. The chamber is dimly lit " +
             "by a few torches on the walls, creating long, strange " +
             "shadows. In the middle of the cave is a circle of stones, " +
             "obviously a fireplace. Wooden chairs and benches line the " +
             "walls and by the east wall stands a stone throne. This " +
             "room gives quite a solemn impression and is obviously a " +
             "room of some importance to the dark gnomes. You feel like " +
             "you are intruding on something just by being present.\n");
    set_new_light(10);
    add_property("indoors");

    add_item("chamber|cave","This cave seems to be of some importance");
    add_item("ceiling","The ceiling in this cave is way higher than in " +
             "any of the caves nearby");
    add_item("torch|torches","There are several wooden torches hanging " +
             "on the walls");
    add_item("walls","Rough stone walls");
    add_item("wall","A rough stone wall");
    add_item("shadow|shadows","Eerie shadows created by the flickering " +
             "torches");
    add_item("circle|stones|fireplace","A circle of large stones. " +
             "Apparently a fireplace");
    add_item("stone","A smooth, grey stone");
    add_item("chair|chairs","There are several wooden chairs in here");
    add_item("bench|benches","There are several wooden benches here");
    add_item("throne","A large stone chair by the east wall");

    add_exit(ROOM + "dgcave_guards","south");
    add_exit(ROOM + "dgcave_guards2","northwest");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "DGking",1);
    add_monster(MONSTER + "DGnome",4);
}

void init(void)
{
    add_action("do_sit","sit");
    SYS_ADMIN->visit(292);
}

int do_sit(string str)
{
    if(str == "in throne" || str == "on throne")
    {
        if(!present("_dark_gnome_king_"))
        {
            W("You sit down on the throne and gaze out over the hall. You " +
              "can't quite shake the feeling that you do not belong here. " +
              "Certainly not sitting on this throne.\n");
            S(TP->QN + " sits down on the throne and gazes out over the " +
              "hall.\n");
            return 1;
        }
        W("The dark gnome king is sitting there now!\n");
        return 1;
    }
    return notify_fail("Sit where?\n");
}
