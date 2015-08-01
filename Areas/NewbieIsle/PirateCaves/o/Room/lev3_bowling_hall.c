#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

int stone_rolled;
// Each player can ring the bell to get a ball of their own
// once every reset. This removes need for special quest object
// reset in this room
string *bell_ringers = ({});

void create_object(void);
void reset(int arg);
void init(void);
int do_play(string str);
int do_roll(string str);
int do_ring(string str);
int do_sit(string str);
void reset_game(void);
int query_stone_rolled(void);

void create_object(void)
{
    ::create_object();
    set_short("A large hall (n)");
    set_long("A quite large hall with a smooth wooden floor. In this end of " +
             "the hall are some stools and a wooden table with some papers " +
             "on it and at the far end of the hall are stacks of open boxes " +
             "and barrels that seem to contain empty bottles. There are " +
             "also a few big piles of broken glass there. A small monkey is " +
             "scurrying about over there, seemingly performing some sort of " +
             "chores.\n");

    add_item("hall|large hall","It's quite narrow but rather long");
    add_item("floor|smooth floor|wooden floor|smooth wooden floor","The " +
             "floor is smooth and seems made to roll stones on");
    add_item("stool|stools","Stools are made for sitting on");
    add_item("table|wooden table","It is covered with papers. There's " +
             "also a small bell on it");
    add_item("bell|small bell","Maybe you could ring the bell?");
    add_item("paper|papers","They seem to have scores written on them");
    add_item("score|scores","Scores for some sort of game. You don't " +
             "quite understand them");
    add_item("stack|stacks","Stacks of boxes and barrels");
    add_item("box|boxes|open box|open boxes","Open boxes that seem to " +
             "contain empty bottles");
    add_item("barrel|barrels|open barrels|open barrels","Open barrels " +
             "that seem to contain empty bottles");
    add_item("pile|piles|big pile|big piles|glass|broken glass","Big piles " +
             "of broken glass");
    add_func_item("monkey","#query_stone_rolled",({
                  "It seems to be waiting for someone to roll a stone in " +
                  "the direction of some whole bottles it has lined up on " +
                  "the floor in the far end of the hall",
                  "It is sweeping away some broken glass and putting new " +
                  "whole bottles on the floor in the far end of the hall"
                 }));
    add_func_item("bottle|bottles|empty bottle|empty bottles|" +
                  "whole bottle|whole bottles",
                  "#query_stone_rolled",({
                  "The boxes seem to contain them and there are a few " +
                  "of them lined up on the floor in the far end of " +
                  "the hall",
                  "The boxes seem to contain them and the monkey is " +
                  "lining a few of them up on the floor in the far end " +
                  "of the hall"
                 }));

    add_exit(PCROOM + "lev3_stairs","north");

    reset(0);
}

void reset(int arg)
{
    add_monster(PCMONSTER + "bowling_pirate",1);
    bell_ringers = ({});
    if(!stone_rolled && !present("_pirate_quest_cannonball_",TO))
    {
        stone_rolled = 1;
        reset_game();
    }
}

void init(void)
{
    add_multi_action("do_roll","roll|throw");
    add_action("do_ring","ring");
    add_action("do_sit","sit");
    add_action("do_play","play");
}

int do_play(string str)
{
    if(str == "game")
    {
        W("To play the game you just need to get one of the round stones " +
          "the monkey keeps rolling back to this end of the hall, and " +
          "then roll it towards the other end.\n");
        return 1;
    }
}

