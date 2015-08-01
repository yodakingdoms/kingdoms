#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

object resting_player;

void create_object(void);
void init(void);
int do_wake_up(string str);
int do_swim(string str);
int do_rest(string str);
int do_drink(string str);
void resting(int step);

void create_object(void)
{
    set_short("A path through rolling hills (w/ne)");
    set_long("A well trodden path going west through a rolling landscape. " +
             "A river cuts its way between the hills on its way from the " +
             "northwest to the southeast and a stone bridge crosses it " +
             "here, letting you go northeast. The grass grows tall on the " +
             "hills around the path and a huge weeping willow tree grows " +
             "near the bank of the river. A thick shrubbery grows on the " +
             "side of the hill south of the path. West of here is a fence " +
             "and some buildings that look like a farm.\n");

    set_new_light(5);

    add_item("path|well trodden path","It is obvious that it has seen a " +
             "lot of trodding in its days");
    add_item("trodding","The trodding you notice most is the trodding you " +
             "are providing here right now");
    add_item("landscape|rolling landscape","There are grassy hills as far " +
             "as the eye can see");
    add_item("river","A gently flowing river running towards the " +
             "southeast. The water is clear and you see stones on the " +
             "bottom and fishes swimming around");
    add_item("water|clear water|cold water","The water is clear but it " +
             "looks very cold, you wouldn't want to take a swim here");
    add_item("stone|stones|small stone|small stones|round stone|round " +
             "stones|small, round stone|small, round stones","Small, round " +
             "stones lying on the bottom of the river, carried here from " +
             "somewhere upstream");
    add_item("bottom","The bottom is covered with small stones");
    add_item("fish|fishes|small fish|small fishes","They are very small " +
             "and are swimming around very fast. You can't tell which " +
             "species they are");
    add_item("hill|hills|green hill|green hills|rolling hill|rolling hills|" +
             "green, rolling hill|green rolling hills|grassy hill|" +
             "grassy hills","Green, rolling hills as far as the eye can see");
    add_item("bridge|stone bridge|old bridge|old stone bridge","The bridge " +
             "is old and worn but it still looks like it is in a good " +
             "shape. Whoever built it long ago must have been very skilled");
    add_item("tree|willow|willow tree|weeping willow|weeping willow tree|" +
             "tall tree|huge tree|huge willow tree|huge weeping willow tree",
             "A tall tree growing by the riverbank. Its roots stretch down " +
             "into the water and the branches reach out above the river. " +
             "The grass is flat on one spot next to the trunk");
    add_item("trunk","There's a spot of flat grass on the ground next to " +
             "the trunk");
    add_item("root|roots|thick root|thick roots","The roots of the tree " +
             "are thick and grown down into the river. You almost think " +
             "you can see the roots pulsating as they drink from the river " +
             "but you tell yourself it's just your imagination");
    add_item("branch|branches|twig|twigs|long branch|long branches|" +
             "long twig|long twigs|drooping branch|drooping branches|" +
             "drooping twig|drooping twigs|long and drooping branch|" +
             "long and drooping branches|long and drooping twig|" +
             "long and drooping twigs|base|bases|brittle base|brittle bases",
             "The twigs and branches of the tree are long and drooping " +
             "with brittle bases. You almost think you hear the leaves " +
             "whispering but you tell yourself it's just your imagination");
    add_item("leaf|leaves|thin leaf|thin leaves|narrow leaf|narrow leaves|" +
             "underside|undersides|silky underside|silky undersides","The " +
             "leaves of the three are thin and narrow, with silky undersides");
    add_item("$|$leaf|$leaves","For a moment you think you heard the " +
             "leaves of the willow whisper but then you decide it was just " +
             "your imagination");
    add_item("ground","Grass grows on the ground all around you");
    add_item("grass|tall grass","The grass grows tall all around you except " +
             "for one spot next to the tree");
    add_item("spot","It seems like a small person has been lying there " +
             "having a nap or just resting");
    add_item("bank|riverbank","Grass grows all the way down to the water");
    add_item("shrubbery|thick shrubbery","A thick shrubbery, preventing " +
             "passage in that direction");
    add_item("side|side of the hill|side of the hill to the south|" +
             "steep side|south hill",
             "It is pretty steep and there's also a thick shrubbery " +
             "preventing passage that way");
    add_item("fence","The fence seems to go quite a long way to the north " +
             "and south. The path seems to lead to a gate in the fence");
    add_item("gate","There seems to be one in the fence. The path seems " +
             "to go there");
    add_item("building|buildings|farm","There seems to be at least a barn " +
             "and a stable there");
    add_item("barn|stable","It looks like one. You'd have to get closer to " +
             "see more of it");
    add_item("$|$tree|$willow|$willow tree","You think you hear a " +
             "whispering sound from the willow tree. Is it real or just " +
             "your imagination?");
    add_item("$sound|$whispering sound","You can't hear it now, it was " +
             "probably just your imagination");

    add_exit(ROOM + "hazeldown_path2","northeast");
    add_exit(ROOM + "fence_gate","west");

    add_sounds(30,10,({ "The grass around you sways gently in the wind.\n",
                        "The branches of the willow sway gently in the " +
                        "wind.\n",
                        "You think you hear some whispering sounds from " +
                        "the willow tree, but convince yourself you are " +
                        "just imagining it.\n",
                        "You hear the sound of running water from the river.\n"
                     }));
}

