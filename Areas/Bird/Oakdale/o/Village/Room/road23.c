#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

int pole_found;

void create_object(void);
void reset(int arg);
void init(void);
int do_search(string str);

void create_object(void)
{
    set_short("A road going south from the village square");
    set_long("You are on a road going south from the main square of the " +
             "village. The road turns here, and you can follow it north " +
             "or west. To the east is a grove and to the south is what " +
             "appears to be a boathouse. Behind the house to the southeast " +
             "and to the south you see the river. You can hear the river " +
             "flowing swiftly past this point. More to the northeast than " +
             "to the east now you see the castle loom over the village.\n");
    set_new_light(5);

    add_item("grove","A grove of oak trees. It's dark in there and you can't "+
            "see very far into it");
    add_item("boathouse","It has no chimney and it lies right down by the "+
            "river. Nets and oars hang on the walls");
    add_item("nets","They hang there to dry");
    add_item("oars","Spare oars to use when the normal ones break");
    add_item("river","It flows swiftly past this point. There are some reeds "+
            "growing right by the riverside");
    add_item("reeds","They are growing down by the riverside. There does not "+
            "seem to be anything special about them");
    add_item("castle","It stands there silently overlooking the village");
    add_item("$|$river","You can hear the river rush past behind the " +
             "boathouse");

    add_exit(ROOM + "road22","north");
    add_exit(ROOM + "road24","west");
    add_exit(ROOM + "boathouse","south");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "dog",1);
    pole_found = 0;
}

void init(void)
{
    add_action("do_search","search");
}

int do_search(string str)
{
    object pole;

    if(str == "reeds")
    {
        if(!pole_found)
        {
            W("Among the reeds you find a fishing pole that someone's " +
              "left behind.\n");
            S(TP->QN + " searches through the reeds and finds a fishing " +
              "pole.\n");
            pole = make(WEAPON + "pole");
            if(transfer(pole,TP))
            {
                W("It's too heavy for you to pick up so you leave it on " +
                  "the ground.\n");
                S(TP->QN + " drops the fishing pole on the ground.\n");
            }
            pole_found = 1;
            return 1;
        }
        else
        {
            W("You search through the reeds but don't find anything " +
              "interesting.\n");
            S(TP->QN + " searches through the reeds. Apparently without " +
              "finding anything interesting.\n");
            return 1;
        }
    }
    return notify_fail("Search what?\n");
}
