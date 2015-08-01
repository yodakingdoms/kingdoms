#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

int orb_taken;

void create_object(void);
string long_fun(void);
void reset(int arg);
void my_reset(void);
void init(void);
int do_polish(string str);
int do_take_orb(string str);
int query_orb_taken(void);

void create_object(void)
{
    set_short("A small chamber");
    set_long("#long_fun");
    set_new_light(0);
    add_property("indoors");

    add_item("room|chamber","A perfectly circular chamber with smooth, " +
             "black walls and floor");
    add_item("ceiling","The ceiling is low. Better watch your head");
    add_item("wall|walls","Smooth, black stone");
    add_item("floor","The floor is so smooth and polished that you almost " +
             "can see your own reflection in it");
    add_item("reflection","Well, it is a bit unclear still. Maybe if you " +
             "polished the floor?");
    add_item("air|atmosphere","There is something about the air here that " +
             "makes you feel at ease");
    add_func_item("pedestal","#query_orb_taken",({
                  "A smooth stone pedestal. There is a transparent orb " +
                  "lying on top of it",
                  "A smooth stone pedestal" }));
    add_func_item("orb|transparent orb","#query_orb_taken",({
                  "A transparent orb, about the size of your fist. A faint " +
                  "light can be seen moving around within it as it lies on " +
                  "the pedestal. A milky white mist is also moving about " +
                  "inside it, and at times you think you can almost discern " +
                  "a face in the mist" }));
    add_func_item("light","#query_orb_taken",({
                  "The light seems to be moving around inside the orb" }));
    add_func_item("mist|white mist|milky mist|milky white mist",
                  "#query_orb_taken",({
                  "The mist moves around inside the orb in a way that " +
                  "seems purposeful" }));
    add_func_item("face","#query_orb_taken",({
                  "The face appears briefly every now and then, but quickly " +
                  "dissolves" }));

    add_exit(ROOM + "dung_antechamber","west");

    reset(0);
}

string long_fun(void)
{
    string long_desc = "A small circular chamber with a low, domed ceiling. " +
                       "The walls and the floor in this room are smooth " +
                       "and black, and the air is still. Compared to the " +
                       "room outside, the atmosphere in this room makes you " +
                       "feel completely at ease. The one feature that " +
                       "catches your eye is the smooth, black pedestal in " +
                       "the centre of the room.";
    if(!query_orb_taken())
    {
        long_desc += " A transparent orb, about the size of your fist, lies " +
                     "on the pedestal. A faint light can be seen moving " +
                     "around within it.";
    }
    return long_desc + "\n";
}

void reset(int arg)
{
    // Just in case
    my_reset();
}

void my_reset(void)
{
    if(orb_taken)
    {
        (ROOM + "dung_antechamber")->my_reset();
    }
    orb_taken = 0;
}

void init(void)
{
    add_action("do_polish","polish");
    add_multi_action("do_take_orb","take|get");
    if(!TP->test_flag(QUEST_SUB_FLAG_7))
    {
        TP->add_exp(15000,1);
        TP->set_flag(QUEST_SUB_FLAG_7);
    }
}

int do_polish(string str)
{
    if(str == "floor")
    {
        W("Well, you polish the floor but to your disappointment you still " +
          "can't see your reflection there. And this is NOT how you get " +
          "full explore here ;]\n");
        S("How odd... " + TP->QN + " starts polishing the floor!\n");
        return 1;
    }
}

int do_take_orb(string str)
{
    object orb;

    if(!query_orb_taken())
    {
        if(str == "orb" || str == "orb from pedestal")
        {
            W("As you lift the orb from the pedestal, it begins to shine " +
              "with a soothing bright light. The light comforts you and " +
              "warms you, and the shadows that looked so threatening a " +
              "moment ago do not scare you anymore. The mist in the orb " +
              "takes the shape of a face, smiling at you.\n");
            S("As " + TP->QN + " lifts the orb from the pedestal it begins " +
              "to shine with a soothing bright. Suddenly the shadows don't " +
              "scare you anymore.\n");
            orb = make(OBJECT + "orb");
            orb->set_fetcher(TP);
            orb_taken = 1;
            if(transfer(orb,TP))
            {
                W("You are carrying too much, so you gently drop the orb " +
                  "onto the floor to rearrange your equipment.\n");
                S(TP->QN + " gently drops the orb onto the floor.\n");
            }
            set_alarm(600.0,0.0,"my_reset");
            return 1;
        }
    }
}

int query_orb_taken(void)
{
    return orb_taken;
}
