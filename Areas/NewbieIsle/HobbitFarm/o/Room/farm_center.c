#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void reset(int arg);
void init(void);

void create_object(void)
{
    set_short("Middle of the farm (e)");
    set_long("A wide open space in the middle of the small farm. The grass " +
             "on the ground has been trampled by many different feet and " +
             "there are many tracks and footprints all around you. South " +
             "of here is a big grassy hill with several small round " +
             "windows in its side. On top of the hill grows a huge oak " +
             "tree casting a shadow over the yard. North of the yard is a " +
             "building that looks like a stable. The yard continues to the " +
             "west and there are some more buildings there. To the east " +
             "you see the gate leading out from the farm.\n");

    set_new_light(5);

    add_item("space|open space|wide open space","It's what is normally " +
             "referred to as a yard");
    add_item("yard","It is in the middle of the farm. The buildings are " +
             "built around it");
    add_item("farm|cosy farm|small farm","A cosy little farm where " +
             "everything seems to be a bit smaller than normal");
    add_item("grass","It has been trampled so much there's almost no grass " +
             "left here");
    add_item("ground","There's almost no grass left. There seems to be a " +
             "lot of activity here");
    add_item("feet|foot","They are at the end of your legs");
    add_item("leg|legs","They are connected to your torso");
    add_item("torso","It's part of your body");
    add_item("body","Not bad, you're in pretty good shape");
    add_item("track|tracks|footprint|footprints","Tracks and footprints " +
             "from all kinds of animals, going off in all directions from " +
             "here");
    add_item("animal|animals|farm animal|farm animals","The usual kinds " +
             "of farm animal by the looks of the tracks");
    add_item("hill|grassy hill|big grassy hill","There's a round door in " +
             "it and several windows next to the door. It looks like a " +
             "hobbit house");
    add_item("house|houses|hobbit house","Hobbits often live in houses " +
             "dug out in a hill");
    add_item("window|windows|round window|round windows|small window|" +
             "small windows|small round window|small round windows","Small " +
             "windows in the side of the hill. None of the curtains are " +
             "drawn, something that gives the house an inviting feeling");
    add_item("curtain|curtains","The curtains in the windows are not drawn " +
             "so you can't see them from here");
    add_item("tree|oak|huge oak|huge tree|oak tree|huge oak tree","It " +
             "towers above you and seems to be the only thing on the farm " +
             "that doesn't look a bit smaller than it should be");
    add_item("shadow|long shadow","A long shadow cast by the oak tree");
    add_item("building|stable|stone building","A stone building that has " +
             "the looks of a stable. It seems a bit small to you but it " +
             "would probably be of a more normal size to someone the size " +
             "of a hobbit");
    add_item("buildings","A barn and a shed by the looks of them");
    add_item("barn|two story building","It is a two story building on the " +
             "far side of the yard");
    add_item("side|far side","There is a barn there");
    add_item("shed","The shed is crammed in between the barn and the stable");
    add_item("gate","The gate to the farm is east of here, you'd have to " +
             "go there to get a better look");
    add_item("$|$sound|$sounds|$animal|$animals","You hear the sounds of " +
             "farm animals coming from all around you");
    add_item("%|%smell|%animal|%animals","You feel the smell of farm " +
             "animals");

    add_exit(ROOM + "farm_gate","east");
    add_exit(ROOM + "farm_stable","north");
    add_exit(ROOM + "farm_west","west");

    (ROOM + "house_hallway")->load_doors();
    reset(0);
}

void reset(int arg)
{
    add_monster(MONSTER + "hobbit_farmer");
    ::reset(arg);
}

void init(void)
{
    SYS_ADMIN->visit(1115);
    ::init();
}
