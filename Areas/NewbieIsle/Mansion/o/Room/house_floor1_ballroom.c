#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_dance(string str);
int do_perform(string str);
int do_close(string str);
int do_break(string str);

void create_object(void)
{
    set_short("A ballroom (w)");
    set_long("This used to be the ballroom of the mansion. The room is " +
             "large and it has big windows in the east wall. Two large, " +
             "red curtains hang on both sides of the windows. In the south " +
             "wall is a small stage where the performers used to stand when " +
             "there was dancing going on here. The wooden floor is covered " +
             "with small stones and other debris. The west and north walls " +
             "are covered by murals depicting happy, dancing people. A " +
             "large chandelier still hangs down from the ceiling.\n");

    set_new_light(5);
    add_property("indoors");

    add_item("room|ballroom|magnificent","It was probably magnificent once " +
             "but not anymore. This was probably where parties were held");
    add_item("mansion","Judging by the state it is in, it was a long time " +
             "since whoever lived here abandoned it");
    add_item("wall|walls","The east wall has large windows in it, there " +
             "is a stage in the south, and the others are covered with " +
             "murals");
    add_item("window|windows|big window|big windows|intact window|" +
             "intact windows","Big windows in the east wall. They are " +
             "still intact and are painted with patterns");
    add_item("pattern|patterns|abstract pattern|abstract patterns","Just " +
             "some abstract patterns, not really meant to look like " +
             "anything");
    add_item("east wall","There are some big windows in it, they are still " +
             "intact, strangely enough");
    add_item("curtains|curtain|large curtain|large curtains|red curtain|" +
             "red curtains|large, red curtain|large, red curtains","They " +
             "hang by the side of the windows and are big enough to cover " +
             "the whole wall. They don't seem to be in a very good shape " +
             "but at least they're still hanging there");
    add_item("south wall","There is a stage where performers probably " +
             "used to stand in that wall");
    add_item("performers|performer","There are no performers here now, " +
             "maybe you could climb the stage and put in a performance " +
             "yourself?");
    add_item("stage","The stage is empty now, maybe you could climb it " +
             "and perform something there yourself?");
    add_item("floor|wooden floor|hard floor|hard wooden floor","A hard " +
             "wooden floor of the kind that's nice to dance on");
    add_item("stone|stones|small stone|small stones","There are plenty of " +
             "them on the floor, they seem to have fallen from the ceiling");
    add_item("ceiling","There are plenty of cracks in the ceiling, you " +
             "feel somewhat uneasy to be standing below it. A large " +
             "chandelier still hangs down from it");
    add_item("crack|cracks","There are plenty of them in the ceiling, " +
             "running from wall to wall");
    add_item("debris","There is plenty of it on the floor, it looks like " +
             "what's left of the furniture that was once here");
    add_item("furniture","There's no furniture here anymore");
    add_item("west wall|north wall|west and north walls","Covered with " +
             "murals of happy people");
    add_item("mural|murals","They show happy people feasting and dancing. " +
             "They also show performers on a stage, entertaining the " +
             "people");
    add_item("people|happy people|dancing people|happy, dancing people",
             "They seem to be having a very good time, and in days gone " +
             "by that's probably what those who lived here had in this " +
             "room as well");
    add_item("chandelier|large chandelier","A large chandelier still " +
             "hangs from the ceiling. It looks like it could fall down " +
             "at any moment");

    add_exit(ROOM + "house_floor1_entrance","west");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "goblin",2);
}

void init(void)
{
    add_action("do_dance","dance");
    add_multi_action("do_perform","climb|perform");
    add_action("do_close","close");
    add_action("do_break","break");
}

int do_dance(string str)
{
    W("The room feels a bit eerie and you're not really in the mood for " +
      "dancing right now.\n");
    S(TP->QN + " looks around the room and looks a bit nervous.\n");
    return 1;
}

int do_perform(string str)
{
    if(str == "stage" || str == "on stage" || str == "onto stage")
    {
        W("You climb the stage.\n");
        S(TP->QN + " climbs the stage.\n");
        TP->command("sing");
        W("That was nice, you climb down onto the floor again.\n");
        S(TP->QN + " climbs off the stage again.\n");
        return 1;
    }
    return notify_fail(C(query_verb()) + " where?\n");
}

int do_close(string str)
{
    if(str == "curtain" || str == "curtains")
    {
        W("The curtains are so filthy you'd rather not touch them. They " +
          "also look as if they could disintegrate if you touch them.\n");
        S(TP->QN + " examines the curtains for a while.\n");
        return 1;
    }
    return notify_fail("Close curtain.\n");
}

int do_break(string str)
{
    if(str == "window" || str == "windows")
    {
        W("The windows have survived a very long time, it would be a pity " +
          "if some little vandal came along and broke them now.\n");
        S(TP->QN + " steps up to the windows and admires them for a while.\n");
        return 1;
    }
    return notify_fail("Break what?\n");
}
