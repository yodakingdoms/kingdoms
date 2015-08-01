#pragma strict_types
#include "../def.h"
inherit MASTER_INDOORS_ROOM;

int stone_taken = 0;

void   create_object(void);
void   reset(int arg);
string long_fun(void);
void init(void);
int do_pry(string str);
int query_stone_taken(void);

void create_object(void)
{
    ::create_object();
    set_short("An underground corridor (w/n)");
    set_long("#long_fun");

    add_item("corridor|underground corridor","An underground corridor with " +
             "walls, floor and ceiling made of stone");
    add_item("place","An underground corridor");
    add_item("air","You can't see it but fresh air seems to be flowing " +
             "here from the north");
    add_item("opening","An opening leading out into the fresh air, by the " +
             "looks of it");
    add_item("fresh air","Not in here, but maybe further north");
    add_item("box|boxes","There are some boxes stacked against the walls " +
             "in the southeast corner. They look like they once contained " +
             "supplies but now they seem empty");
    add_item("corner|southeast corner","There are some boxes stacked there");

    add_func_item("light|yellow light","#query_stone_taken",({
                 "The light in the room comes from the stone in a niche " +
                 "in one of the walls",
                 "There's enough light coming from the north for you to " +
                 "be able to see in here"
                 }));
    add_func_item("niche","#query_stone_taken",({
                 "A small niche in one of the walls. There is a small "+
                 "stone in the niche, flickering with a soft, yellow light",
                 "A small niche in on of the walls. It is empty"
                }));

    add_exit(PCROOM + "lev1_ew_corridor1","west");
    add_exit(PCROOM + "lev1_ns_corridor1","north");

    reset(0);
}

void reset(int arg)
{
    if(stone_taken)
    {
        tell_room(TO,"Drunk pirate arrives from the north.\n"+
                  "Drunk pirate grumbles something about missing stones.\n"+
                  "Drunk pirate places a stone in the empty niche in the "+
                  "wall.\n"+
                  "The stone starts to shine.\n"+
                  "Drunk pirate leaves north.\n");
    }
    add_item("small stone|round stone|stone|strange stone","A strange "+
             "looking round stone that flickers with a soft yellow light. " +
             "It seems to be loose, maybe you could try prying it out of " +
             "the niche?");
    stone_taken = 0;

    add_monster(PCMONSTER + "pirate",2);
}

string long_fun(void)
{
    if(!stone_taken)
    {
        return "An underground corridor that turns here, going west and " +
               "north from this place. It is pretty cold here, but fresh " +
               "air flows here from the north. There seems to be " +
               "an opening some distance in that direction. There are " +
               "some boxes stacked in the southeast corner and a flickering " +
               "stone in a niche on a wall provides light to the room.\n";
    }
    else
    {
        return "An underground corridor that turns here, going west and " +
               "north from this place. It is pretty cold here, but fresh " +
               "air flows into the room from the north. There seems to be " +
               "an opening some distance in that direction. There are " +
               "some boxes stacked in the southeast corner. There's no " +
               "source of light in this room, but there is enough light " +
               "coming from the north for you to be able to see here " +
               "anyway.\n";
    }
}

void init(void)
{
    add_action("do_pry","pry");
}

int do_pry(string str)
{
    object stone;

    if(!stone_taken)
    {
        if(str == "stone" || str == "stone out" || str == "stone out of niche")
        {
            W("You pry the stone loose from the niche. The light flickers " +
              "one more time and then dies.\n");
            S(TP->QN + " prys a stone loose from a niche in the wall. The " +
              "light in the stone flickers one more time and then dies.\n");
            stone = make(PCOBJECT + "lightstone");
            if(transfer(stone,TP))
            {
                W("It's too heavy for you to pick up, so you drop it on " +
                  "the floor.\n");
                S(TP->QN + " drops a stone on the floor.\n");
            }
            stone_taken = 1;
            remove_item("small stone|round stone|stone|strange stone");
            return 1;
        }
        return notify_fail("Pry what?\n");
    }
    return 0;
}

int query_stone_taken()
{
    return stone_taken;
}
