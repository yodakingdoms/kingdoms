#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);
void init(void);
int do_address(string str);
int do_lean(string str);
int do_move(string str);

void create_object(void)
{
    set_short("Second floor landing (d/e)");
    set_long("This is the landing of the second floor. The stone staircase " +
             "goes back down to the first floor. The landing continues " +
             "to the east, where there seems to be a bedroom. A wooden " +
             "railing provides protection from falling down to the room " +
             "below. There used to be corridors going north and west from " +
             "here but it seems much of the second floor has collapsed and " +
             "now you can't go in those directions as large piles of rubble " +
             "block the entrances to the corridors.\n");

    set_new_light(5);
    add_property("indoors");

    add_item("landing","This is where the stairs from the first floor reach " +
             "the second floor. This was probably where the host of the " +
             "mansion stood when he addressed the guests arriving below " +
             "when there were parties here in the days before the mansion " +
             "was abandoned");
    add_item("host","The host probably left the mansion a long time ago. " +
             "You can't help wondering what happened that made people leave");
    add_item("guest|guests","You think it was a very long time since the " +
             "last time there were guests here");
    add_item("mansion","It looks more like a ruin than a mansion now");
    add_item("ruin","It must have been left to deteriorate for quite a long " +
             "time, judging by the state it is in");
    add_item("floor|second floor","This is the second floor of the " +
             "mansion. A large part of it seems to have collapsed and is " +
             "not accessible anymore. You wonder how safe the parts that " +
             "haven't collapsed yet are");
    add_item("part|large part","Only this landing and the room to the " +
             "east seems to be accessible now");
    add_item("room|room to the east|bedroom","The room to the east seems " +
             "to be a bedroom but you'd have to go there to get a better " +
             "look");
    add_item("staircase|stone staircase","It will take you down to the " +
             "room below. It seems to be in a reasonably good shape still");
    add_item("room below|first floor","You can go back there thanks to the " +
             "staircase, and that's what you would have to do to get a " +
             "better look");
    add_item("railing|wooden railing","The railing is there to prevent " +
             "people from falling down to the first floor. It does not " +
             "seem to be in a very good shape now and you probably should " +
             "not try to lean against it");
    add_item("wood","The wood looks rotten to the core and the railing " +
             "would probably crumble if you were to lean against it");
    add_item("corridor|corridors|north corridor|west corridor","There used " +
             "to be two of them going north and west from here but they've " +
             "collapsed and now big piles of rubble block further travel " +
             "in those directions");
    add_item("rubble|pile|piles|large pile|large piles|pile of rubble|" +
             "piles of rubble|large pile of rubble|large piles of rubble",
             "Large piles of rubble totally block the entrances to the " +
             "corridors to the west and the north. Moving all that rubble " +
             "would take very long and is probably pointless");
    add_item("entrance|entrances","The entrances are totally blocked by " +
             "the rubble. You wonder what kind of rooms once lay that way");

    add_exit(ROOM + "house_floor1_entrance","down");
    add_exit(ROOM + "house_floor2_bedroom","east");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "goblin",2);
}

void init(void)
{
    add_action("do_address","address");
    add_action("do_lean","lean");
    add_action("do_move","move");
}

int do_address(string str)
{
    if(str == "guest" || str == "guests" || str == "the guest" ||
       str == "the guests")
    {
        if(present("goblin",find_object(query_exit("down"))))
        {
            W("You are not the " + (TP->QGE == 2 ? "hostess" : "host") +
              " of the mansion and the goblins downstairs are not your " +
              "guests.\n");
            S(TP->QN + " opens " + TP->QPO + " mouth as if to speak but " +
              TP->QPR + " just peers down at the goblins downstairs " +
            "instead.\n");
        }
        else if(present_player(find_object(query_exit("down"))))
        {
            W("You are not the " + (TP->QGE == 2 ? "hostess" : "host") +
              " of the mansion and the people downstairs are not your " +
              "guests.\n");
            S(TP->QN + " opens " + TP->QPO + " mouth as if to speak but " +
              TP->QPR + " just peers down at the people downstairs " +
            "instead.\n");
        }
        else
        {
            W("You are not the " + (TP->QGE == 2 ? "hostess" : "host") +
              " of the mansion and there are no guests downstairs to " +
              "address.\n");
            S(TP->QN + " opens " + TP->QPO + " mouth as if to speak but " +
              TP->PRN + " just peers down at the room below instead.\n");
        }
        return 1;
    }
    return notify_fail("Address whom?\n");
}

int do_lean(string str)
{
    if(str == "against railing")
    {
        W("Not a good idea. The railing still stands but the wood looks " +
          "rotten and if you were to lean against it, it would probably " +
          "crumble and send you plummeting to the floor below.\n");
        S(TP->QN + " looks at the railing and ponders deeply.\n");
        return 1;
    }
    return notify_fail("Lean against what?\n");
}

int do_move(string str)
{
    if(str == "rubble")
    {
        W("It would take way too long for you to move all that rubble, " +
          "you decide it is pointless.\n");
        S(TP->QN + " looks at the rubble and ponders deeply.\n");
        return 1;
    }
    return notify_fail("Move what?\n");
}
