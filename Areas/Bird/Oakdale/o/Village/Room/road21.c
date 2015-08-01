#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);

void create_object(void)
{
    set_short("A small yard");
    set_long("The side road ends here in a small yard surrounded by " +
             "three houses. The forest has closed in on the village and " +
             "you see the treetops over the roofs of the houses. The house " +
             "to the west is the Oakdale blacksmith's shop. The castle " +
             "looms high over the village to the east.\n");
    set_new_light(5);

    add_item("houses","Small houses with stone chimneys");
    add_item("forest","You see the treetops over the roofs of the houses");
    add_item("treetops","All of the trees in the forest seem to be oaks");
    add_item("castle","The castle stands there on its cliff, silent and " +
             "sinister");
    add_item("cliff","The cliff is very high and smooth. It looks " +
             "impossible to climb");

    add_exit(ROOM + "road20","south");
    add_exit(ROOM + "smith","west");

    (ROOM + "house8")->load_doors();
    (ROOM + "house9")->load_doors();
    reset(0);
}
