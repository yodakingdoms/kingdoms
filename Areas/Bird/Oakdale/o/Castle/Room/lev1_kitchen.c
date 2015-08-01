#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void init(void);
int do_enter(string str);
int load_doors(void);

void create_object(void)
{
    set_short("A chaotic kitchen");
    set_long("This is a kitchen. The room is cramped, with barrels and " +
             "sacks everywhere. Two huge ovens take up most of the north " +
             "wall, and various kinds of kitchen utensils lie everywhere, " +
             "giving the room a rather chaotic appearence. By the west wall " +
             "is a hole in the floor. The smell in here is quite " +
             "appalling.\n");
    set_new_light(5);
    set_skip_obvious(1);
    add_property("indoors");

    add_item("room|kitchen","The room is quite large, but since everything " +
             "here is in complete disarray, it seems very small. You can't " +
             "understand how people could actually prepare food in this mess");
    add_item("barrels|barrle|sacks|sack","No doubt containing supplies");
    add_item("supply|supplies","Things needed to prepare food");
    add_item("food","You see no food in here at the moment");
    add_item("oven|ovens","The two ovens are huge. Apparently it's " +
             "quantity, not quality that is the main priority in this " +
             "kitchen");
    add_item("wall|walls","Smooth stone walls");
    add_item("utensil|utensils","Spoons, forks, pans, cauldrons..");
    add_item("spoon|spoons|fork|forks|pans|pan|cauldron|cauldrons","They " +
             "are thrown out around the room. What a mess!");
    add_item("hole","A shaft goes down through the rock under the floor. " +
             "You could try to enter the hole and see where that shaft " +
             "leads if you wanted to");
    add_item("shaft","A steep, tight shaft");
    add_item("%","Sheesh! You're glad you're not here to eat");

    load_doors();
    reset(0);
}

void init(void)
{
    add_action("do_enter","enter");
    ::init();
}

int do_enter(string str)
{
    if(str == "hole")
    {
        if(!present_player(find_object((ROOM + "lev1_shaft"))))
        {
            W("You climb down through the hole and enter the shaft.\n");
            TP->move_player("climbs down into the hole, seems to lose " +
                            TP->QPO + " grip, and falls down into the shaft!!",
                            ROOM + "lev1_shaft","",1);
            return 1;
        }
        else
        {
            W("It seems like someone's falling down through the shaft right " +
              "now. At least you hear screaming from down there. Perhaps it " +
              "would be better to wait until whoever it is has landed... " +
              "You wouldn't want to hit him/her/it on the way down.\n");
            S(TP->QN + " steps up to the hole and looks down into it.\n");
            return 1;
        }
    }
    return notify_fail("Enter what?\n");
}

int load_doors(void)
{
    string dir1 = "south";
    string dir2 = "north";
    string next_room = ROOM + "lev1_corridor1";
    string desc = "oak door";
    int closed = 1;
    int locked = 0;
    string key_id = "_door_has_no_key_";
    string long_desc = "A strong oak door.\n";
    string entercmd1 = "south";
    string entercmd2 = "north";
    int solidity = 10;
    int complex = 0;
    int hidden1 = 0;
    int hidden2 = 0;

    add_door(dir1, dir2, next_room, desc,  closed, locked, key_id,
             long_desc, entercmd1, entercmd2, solidity, complex,
             hidden1, hidden2 );
    return 1;
}
