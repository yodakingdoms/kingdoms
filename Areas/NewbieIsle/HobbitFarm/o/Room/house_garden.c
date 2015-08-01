#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

string *pickers;

void create_object(void);
void reset(int arg);
void init(void);
int do_climb(string str);
int do_relax(string str);
int do_pick(string str);

void create_object(void)
{
    set_short("A garden behind the house");
    set_long("A small garden behind the hobbit house. On the north side of " +
             "the garden is the big grassy hill with the huge oak growing " +
             "on top of it. There are windows in the side of the hill, and " +
             "there are also some wooden steps going up towards the top. " +
             "A wooden fence encircles the garden in the other directions. " +
             "There are some bushes with berries planted next to the fence " +
             "and two apple trees grow next to them. There's also a tiny " +
             "field where there seem to be carrots growing here, and small " +
             "flowers grow in the grass all over the garden. Next to the " +
             "door stands a small wooden bench.\n");

    set_new_light(5);
    set_skip_obvious(1);

    add_item("garden|small garden","It's hidden away behind the house and " +
             "seems to be a peaceful place, nice for relaxing in");
    add_item("house|hobbit house","Hobbits like to live in houses like " +
             "this one, a hollowed out hill");
    add_item("hill|grassy hill|big hill|big grassy hill|hollowed out hill",
             "The hill functions as a hobbit house");
    add_item("oak|huge oak","From down here it looks as if it might be " +
             "the biggest oak you have ever seen");
    add_item("window|windows|round window|round windows","Round windows, " +
             "their curtains are not drawn");
    add_item("curtain|curtains","The curtains are open so you can't see " +
             "them from the outside");
    add_item("side|side of the hill","There's a door and some windows " +
             "there, and some steps go up onto the hill");
    add_item("step|steps|wooden step|wooden steps","You can climb the " +
             "steps if you want to get up to the top of the hill");
    add_item("top|roof","The top of the hill would be the roof of the house");
    add_item("fence|wooden fence|neat fence|neat wooden fence","A neat " +
             "wooden fence that's meant for marking the boundary of the " +
             "garden rather than keeping animals and people in and out of it");
    add_item("boundary","It's where the garden ends or begins, depending " +
             "on which side of it you are");
    add_item("bush|bushes","The bushes have some berries growing on them");
    add_item("berry|berries","They don't look very tasty. You think they're " +
             "not quite ready to be eaten yet");
    add_item("tree|trees|apple tree|apple trees","Two apples trees grow " +
             "next to the bushes. They look as if it was not very long " +
             "since they were planted. There are no apples on them right " +
             "now");
    add_item("apple|apples","There are none here right now. Maybe if you " +
             "come back (much) later?");
    add_item("field|tiny field","A small field where there are some " +
             "carrots growing. Maybe you could pick a carrot if you need " +
             "one?");
    add_item("carrot|carrots","The carrots look as if they would need " +
             "to grow larger before you pick them to eat them but if you " +
             "have some other use for carrots you could probably pick one");
    add_item("flower|flowers","Small flowers growing in the grass. They " +
             "don't look as if they were planted here. The garden looks " +
             "nice with them here but they're probably just a happy " +
             "accident");
    add_item("%|%smell|%flower|%flowers","The flowers in the garden don't " +
             "really smell that much but the faint smell you detect lifts " +
             "your spirits anyway");
    add_item("ground","The ground is covered by neatly trimmed grass");
    add_item("grass|trimmed grass|neatly trimmed grass","The grass is " +
             "neatly trimmed");
    add_item("bench|wooden bench|small wooden bench","A small wooden bench " +
             "that looks as if it would be nice to sit and relax on");

    (ROOM + "house_living_room")->load_doors();

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "hobbit_wife");
    pickers = ({});
    ::reset(arg);
}

void init(void)
{
    add_action("do_climb","climb");
    add_multi_action("do_relax","relax|sit");
    add_action("do_pick","pick");
    ::init();
}

int do_climb(string str)
{
    if(str == "hill" || str == "steps" || str == "stair")
    {
        W("You climb the steps to the top of the hill.\n");
        TP->move_player("climbs the steps to the top of the hill",
                        ROOM + "house_hill",
                        "comes climbing up the steps from below",1);
        return 1;
    }
    return notify_fail("Climb what?\n");
}

int do_relax(string str)
{
    if(str == "bench" || str == "on bench")
    {
        W("You sit down on the bench and relax for a while, watching the " +
          "garden in front of you.\n");
        S(TP->QN + " sits down on the bench and relaxes for a while.\n");
        return 1;
    }
    return notify_fail(C(query_verb()) + " where?\n");
}

int do_pick(string str)
{
    object carrot;

    if(str == "carrot" || str == "a carrot")
    {
        if(member_array(TP->QRN,pickers) == -1)
        {
            W("You bend down and pick a suitable carrot.\n");
            S(TP->QN + " bends down and picks a carrot.\n");
            carrot = make(OBJECT + "carrot");
            if(transfer(carrot,TP))
            {
                W("It is too heavy for you to pick up though.\n");
                S(TP->QN + " doesn't seem to be able to carry it.\n");
            }
            pickers += ({ TP->QRN });
        }
        else
        {
            W("You have already picked a carrot recently, be nice " +
              "and leave some for those who live here.\n");
        }
        return 1;
    }
    else if(str == "berries" || str == "a berry" || str == "berry")
    {
        W("You are not really sure which berries are ripe and which " +
          "ones aren't so you decide against it.\n");
        return 1;
    }
    W("Pick what?\n");
    return 1;
}
