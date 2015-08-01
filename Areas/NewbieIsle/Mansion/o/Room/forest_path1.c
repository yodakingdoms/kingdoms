#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_read(string str);
int do_leave(string str);
int do_reach(string str);

void create_object(void)
{
    set_short("A forest path (nw/s)");
    set_long("You are on a path through a forest. The bushes beside the " +
             "road are thick and prevent you from leaving the path. Tall " +
             "trees grow close to the path, preventing you from seeing " +
             "very far into the woods. The ground slopes down gently to " +
             "the south and the path continues that way and back towards " +
             "Hazeldown to the northwest. Fallen branches and leaves from " +
             "the trees lie all over the ground and on one side of the " +
             "path stands a flat stone.\n");

    set_new_light(5);

    add_item("path","It's winding its way through a dense forest");
    add_item("forest|dense forest","A dense forest that seems to cover " +
             "a large part of the island");
    add_item("part|large part","The part of the island where you are");
    add_item("island|newbie island|Newbie Island","Newbie Island, that's " +
             "where you are now");
    add_item("bush|bushes|thick bush|thick bushes","Thick bushes with " +
             "nasty looking thorns, preventing you from leaving the path");
    add_item("thorn|thorns|nasty looking thorn|nasty looking thorns","You " +
             "don't want to find out what it feels like to get stung by " +
             "them so you don't think it would be a good idea to try to " +
             "pass them and leave the path");
    add_item("path","A path that doesn't seem to be too well trodden. You " +
             "see some round stones sticking out of the ground in some " +
             "places");
    add_item("stones|round stones|round stone","It seems as if this path " +
             "was once a road. It must have been a long time ago");
    add_item("road","It's not a road anymore, just a path");
    add_item("trees|tree|tall trees|tall tree","Tall trees grow all around " +
             "you. Their branches reach out above the path");
    add_item("branch|branch","The branches of the trees reach out over the " +
             "path. They're too high for you to reach them though");
    add_item("wood|woods","You can't see very far into the woods, there " +
             "are simply too many trees");
    add_item("ground|grassy ground","The ground is grassy and slopes down " +
             "gently to the south. Round stones can be seen sticking up " +
             "out of it in some places");
    add_item("hazeldown|Hazeldown|village|hobbit village","The hobbit " +
             "village to the northwest, it's where you came here from");
    add_item("branch|branches|fallen branch|fallen branches","There are " +
             "plenty of fallen branches on the ground around you. The " +
             "trees around you don't seem to have many broken branches " +
             "so they've probably been there for a while");
    add_item("leaf|leaves|fallen leaf|fallen leaves","There are " +
             "plenty of fallen leaves on the ground around you. It does " +
             "not seem to be time for the trees to drop them now so you " +
             "wonder if maybe there's been a storm not too long ago");
    add_item("stone|flat stone","A flat stone standing by the side of the " +
             "path. The surface of the stone is worn but there are some " +
             "runes carved into it that can still be made out");
    add_item("surface|surface of the stone","It is worn and it looks like " +
             "the stone has been standing here for a long time. The runes " +
             "carved into it can still be made out");
    add_item("@rune|@runes|rune|runes","#do_read");

    add_exit(PLAYGROUND,"northwest");
    add_exit(ROOM + "forest_path2","south");

    add_sounds(30,25,({
               "You hear the trees around you creak in the wind.\n",
               "You hear something move in the bushes beside the path.\n",
               "You hear chirping of birds from somewhere above you.\n"
               }));
}

void init(void)
{
    add_multi_action("do_leave","leave|pass");
    add_action("do_reach","reach");
    ::init();
}

int do_read(string str)
{
    if(TP->QS("runes") >= 10)
    {
        W("The runes say: Coridian Island road.\n" +
          "               Februarius 27, 687\n");
        S(TP->QN + " reads the runes on the flat stone.\n");
        return 1;
    }
    W("You can't understand the runes. Maybe higher runes skill would " +
      "be helpful?\n");
    S(TP->QN + " looks puzzled as " + TP->QPR + " looks at the runes " +
      "on the flat stone.\n");
    return 1;
}

int do_leave(string str)
{
    if((query_verb() == "leave" && str == "path") ||
       (query_verb() == "pass" && str == "bushes"))
    {
        W("The bushes are thick and the thorns in them are too sharp. You " +
          "decide not to do that.\n");
        S(TP->QN + " considers passing through the bushes and leaving " +
          "the path, but decides against it.\n");
        return 1;
    }
    return notify_fail(C(query_verb()) + " what?\n");
}

int do_reach(string str)
{
    if(str == "branch" || str == "branches")
    {
        W("They are too high above you for you to be able to reach them.\n");
        S(TP->QN + " looks up towards the branches above you.\n");
        return 1;
    }
    return notify_fail("Reach what?\n");
}
