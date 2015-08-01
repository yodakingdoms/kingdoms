#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

int door_open;

void create_object(void);
string long_fun(void);
void reset(int arg);
void init(void);
int do_fit(string str);
int do_read(string str);
void open_door(void);
void close_door(void);
int query_door_open(void);

void create_object(void)
{
    set_short("A small shrine");
    set_long("#long_fun");
    set_new_light(1);
    add_property("indoors");

    add_item("chamber|cave","A small, cold cave that looks like a shrine " +
             "of some kind");
    add_item("shadow|shadows","Strange, eerie shadows created by the " +
             "flickering torches");
    add_item("walls","Smooth stone walls");
    add_item("floor","A very smooth stone floor");
    add_item("altar","A crude stone altar that clearly wasn't made by the " +
             "same people who dug out this very nicely created chamber");
    add_item("icon|icons","Small figurines and statues");
    add_item("figurines|statues","Probably representing the gods worshipped " +
             "here, but you can't recognize any of them");
    add_item("figurine|statue","It is probably in the likeness of some god, " +
             "you can't recognize it");
    add_item("symbols|symbol","Strange symbols you haven't seen before and " +
             "don't recognize");
    add_item("candle|candles","Two wax candles in black candle holders, " +
             "flickering desperatly");
    add_item("holder|holders","Two strangely shaped iron candle holders");
    add_item("light","A faint, flickering light");
    add_item("archway","It is highly decorated. Carved into the stone wall " +
             "is the image of two oaks, side by side. Their branches " +
             "reach out over the archway and intertwine in one, big " +
             "canopy. Over the archway are some runes");
    add_item("runes","Try to read them");
    add_item("image","An image of two oaks. One on each side of the " +
             "archway");
    add_func_item("branch|branches","#query_door_open",({
                  "You could pass under them if you could open the wall " +
                  "under them",
                  "You'll pass under them if you walk through the opening" }));
    add_func_item("canopy","#query_door_open",({
                  "You could pass under it if you could open the wall " +
                  "under them",
                  "You'll pass under it if you walk through the opening" }));
    add_func_item("block|stone|wall","#query_door_open",({
                  "It would seem the logic place for a door, but you can't " +
                  "see or feel any edges that would indicate that the " +
                  "stone and the wall is not one and the same. The only " +
                  "thing that breaks the smooth surface of the stone is " +
                  "a small hole in the centre of it" }));
    add_func_item("hole","#query_door_open",({
                  "A small hole. The shape of the hole is something like " +
                  "what you would get if you stuck a diamond into smooth, " +
                  "wet sand. If you had a stone that was shaped correctly, " +
                  "you could try to fit it into the hole" }));
    add_func_item("opening","#query_door_open",({
                  "",
                  "The opening leads into a dark tunnel" }));
    add_func_item("tunnel|dark tunnel","#query_door_open",({
                  "",
                  "You cannot see where it leads from here" }));

    add_exit(ROOM + "dgcave_tunnel","west");

    reset(0);
}

string long_fun(void)
{
    if(!door_open)
    {
        return "A small, cold cave with strange shadows dancing on the " +
               "walls. The stone floor is very smooth, and the chamber is " +
               "almost perfectly circular. In the centre of the room " +
               "stands a crude stone altar with a few icons and symbols on " +
               "it. There are two candles on the altar, providing the room " +
               "with light. In the east wall is a highly decorated archway, " +
               "sealed with a single, smooth block of stone that seems to " +
               "part of the wall around it.\n";
    }
    else
    {
        return "A small, cold cave with strange shadows dancing on the " +
               "walls. The stone floor is very smooth, and the chamber is " +
               "almost perfectly circular. In the centre of the room stands " +
               "a crude stone altar with a few icons and symbols on it. " +
               "There are two candles on the altar, providing the room " +
               "with light. In the east wall is a highly decorated archway. " +
               "It looks as if the archway has been sealed once, but now " +
               "there's an opening you can enter.\n";
    }
}

void reset(int arg)
{
    add_monster(MONSTER + "DGshaman",1);
    if(door_open)
    {
        close_door();
    }
}

void init(void)
{
    add_action("do_fit","fit");
    add_action("leave","enter");
    add_action("read","read");
    SYS_ADMIN->visit(291);
}

int do_fit(string str)
{
    object keystone;

    if(str == "stone" || str == "stone into hole" || str == "stone in hole" ||
       str == "jewel" || str == "jewel into hole" || str == "jewel in hole")
    {
        if(!door_open)
        {
            if(keystone = present("_secret_door_keystone_",TP))
            {
                W("As you fit the stone into the hole, there is a quick, " +
                  "bright burst of light. The jewel merges with the stone " +
                  "around it, and thin wedge of light appears slowly " +
                  "around the edge of the 'door'. Suddenly the stone " +
                  "swings inwards without making a sound. A voice in your " +
                  "head whispers: 'Welcome home, Sire...'\n");
                S("As " + TP->QN + " fits the stone into the hole, there's " +
                  "a quick, bright burst of light. A thin wedge of light " +
                  "appears slowly around the edge of the 'door', Suddenly " +
                  "the stone swings inwards without making a sound, " +
                  "revealing an opening.\n");
                keystone->destroy();
                open_door();
                if(!TP->test_flag(QUEST_SUB_FLAG_6))
                {
                    TP->add_exp(15000);
                    TP->set_flag(QUEST_SUB_FLAG_6);
                }
                return 1;
            }
            else
            {
                W("You don't have the right stone.\n");
                return 1;
            }
        }
        else
        {
            return 0;
        }
    }
    return notify_fail("You can't fit that into the hole, no matter how " +
                       "hard you try.\n");
}

int do_read(string str)
{
    if(str == "runes")
    {
        if(TP->query_skill("runes") + TP->query_int() > 50)
        {
            W("'Times of danger\n Bring the stone\n Kin or stranger\n" +
              " Welcome home'\n");
            S(TP->QN + " reads the runes over the archway.\n");
            return 1;
        }
        else
        {
            W("You can't read these runes.\n");
            S(TP->QN + " looks at the runes over the archway, but looks " +
              "confused.\n");
            return 1;
        }
    }
    return notify_fail("Read what?\n");
}

void open_door(void)
{
    tell_room(ROOM + "tunnel_cave_end","The stone door in the west wall " +
              "opens without making a sound...\n");
    add_exit(ROOM + "tunnel_cave_end","opening");
    (ROOM + "tunnel_cave_end")->add_exit(ROOM + "dgcave_shrine","out");
    door_open = 1;
}

void close_door(void)
{
    tell_room(TO,"The stone door in the east wall closes without making a " +
              "sound...\n");
    tell_room(ROOM + "tunnel_cave_end","The stone door in the west wall " +
              "closes without making a sound...\n");
    remove_exit("opening");
    (ROOM + "tunnel_cave_end")->remove_exit("out");
    door_open = 0;
}

int query_door_open(void)
{
    return door_open;
}
