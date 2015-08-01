#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);

void create_object(void)
{
    set_short("A road in the village, ending here");
    set_long("You are on a road in the village. The road ends here and " +
             "it only goes back north. There are houses to the west and " +
             "the south, and to the south and the east is the river. The " +
             "river flows swiftly from the northeast to the southwest " +
             "here. To the northeast the castle looms over the village.\n");
    set_new_light(5);

    add_item("house","A small stone house with a wooden roof and a stone " +
             "chimney");
    add_item("river","The river flows swiftly past this point. Trying to " +
             "swim across here would be foolish");
    add_item("castle","The castle looks eerie. You feel a shiver run down " +
             "your spine as you look at it");

    add_exit(ROOM + "road25","north");

    (ROOM + "house14")->load_doors();
    reset(0);
}
