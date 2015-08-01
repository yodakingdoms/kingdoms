#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

int trapdoor_open;

void   create_object(void);
void   reset(int arg);
void   init(void);
int    do_get(string str);
int    do_breathe(string str);
int    do_hold(string str);
int    do_open(string str);
int    do_close(string str);
void   trapdoor_opens(void);
void   trapdoor_closes(void);
int    query_trapdoor_open(void);
string long_fun(void);
void   trapdoor_desc(void);
void   air_desc(void);

void create_object(void)
{
    set_short("Underground stairs (d)");
    set_long("#long_fun");

    set_new_light(5);
    set_property("indoors");

    add_item("room","A small underground room that seems to have been "+
             "dug out under the hill, rather than being a natural cave");
    add_item("hill","This room seems to be inside an old hill in the "+
             "forest");
    add_item("ground","You are under it!");
    add_item("cave","This room does not seem to be a natural cave, but "+
             "rather a room dug out from below by someone");
    add_item("forest","#forest_desc");
    add_item("floor|stone floor","The floor is made of stone, and there "+
             "are some stairs going down through it");
    add_item("stone","Cold, damp, black stone");
    add_item("wall|walls","The walls in the room are made of packed "+
             "earth, and are too smooth to have been created naturally");
    add_item("earth","Cold, damp earth, packed into smooth, hard walls");
    add_item("ladder|wooden ladder","A wooden ladder that seems to be "+
             "in a very good shape, considering how damp the air in the "+
             "room is. The wood is not rotten at all, and you can only "+
             "conclude that someone has cared enough about this place "+
             "to put a new ladder here recently");
    add_item("wood","The wood in the ladder is in a remarkably good shape");
    add_item("trapdoor|trap door|wooden trapdoor|wooden trap door",
             "#trapdoor_desc");
    add_item("ceiling","The ceiling, as the walls, is made out of packed "+
             "earth");
    add_item("steps|stairs|staircase|stone staircase","Smooth, cold stone "+
             "steps leading deeper down into the hill. Dare you walk there?");
    add_item("small stone|round stone|stone|strange stone","A strange "+
             "looking round stone that glows with a soft yellow light");
    add_item("light|yellow light","The light in the room comes from the "+
             "stone in a niche in one of the walls");
    add_item("niche","A small niche in one of the walls. There is a small "+
             "stone in the niche, glowing with a soft, yellow light");
    add_item("air","#air_desc");

    add_exit(PCROOM+"forest_entrance_stairs","down");

    trapdoor_open = 0;

    reset(0);
}

void reset(int arg)
{
    if(trapdoor_open)
    {
        tell_room(TO,"Suddenly the trap door slams shut!\n");
        tell_room(TROLL_HILL,"Suddenly the trap door slams shut!\n");
        trapdoor_closes();
    }
}

void init(void)
{
    add_multi_action("do_get","get|take|pry");
    add_action("do_open","open");
    add_action("do_close","close");
    add_action("do_breathe","breathe");
    add_action("do_hold","hold");
    "/sys/admin/room/admin_room"->visit(1097);
}

int do_get(string str)
{
    if(str == "stone" || str == "stone from niche")
    {
        W("You try to pry the stone loose, but it seems to be "+
          "stuck.\nYou can't take the stone.\n");
        S(TP->QN + " tries to pry the glowing stone loose from "+
          "it's place in the niche, but does not succeed.\n");
        return 1;
    }
}

int do_breathe(string str)
{
    if(!trapdoor_open)
    {
        W("The air is cold, damp and so unpleasant to breathe that "+
          "you'd rather hold your breath than breathe.\n");
        S(TP->QN + " holds " + TP->QPO + " breath for a while.\n");
        return 1;
    }
    else
    {
        W("You take deep breaths of the fresh forest air. It feels "+
          "wonderful!\n");
        S(TP->QN + " takes deep breaths of the fresh forest air and "+
          "seems to be enjoying it.\n");
        return 1;
    }
}

int do_hold(string str)
{
    if(str == "breath" || str == "my breath")
    {
        if(!trapdoor_open)
        {
            W("You hold your breath for a while.\n");
            S(TP->QN + " holds " + TP->QPO + " breath for a while.\n");
            return 1;
        }
        else
        {
            W("You hold your breath for a while. Isn't this a waste "+
              "of fresh forest air?\n");
            S(TP->QN + " holds " + TP->QPO + " breath for a while.\n");
            return 1;
        }
    }
}

