#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_turn(string str);

void create_object(void)
{
    set_short("Second floor of the inner gate tower");
    set_long("A large room up on the second floor of the inner gate tower. " +
             "There are narrow arrowslits in the north and east walls, and " +
             "the floor is full of small holes and wooden hatches. Over the " +
             "hatches are iron cauldrons hanging in chains from the " +
             "ceiling. Most of the room, however, is taken up by the huge " +
             "machinery that raises and lowers the drawbridge and the " +
             "portcullises of the tower. There are archways in the west and " +
             "north walls.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("room","A large room on the second floor of the tower");
    add_item("arrowslits|slits","Through the arrowslits in the north wall " +
             "you see the outer courtyard. Through the ones in the east " +
             "wall you see the drawbridge");
    add_item("courtyard|drawbridge","You would have to go down there to " +
             "get a good look");
    add_item("wall|walls","Smooth, black stone");
    add_item("floor","The floor is full of small holes and wooden hatches");
    add_item("hole|holes","Probably for shooting arrows through");
    add_item("hatch|hatches","There are shafts under the hatches");
    add_item("shaft|shafts","Probably for pouring lead and other nasty " +
             "things down at attackers in the tunnel below through");
    add_item("cauldron|cauldrons","Probably for melting and keeping lead " +
             "in, lead that will be poured down upon attackers entering " +
             "the tunnel below");
    add_item("ceiling","A smooth, black stone ceiling");
    add_item("machinery","A huge machinery with a thick iron chain running " +
             "through it. You notice a big wooden wheel that apparently " +
             "operates the whole thing");
    add_item("wheel","When the wheel is turned, the drawbridge will be " +
             "raised");
    add_item("chain","A huge chain, attacked to the drawbridge");
    add_item("archway|archways","Just go through them if you're curious");

    add_exit(ROOM + "lev2_guardroom1","west");
    add_exit(ROOM + "lev2_wall1","north");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_trooper",3);
    foreach(object ob: all_inventory())
    {
        if(ob->id("darkling")) ob->set_aggressive(1);
    }
}

void init(void)
{
    add_action("do_turn","turn");
}

int do_turn(string str)
{
    W("You try as hard as you can to turn the wheel but you can't budge " +
      "it. It would take several strong hands to raise the drawbridge.\n");
    S(TP->QN + " tries to turn the wheel operating the machinery. The " +
      "veins on " + TP->QPO + " forehead stands out, and " + TP->QPO +
      " face turns red, but apparently " + TP->QPR + " can't budge it.\n");
    return 1;
}
