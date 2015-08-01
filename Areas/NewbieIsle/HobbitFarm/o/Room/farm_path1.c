#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void reset(int arg);

void create_object(void)
{
    set_short("A path between two buildings (n/s)");
    set_long("A path going north between two buildings from the main yard " +
             "of the farm to an open field to the north. To the east is the " +
             "stone building that seems to be a stable and to the west " +
             "is a small wooden shed. The path is well trodden and tracks " +
             "from many different creatures can be seen on it. Thick bushes " +
             "grow by the walls of both buildings but their branches have " +
             "been cut so that they will not get in the way.\n");

    set_new_light(5);

    add_item("path|narrow path","The path is pretty narrow, and it would " +
             "have to be to fit in between the shed and the stable");
    add_item("building|buildings","There's a shed to the west and a stable " +
             "to the east");
    add_item("shed|wooden shed|small shed|small wooden shed","It's a small " +
             "wooden shed. It has no windows so you'd have to go south to " +
             "find out what's inside");
    add_item("stone building|stable|stone stable","The stone building " +
             "seems to be a stable. The entrance is southeast of here so " +
             "you would have to go that way to find out what's inside");
    add_item("stone|kind|normal kind|normal kind of stone","The normal " +
             "kind of stone used to build buildings you want to be sturdy");
    add_item("sturdy building|sturdy buildings","The stable seems to be " +
             "one of those");
    add_item("entrance","Neither building has an entrance here, you " +
             "should go south to the main yard if you want to get inside " +
             "them");
    add_item("yard|main yard","The main yard is south of here");
    add_item("field|open field","There's a field that looks like it should " +
             "be used to keep animals on north of here");
    add_item("animals|animal","You can't tell what kind of animal is " +
             "supposed to be kept in the field from here");
    add_item("ground","There are many tracks from animals on the ground");
    add_item("farm","You can't see much of the farm from here");
    add_item("track|tracks","There are tracks from many different " +
             "creatures on the path but most of the tracks seem to be " +
             "cow tracks");
    add_item("cow track|cow tracks","It looks as if this path is mostly " +
             "used to bring cows to and from the open field north of here");
    add_item("wall|walls","A stone wall or a wooden wall, depending on " +
             "which building you look at");
    add_item("stone wall","The stone wall is the wall of the stable");
    add_item("wooden wall","The wooden wall is the wall of the shed");
    add_item("bush|bushes|thick bush|thick bushes","Their branches have " +
             "been neatly trimmed");
    add_item("branch|branches","They have been neatly trimmed. You can " +
             "imagine that they'd grow out and completely fill the area " +
             "between the houses and block the path if they weren't " +
             "trimmed regularily");
    add_item("area","The area between the shed and the stable, currently " +
             "occupied by a path");
    add_item("$|$sound|$sounds|$animal|$animals","You hear the sounds of " +
             "farm animals coming mostly from the south");
    add_item("%|%smell|%animal|%animals","You feel the smell of farm " +
             "animals");

    add_exit(ROOM + "farm_west","south");
    add_exit(ROOM + "farm_cow_field","north");

    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "kitten");
}
