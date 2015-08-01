#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

int pouch_found;

void create_object(void);
void reset(int arg);
void init(void);
int do_search(string str);
int do_swim(string str);
int do_drink(string str);
int do_fish(string str);

void create_object(void)
{
    set_short("A glen by a pond in the forest (w/n)");
    set_long("A grassy glen in a dark forest. To the west is a deep gully " +
             "continuing into the forest in that direction. A small brook " +
             "flows gently out of the gully into a dark pond on the south " +
             "side of the glen. The forest around the glen is dense and " +
             "dark, the pine trees tower high above you. This glen appears " +
             "to be used as a camp site right now. There's a fireplace in " +
             "the centre of it and several blankets, sacks and other things " +
             "spread out around the fireplace. A thin plume of smoke rises " +
             "from the smouldering embers in the fireplace. The glen " +
             "continues to the north, where there seems to be some sort of " +
             "building.\n");

    set_new_light(5);

    add_item("glen|grassy glen|secluded glen","A secluded glen in the dark " +
             "forest. It is quiet and peaceful here now but the grass on " +
             "the ground is trampled so there seems to have been lots of " +
             "activity here not too long ago");
    add_item("forest|dark forest","The trees are tall and stand close to " +
             "each other making it difficult to see very far into it");
    add_item("tree|trees|pine tree|pine trees","Pine trees, towering high " +
             "above you");
    add_item("gully","The gully ends here. You can walk into it by going " +
             "west");
    add_item("brook|small brook","A small brook gently trickling out of " +
             "the gully to the west into the dark pond to the south");
    add_item("pond|dark pond|forest pond|dark forest pond","A dark forest " +
             "pond in the glen. There are reeds growing close to the shore " +
             "and the surface is covered with waterlilies. The brook " +
             "from the gully flows into the pond, causing rings to ripple " +
             "across the surface");
    add_item("reed|reeds","Lots of them growing close to the shore");
    add_item("shore","The grass grows down all the way into the water");
    add_item("ground","The ground is covered by trampled grass");
    add_item("grass|trampled grass","The grass is thick and long but seems " +
             "to have been trampled quite a bit recently");
    add_item("surface","The dark water of the pond is covered with " +
             "waterlilies. It is a beautiful sight");
    add_item("water|dark water|deep water","The water in the pond is dark, " +
             "and it looks very cold. It also looks very deep so it might " +
             "not be a good idea to swim in it");
    add_item("sight|beautiful sight","The pond certainly is a beautiful " +
             "sight, you could spend hours just sitting here watching it");
    add_item("waterlily|waterlilies","Beautiful flowers floating on the " +
             "surface of the pond");
    add_item("flower|flowers|beautiful flower|beautiful flowers","Pretty " +
             "waterlilies floating on the water of the pond");
    add_item("ring|rings|ripple|ripples","They ripple across the surface " +
             "of the pond as the brook trickles into it from the west");
    add_item("site|camp site","It seems as if the glen is beeing used for " +
             "that purpose currently. There's a fireplace there, with " +
             "sacks and blankets surrounding it");
    add_item("fireplace","A ring of stones with some smouldering embers " +
             "in it");
    add_item("ring|circle|stone|stones|ring of stones","Stones placed in a " +
             "circle. There is no way they could have ended up like that in " +
             "a natural way");
    add_item("embers|smouldering embers","Looks like there's been a fire " +
             "there not too long ago. Only a thin plume of smoke rises " +
             "from it now though");
    add_item("thin plume|plume|smoke|thin plume of smoke|plume of smoke",
             "A thin plume of smoke rising up into the sky");
    add_item("centre","There is a fireplace there");
    add_item("blanket|blankets","Blankets looking like they've been used " +
             "and abused for a long time without being washed");
    add_item("sack|sacks","You can't tell what the sacks hold unless " +
             "you search them");
    add_item("thing|things|other thing|other things","None of the other " +
             "things look particularily interesting right now");
    add_item("building","You would have to go north to get a better look " +
             "at the building");

    add_exit(ROOM + "gully_bottom2","west");
    add_exit(ROOM + "outside_house","north");

    add_sounds(10,10,({ "The embers in the fireplace crackle.\n",
                        "Rings ripple across the surface of the pond.\n",
                        "Some smoke from the fireplace stings your " +
                        "nostrils.\n",
                        "A bird sings somewhere in the forest.\n"
                     }));
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "fishing_goblin");
    pouch_found = 0;
}

void init(void)
{
    add_action("do_search","search");
    add_multi_action("do_swim","swim|dive");
    add_multi_action("do_drink","drink|taste");
    add_action("do_fish","fish");
    ::init();
}

int do_search(string str)
{
    object pouch;

    if(str == "sack" || str == "sacks")
    {
        if(present("goblin",TO))
        {
            W("Goblin exclaims: Hey, don't mess with our things!\n" +
              "Goblin bonks you on your head.\n");
            S("Goblin exclaims: Hey, don't mess with our things!\n" +
              "Goblin bonks " + TP->QN + " on " + TP->QPO + " head.\n");
            return 1;
        }
        if(!pouch_found)
        {
            W("You search the sacks and find an interesting pouch.\n");
            S(TP->QN + " searches the sacks and pulls out a pouch.\n");
            pouch = make(OBJECT + "money_pouch");
            if(!transfer(pouch,TP))
            {
                W("You pick it up.\n");
                S(TP->QN + " picks up the pouch.\n");
            }
            pouch_found = 1;
        }
        else
        {
            W("You search through the sacks but don't find anything. It " +
              "looks like someone else have been rummaging through them " +
              "not too long ago though.\n");
            S(TP->QN + " searches through the sacks but does not seem to " +
              "find anything interesting.\n");
        }
        return 1;
    }
}

int do_swim(string str)
{
    if(str == "water" || str == "in water" || str == "into water" ||
       str == "pond" || str == "in pond" || str == "into pond")
    {
        W("The pond looks very deep and there seems to be lots of water " +
          "plants in there to get tangled up in, so you think it might " +
          "be safer to stay on dry land.\n");
        S(TP->QN + " steps closer to the pond and looks at it for a " +
          "while.\n");
        return 1;
    }
    return notify_fail(C(query_verb()) + " where?\n");
}

int do_drink(string str)
{
    if(str == "water" || str == "from pond" || str == "water from pond")
    {
        W("You taste some water from the pond. It's cold and tastes " +
          "pretty well.\n");
        S(TP->QN + " bends down and tastes some water from the pond.\n");
        return 1;
    }
    return notify_fail("Drink what?\n");
}

int do_fish(string str)
{
    if(present("fishing pole",TP) || present("fishing pole",TP))
    {
        W("You fish for a while but don't catch anything.\n");
        S(TP->QN + " fishes for a while but doesn't catch anything.\n");
        return 1;
    }
    W("You need a fishing pole to fish.\n");
    return 1;
}
