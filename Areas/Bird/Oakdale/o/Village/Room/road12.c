#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);

void create_object(void)
{
    set_short("A road through the village");
    set_long("A road through the village. There is a house to the west and " +
             "a larger building to the east with a sign hanging over the " +
             "door. You can hear people screaming inside the building. To " +
             "the north the road leaves the village and enters the forest. " +
             "To the east the cliff rises into the air. The castle stands " +
             "there, silent and sinister.\n");
    set_new_light(5);

    add_item("house","It is built out of stone with a wooden roof. There " +
             "is smoke coming from the chimney");
    add_item("building","The building has two floors. There is a sign " +
             "hanging over the door and the window on the second floor " +
             "are barred");
    add_item("smoke","Apparently there is a fire burning in the fireplace");
    add_item("sign|@sign","'Oakdale sanatarium'");
    add_item("forest","A dense forest. Most of the trees seem to be oaks");
    add_item("cliff","A sheer cliff that looks impossible to climb");
    add_item("castle","There is something unnatural about that castle. Just " +
             "looking at it gives you the creeps");
    add_item("window","The window on the second floor of the building to " +
             "the east is barred");
    add_item("$|$people|$screams|$screaming|$shouting|$shouts","You hear " +
             "shouting and screaming from inside the building. You can't " +
             "hear what they scream, but there seem to be more than one " +
             "screamer in there");

    add_exit(ROOM + "road11","south");
    add_exit(ROOM + "sanatarium","east");
    add_exit(FOREST + "Room/north_road1","north");

    (ROOM + "house11")->load_doors();
    reset(0);
}
