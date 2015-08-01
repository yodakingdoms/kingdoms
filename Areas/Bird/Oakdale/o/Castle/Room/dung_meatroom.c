#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_smell(string str);

void create_object(void)
{
    set_short("A storage room for corpses");
    set_long("Your stomach almost turns inside out when the light you bring " +
             "illuminates the room and reveals the source of the disgusting " +
             "smell. This is a cold, damp dungeon room with rough stone " +
             "walls. Hanging in iron hooks from the ceiling, head down, in " +
             "neat lines from wall to wall, are dozens of of corpses. Human " +
             "corpses. Some are dismembered, some look really fresh. So " +
             "this is what happens to the people who disappear from the " +
             "village... The room looks very much, even if you'd rather " +
             "not think the thought, like a food storage. The smell is " +
             "appaling.\n");
    set_new_light(0);
    add_property("indoors");

    add_item("room|storage","A horrible sight. Human corpses are hung up " +
             "like steaks at the butcher's. The smell here is awful");
    add_item("corpse|corpses","Probably the corpses of poor villagers " +
             "abducted from the village. So this is what darklings eat..");
    add_item("wall|walls","Rough, black stone");
    add_item("ceiling","Rough, black stone");
    add_item("hook|hooks","The iron hooks have been driven through the " +
             "feet or legs of the corpses they hold up");
    add_item("leg|legs|feet|foot","You can't bear to look at that");

    add_exit(ROOM + "dung_torture","east");
    add_exit(ROOM + "dung_stairroom2","north");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "munching_darkling",1);
}

void init(void)
{
    add_action("do_smell","smell");
}

int do_smell(string str)
{
    W("Oh by the gods! You can't take this any longer!\n");
    S(TP->QN + " smells the air and looks appalled.\n");
    TP->command("flee");
    return 1;
}

