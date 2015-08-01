#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

int key_found;

void create_object(void);
void reset(int arg);
void init(void);
int do_search(string str);

void create_object(void)
{
   set_short("The Oakdale Sanatarium");
   set_long("You have entered the Oakdale Sanatarium. This is the main " +
            "room of the building and the office of the warden. The roof " +
            "and ceiling is made of wood, as are three of the walls. The " +
            "east wall is made of stone and there's a door with a sign on " +
            "it. A desk stands by the north wall and some stairs lead up " +
            "to the second floor. You can hear people screaming from " +
            "behind the east wall.\n");
    set_new_light(10);
    add_property("indoors");

    add_item("ceiling|floor","Made of wood");
    add_item("walls","Three of them are made of wood, the east one is " +
             "made of stone. You assume they store the lunatics behind " +
             "that wall");
    add_item("stone|wall","The east wall is made of large grey stones");
    add_item("sign","Try reading it");
    add_item("desk","A desk made of oak. There is a drawer in it");
    add_item("drawer","The drawer is filled with papers and documents. " +
             "A quick glance in the drawer reveals nothing of interest");
    add_item("$|$screams|$people|$rambling","You hear people scream and " +
             "ramble from behind the east wall");
    add_item("@sign|sign","Please do not leave this door open. We do not " +
             "want the lunatics to get out.\n-The village council-");

    add_exit(ROOM + "road12","west");
    add_exit(ROOM + "sanatarium4","up");

    (ROOM + "sanatarium2")->load_doors();
    reset(0);
}

void reset(int arg)
{
    key_found = 0;
    add_monster(MONSTER + "warden",1);
    ::reset(arg);
}

void init(void)
{
    add_action("do_search","search");
    ::init();
}


int do_search(string str)
{
    object key;

    if(str == "drawer")
    {
        SYS_ADMIN->visit(289);
        if(!key_found)
        {
            W("You go through the drawer hoping that noone will pay " +
              "attention, and lo! Under all the papers and documents you " +
              "find a small, black key.\n");
            S(TP->QN + " searches through the drawer as quickly as " +
              TP->QPR + " can. With a triumphant smile " + TP->QPR +
              " picks up a small key from the drawer.\n");
            key = make(OBJECT + "key");
            if(transfer(key,TP))
            {
                W("It's too heavy for you to pick up so you drop it on the " +
                  "floor.\n");
                S(TP->QN + " drops the key on the floor.\n");
            }
            key_found = 1;
            return 1;
        }
        else
        {
            W("You search through the drawer, but you can't find anything " +
              "of interest. It looks as if someone else has searched it " +
              "not too long ago though.\n");
            S(TP->QN + " searches through the drawer. Apparently without " +
              "finding anything of interest.\n");
            return 1;
        }
    }
    return 0;
}
