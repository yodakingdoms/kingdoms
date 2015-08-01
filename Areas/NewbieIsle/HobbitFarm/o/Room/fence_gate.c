#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit DOOR_MOD;

void create_object(void);

void create_object(void)
{
    set_short("Gate of a fence (w/e)");
    set_long("A fence divides the rolling landscape here. A well trodden " +
             "path winds east from here, in between the hills and a short " +
             "distance that way is a stone bridge crossing a river. There " +
             "is a gate in the fence and over the gate rises a wooden arch " +
             "with a large sign nailed to it. The fence itself is " +
             "delicately and artistically crafted of a dark kind of wood. " +
             "The grass grows tall around you and on the other side of the " +
             "fence are some buildings that make up a farm.\n");

    set_new_light(5);

    add_item("fence","The fence would be pretty high if you were a hobbit " +
             "but for someone your size, it really isn't. It's made up of " +
             "carefully carved wooden poles and is obviously a labour of " +
             "love rather than just some pieces of wood nailed together");
    add_item("pole|poles|wooden pole|wooden poles|carved wooden pole|" +
             "carved wooden poles","Wooden poles carved in delicate " +
             "patterns");
    add_item("pattern|patterns|delicate pattern|delicate patterns|" +
             "abstract pattern|abstract patterns","The patterns are " +
             "abstract and don't depict anything in particular. You wonder " +
             "if the whole fence looks like this or just this part near " +
             "the gate");
    add_item("landscape|rolling landscape","The hills stretch as far as " +
             "the eye can see");
    add_item("path|trodden path|well trodden path","It looks as if many " +
             "feet have trodden upon it in its days");
    add_item("ground","Most of the ground on the side of the path is " +
             "covered by tall grass");
    add_item("feet","The most interesting ones to you are the two at the " +
             "end of your legs");
    add_item("hill|hills|grassy hill|grassy hills","Grassy hills, most " +
             "of them with trees growing on top of them");
    add_item("top|tops|top of the hill|tops of the hills","Most of the " +
             "hills have trees growing on top of them");
    add_item("stone","The kind of stone people have used to build bridges " +
             "for centuries all over the Kingdoms");
    add_item("tree|trees","Trees grow on top of the hills, but without " +
             "going closer you can't tell much about them");
    add_item("bridge|stone bridge|old stone bridge","It looks very old " +
             "but it still seems to be in a very good shape");
    add_item("river","The river is gently running from the northwest " +
             "towards the southeast");
    add_item("arch|wooden arch","A wooden arch made of the same carved " +
             "poles that make up the fence. It's pretty high from a hobbit " +
             "perspective, but you would have to watch your head if you " +
             "were to go through the gate. A wooden sign is nailed to it");
    add_item("sign|@sign","The sign says: Bumbleroot Farm");
    add_item("wood|dark wood|dark kind of wood","A kind of wood you have " +
             "not seen anywhere else");
    add_item("grass|tall grass","The grass grows tall around you and sways " +
             "in the wind");
    add_item("building|buildings|farm|farm building|farm buildings","There " +
             "seems to be at least a barn and a stable there and also some " +
             "fields and a shed");
    add_item("barn|shed|stable","It looks like one. You'd have to get " +
             "closer to see more of it");
    add_item("field|fields","There are several of them, but you can't tell " +
             "what they are used for from here");
    add_item("$|$sound|$sounds","You can hear the sounds of animals coming " +
             "from the farm");

    add_exit(ROOM + "hazeldown_path3","east");

    set_door_control("door_control");
}
