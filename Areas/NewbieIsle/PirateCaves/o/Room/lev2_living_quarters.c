#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

int sextant_found;

void create_object(void);
void reset(int arg);
void my_reset(void);
void init(void);
int do_smell(string str);
int do_search(string str);

void create_object(void)
{
    ::create_object();
    set_short("Living quarters (e)");
    set_long("This room appears to be some sort of living quarters. " +
             "Many beds are lined up against the walls and at the foot of " +
             "each bed stands a small chest. There are a few small tables " +
             "and stools on the floor and empty bottles and dirty clothes " +
             "are everywhere. None of the beds are made and the sheets do " +
             "not look as if they've been changed for a very long time. " +
             "The smell in here is horrible.\n");

    add_item("room","It appears to be some sort of living quarters");
    add_item("quarters|living quarters","That's what this room seems to " +
             "be");
    add_item("bed|beds|filthy bed|filthy beds","They're not made and they " +
             "are filthy");
    add_item("chest|chests","There are quite a few chests here, probably " +
             "holding the belongings of the pirates. Maybe you would find " +
             "something interesting if you searched them?");
    add_item("belongings","You can't know what's there until you search " +
             "the chests");
    add_item("table|tables","Small tables with nothing on them but " +
             "empty bottles");
    add_item("stool|stools","They stand next to the tables");
    add_item("bottle|bottles|empty bottle|empty bottles","They're " +
             "everywhere in the room");
    add_item("clothes|dirty clothes","They lie on the beds and on the " +
             "floor. It is a real mess");
    add_item("mess|real mess","Indeed it is");
    add_item("sheet|sheets|filthy sheet|filthy sheets","They are " +
             "absolutely filthy. It's been a long time since someone " +
             "changed them");

    add_exit(PCROOM + "lev2_corridor3","east");

    reset(0);
}

void reset(int arg)
{
    add_monster(PCMONSTER + "pirate",3);
}

void my_reset(void)
{
    sextant_found = 0;
}

void init(void)
{
    add_action("do_smell","smell");
    add_action("do_search","search");
}

int do_smell(string str)
{
    W("The smell in here makes you feel like you want to throw up.\n");
    S(TP->QN + " sniffs the air and turns green in the face.\n");
    return 1;
}

int do_search(string str)
{
    object sextant;

    if(str == "chest" || str == "chests" || str == "belongings")
    {
        if(TP->query_skill("perception") > 10 + random(10))
        {
            if(!sextant_found)
            {
                W("You search through the " + str + " and find a " +
                  "sextant!\n");
                S(TP->QN + " searches the " + str + " and finds a " +
                  "sextant.\n");
                sextant = make(PCOBJECT + "sextant");
                if(transfer(sextant,TP))
                {
                    W("You're carrying too much to pick it up so you " +
                      "drop it on the floor.\n");
                    S(TP->QN + " drops it in the floor.\n");
                }
                sextant_found = 1;
                set_alarm(300.0,0.0,"my_reset");
            }
            else
            {
                W("It looks like someone has searched the " + str +
                  " already.\n");
                S(TP->QN + " searches through the " + str + " but " +
                  "doesn't seem to find anything.\n");
            }

        }
        else
        {
            W("You search the " + str + " but don't find anything. " +
              "Maybe you have to try again or maybe you're just not " +
              "perceptive enough.\n");
            S(TP->QN + " searches through the " + str + " but doesn't " +
              "seem to find anything.\n");
        }
        return 1;
    }
}