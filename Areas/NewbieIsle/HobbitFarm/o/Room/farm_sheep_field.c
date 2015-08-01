#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
int load_doors(void);
void init(void);
int do_climb(string str);
int do_drink(string str);

void create_object(void)
{
    set_short("A small grassy field");
    set_long("A small grassy field surrounded by a wooden fence. The grass " +
             "is short and looks well kept and small flowers grow all over " +
             "the field. Near the gate is a wooden trough filled with " +
             "water, and a bucket lies carelessly tossed next to it. Thick " +
             "bushes grow on the south side of the field, their branches " +
             "look chewed upon. On the other side of the fence to the " +
             "north is the main yard of the farm and to the east is a " +
             "large grassy hill with a huge oak growing on top. The rolling " +
             "landscape disappears into the distance to the south.\n");

    set_new_light(5);
    set_skip_obvious(1);

    add_item("field|small field|grassy field|small grassy field","A " +
             "small field with short grass that looks as if it is being " +
             "used to keep animals on");
    add_item("fence|wooden fence","It doesn't look very high. You could " +
             "probably climb it to get to the main yard to the north");
    add_item("ground","The ground is covered by short grass");
    add_item("grass|short grass","It is short and looks well kept even if " +
             "it looks as if that is due to animals grazing rather than " +
             "someone taking care of it");
    add_item("flower|flowers|small flower|small flowers","They smell nice " +
             "but the probably don't taste very nice, or else they would " +
             "surely have been eaten by the animals who have been " +
             "grazing here");
    add_item("%|%flower|%flowers|scent|%scent","The scent of the flowers " +
             "fill your nostrils and you feel quite relaxed");
    add_item("trough|wooden trough","It's filled with water for the animals " +
             "who graze here to drink");
    add_item("water","It looks pretty clear and cold, the animals here are " +
             "obviously well taken care of");
    add_item("bucket","It looks as if someone has filled the trough and " +
             "then just tossed the bucket there instead of taking it back");
    add_item("bush|bushes|thick bush|thick bushes","They grow on the south " +
             "side of the field, almost hiding the fence completely there " +
             "and giving the field a natural look");
    add_item("branch|branches","It looks as if some animals have chewed " +
             "on them. You're not sure if that's because the branches " +
             "taste good or if the animals have starved");
    add_item("yard|main yard","It's in the middle of the farm. You could " +
             "probably climb the fence to get there");
    add_item("farm|little farm|nice farm|nice little farm","It's a nice " +
             "little farm and if you weren't busy being an adventurer, " +
             "you think you could settle down here");
    add_item("hill|grassy hill|large hill|large grassy hill","There are " +
             "some windows in the hill");
    add_item("window|windows|small window|small windows|round window|" +
             "round windows|small round window|small round windows","Small " +
             "round windows with open curtains. It looks as if someone is " +
             "living in the hill");
    add_item("curtain|curtains","They are open, giving the hill a welcoming " +
             "feeling");
    add_item("top|top of the hill","A huge tree grows on top of the hill");
    add_item("oak|huge oak|tree|oak tree","The oak grows on top of the " +
             "hill and is towering above you. You feel very small standing " +
             "here looking at it");
    add_item("landscape|rolling landscape|hill|hills|green hill|green hills",
             "Green hills stretch as far as the eye can see");
    add_item("vegetation","Bushes grow by the south side of the field and " +
             "flowers grow on the ground");

    load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "sheep",8);
    ::reset(arg);
}

int load_doors(void)
{
    string dir1 = "in the fence to the west";
    string dir2 = "in the fence to the east";
    string next_room = ROOM + "farm_path2";
    string desc = "gate";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A finely crafted wooden gate in the fence.\n";
    string entercmd1 = "west";
    string entercmd2 = "east";
    int solidity = 30;
    int complex = 20;
    int hidden1 = 0;
    int hidden2 = 0;

    add_door(dir1, dir2, next_room, desc,  closed, locked, key_id,
             long_desc, entercmd1, entercmd2, solidity, complex,
             hidden1, hidden2 );
    return 1;
}

void init(void)
{
    add_action("do_climb","climb");
    add_action("do_drink","drink");
    add_multi_action("do_taste","taste|chew|eat");
    ::init();
}

int do_climb(string str)
{
    if(str == "fence")
    {
        if(TP->QS("climb") >= 15)
        {
            W("You climb the fence with ease.\n");
            TP->move_player("climbs the fence on the north side of the field",
                            ROOM + "farm_west",
                            "comes climbing over the fence on the south " +
                            "side of the yard",1);
        }
        else
        {
            W("You're not a good enough climber to climb even this small " +
              "fence. Maybe raising your climb skill would be in order?\n");
            S(TP->QN + " tries to climb the fence on the north side of the " +
              "field but fails miserably.\n");
        }
        return 1;
    }
    return notify_fail("Climb what?\n");
}

int do_drink(string str)
{
    if(str == "water")
    {
        W("You drink some water from the trough. You enjoy the taste and " +
          "feel refreshed.\n");
        S(TP->QN + " drinks some water from the trough.\n");
        return 1;
    }
    return notify_fail("Drink what?\n");
}

int do_taste(string str)
{
    if(query_verb() == "taste" && str == "water")
    {
        return do_drink(str);
    }
    if(str == "flower" || str == "flowers" || str == "branch" ||
       str == "branches" || str == "on flower" || str == "on branch")
    {
        W("Damnit, " + TP->QN + ", you're not an animal.\n");
        S(TP->QN + " looks longingly at the vegetation in the field.\n");
        return 1;
    }
    return notify_fail(C(query_verb()) + " what?\n");
}
