#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_block(string str);

void create_object(void)
{
    set_short("The west side of the inner courtyard of the castle");
    set_long("The west side of the inner courtyard of the castle. The yard " +
             "is crawling with marching and excercising troops and people " +
             "running around shouting. The courtyard continues to the east, " +
             "and further east are the massive inner walls of the castle " +
             "and the third gate tower. To the north, west and south are " +
             "the cold, black inner walls of the castle. There are " +
             "archways to the north and the south. The entrances to the " +
             "castle. Dark clouds are gathering in the sky above.\n");
    set_new_light(5);

    add_item("courtyard|yard","A yard paved with cobblestones. It is " +
             "crawling with activity");
    add_item("activity|troops|people","Darkling troops running and marching " +
             "around. They do not seem to take much notice of you");
    add_item("gate|gates|tower","The gates and the tower lies some distance " +
             "to the east");
    add_item("wall|walls","High, black stone walls without any windows. " +
             "There are only a few arrowslits high up there");
    add_item("arrowslit|arrowslits","The thin arrowslits are the closest " +
             "thing to windows you see on the walls");
    add_item("window|windows","There are no real windows facing the " +
             "courtyard");
    add_item("castle","You stand within its walls now");
    add_item("cloud|clouds","Dark threatening clouds are gathering over " +
             "the castle");

    add_exit(ROOM + "icourtyarde","east");
    add_exit(ROOM + "stable","north");
    add_exit(ROOM + "lev1_entr.c","south");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_sentry",2);
    add_monster(MONSTER + "darkling_guard",2);
    add_monster(MONSTER + "darkling_trooper",2);
}

void init(void)
{
    add_multi_action("do_block","n|north");
    add_multi_action("do_block","a|south");
    SYS_ADMIN->visit(281);
}

int do_block(string str)
{
    if(present("darkling",TO))
    {
        // It's pointless to make higher level evil chars screw up their
        // align just to go into the castle and get the explore. Lvl 10
        // is the trooper level
        if(TP->query_level() <= 10) {
            W("A darkling shoves you away and says: Get out of here! You " +
              "have no business here!\n");
            S(TP->QN + " tries to enter an archway, but a darkling stops " +
              TP->QO + ".\n");
            return 1;
        }
        else
        {
            W("A darkling mutters: They're not paying me enough to get in " +
              "the way of the likes of " + TP->QN + ".\n");
            S("A darkling mutters: They're not paying me enough to get in " +
              "the way of the likes of " + TP->QN + ".\n");
            return 0;
        }
    }
}