int do_roll(string str)
{
    int success;
    object ball = present("_pirate_quest_cannonball_",TP);

    if(str == "ball" || str == "stone")
    {
        if(!ball)
        {
            W("You don't have suitable ball or stone to roll at the " +
              "bottles.\n");
            return 1;
        }
        if(!stone_rolled)
        {
            W("You roll the stone towards the bottles.\n");
            S(TP->QN + " rolls the stone towards the bottles.\n");
            success = random(TP->query_dex()) + random(TP->query_dic()) +
                      random(5) +
                      random(TP->query_skill("bowling")); // You never know ...
            switch(success)
            {
                case 0:
                  W("You don't even hit one single bottle. A pathetic " +
                    "roll!\n");
                  S(TP->QN + " doesn't even hit one single bottle. A " +
                    "pathetic roll!\n");
                  break;
                case 1:
                  W("You only manage to break one bottle. A very poor " +
                    "roll.\n");
                  S(TP->QN + " only manages to break one bottle. A very " +
                    "poor roll.\n");
                  break;
                case 2:
                  W("You only manage to break two bottles. Pretty poor " +
                    "roll.\n");
                  S(TP->QN + " only manages to break two bottles. Pretty " +
                    "poor roll.\n");
                  break;
                case 3:
                  W("You only manage to break three bottles. Not a good " +
                    "roll.\n");
                  S(TP->QN + " only manages to break three bottles. Not a " +
                    "good roll.\n");
                  break;
                case 4:
                  W("You manage to break four bottle. A half decent " +
                    "roll.\n");
                  S(TP->QN + " manages to break four bottles. A half " +
                    "decent roll.\n");
                  break;
                case 5:
                  W("You manage to break five bottles. A decent roll.\n");
                  S(TP->QN + " manages to break five bottles. A decent " +
                    "roll.\n");
                  break;
                case 6:
                  W("You manage to break six bottles. Pretty good " +
                    "roll.\n");
                  S(TP->QN + " manages to break six bottles. Pretty good " +
                    "roll.\n");
                  break;
                case 7:
                  W("You manage to break seven bottles. A good roll.\n");
                  S(TP->QN + " manages to break seven bottles. A good " +
                    "roll.\n");
                  break;
                case 8:
                  W("You manage to break eight bottles. A very good roll!\n");
                  S(TP->QN + " manages to break eight bottles. A very good " +
                    "roll!\n");
                  break;
                case 9:
                  W("You manage to break nine bottles. An excellent roll!\n");
                  S(TP->QN + " manages to break nine bottles. An excellent " +
                    "roll!\n");
                  break;
                default:
                  W("You manage to hit all ten bottles! A fantastic roll!\n");
                  S(TP->QN + " manages to hit all ten bottles! A fantastic " +
                    "roll!\n");
                  tell_room(TO,"The monkey at the other end of the hall " +
                            "applauds wholeheartedly!\n");
                  "/sys/admin/room/admin_room"->visit(1104);
                  break;
            }
            ball->destroy();
            stone_rolled = 1;
            tell_room(TO,"The monkey at the other end of the hall starts " +
                         "working to set up the game and roll the stone " +
                         "back to the player.\n");
            set_alarm(15.0,0.0,"reset_game");
            return 1;
        }
        else
        {
            W("You have to wait until the monkey has put some new bottles " +
              "up over there.\n");
            return 1;
        }
    }
    W("Roll what?\n");
    return 1;
}

int do_ring(string str)
{
    if(str == "bell")
    {
        if(member_array(TP->QRN,bell_ringers) == -1)
        {
            W("You ring the bell.\n");
            S(TP->QN + " rings the bell.\n");
            tell_room(TO,"The monkey disappears behind some barrels and " +
                         "reappears with a new stone.\nThe monkey rolls the " +
                         "stone to your end of the hall.\n");
            make(PCOBJECT + "cannonball");            bell_ringers += ({ TP->QRN });
        }
        else
        {
            W("You have already rung the bell and gotten a new stone.\n");
        }
        return 1;
    }
    notify_fail("Ring what?\n");
}

int do_sit(string str)
{
    if(str == "stool" || str == "on stool")
    {
        W("You sit down on a stool and watch others play for a while.\n");
        S(TP->QN + " sits down on a stool and watches others play for " +
          "a while.\n");
        return 1;
    }
    return notify_fail("Sit where?\n");
}

void reset_game(void)
{
    if(stone_rolled)
    {
        tell_room(TO,"The monkey at the other end of the hall has finished " +
                     "cleaning up the broken glass and setting up new " +
                     "bottles again and rolls a stone back to this end of " +
                     "the hall.\n");
        make(PCOBJECT + "cannonball");
        stone_rolled = 0;
    }
}

int query_stone_rolled(void)
{
    return stone_rolled;
}

int quest_reset()
{
  if(!stone_rolled && !present("_pirate_quest_cannonball_",TO))
  {
    stone_rolled = 1;
    reset_game();
    return 1;
  }
}
