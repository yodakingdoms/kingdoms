#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
string long_fun(void);
void reset(int arg);
void init(void);
int do_drink(string str);
void tower_falls(void);
int query_tower_destroyed(void);

void create_object(void)
{
    set_short("Cellar stair (u/e)");
    set_long("#long_fun");

    add_property("indoors");

    add_item("stair|stairs","They go back up from here. The steps don't " +
             "look very stable so watch your step when you go back up");
    add_item("step|steps","They look as if they could crumble when someone " +
             "steps on them");
    add_item("cellar|scary cellar|dark cellar|dark and scary cellar",
             "It is very dark, it's a good thing you brought something " +
             "to provide light or that you're able to squint well enough " +
             "to see here");
    add_item("room","It is very dark and scary. You feel a bit " +
             "claustrophobic standing here");
    add_item("wall|walls|stone wall|stone walls","The walls are rough " +
             "stone walls with moisture slowly trickling down to the floor");
    add_item("moisture","It trickles down to the floor to form some small " +
             "puddles. The air does not feel very damp so you wonder where " +
             "the moisture comes from");
    add_item("air","The air is pretty dry. Pretty strange for this kind " +
             "of place");
    add_item("puddle|puddles|small puddle|small puddles","Puddles on the " +
             "floor, formed when the moisture on the walls trickles down. " +
             "The water in the puddle looks pretty disgusting");
    add_item("water|disgusting water|black water|filthy water","The water " +
             "is black and filthy and does not look tasty at all");
    add_func_item("floor","#query_tower_destroyed",({
                  "The floor is covered with dirt and small stones",
                  "The floor is covered with debris and rocks"
                  }));
    add_item("dirt","There's lots of it here, noone has been down here to " +
             "clean in a very long time");
    add_item("stone|stones|small stone|small stones","There are plenty " +
             "of them on the floor, they look like they've fallen down " +
             "from the ceiling");
    add_item("ceiling","The ceiling has cracks in it and looks as if it " +
             "could fall down at any moment");
    add_item("crack|cracks","There are plenty of them in the ceiling. You " +
             "feel a bit worried standing under a ceiling looking like that");
    add_func_item("debris","#query_tower_destroyed",({
                  "",
                  "There's lots of it, there seems to have been an " +
                  "accident somewhere above"
                  }));
    add_func_item("pile|piles|rock|rocks|pile of rock|piles of rock",
                  "#query_tower_destroyed",({
                  "",
                  "There are many of them here. They seem to have fallen " +
                  "down from somewhere above"
                  }));
    add_item("dark room|dark cellar room","It is east of here, you have " +
             "to go there to get a better look");

    add_exit(ROOM + "house_tower_bottom","up");
    add_exit(ROOM + "house_cellar_room","east");

    reset(0);
}

string long_fun(void)
{
    string long_desc = "The stairs end in a dark and scary cellar. The " +
             "room is cramped and it feels like the stone walls are closing " +
             "in on you. There is moisture on the walls and small puddles " +
             "on the floor.";
    if(!query_tower_destroyed())
    {
        long_desc += " There's lots of dirt on the floor and many small " +
             "stones have fallen from the cracked ceiling.";
    }
    else
    {
        long_desc += " There's lots of debris and piles of rocks down here " +
             "but there's still enough room to move around and get back " +
             "up the stairs.";
    }
    long_desc += " East of here is another dark cellar room, but you " +
        "can't see what's in there from here. You feel very " +
        "claustrophobic in this room.";
    return long_desc + "\n";
}

void reset(int arg)
{
    add_monster(MONSTER + "wounded_goblin");
}

void init(void)
{
    add_multi_action("do_drink","drink|taste");
}

int do_drink(string str)
{
    if(str == "water" || str == "from puddle")
    {
        W("You do not want to taste filthy black water from the floor of " +
          "a cellar in a ruined mansion.\n");
        S(TP->QN + " bends down to inspect the water on the floor.\n");
        return 1;
    }
    return notify_fail(C(query_verb()) + " what?\n");
}

void tower_falls(void)
{
    int i;
    object *things = all_inventory(TO);
    string *messages = ({ " is hit on the head by a falling rock!\n",
                          " is flattened under a falling boulder!\n",
                          " is buried under falling stones!\n"
                       });
    // Without this, the player destroying the tower will kill the
    // goblins in this room and we don't want that
    set_this_player(0);
    tell_room(TO,"Suddenly there's a loud rumbling noise from above and " +
              "large rocks start falling down into the room! You throw " +
              "yourself onto the floor and miraculously avoid the falling " +
              "debris.\n");
    for(i = 0; i < sizeof(things); ++i)
    {
        // Kill all living things except players!
        if(living(things[i]) && !things[i]->is_player())
        {
            tell_room(TO,things[i]->QN + messages[random(3)]);
            things[i]->reduce_hit_point(1000);
        }
    }
    tell_room(TO,"You stand up again when the dust settles.\n");
}

int query_tower_destroyed(void)
{
    return (ROOM + "house_tower_top")->query_tower_destroyed();
}