void init(void)
{
    add_action("do_wake_up","",1);
    add_action("do_drink","drink");
    add_multi_action("do_swim","swim|dive");
    add_multi_action("do_rest","rest|nap");
    ::init();
}

int do_wake_up(string str)
{
    if(TP == resting_player)
    {
        W("You shake your head and stand up to stop yourself from falling " +
          "asleep.\n\n");
        S(TP->QN + " shakes " + TP->QPO + " head and stands up.\n");
        resting_player = 0;
    }
}

int do_swim(string str)
{
    if(str == "river" || str == "water" || str == "in river" ||
       str == "in water" || str == "into river" || str == "into water")
    {
        W("The water looks much too cold, you don't think that would be " +
          "a very good idea.\n");
        S(TP->QN + " looks at the water thoughtfully for a short while.\n");
        return 1;
    }
    return notify_fail("Swim where?\n");
}

int do_drink(string str)
{
    if(str == "water")
    {
        W("You bend down and drink some water from the river. It tastes " +
          "refreshing.\n");
        S(TP->QN + " bends down and drinks some water from the river.\n");
        return 1;
    }
    // Don't want to stop drinking potions and what have you
    return 0;
}

int do_rest(string str)
{
    if(resting_player && !present(resting_player,TO)) resting_player = 0;
    if(resting_player)
    {
        W("The spot is taken. " + resting_player->QN + " is resting there " +
          "now.\n");
        return 1;
    }

    W("You lay down on the spot next to the tree and start resting, " +
      "it's very comfortable.\n");
    S(TP->QN + " lies down on a spot in the grass by the tree and starts " +
      "resting.\n");
    resting_player = TP;
    set_alarm(1.0,0.0,"resting",0);
    return 1;
}

void resting(int step)
{
    if(!resting_player || !present(resting_player,TO))
    {
        resting_player = 0;
        return;
    }
    set_this_player(resting_player);

    switch(step)
    {
        case 0: W("You close your eyes and feel yourself drifting away " +
                  "into a light slumber.\n");
                S(TP->QN + " closes " + TP->QPO + " eyes and seems to " +
                  "fall asleep.\n");
                set_alarm(3.0,0.0,"resting",1);
          break;
        case 1: W("You start dreaming, and think you hear the willow tree " +
                  "whisper to you.\n");
                S(TP->QN + " stirs in " +TP->QPO + " slumber, and for a " +
                  "second you think you hear a whispering sound coming " +
                  "from the willow tree.\n");
                set_alarm(4.0,0.0,"resting",2);
          break;
        case 2: W("Suddenly you're stirred from your slumber by someone " +
                  "or something shaking you awake.\n");
                S("Suddenly the roots of the tree next to where " + TP->QN +
                  " is resting start trembling.\n");
                set_alarm(1.0,0.0,"resting",3);
          break;
        case 3: W("You're pushed into the river and land with a *SPLASH!*\n" +
                  "You quickly jump out of the cold water and in the corner " +
                  "of your eye you think you see the roots of the tree move " +
                  "and settle back into their normal positions. Spooky!\n" +
                  "You are soaking wet.\n");
                S("Suddenly the roots of the tree move and throw " + TP->QN +
                  " into the river where " + TP->QPR + " lands with a " +
                  "*SPLASH*!\n" + TP->QN + " quickly jumps out of the water " +
                  "as the roots settle back into their normal positions.\n" +
                  TP->QN + " is soaking wet.\n");
                make(OBJECT + "wet_object",resting_player);
                resting_player = 0;
          break;
    }
}
