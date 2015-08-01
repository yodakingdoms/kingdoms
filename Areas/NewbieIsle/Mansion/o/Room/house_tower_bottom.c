#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
string long_fun(void);
void reset(int arg);
void tower_falls(void);
int query_tower_destroyed(void);

void create_object(void)
{
    set_short("A stairway (e/d)");
    set_long("#long_fun");
    add_property("indoors");
    set_new_light(5);

    add_item("stairway|narrow stairway","It's narrow and it can take you " +
             "down into the cellar");
    add_item("stair|stairs|winding stair|winding stairs","The stairs " +
             "are winding their way down into the cellar below. The steps " +
             "look like they are crumbling");
    add_item("step|steps","They look like they are crumbling, you'd better " +
             "be careful if you're going to walk down there");
    add_item("cellar","It is below you, you wonder what you'd find if you " +
             "would go down there");
    add_func_item("tower","#query_tower_destroyed",({
                  "The tower rises above you but you can't get up there " +
                  "from here since the stairs going up have collapsed. " +
                  "It looks to be intact up there though, so maybe you " +
                  "could find another way to get there",
                  "The whole inside of the tower has fallen and the rubble " +
                  "is all around you"
                 }));
    add_func_item("inside","#query_tower_destroyed",({
                  "",
                  "The whole of the inside of the tower has fallen into " +
                  "rubble, only a shell remains",
                  }));
    add_func_item("shell","#query_tower_destroyed",({
                  "",
                  "That's all that remains of the tower"
                  }));
    add_func_item("pile|piles|small pile|small piles|pile of rubble|" +
                  "piles of rubble|small pile of rubble|small piles of rubble",
                  "#query_tower_destroyed",({
                  "Small piles of rubble, evidence, if needed, that the " +
                  "mansion has been abandoned for a long time",
                  "Lots of rubble take up most of the space here. There has " +
                  "apparently been some sort of accident here not too long " +
                  "ago"
                  }));
    add_func_item("rubble","#query_tower_destroyed",({
                  "Most of it seems to have been cleared away, perhaps to " +
                  "provide passage down into the cellar",
                  "Piles of rubble take up most of the space in the " +
                  "stairwell but there is still enough room to squeeze " +
                  "down into the cellar",
                 }));
    add_func_item("debris","#query_tower_destroyed",({
                  "Most of the debris from the fallen stair seems to have " +
                  "been cleared away, perhaps to provide passage down " +
                  "into the cellar",
                  "The debris takes up most of the space here but you can " +
                  "still squeeze past it and go down into the cellar",
                 }));
    add_func_item("fallen stair","#query_tower_destroyed",({
                  "It would have let you go up in the tower if it still " +
                  "were here, but it's not so you will have to find another " +
                  "way"
                 }));

    add_exit(ROOM + "house_cellar_stair","down");
    add_exit(ROOM + "house_floor1_entrance","east");

    reset(0);
}

string long_fun(void)
{
    string long_desc = "A narrow stairway with winding stairs going " +
              "down into the cellar.";
    if(!query_tower_destroyed())
    {
        long_desc += " There used to be stairs going up into the tower " +
              "but those stairs have collapsed and now you can't get up " +
              "into the tower this way. There are small piles of rubble " +
              "around you but most of the debris from the fallen stair " +
              "seems to have been cleared away.";
    }
    else
    {
        long_desc += " There used to be stairs going up into the tower " +
              "but now the whole inside of the tower has collapsed and " +
              "the rubble takes up most of the space in the stairwell. " +
              "There are piles of it everywhere but it's still possible " +
              "to go east and down into the cellar.";
    }
    long_desc += " The cellar below you looks dark.";
    return long_desc + "\n";
}

void reset(int arg)
{
    add_monster(MONSTER + "goblin",2);
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
    tell_room(TO,"Suddenly the tower above collapses and stones and " +
              "boulders rain down on you! You throw yourself onto the " +
              "floor and miraculously avoid all the falling debris.\n");
    for(i = 0; i < sizeof(things); ++i)
    {
        // Kill all living things except players!
        if(living(things[i]) && !things[i]->is_player())
        {
            tell_room(TO,things[i]->QN + messages[random(3)]);
            things[i]->reduce_hit_point(1000);
        }
    }
    tell_room(TO,"You stand up when the coast is clear.\n");
}

int query_tower_destroyed(void)
{
    return (ROOM + "house_tower_top")->query_tower_destroyed();
}
