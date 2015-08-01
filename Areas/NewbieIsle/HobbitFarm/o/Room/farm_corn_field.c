#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

object scarecrow;

void create_object(void);
void reset(int arg);
void my_reset(void);
void init(void);
int do_place(string str);
int query_is_quest_field(void);

void create_object(void)
{
    set_short("A cornfield (ne)");
    set_long("A large cornfield on the southwest side of the farm. The corn " +
             "is planted in neat straight rows going far into the distance " +
             "to the south. The soil is damp and dark brown and looks very " +
             "fertile. A small wooden wagon stands near the edge of the " +
             "field and a shovel stands leaning against it. The corn " +
             "is swaying peacefully in the wind coming in from the ocean " +
             "in the distance to the west. North of here is a poultry yard " +
             "and to the northeast is a smaller fenced in field.\n");

    set_new_light(5);

    add_item("field|large field|cornfield|large cornfield","The field " +
             "stretches far to the south and to the west, you can't see " +
             "where it ends");
    add_item("side|southwest side","The field takes up most of this side " +
             "of the farm");
    add_item("farm","A place to grow crops and keep animals");
    add_item("corn|crops","Rows of corn stretch far into the distance. The " +
             "corn is so high you can't see very far into the field");
    add_item("row|rows|neat row|neat rows","It looks like a lot of effort " +
             "has gone into plating the corn and making the rows perfect");
    add_item("soil|damp soil|brown soil|dark brown soil|fertile soil|ground",
             "The soil looks fertile and perfect for growing corn in. " +
             "It also looks like it could be a good spot to place a " +
             "scarecrow in");
    add_item("wagon|wooden wagon|small wooden wagon","A small wooden wagon " +
             "that's closer to the size of a wheelbarrow for someone who " +
             "is not the size of a hobbit");
    add_item("wheelbarrow","It's not really a wheelbarrow, it's just so " +
             "small that it's the size of one");
    add_item("shovel","Someone probably left it there when his, her or its " +
             "work was done for the day");
    add_item("ocean","You can't see it, but you know it's that way");
    add_item("yard|poultry yard","That's where the poultry is kept");
    add_item("poultry|bird|birds","You'd have to go to the poultry yard " +
             "to see if there are any birds there");
    add_item("smaller field|small field|smaller fenced in field","It " +
             "looks like a field where animals are kept");
    add_item("fence","The fence goes round the smaller field to the " +
             "northeast");
    add_item("animal|animals","You'd have to go to the field to the " +
             "northeast to see if there are any animals there");
    add_item("%|%soil|%damp soil","You feel the smell of the damp soil");
    add_item("$|$ocean|$wave|$waves","You faintly hear the sound of the " +
             "waves of the ocean some distance to the west");

    add_exit(ROOM + "farm_path2","northeast");

    add_sounds(30,10,({ "The corn around you sways gently in the wind.\n",
                        "You feel a soft wind in your face.\n"
                     }));

    reset(0);
}

void reset(int arg)
{
    my_reset();
}

void my_reset(void)
{
    if(scarecrow)
    {
        scarecrow->destroy();
    }
    add_monster(MONSTER + "crow",10 + random(5));
}

void init(void)
{
    SYS_ADMIN->visit(1117);
    add_action("do_place","place");
    ::init();
}

int do_place(string str)
{
    object crow;
    object player_scarecrow = present("_scarecrow_quest_scarecrow_",TP);

    if(!player_scarecrow) return 0;

    if(str == "scarecrow" || str == "scarecrow in ground" ||
       str == "scarecrow in soil")
    {
        if(!scarecrow)
        {
            W("You stick the scarecrow into the ground.\n");
            S(TP->QN + " sticks a scarecrow into the ground.\n");
            tell_room(TO,"The crows take one look at the scarecrow " +
                      "before they turn around and fly away with their " +
                      "tailfeathers between their legs!\n");
            transfer(player_scarecrow,TO);
            scarecrow = player_scarecrow;
            scarecrow->place();

            crow = present("_scarecrow_quest_crow_",TO);
            while(crow)
            {
                crow->destroy();
                crow = present("_scarecrow_quest_crow_",TO);
            }
            (OBJECT + "quest_obj")->quest_solved(TP,1);
            write_file(QUEST_LOG,C(TP->QRN) + " solved the " +
                       "quest at level " + TP->query_level() +
                       " Time: " + ctime(time()) + "\n");

            W("Well done, you've helped farmer Bumbleroot!\n" +
              "You feel more experienced.\n");
            // Reset quest things after 5 minutes
            set_alarm(300.0,0.0,"my_reset");
        }
        else
        {
            W("Someone has already placed a scarecrow here and scared all " +
              "the nasty birds away.\n");
        }
        return 1;
    }
    return notify_fail("Place what in what?\n");
}

int query_is_quest_field(void)
{
    return 1;
}
