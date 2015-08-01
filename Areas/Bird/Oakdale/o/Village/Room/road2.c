#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);

void create_object(void)
{
    set_short("A road leading down into a valley");
    set_long("The road leads down into a valley. A village lies securely "+
             "nestled among the trees. A few thin pillars of smoke are " +
             "rising up into the air, but otherwise the sky is remarkably " +
             "clear. There is an almost magic shimmer over this peaceful " +
             "valley, but when you look up the castle comes into view. " +
             "The shimmer over the valley seems to disappear and you " +
             "feel somewhat uneasy.\n");
    set_new_light(5);

    add_exit(ROOM + "road1","west");
    add_exit(ROOM + "road3","east");

    add_item("valley","A deep, tranquil valley");
    add_item("village","A small village. You see people moving about, and " +
             "you can hear talking and other noises");
    add_item("trees","Strong, healthy oak trees");
    add_item("smoke","The smoke rises straight up into the calm air");
    add_item("shimmer","Almost like a shimmering mist making it hard to see " +
             "clearly. The shimmer dissapears as soon as the castle on the " +
             "cliff comes into view");
    add_item("castle","A black castle built upon a high cliff. It looms " +
             "above the village almost like a huge bird ready to swoop " +
             "down and strike it's claws into it's prey. No light can be " +
             "seen in any of the windows. The birds you saw circling the " +
             "towers earlier have disappeared");
    add_item("cliff","It seems to be several hundred feet high");
    add_item("$","You hear talking, shouting, a church bell ringing and " +
             "some other noise you can't quite place");
    add_item("$noise","You hear a strange screeching noise coming from the " +
             "castle. Something living? Well, not like anything you've " +
             "ever encountered before");
}
