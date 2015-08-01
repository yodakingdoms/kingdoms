#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
string long_fun(void);
void reset(int arg);
void init(void);
int do_touch(string str);
void tower_falls(void);
int query_tower_destroyed(void);
void palace_desc(void);
void summer_palace_desc(void);

void create_object(void)
{
    set_short("Entrance of the house (out/w/n/e/u)");
    set_long("#long_fun");
    add_property("indoors");
    set_new_light(5);

    add_item("hallway|grand hallway|entrance","It used to be the entrance " +
             "to the mansion, designed to impress visitors. It won't " +
             "impress anyone these days");
    add_item("mansion","It has been abandoned for a very long time judging " +
             "by the state of disrepair it is in");
    add_item("furniture","Any furniture that might have been here is long " +
             "gone now. You can only imagine how splending this room once " +
             "looked");
    add_item("carpeting|rag|rags","There's not a lot of it left, just a few " +
             "rags in the corners. It is so filthy you can't even tell " +
             "what colour it once was");
    add_item("wall|walls|stone wall|stone walls","Stone walls that don't " +
             "look very strong anymore. Cracks run from the floor to the " +
             "ceiling, not very reassuring");
    add_item("crack|cracks","Cracks have broken the walls, and you feel " +
             "a bit nervous looking at them. It looks like the whole " +
             "mansion could fall apart at any time");
    add_item("floor|stone floor|bare floor|cold floor","The floor is made " +
             "of stone and almost completely bare. It feels pretty cold " +
             "now that there's no carpeting on it anymore");
    add_item("corner|corners","There are some rags in the corners. They " +
             "look like what's left of the carpeting that once covered the " +
             "floor. There's filth and dirt in the corners as well");
    add_item("filth|dirt","There's quite a bit of it in the corners. It " +
             "is obvious noone has been here to clean up in a long time");
    add_item("tapestry|ragged tapestry","A ragged tapestry depicting a " +
             "magnificent palace");
    add_item("palace|magnificent palace","#palace_desc");
    add_item("summer palace|city|kordar|Kordar|city of kordar|" +
             "city of Kordar","#summer_palace_desc");
    add_item("staircase|stone staircase","A stone staircase that can " +
             "take you up to the second floor. Some of the steps are " +
             "cracked but it still looks to be in a rather good shape");
    add_item("step|steps|surface","Some of the steps have cracks in them " +
             "but they only seem to be on the surface and not go all the " +
             "way through the steps");
    add_item("second floor","You'd have to go up the staircase to get " +
             "a better look at it");
    add_item("doorway|small doorway","It leads to the west, there seems " +
             "to be a small room beyond it");
    add_item("small room","You'd have to go there to get a better look");
    add_item("large doorway|large doorways|doorways","One leads north " +
             "and one goes east. You can't see the rooms beyond them " +
             "very well from in here");
    add_item("rooms|rooms beyond","You'd have to go to those rooms to " +
             "get a better look of them");
    add_item("door|doors","There probably were some doors in the doorways " +
             "once but they're gone now");
    add_func_item("stone|stones","#query_tower_destroyed",({
                  "That's what the floor is made of. It feels pretty cold",
                  "Stones and other debris cover the floor. It seems as if " +
                  "most of it has spilt out into this room through the " +
                  "small doorway to the west"
                 }));
    add_func_item("debris|other debris","#query_tower_destroyed",({
                  "",
                  "That's what the floor is made of. It feels pretty cold",
                  "Stones and other debris cover the floor. It seems as if " +
                  "most of it has spilt out into this room through the " +
                  "small doorway to the west"
                 }));

    add_exit(ROOM + "outside_house","out");
    add_exit(ROOM + "house_tower_bottom","west");
    add_exit(ROOM + "house_floor1_dining_room","north");
    add_exit(ROOM + "house_floor1_ballroom","east");
    add_exit(ROOM + "house_floor2_landing","up");

    reset(0);
}

string long_fun(void)
{
    string long_desc = "This is what's left of what used to be the grand " +
               "hallway of the mansion. It looks as if it has been " +
               "abandoned a long time. There's no furniture left and the " +
               "only thing left of the carpeting on the floor are some " +
               "rags in the corners. The stone walls are cold and bare " +
               "except for a ragged tapestry on one of them. In front of " +
               "you, a stone staircase goes up to the second floor. To the " +
               "west is a small doorway and to the north and east are " +
               "larger ones where there seems to have been doors who are " +
               "now gone.";
    if(query_tower_destroyed())
    {
        long_desc += " The floor is covered with stones and other debris, " +
                "there seems to have been an accident here not too long " +
                "ago.";
    }
    return long_desc + "\n";
}

void reset(int arg)
{
    add_monster(MONSTER + "goblin",3);
}

void init(void)
{
    add_multi_action("do_touch","touch|feel");
}

int do_touch(string str)
{
    if(str == "floor")
    {
        W("The floor is pretty cold to the touch.\n");
        S(TP->QN + " bends down and touches the floor.\n");
        return 1;
    }
    return notify_fail(C(query_verb()) + " what?\n");
}

/**
* Called from house_tower_top when a player triggers it.
*/
void tower_falls(void)
{
    int i;
    object *things = all_inventory(TO);
    string *messages = ({ " is knocked over brutally by a flying rock!\n",
                          " is hit in the groin by a falling stone!\n",
                          " is hit in the face by a sharp, flying stone!\n"
                       });
    // Without this, the player destroying the tower will kill the
    // goblins in this room and we don't want that
    set_this_player(0);
    tell_room(TO,"Suddenly the tower to the west collapses in a " +
              "spectacular manner! You throw yourself on the floor and " +
              "miraculously manage to avoid being hit by flying debris.\n");
    for(i = 0; i < sizeof(things); ++i)
    {
        // Kill all living things except players!
        if(living(things[i]) && !things[i]->is_player())
        {
            tell_room(TO,things[i]->QN + messages[random(3)]);
            things[i]->reduce_hit_point(1000);
        }
    }
    tell_room(TO,"You stand up as the dust settles.\n");
}

int query_tower_destroyed(void)
{
    return (ROOM + "house_tower_top")->query_tower_destroyed();
}

/**
* Checks to see if the player has been to the summer palace in Kordar.
* If he/she/it has, he/she/it will recognize the palace in the add_item.
*/
void palace_desc(void)
{
    if(!TP->test_expl_flag(643))
    {
        W("It looks magnificent, but you do not recognize it.\n");
    }
    else
    {
        W("It looks like the summer palace in the city of Kordar.\n");
    }
}

void summer_palace_desc(void)
{
    if(!TP->test_expl_flag(643))
    {
        W("There is no summer palace here.\n");
    }
    else
    {
        W("You remember your visit there and wish you were there " +
          "instead of in this mansion.\n");
    }
}
