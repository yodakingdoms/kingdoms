#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);

void create_object(void)
{
    set_short("A road through the village");
    set_long("A road through the village going north and south. To the " +
             "east is a house and to the west is the Oakdale adventurer's " +
             "guild. Further north is a crossroad. The castle looms over " +
             "the village to the east.\n");
    set_new_light(5);

    add_item("house","A nice stone house with a red roof and a stone " +
             "chimney");
    add_item("chimney","No smoke is coming from the chimney. It seems " +
             "like there's no fire burning in this house's fireplace");
    add_item("crossroad","This road crosses the main road through the " +
             "village there");
    add_item("castle","It looks dark and uninviting. You quickly avert " +
             "your eyes");

    add_exit(ROOM + "road13","north");
    add_exit(ROOM + "road15","south");
    add_exit(ROOM + "adv_guild","west");

    (ROOM + "house5")->load_doors();
    reset(0);
}
