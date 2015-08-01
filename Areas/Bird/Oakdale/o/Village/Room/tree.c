#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);

void create_object(void)
{
    set_short("You are at the top of the big oak tree");
    set_long("You are at the top of the big oak. You have a nice view of " +
             "the village and the surrounding valley from here. The " +
             "branches of the tree are thick and strong, and you feel " +
             "really safe here. The villagers on the ground look amused as " +
             "they observe you sitting in the tree. To the east the castle " +
             "looms, watching over the village.\n");
    set_new_light(5);

    add_item("oak","It is a huge oak, one of the tallest oaks you have " +
             "ever seen");
    add_item("view|valley","You look out over the valley. To the south " +
             "you see a slender white church tower rise above the " +
             "treetops. To the east the river flows between the village " +
             "and the castle, and far to the southeast there appears to be " +
             "a waterfall. The road leading north from the crossroad leads " +
             "to some hills. In the forest on the west side of that road, " +
             "you see a small cottage. The east road crosses a bridge over " +
             "the river, and it seems like it will eventually lead up to " +
             "the castle");
    add_item("village","Twenty-five or so small houses");
    add_item("branch|branches","Strong and thick");
    add_item("villagers","They appear to think you're quite an amusing " +
             "sight as you sit up in the tree");
    add_item("castle","It stands there on the cliff overlooking the village");
    add_item("church|tower","A slender tower can be seen over the trees " +
             "to the south. It appears there is a church there");
    add_item("river","You can't actually see the river, or how wide it is. " +
             "You just see the mist formed by the drizzle it throws up");
    add_item("waterfall","You are not sure, but what else could throw up " +
             "such a big cloud of drizzle?");
    add_item("hills","They are to the north. You are not sure, but there " +
             "seem to be some caves in the hillsides");
    add_item("cave|caves","You can't tell for sure from here");
    add_item("cottage","The road passes a few hundred feet to the east of " +
             "the cottage. You guess there must be a path from the road " +
             "to the house");
    add_item("bridge","From here it looks like a sturdy stone bridge");

    add_exit(ROOM + "crossroad","down");
}

void init(void)
{
    SYS_ADMIN->visit(290);
}
