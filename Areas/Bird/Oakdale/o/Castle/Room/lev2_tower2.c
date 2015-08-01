#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("The second floor of the third gate tower");
    set_long("The second floor of the third gate tower. There are several " +
             "holes and wooden hatches on the floor, and large iron " +
             "cauldrons hang over the hatches in chains from the ceiling. " +
             "There are thin arrowslits in the west and south walls, and " +
             "archways to the east and the northwest.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("room","A room on the second floor of the tower");
    add_item("floor","A smooth, black stone floor with holes and wooden " +
             "hatches on it");
    add_item("hatch|hatches","The hatches cover shafts going down to the " +
             "tunnel below");
    add_item("hole|holes","Probably for firing arrows through, if an " +
             "attacking force would manage to come all the way down there");
    add_item("shafts|shaft","Probably used for pouring molten lead and " +
             "other nasty things down upon attackers in the tunnel below " +
             "through");
    add_item("cauldron|cauldrons","The big iron cauldrons are probably " +
             "being used for melting and keeping lead, that would be " +
             "poured down upon an attacking force in the tunnel below in");
    add_item("chain|chains","Strong iron chains holding up the cauldrons");
    add_item("ceilong|wall|walls","Smooth, black stone");
    add_item("arrowslits|arrowslit","Through the arrowslits in the west " +
             "wall you see the inner courtayard, and through those in the " +
             "south wall you see the outer courtyard");
    add_item("courtyard","You would have to go down there to get a good look");
    add_item("archway|archways","Two of them. One going east, the other " +
             "going northwest");

    add_exit(ROOM + "lev2_wall2","east");
    add_exit(ROOM + "lev2_guardroom2","northwest");

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
