#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
int do_enter(string str);

void create_object(void)
{
    set_short("The main road through the village");
    set_long("The main road of the village leads east and west from here. " +
             "There is a house to the north, but you can't enter it from " +
             "here. To the south is a grove. Further east is the river, " +
             "and there seems to be a bridge crossing it. You can hear the " +
             "sound of the river from here, so it must be quite wild. The " +
             "castle looms over the village.\n");
    set_new_light(5);

    add_item("grove","A grove of healthy oak trees. It is hard to see " +
             "anything in there, as the branches of the trees block out " +
             "most of the light. You think you can hear something in " +
             "there, though..");
    add_item("river","It flows from the north to the south, and there is a " +
             "bridge crossing it");
    add_item("bridge","A sturdy stone bridge. A road seems to continue into " +
             "the forest on the other side");
    add_item("castle","Nothing is moving up on the battlements or in the " +
             "windows. No banners fly from the towers, yet you can't shake " +
             "the feeling that someone's watching you from up there");
    add_item("$|$something|$grove","The river roars as it rapidly flows " +
             "south, but you think you can hear another sound as well..");
    add_item("$sound|$another sound","You think you can hear a sad tune " +
             "being played on a flute. The sound is coming from within " +
             "the grove... Maybe you could enter it and investigate?");

    add_exit(ROOM + "square","west");
    add_exit(ROOM + "road9","east");
}

void init(void)
{
    add_action("do_enter","enter");
}

int do_enter(string str)
{
    if(str == "grove")
    {
        W("You follow the sound of the flute and enter the grove.\n");
        TP->move_player("enters the grove",
                        ROOM + "grove",
                        "comes walking into the grove from the road " +
                        "outside",1);
        return 1;
    }
    return notify_fail("Enter what?\n");
}
