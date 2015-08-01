#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_drink(string str);
int do_swim(string str);

void create_object(void)
{
    set_short("A large field (s)");
    set_long("A large grassy field encircled by a wooden fence. There are " +
             "small hills and bushes in the field, and in one corner is a " +
             "small pond filled with clear water. Small flowers grow all " +
             "over the field and the grass is short. There is a distinct " +
             "smell in the air, which seems to emanate from the numerous " +
             "small, brown piles dropped all over the field. In the " +
             "distance, beyond the fence, you see the rolling landscape " +
             "spread towards the north and the east. To the northwest there " +
             "is a forest and to the south is the rest of the farm.\n");

    set_new_light(5);

    add_item("field|large field|grassy field|large grassy field","A field " +
             "that looks perfect for keeping cows in, and judging by the " +
             "brown piles all around it, that's exactly what it is being " +
             "used for");
    add_item("fence|wooden fence","It's the wooden fence that seems to " +
             "go round the whole farm");
    add_item("farm","You are on the north side of the farm, most of it is " +
             "south from here");
    add_item("hill|hills|small hill|small hills","Small hills covered with " +
             "grass. The field looks like a smaller version of the " +
             "landscape surrounding the farm");
    add_item("ground","The ground is covered with grass, and small brown " +
             "piles lie here and there");
    add_item("grass|short grass","The grass is short and is obviously " +
             "being grazed regularly");
    add_item("bush|bushes|small bush|small bushes","Small bushes that " +
             "look like they have been chewed on");
    add_item("corner|corners","A small pond with clear water is in one " +
             "of the corners");
    add_item("pond|small pond","A pond with water for the cows to drink. " +
             "The pond looks like it's been made rather than natural and " +
             "the water looks clear");
    add_item("water|clear water|cold water","It's cold and clear, the " +
             "pond is not very deep");
    add_item("flower|flowers|small flower|small flowers","Small flowers " +
             "trying desperately to overpower the brown piles with their " +
             "scent, but fighting a losing battle");
    add_item("%flower|%flowers|%small flower|%small flowers|scent|%scent",
             "The scent of the flowers might be nice but there's another " +
             "smell in this field that completely overpowers it");
    add_item("%|smell|%smell|air|%air","The smell coming from the small " +
             "brown piles makes you feel like you'd rather not be here!");
    add_item("pile|piles|small pile|small piles|brown pile|brown piles|" +
             "small, brown piles","They look like something that has come " +
             "out of the wrong end of a cow");
    add_item("%pile|%piles","They smell like something that has come out " +
             "the wrong end of a cow");
    add_item("landscape|rolling landscape","The landscape on the other " +
             "side of the fence looks like a larger version of the " +
             "landscape in the field");
    add_item("forest|edge","You can just make out the edge of a forest " +
             "to the northwest");

    add_exit(ROOM + "farm_path1","south");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "cow",6);
    add_monster(MONSTER + "bull");
}

void init(void)
{
    add_multi_action("do_drink","taste|drink");
    add_multi_action("do_swim","swim|dive|enter");
    SYS_ADMIN->visit(1116);
}

int do_drink(string str)
{
    if(str == "water" || str == "from pond" || str == "water from pond")
    {
        W("You drink some water from the pond. It's cold and refreshing.\n");
        S(TP->QN + " bends down and drinks some water from the pond.\n");
        return 1;
    }
    return notify_fail(C(query_verb()) + " what?\n");
}

int do_swim(string str)
{
    if(str == "pond" || str == "in pond" || str == "into pond" ||
       str == "water" || str == "in water" || str == "into water")
    {
        W("The water in the pond is too shallow to swim in. The pond " +
          "is meant for drinking, not swimming.\n");
        S(TP->QN + " looks at the pond, pondering.\n");
        return 1;
    }
    return notify_fail(C(query_verb()) + " where?\n");
}
