#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_climb(string str);
int do_force(string str);

void create_object(void)
{
    set_short("A path through rolling hills (n/s)");
    set_long("A well trodden path travelling north and south through the " +
             "rolling landscape. There are tall hills on both sides of the " +
             "path and trees grow on top of both of them. On top of the " +
             "hill to the east are also some remnants of what once was a " +
             "stone building. The grass near the path is rather tall and " +
             "sways in the wind. Several large rocks lie strewn around " +
             "the ground on the east side of the path and bushes grow on " +
             "the sides of the hills. There is a small wooden sign beside " +
             "the path.\n");

    set_new_light(5);

    add_item("path|well trodden path","It's been walked upon by many " +
             "a hairy hobbit foot, by the looks of it");
    add_item("foot|hobbit foot|hairy hobbit foot","If you find a hobbit, " +
             "there's a good chance it has two of them");
    add_item("hobbit|hobbits","Sadly, there are no hobbits here right now");
    add_item("landscape|rolling landscape|beautiful landscape|area","The " +
             "landscape is beautiful, and a soothing feeling comes over " +
             "you as you walk around in in");
    add_item("hill|hills|tall hill|tall hills","They rise on both sides " +
             "of the path. The west hill is topped by a small grove of " +
             "trees while the east hill has some sort of ruin on top of " +
             "it in addition to some trees");
    add_item("west hill","It is the hill on the west side of the path. " +
             "Grass grows in its sides and a small grove of trees grows " +
             "on top of it");
    add_item("side|sides","Bushes and tall grass grows on the sides of " +
             "the hills");
    add_item("east side","There are many large rocks on the ground on " +
             "that side of the path");
    add_item("grass|tall grass","The grass is rather tall, a sign that " +
             "neither animals nor hobbits or other creatures have been " +
             "moving around much in the area except for on the path");
    add_item("animal|animals","Sadly, there are no animals here right now");
    add_item("creature|creatures|other creature|other creatures","Sadly, " +
             "or luckily depending on your point of view, there are no " +
             "other creatures here right now");
    add_item("grove|small grove","A small grove of trees grows on top of " +
             "the hill to the west. They're standing very close together, " +
             "and from here it looks as if they might have been planted " +
             "there");
    add_item("tree|trees","Trees grow on both of the hills near the path. " +
             "The ones on the west hill grow close together to form a " +
             "small grove while the ones to the east are a bit more sparse");
    add_item("east hill|top|top of the hill","The east hill is higher than " +
             "the west one and has a building, or what used to be a " +
             "building on top of it. There are fewer trees on that hill " +
             "also, it looks as if someone has chopped some of them down " +
             "to make room some time in the past");
    add_item("building|stone building|remnants|ruin","It looks as if it " +
             "used to be a tower but now it's only a ruin");
    add_item("tower","Probably a tower of the kind one would stick a sentry " +
             "in. The view from up there would probably be very good");
    add_item("sentry","Judging by the state the tower is in, it was a long " +
             "time since a sentry last sat up there. You're probably safe " +
             "from spying eyes now");
    add_item("eye|eyes|spying eyes|spying eyes","You don't see any right " +
             "now, but one can of course never be too sure");
    add_item("view|view from the tower|view from the hill","The view from " +
             "the tower was probably magnificent and the view from the " +
             "hill probably still is. You have more interesting things to " +
             "do now though");
    add_item("rock|rocks|large rock|large rocks","The rocks look as if " +
             "they rolled down from the top of the hill when the tower " +
             "that used to be there fell. You wonder what happened");
    add_item("ground","The ground is covered by tall grass all around you " +
             "except for on the path you're walking on");
    add_item("bush|bushes|thick bush|thick bushes","Thick bushes with " +
             "thorny branches. Climbing the hills and forcing yourself " +
             "through those bushes would be tricky");
    add_item("branch|branches|thorny branch|thorny branches","They look " +
             "nasty. It would be a very unpleasant experience to force " +
             "oneself past them");
    add_item("thorn|thorns","They look like they could pierce through " +
             "a Fireplatemail");
    add_item("fireplatemail|Fireplatemail|platemail","You wish you had one " +
             "but you probably have to grow a lot stronger before you " +
             "can even attempt to go in search of a Fireplatemail!");
    add_item("sign|@sign|small sign|@small sign|wooden sign|@wooden sign|" +
             "small wooden sign|@small wooden sign","The sign says: " +
             "Bumbleroot Farm");
    add_item("farm|bumbleroot farm|Bumbleroot Farm|Bumbleroot farm","You " +
             "can't see any farm here. You assume the path leads to one");
    add_item("$","You hear the sound of the grass around you sway gently " +
             "in the wind");

    add_exit(HAZELDOWN,"north");
    add_exit(ROOM + "hazeldown_path2","south");

    add_sounds(30,10,({ "The grass around you sways gently in the wind.\n" }));
}

void init(void)
{
    add_action("do_climb","climb");
    add_action("do_force","force");
    ::init();
}

int do_climb(string str)
{
    if(str == "hill" || str == "east hill" || str == "west hill")
    {
        W("The hill doesn't look very interesting and the thorns on the " +
          "bushes look very nasty so you decide it's not worth it.\n");
        S(TP->QN + " looks up the side of the " + str + " for a short " +
          "while.\n");
        return 1;
    }
    return notify_fail("Climb what?\n");
}

int do_force(string str)
{
    if(str == "bushes" || str == "through bushes" ||
       str == "myself through bushes")
    {
        W("Those thorns look too sharp, you decide it would not " +
          "be a good idea.\n");
        S(TP->QN + " steps up to the bushes and looks at the thorns " +
          "for a while.\n");
        return 1;
    }
    return notify_fail("Force yourself through what?\n");
}
