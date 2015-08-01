/*-------------------------------------------------------------------------
  By jumping here, the tower will collapse and kill most of the goblins
  preventing the hobbit from following the players out, making it easier
  to do the quest.
  -------------------------------------------------------------------------*/
#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

int tower_destroyed;

void create_object(void);
void reset(int arg);
void init(void);
void player_falls(object player);
int do_climb(string str);
int do_jump(string str);
void tower_falls(void);
int query_tower_destroyed(void);

void create_object(void)
{
    set_short("Top of a tower (d)");
    // Only need one long and items for that long since people aren't
    // supposed to be able to get here if the tower is fallen
    set_long("The top floor of a tower of an abandoned mansion in the " +
             "forest. The roof has fallen in and the trees of the forest " +
             "rise above you. The floor is covered with stones and debris. " +
             "The stairs going down to the floors below have collapsed and " +
             "there's now a gaping hole in the floor where the stairs " +
             "should be. The tower is circular and a small part of the " +
             "wall to the west is still standing and there's an empty " +
             "window there. The only way to get out of here seems to be " +
             "by climbing the ivy on the wall back down. The floor is " +
             "very unstable and it feels like the tower could collapse " +
             "at any time.\n");

    set_new_light(10);
    set_skip_obvious(1);

    add_item("top floor","This used to be the top floor but the roof and " +
             "most of the wall has collapsed");
    add_item("roof","There's no trace of the roof there anymore");
    add_item("wall|walls","Most of the wall has collapsed, only a small " +
             "part still stands and even that part doesn't look like " +
             "it could take even the assault of a light breeze");
    add_item("floor","It's covered with stones and debris and there's a " +
             "gaping hole where the stairs down used to be. It looks " +
             "very unstable, you wouldn't want to jump around up here");
    add_item("stone|stones|debris","Stones and debris covers the floor");
    add_item("stair|stairs|stairs down","There's only a gaping hole " +
             "there now. Apparently the stair that once was there has " +
             "collapsed. You can't see very far into the stairwell " +
             "below as debris hides the view");
    add_item("stairwell","It's there under the hole in the floor but " +
             "you can't see much of it");
    add_item("floors|floors below","You can't see much of them from here");
    add_item("hole|gaping hole","It's where the stairs used to go down " +
             "to the floors below. Not anymore though. If you're not " +
             "careful when you walk around up here you might fall down");
    add_item("tower","It feels very unstable. You wouldn't want to jump " +
             "around up here");
    add_item("part|small part|wall to the west","There's a window in the " +
             "part of the wall that still stands. The window is broken");
    add_item("window|empty window|broken window","It's more like a hole " +
             "in the wall now");
    add_item("hole in the wall","That's what the window looks like. By the " +
             "looks of the wall, the space currently occupied by it will " +
             "soon join that window as being occupied only by air");
    add_item("ivy","It grows on the outside of the tower, you can climb it " +
             "to get back down from here");
    add_item("outside|outside of the tower","Ivy grows there and it looks " +
             "like you could climb the ivy to get down");

    (ROOM + "outside_house")->load_me();
    (ROOM + "house_tower_bottom")->load_me();
    (ROOM + "house_floor1_entrance")->load_me();
    (ROOM + "house_cellar_stair")->load_me();

    reset(0);
}

void reset(int arg)
{
    tower_destroyed = 0;
}

void init(void)
{
    SYS_ADMIN->visit(1109);
    if(query_tower_destroyed())
    {
        // Need to do it this way since moving players in init apparently
        // messes things up with light
        set_alarm(0.1,0.0,"player_falls",TP);
    }
    else
    {
        add_action("do_climb","climb");
        add_action("do_jump","jump");
    }
    ::init();
}

void player_falls(object player) {
    tell_object(player,"As you pull yourself up into the tower you notice " +
                "that the whole inside of the tower has collapsed! You fall " +
                "down on the other side of the wall and land at the bottom " +
                "of the tower with a *THUD*!\n");
    player->move_player("falls down",
                        ROOM + "house_tower_bottom",
                        "comes falling down from above and lands with " +
                        "a *THUD*!",1,"silent");
    player->add_temporary_penalty(5 + random(5));
}

int do_climb(string str)
{
    if(str == "ivy" || str == "down")
    {
        W("You climb the ivy back down again.\n");
        TP->move_player("climbs the ivy to get back down",
                        ROOM + "outside_house",
                        "comes climbing down the ivy from above",1);
        return 1;
    }
    return notify_fail("Climb what?\n");
}

int do_jump(string str)
{
    W("You start jumping up and down. It doesn't seem to have been a " +
      "good idea as the tower collapses!\n");
    S(TP->QN + " starts jumping up and down. Suddenly the tower " +
      "collapses!\n");
    tower_falls();
    return 1;
}

void tower_falls(void)
{
    int i;
    object *things = all_inventory(TO);

    if(tower_destroyed) return;

    tower_destroyed = 1;

    (ROOM + "outside_house")->tower_falls();
    (ROOM + "house_tower_bottom")->tower_falls();
    (ROOM + "house_floor1_entrance")->tower_falls();
    (ROOM + "house_cellar_stair")->tower_falls();

    for(i = 0; i < sizeof(things); ++i)
    {
        if(living(things[i]))
        {
            // This is probably a player
            things[i]->catch_tell("You fall down as the tower collapses " +
                                  "around you!\n");
            things[i]->move_player("falls down as the tower collapses " +
                                   "around you",
                                   ROOM + "house_tower_bottom",
                                   "comes tumbling down from above",1);
            things[i]->catch_tell("You land on the floor with a *THUD*!\n");
            things[i]->add_temporary_penalty(10 + random(10));
            things[i]->catch_tell("Stones and debris land on the floor " +
                                  "all around you, one big rock narrowly " +
                                  "misses your head!\n");
            things[i]->catch_tell("You stand up, amazed to be alive!\n");
        }
        else
        {
            tell_room(TO,things[i]->QN + " falls down as the tower " +
                      "collapses.\n");
            transfer(things[i],find_object(ROOM + "house_tower_bottom"));
            tell_room(ROOM + "house_tower_bottom",things[i]->QN + " falls " +
                      "down from above.\n");
        }
    }
}

int query_tower_destroyed(void)
{
    return tower_destroyed;
}