int do_open(string str)
{
    if(str == "trapdoor" || str == "trap door")
    {
        if(!trapdoor_open)
        {
            W("You climb up the ladder and push the trap door open.\n" +
              "You notice the trap door is at the top of a hill in a "+
              "forest somewhere on the island.\n");
            S(TP->QN + " climbs up the ladder and pushes the trap door "+
              "open.\n");
            tell_room(TROLL_HILL,"A trap door in the ground is opened "+
                      "from below.\n");
            trapdoor_opens();
            return 1;
        }
        else
        {
            W("The trap door is open already!\n");
            S(TP->QN + " appears to be pondering the possibilities "+
              "of opening an already open trap door... Strange...\n");
            return 1;
        }
    }
}

int do_close(string str)
{
    if(str == "trapdoor" || str == "trap door")
    {
        if(!trapdoor_open)
        {
            W("The trap door is closed allready!\n");
            S(TP->QN + " seems to ponder the possibilities of closing "+
              "a trap door that is already closed... Strange...\n");
            return 1;
        }
        else
        {
            W("You climb up the ladder and close the trap door above "+
              "you.\n");
            S(TP->QN + " climbs up the ladder and closes the trap door "+
              "above you.\n");
            tell_room(TROLL_HILL,"Someone closes the trap door from "+
                      "below.\n");
            trapdoor_closes();
            return 1;
        }
    }
}

void trapdoor_opens(void)
{
    tell_room(TO,"Fresh forest air rushes in through the open trap "+
             "door, making breathing in the room a whole lot more "+
             "pleasant.\n");
    add_exit(TROLL_HILL,"up");
    add_item("forest","You can see the forest through the open trap "+
             "door");
    TROLL_HILL->add_exit(PCROOM + "forest_entrance","down");
    TROLL_HILL->add_item("ladder","You can use the ladder to climb down "+
                         "into the room under the ground");
    TROLL_HILL->add_item("room","You can't see much of the room from up "+
                         "here. You would have to go down there to get "+
                         "a better look");
    trapdoor_open = 1;
}

void trapdoor_closes(void)
{
    tell_room(TO,"You feel more claustrophobic now that the "+
              "fresh air from the forest can't get down here.\n");
    remove_exit("up");
    TROLL_HILL->remove_exit("down");
    remove_item("forest");
    TROLL_HILL->remove_item("ladder");
    TROLL_HILL->remove_item("room");
    trapdoor_open = 0;
}

int query_trapdoor_open(void)
{
    return trapdoor_open;
}

string long_fun(void)
{
    if(!trapdoor_open)
    {
        return "A small underground room with a stone floor and walls "+
            "of packed earth. There is a ladder here, going up to a "+
            "closed trap door in the ceiling, and a stone staircase "+
            "going deeper down into the hill. The room is lit by a "+
            "strange stone that glows with a soft light from its place "+
            "in a niche in one of the walls. The air is chilly and damp, "+
            "and you feel a bit uneasy breathing here.\n";
    }
    else
    {
        return "A small underground room with a stone floor and walls "+
            "of packed earth. There is a ladder here, going up to an "+
            "open trap door in the ceiling, and a stone staircase "+
            "going deeper down into the hill. The room is lit by a "+
            "strange stone that glows with a soft light from its place "+
            "in a niche in one of the walls. The room is chilly, but "+
            "the fresh forest air entering the room through the open "+
            "trap door keeps you from feeling uneasy in the cramped "+
            "room.\n";
    }
}

void air_desc(void)
{
    if(trapdoor_open)
    {
        W("Fresh air from the forest comes into the room from above, "+
          "so the air is not as unpleasant as it usually is in cramped "+
          "rooms under the ground.\n");
    }
    else
    {
        W("The air is cold and damp and unpleasant to breathe.\n");
    }
}

void trapdoor_desc(void)
{
    if(trapdoor_open)
    {
        W("The wooden trap door is open and fresh air from the forest "+
          "above is entering the room.\n");
    }
    else
    {
        W("A closed wooden trap door in the ceiling.\n");
    }
}
