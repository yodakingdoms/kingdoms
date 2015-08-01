#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_SOUND;

void  create_object(void);
void  init(void);
int   do_climb(string str);  

void create_object(void)
{
  set_short("At the top of the slope (ne)");
  set_long("You stand at the top of the cliff. From here you have "+
           "a marvellous view of the grey sea to the west. The strong "+
           "wind from the sea is blowing into your face, and you can see "+
           "all the way to the Larsia continent to the west. Short grass "+
           "grows on the ground of this viewpoint, but you can also make "+
           "out some footprints here. The drop down the cliff is to the "+
           "west, and there are tall trees around you in all other "+
           "directions. There is a barely noticable path entering the "+
           "forest to the northeast, while the only way to get back down "+
           "would be to climb.\n");
  set_new_light(5);
  set_dragon_visibility(1);
  set_room_hint("Be careful if you enter the forest here at night. There "+
                "are trolls living in there and they might be about. Of "+
                "course, if the sun is up, all the trolls you'll see will "+
                "be made of stone.;)\n");

  add_item("top","The top of the cliff you probably climbed to get here");
  add_item("sea|view","The sea looks magnificent from here, stretching out "+
           "like a huge, grey blue carpet, rolling and heaving. Beyond it "+
           "is the Larsia continent");
  add_item("carpet","It's not really a carpet. That was just a metaphor");
  add_item("wind","You can't see the wind, but you can sure feel it");
  add_item("Larsia|larsia|continent","You can easily make it out in the " +
           "distance");
  add_item("grass","It is pretty short here but it does grow. You can see "+
           "footprints in the grass too");
  add_item("footprint|footprints","Hmm, they look kinda like troll "+
           "footprints");
  add_item("troll footprints","Yes, they _are_ troll footprints!");
  add_item("ground","Short grass grows on it and there are some footprints "+
           "here");
  add_item("viewpoint","This place is a nice viewpoint as you have a "+
           "good view of the sea from here");
  add_item("drop|cliff","The steep cliff you climbed to get here. You would "+
           "have to climb back down it if you wanted to get back to the "+
           "shore");
  add_item("shore","It lies at the foot of the cliff");
  add_item("tree|trees","Really tall, really old pine trees. The woods "+
           "to the northeast look really dark");
  add_item("woods|forest","The forest around you looks very dark and old, "+
           "there's a barely noticable path entering it to the northeast");
  add_item("path","It's barely noticeable, and enters the woods to the "+
           "northeast. The same footprints that are on the ground here "+
           "can be seen on the path");

  add_exit(NROOM+"troll_woods1","northeast");

  add_sounds(30,80,({"The sharp wind from the sea is blowing into your face\n",
                     "The sound of seagulls is carried here from somewhere "+
                     "out to sea by the wind.\n",
                     "The trees around you are swaying in the strong winds "+
                     "from the sea.\n"}));
}

void init(void)
{
  "/sys/admin/room/admin_room"->visit(990);
  add_action("do_climb","climb");
  ::init();
}

int do_climb(string str)
{
  if(str == "down" || str == "d" || str == "slope" || str == "cliff")
  {
    W("You climb down the slope. It sure is a lot easier to climb down than "+
      "to climb up!\n");
    TP->move_player("climbs back down",
                    NROOM+"shore2",
                    "comes climbing down the cliff",
                    1);
    return 1;
  }
  notify_fail("Climb where?\n");
}
