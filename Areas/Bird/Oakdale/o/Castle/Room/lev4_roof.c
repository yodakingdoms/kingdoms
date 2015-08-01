#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_DOOR;

void create_object(void);
void init(void);

void create_object(void)
{
    set_short("A roof in front of a tower");
    set_long("An open area up on the roof of the castle. A five foot high " +
             "wall goes round the edge of the roof. On the other side is " +
             "the hundred foot drop down into the forested valley below. " +
             "Directly in front of you is the thin, black tower that rises " +
             "above everything else in the castle. You are filled with awe " +
             "as you look up at the tower. Dark clouds circle the tower " +
             "slowly, and the wind is howling. The surface of the tower " +
             "is black and smooth. Three stone steps lead up to the door " +
             "into the tower. Over the door is a dragon's head that has " +
             "been cut out of the stone of the tower. You have an " +
             "unsettling feeling that someone is watching you from high up " +
             "in the tower.\n");
    set_new_light(5);
    set_skip_obvious(1);

    add_item("area|roof","You are up on a roof in the west part of the " +
             "castle");
    add_item("edge|wall","A five foot high wall goes round the edge of the " +
             "wall");
    add_item("drop|valley","The valley lies several hundred feet down " +
             "from the roof where you stand");
    add_item("tower","You stand in front of the highest tower of the " +
             "castle. The thin, black structure almost touches the clouds " +
             "above. You feel very uneasy here and it's almost like you " +
             "can feel an evil power radiating from the tower");
    add_item("cloud|clouds","Dark, eerie clouds slowly circling over the " +
             "tower. You're not sure, but you thought you saw something " +
             "moving up there");
    add_item("something","You can't see it now, but it looked like a huge, " +
             "dark shadow swept through the clouds. Maybe it's not such a " +
             "good idea to be standing around here..");
    add_item("surface","The surface of the tower is smooth and black. It's " +
             "not made of stone. In fact, you can't tell what it is made of");
    add_item("dragon|head","A black, sculpted dragon's head. The dragon " +
             "seems to be gazing hungrily at you, and you feel most " +
             "uncomfortable standing in front of it");

    (ROOM + "lev4_stairroom")->load_doors();
    (ROOM + "lev4_tower")->load_doors();
}

void init(void)
{
    SYS_ADMIN->visit(348);
    ::init();
}
