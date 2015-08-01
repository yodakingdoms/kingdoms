#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_drink(string str);

void create_object(void)
{
    ::create_object();
    set_short("A small stable (s)");
    set_long("A small stable with stone walls and a low ceiling. The floor " +
             "is dirty and covered with trampled hay. Some wooden poles " +
             "come up out of the floor, supporting the ceiling. Iron hooks " +
             "are nailed to the poles and ropes hang from them. There are " +
             "a few wooden troughs on the floor by the walls and in one " +
             "corner stands a large barrel. In another corner you see some " +
             "shovels, pitchforks and other tools carefully stacked. The " +
             "smell here is pretty terrible, in a farm animal kind of way.\n");

    add_item("stable|small stable","It looks a bit small to you, but it " +
             "would probably seem big and nice to someone the size of a " +
             "hobbit");
    add_item("wall|walls|stone wall|stone walls|stone","The walls are " +
             "made of stone and they look very strong. Excellent " +
             "workmanship has gone into making these walls");
    add_item("ceiling","It's pretty low and you have to be careful not to " +
             "bump your head. It's high enough that you would not have " +
             "to worry about that if you were a hobbit though");
    add_item("floor|dirty floor|filthy floor","The floor is absolutely " +
             "filthy and it smells awful");
    add_item("%|%floor|%smell","You feel like you're going to throw up. " +
             "It's clear you are not farmer material");
    add_item("hay|trampled hay","It's been laid out all over the floor, " +
             "perhaps to absorb moisture");
    add_item("moisture","The kind of moisture that comes from horses " +
             "now and then, probably");
    add_item("pole|poles|wooden pole|wooden poles","They look very sturdy " +
             "and support the ceiling well");
    add_item("hook|hooks|iron hook|iron hooks","Hooks used for hanging " +
             "things on. Right now there are some ropes and also a leather " +
             "strap hanging from them");
    add_item("rope|ropes","Just some normal ropes, probably used to " +
             "tie animals here");
    add_item("animals","This stable is probably used to keep horses in");
    add_item("horses","Maybe there are some here right now, maybe " +
             "there aren't");
    add_item("strap|leather strap","A strap of the kind you put on the " +
             "head of a horse when you want to ride it");
    add_item("trough|troughs|wooden trough|wooden troughs","That's where " +
             "the food for the horses should be. They're empty now");
    add_item("corner|corners","There is a barrel in one of them");
    add_item("barrel|wooden barrel","The barrel has water in it");
    add_item("water","It is not very clear and does not look suitable " +
             "for drinking");
    add_item("shovel|shovels|pitchfork|pitchforks|tool|tools","Your normal " +
             "stable kind of tool");
    add_item("%|%stench|%animal|%animals","Your nostrils are filled with " +
             "the kind of stench farm animals create when many of them " +
             "they stand around close together for a long time");

    add_exit(ROOM + "farm_center","south");
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "horse",3);
}

void init(void)
{
    add_multi_action("do_drink","drink|taste");
}

int do_drink(string str)
{
    if(str == "water" || str == "from barrel" || str == "water from barrel")
    {
        W("The water might be suitable for hobbit horses, but since you " +
          "are not a hobbit horse you decide not to try it.\n");
        S(TP->QN + " looks closely at the water in the barrel.\n");
        return 1;
    }
    return notify_fail(C(query_verb()) + " what?\n");
}
