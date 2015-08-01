#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_search(string str);

void create_object(void)
{
    set_short("A small cave dug out of the hill");
    set_long("A cave that has been dug out of the hill. This cave is rather " +
             "large and the floor, ceiling and walls are smooth, packed " +
             "dirt. The floor is covered with small bunks, and there's a " +
             "circle of stones, apparently a fireplace, in the middle of " +
             "the room. There's a small hole in the ceiling above the " +
             "fireplace. There are some dying embers still in the circle, " +
             "emitting a thin line of smoke slowly floating out through " +
             "the hole in the ceiling.\n");
    set_new_light(10);
    add_property("indoors");

    add_item("cave","A larger cave, apparently serving as sleeping quarters");
    add_item("floor|ceiling|wall|walls","Smooth, packed dirt");
    add_item("bunk|bunks","Heaps of straw and grass. Some with blankets, " +
             "some without");
    add_item("blanket|blankets","Thick, wollen blankets");
    add_item("circle|stones|fireplace","A few stones placed in a circle. A " +
             "fire has been lit there not too long ago");
    add_item("ember|embers","The last dying remnants of a fire");
    add_item("line|smoke","A thin line of smoke from the embers of the " +
             "dying fire");
    add_item("stone","A round, grey stone");
    add_item("hole","A small hole which lets the smoke from the fire out, " +
             "when there's a fire in the fireplace");

    add_exit(ROOM + "dgcave_entrance","south");
    add_exit(ROOM + "dgcave_guards2","northeast");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "DGnome",1);
}

void init(void)
{
    add_action("do_search","search");
}

int do_search(string str)
{
    if(str == "fireplace" || str == "embers")
    {
        W("The embers are still too hot to touch, so you grab a twig and " +
          "poke around in them. The only things you notice are some small " +
          "bones, remnants of small animals roasted by the gnomes " +
          "probably.\n");
        S(TP->QN + " grabs a twig and pokes around in the dying embers " +
          "for a while.\n");
        return 1;
    }
}
