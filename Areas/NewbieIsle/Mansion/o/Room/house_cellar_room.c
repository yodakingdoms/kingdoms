#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

object hobbit;

void create_object(void);
void reset(int arg);
void init(void);
int do_drink(string str);
void start_quest(void);
void my_reset(void);

void create_object(void)
{
    set_short("A cellar room (w)");
    set_long("A dark, cramped cellar room. There is moisture on the walls " +
             "and small puddles on the floor. The walls are lined with " +
             "empty wooden shelves and there are also a few crates and " +
             "barrels in the room. The floor is covered with small stones " +
             "that look like they've fallen down from the ceiling. There " +
             "are many cracks in the ceiling and it looks as if it could " +
             "fall down any second.\n");

    add_property("indoors");

    add_item("room|cellar room|dark room|cramped room|dark, cramped cellar " +
             "room","You feel very uneasy standing in it. It feels like " +
             "the walls are closing in");
    add_item("moisture","There's a lot of it on the walls, and it's " +
             "dripping down into puddles on the floor");
    add_item("wall|walls|rough wall|rough walls|stone wall|stone walls|" +
             "rough stone walls","The walls are rough stone walls and look " +
             "like they are crumbling. They are lined with shelves and " +
             "there's a lot of moisture on them");
    add_item("stone|rough stone","The stone is rough. It looks like this " +
             "room has been cut out from the stone");
    add_item("puddle|puddles|small puddle|small puddles","There are quite " +
             "a few of them on the floor, the water looks disgusting");
    add_item("water|filthy water|disgusting water|filthy and disgusting water",
             "It looks filthy and disgusting. You would not want to drink " +
             "that");
    add_item("floor","There are small puddles of water and small stones " +
             "on it");
    add_item("shelf|shelves|wooden shelf|wooden shelves|empty shelf|" +
             "empty shelves|empty wooden shelf|empty wooden shelves",
             "They are all empty. You get the feeling you're not the first " +
             "one who's come down here since the mansion was abandoned and " +
             "that every room has been thoroughly searched by others " +
             "before you");
    add_item("crate|crates|barrel|barrels","They've been left here but they " +
             "are all empty. You can't tell what they once contained");
    add_item("stone|stones|small stone|small stones","They cover the floor");
    add_item("ceiling","The ceiling is cracked and looks like it could " +
             "fall in at any moment");
    add_item("crack|cracks","There are plenty of them in the ceiling. You " +
             "wonder what's happened here as those cracks don't look like " +
             "they've occured just because of time passing");

    add_exit(ROOM + "house_cellar_stair","west");

    reset(0);
}

void reset(int arg)
{
    // Put this here as well in case things get mixed up elsewhere
    my_reset();
}

void init(void)
{
    SYS_ADMIN->visit(1108);
    add_multi_action("do_drink","drink|taste");
}

int do_drink(string str)
{
    if(str == "water" || str == "from puddle")
    {
        W("No. You definitely don't want to drink that filthy water.\n");
        S(TP->QN + " investigates the water in a puddle with a disgusted " +
          "look.\n");
        return 1;
    }
    return notify_fail(C(query_verb()) + " what?\n");
}

void start_quest(void)
{
    // Players get 15 minutes to get the quest done before the hobbit
    // gives up (so it won't be stuck and prevent someone else from
    // doing it). This is called from the hobbit boy when quest is
    // started
    set_alarm(900.0,0.0,"my_reset");
}

void my_reset(void)
{
    if(!hobbit)
    {
        hobbit = add_monster(MONSTER + "hobbit_boy");
    }
    else if(!present(hobbit,TO))
    {
        hobbit->move_player("says: This is taking too long, I'm going " +
                            "back :(\nHobbit leaves",
                            ROOM + "house_cellar_room",
                            "stumbles into the room",1);
        hobbit->my_reset();
    }
}
