#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_block(string str);

void create_object(void)
{
    set_short("The north end of the third floor landing");
    set_long("The north end of the landing on the third floor. The hall is " +
             "silent, and the only light here is coming from two flickering " +
             "torches on the walls. The hall continues to the south and " +
             "there are archways in the east, west and north walls. Two " +
             "black stone statues flank the northern archway. You are " +
             "beginning to feel very uneasy here.\n");
    set_new_light(5);
    add_property("indoors");
    add_property("allow_horse");

    add_item("landing|hall|room","A large, silent hall");
    add_item("torch|torches","Two flickering torches");
    add_item("wall|walls","Smooth, black stone");
    add_item("archways","There are three of them here. The ones to the east " +
             "and the west look quite plain, but the one to the north " +
             "looks very impressive");
    add_item("archway","It is bigger than the others and it is flanked by " +
             "two stone statues. You feel very uneasy standing in front " +
             "of it, and you wonder if it really would be in your best " +
             "interest to pass through it..");
    add_item("statue|statues","The left statue or the right statue?");
    add_item("left statue|man","The black stone statue shows a tall man in " +
             "robes. His fingers are long and slender, but his face is " +
             "hidden under his hood and can't be seen");
    add_item("right statue|dragon","The black stone statue shows a black " +
             "dragon standing on it's hind legs, wings folded");

    add_exit(ROOM + "lev3_landing","south");
    add_exit(ROOM + "lev3_corridor1","west");
    add_exit(ROOM + "lev3_corridor2","east");
    add_exit(ROOM + "lev3_throne","north");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "darkling_highguard",2);
}

void init(void)
{
    add_multi_action("do_block","n|north");
}

int do_block(string str)
{
    if(present("high guard",TO))
    {
        if(TP->query_level() <= 16)
        {
            W("The guard steps out in front of you and stops you from " +
              "entering the room beyond.\n");
            S("A guard steps out in front of " + TP->QN + " and stops " +
              TP->QO + " from walking through the archhway.\n");
            return 1;
        }
        else
        {
            W("A darkling mutters: They're not paying me enough to get in " +
              "the way of the likes of " + TP->QN + ".\n");
            S("A darkling mutters: They're not paying me enough to get in " +
              "the way of the likes of " + TP->QN + ".\n");
        }
    }
    return 0;
}
