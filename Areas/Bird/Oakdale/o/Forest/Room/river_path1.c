#include "../def.h"
#pragma strict_types
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_back(string str);
int do_swim(string str);

void create_object(void)
{
    set_short("A path followning the river downstream");
    set_long("You are on a path following the river. The river flows " +
             "swiftly from the northeast to the south, and the forest " +
             "grows all the way down to the riverbank on the other side. " +
             "To the north is the boathouse. The path continues south, " +
             "following the river, and northeast, turning in through the " +
             "opening in the boathouse. The castle looms over the forest " +
             "to the northeast.\n");
    set_new_light(5);

    add_item("path","You can follow it downstream to the south, or " +
             "northeast, back into the boathouse");
    add_item("river","The river flows rapidly to the south. It is not " +
             "very wide, but it would still be foolish to try and swim " +
             "across it");
    add_item("forest","A dark, silent forest of oak trees");
    add_item("oak|oaks|tree|trees","Huge, majestic trees");
    add_item("bank|riverbank","The steep bank is littered with stones and " +
             "boulders");
    add_item("boulder|boulders","Large boulders carried here by the river");
    add_item("stone|stones","Smaller stones carried here by the river");
    add_item("boathouse","A wooden house with nets hanging on the wall. " +
             "There is an opening in the east wall, which you will enter " +
             "if you go northeast");
    add_item("net|nets","The nets have been hung up to dry");
    add_item("opening","You'll enter the boathouse through it if you go " +
             "northeast");
    add_item("castle","Dark and sinister it stands there, quietly guarding " +
             "the village");

    add_sounds(10,30,({ "You are covered with drizzle as the river slams " +
                        "into the rocks by the water's edge.\n",
                        "The river roars as it flows south.\n" }));

    add_exit(ROOM + "river_path2","south");
    add_exit(VILLAGE + "Room/boathouse","northeast");
}

void init(void)
{
    add_multi_action("do_back","ne|northeast");
    add_multi_action("do_swim","swim|dive|enter");
    SYS_ADMIN->visit(293);
    ::init();
}

int do_back(string str)
{
    W("You follow the path round the corner and step back into the house " +
      "through the opening.\n");
    S(TP->QN + " follows the path round the corner of the house.\n");
    return 0;
}

int do_swim(string str)
{
    if(str == "river" || str == "in river" || str == "into river" ||
       str == "across river")
    {
        if(TP->query_skill("swim") < 30)
        {
            W("You idiot! You can hardly take a bath without drowning, " +
              "and you think you could swim in this river??\n");
            S(TP->QN + " stares longingly across the river.\n");
            return 1;
        }
        W("As you walk down to the riverbank, the river begins to roar " +
          "louder and louder, like a beast waiting to be fed. You hear " +
          "soft voices from the water, beckoning you to join them! " +
          "Horrified you summon your willpower and break the spell. You " +
          "won't try that again!\n");
        S(TP->QN + " walks down to the rivers edge and stares dreamily " +
          "into the water for a while.\n");
        return 1;
    }
    return notify_fail("Swim where?\n");
}
