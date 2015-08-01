#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

string quest_solver;

void create_object(void);
void reset(int arg);
void init(void);
int do_pray(string str);
int do_place(string str);
void end_quest(int step);

void create_object(void)
{
    set_short("A tranquil altarroom");
    set_long("This is the main chamber of the shrine. You suddenly feel at " +
             "ease and very calm. The floor, walls and ceiling are of " +
             "shining white marble, and a mosaic is laid in the floor. The " +
             "walls are decorated, and there is a glass dome in the " +
             "ceiling. The light coming through the dome falls upon an " +
             "altar in the centre of the room. You feel the gods are " +
             "present in this chamber and feel an urge to pray for their " +
             "blessing.\n");
    set_new_light(5);
    add_property("indoors");

    add_item("chamber|room","A peaceful chamber. The absence of dust here " +
             "is quite conspicous");
    add_item("floor","White marble with a mosaic laid in it");
    add_item("symbol|mosaic","A mosaic of the symbol of The Church of True " +
             "Faith");
    add_item("wall|walls","Marble walls with decorations on them");
    add_item("decorations|decoration","Paintings of gods and saints. Only " +
             "good beings are depicted here");
    add_item("god|gods","Kor and Cay are among them");
    add_item("saint|saints","Nicholaus, Patrick and Simon Templar are " +
             "among them");
    add_item("ceiling","A glass dome is letting light through the ceiling");
    add_item("dome","It lets a dome of light fall upon the altar. The " +
             "lighting is dim, since the branches of the trees outside " +
             "cover it");
    add_item("tree|trees","The ancient oaks outside");
    add_item("branch|branches","They hang over the dome, blocking out much " +
             "of the light");
    add_item("light","It is dim");
    add_item("altar","A white altar, made not out of marble, but some " +
             "strange material you do not recognize. The altar radiates a " +
             "holy power, as if it has been touched by the gods");

    add_exit(ROOM + "shrine_antechamber","south");

    reset(0);
}

void reset(int arg)
{
    // Just in case something gets messed up
    quest_solver = 0;
}

void init(void)
{
    add_action("do_pray","pray");
    add_multi_action("do_place","place|put");
    SYS_ADMIN->visit(288);
}

int do_pray(string str)
{
    W("You feel the blessing of the gods, and feel at peace and rested when " +
      "you lift your head again.\n");
    S(TP->QN + " bows " + TP->QPO + " head in prayer.\n");
    return 1;
}

int do_place(string str)
{
    object orb;

    if(str == "orb on altar" || str == "orb upon altar")
    {
        if(orb = present("_oakdale_quest_orb_",TP))
        {
            if(quest_solver)
            {
                W("You are too enthralled by the scene in front of you to " +
                  "do that.\n");
                return 1;
            }
            if(orb->query_fetcher() == TP)
            {
                W("As you place the orb upon the altar there is a bright " +
                  "flash, and the orb shatters into a million pieces. The " +
                  "milky white mist in the orb hangs suspended in mid " +
                  "air...\n");
                S("As " + TP->QN + " places the orb upon the altar there " +
                  "is a bright flash, and the orb shatters into a million " +
                  "pieces. The milky white mist in the orb hangs suspended " +
                  "in mid air...\n");
                orb->destroy();
                quest_solver = TP->QRN;
                if(!TP->test_flag(QUEST_FLAG))
                {
                    (OBJECT + "quest_object")->quest_solved(TP);
                    TP->add_exp((OBJECT + "quest_object")->
                                query_experience(TP->query_level()),1);
                }
                write_file(QUEST_LOG,"The quest was solved by " + TP->QN +
                           " at level " + TP->query_level() + ". " +
                           "Time: "+ ctime(time()) + ".\n");
                set_alarm(4.0,0.0,"end_quest",0);
                return 1;
            }
            W("Something feel wrong. It's like the magic is not here...\n" +
              "Could it be that you were not the one who fetched the orb?\n");
            return 1;
        }
        else
        {
            W("You do not have the orb on you!\n");
            return 1;
        }
    }
    return notify_fail("Place what upon what?\n");
}

void end_quest(int step)
{
    switch(step)
    {
        case 0: tell_room(TO,"The mist slowly takes the shape of a man, as " +
                          "a portal of light opens over the altar. The " +
                          "shining spirit turns towards you and smiles.\n");
                set_alarm(4.0,0.0,"end_quest",1);
          break;
        case 1: tell_room(TO,"Suddenly a scream echoes through the " +
                          "valley!!\n");
                (CASTLE + "Room/lev5_nirachs_study")->orb_destroyed();
                set_alarm(3.0,0.0,"end_quest",2);
          break;
        case 2: tell_room(TO,"A shriek is heard, and you feel something " +
                          "is approaching the shrine.\n");
                set_alarm(3.0,0.0,"end_quest",3);
          break;
        case 3: tell_room(TO,"The shriek grows louder and louder. " +
                          "Whatever it is, it's very close now.\n");
                set_alarm(4.0,0.0,"end_quest",4);
          break;
        case 4: tell_room(TO,"Suddenly a black shape sweeps into the room! " +
                          "You recoil in horror as two eyes filled with " +
                          "hatred glare at you!\n");
                set_alarm(4.0,0.0,"end_quest",5);
          break;
        case 5: tell_room(TO,"Alywin speaks: Nirach, it is time for us to " +
                          "depart. Nirachs spirit obeys, walking over to " +
                          "stand behind the radiant apparition of Alywin. " +
                          "Alywin turns towards you.\n");
                set_alarm(6.0,0.0,"end_quest",6);
          break;
        case 6: tell_room(TO,"Alywin says: I thank you, " + quest_solver +
                          ", for freeing me and thereby banishing Nirach. " +
                          "For years to come, the people of this valley " +
                          "will praise your name in song, and my prayers " +
                          "will be with you, always... Farewell.\n");
                set_alarm(7.0,0.0,"end_quest",7);
          break;
        case 7: tell_room(TO,"Alywin bows to you and the two spirits walk " +
                          "into the light. The light fades away. You look " +
                          "around and wonder if this was all just a " +
                          "dream...\n");
                shout("The bells in Oakdale chime for freedom.\n" +
                      C(quest_solver) + " has banished Nirach.\n" +
                      "The people of the valley are free!!!\n");
                quest_solver = 0;
          break;
        default: quest_solver = 0; // Just in case
          break;
    }
}
