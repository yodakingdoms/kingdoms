#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

string *pickers;

void create_object(void);
void reset(int arg);
void init(void);
int do_pick(string str);
int do_water(string str);

void create_object(void)
{
    set_short("A pumpkin field (s)");
    set_long("You're standing in the middle of what seems to be a pumpkin " +
             "field. The ground is hidden under a mass of large green " +
             "leaves and placed in neat rows are many pumpkins of various " +
             "sizes. The soil under the leaves is damp and looks fertile. " +
             "In the middle of the field stands a large wooden barrel. " +
             "East and north of the field is the wooden fence that seems " +
             "to encircle the farm and beyond that the rolling landscape " +
             "of the island and to the west is a building that looks like " +
             "a stable.\n");

    set_new_light(5);

    add_item("field|pumpkin field","It's a field to grow pumpkins in. " +
             "It looks pretty scary, actually, with those neat rows of " +
             "pumpkins in front of you");
    add_item("mass|leaf|leaves|green leaf|green leaves|large leaf|" +
             "large leaves|large green leaf|large green leaves","The " +
             "leaves are large enough that they almost cover the ground " +
             "completely");
    add_item("ground","You can hardly see it beneath the leaves");
    add_item("row|neat row|rows|neat rows","The pumpkins are placed in " +
             "neat rows. They almost look like a marching army");
    add_item("army|marching army|marching pumpkin army","A marching pumpkin " +
             "army! They're standing to attention now but you think they " +
             "might start moving in your direction any second. Or maybe " +
             "you're just imagining things. It looks pretty spooky either " +
             "way");
    add_item("pumpkin|pumpkins","They'd be pretty big if from the point " +
             "of view of a hobbit, but to you they look rather small. " +
             "Still, if you need a pumpkin, you could probably pick one " +
             "here");
    add_item("soil","The soil is damp. The pumpkins seem to be taken well " +
             "care of");
    add_item("barrel|wooden barrel","It's empty. There are some hoses " +
             "extending from it");
    add_item("hose|hoses","The hoses disappear beneath the leaves. You " +
             "assume they're part of some sort of watering system");
    add_item("system|watering system","It looks like a clever way of " +
             "watering the pumpkins without doing too much work yourself");
    add_item("fence|wooden fence","It seems to encircle the farm. It is " +
             "delicately carved. You're amazed at the dedication it must " +
             "have taken to a fence as long as this as beautiful as that");
    add_item("farm","Most of it is west and south of this field");
    add_item("landscape|rolling landscape","The rolling landscape of Newbie " +
             "Island");
    add_item("island|newbie island|Newbie Island","It's where newbies can " +
             "walk around and try their hand at being adventurers");
    add_item("building|stable","It is the stable, but you can't enter it " +
             "from here");
    add_item("$|$rodent|$rodents|$sound|$sounds","You hear the sound of " +
             "rodents scurrying about under the leaves");
    add_item("%|%earth|%damp earth|%smell","You feel the smell of damp " +
             "earth");

    add_exit(ROOM + "farm_gate","south");

    reset(0);
}

void reset(int arg)
{
    pickers = ({});
    add_monster(MONSTER + "hobbit_helper1");
    add_monster(MONSTER + "rodent",2);
}

void init(void)
{
    add_action("do_pick","pick");
    add_action("do_water","water");
}

int do_pick(string str)
{
    object pumpkin;

    if(str == "pumpkin" || str == "a pumpkin")
    {
        if(member_array(TP->QRN,pickers) == -1)
        {
            W("You bend down and pick a suitable pumpkin.\n");
            S(TP->QN + " bends down and picks a pumpkin.\n");
            pumpkin = make(OBJECT + "pumpkin");
            if(transfer(pumpkin,TP))
            {
                W("It is too heavy for you to pick up though.\n");
                S(TP->QN + " doesn't seem to be able to carry it.\n");
            }
            pickers += ({ TP->QRN });
        }
        else
        {
            W("You have already picked a pumpkin recently, be nice " +
              "and leave some for the farmer.\n");
        }
        return 1;
    }
    // Notify_fail leads to pick feeling here
    W("Pick what?\n");
    return 1;
}

int do_water(string str)
{
    if(str == "pumpkins")
    {
        W("The pumpkins look like they've been watered recently, no " +
          "need to do it again now.\n");
        S(TP->QN + " examines the watering system closely for a while.\n");
        return 1;
    }
    return notify_fail("Water what?\n");
}
