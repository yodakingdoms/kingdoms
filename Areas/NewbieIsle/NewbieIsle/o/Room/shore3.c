/* crazy kids have problem with cloud passing in front of the sun - at night
 * so I fixed it. - Pathfinder 10.10.00
 */

#pragma strict_types
#include "../def.h"

inherit MASTER_ROOM;
inherit MOD_SOUND;

void create_object(void);
void init(void);
int  do_climb(string str);
int  do_swim(string str);
int  do_wade(string str);
int  do_search(string str);

void create_object(void)
{
  int hour; /* time of day */
  string foo; /* what person sees when looking into the sky */

  set_short("A calm shore");
  set_long("You are at the south end of a small sandy beach on the west side "+
           "of the island. The slope to the east is way too steep to climb "+
           "here. There is some wooden debris in the sand here, that seems "+
           "to be the remains of a rowboat. A big stone lies a few feet out "+
           "into the shallow water near the shore. The beach goes back to "+
           "the north, and to the west is the sea, with the Larsia continent "+
           "far in the distance.\n");
  set_new_light(5);
  set_dragon_visibility(1);
  //  set_room_hint("Closer examination of things like debris, junk or "+
  //                "wreckage is rewarded in many places in the Kingdoms.;)\n");
  // This will perhaps be here later - Yoda

  add_item("beach","You are at the south end of it now. The sand is white "+
           "and cool");
  add_item("sand","The white sand is cool, as it's been in the shade for "+
           "quite a while");
  add_item("shade","Shade provided by the trees up on the slope");
  add_item("tree|trees","The trees up there on the slope provide shade for "+
           "the beach here");
  add_item("island","You are on the west side of it now, but from where you "+
           "are, you don't see much of it at all");
  add_item("slope","A steep, grassy slope which you won't be able to climb");
  add_item("debris|skeleton","It is the wooden skeleton of an old rowboat "+
           "that must have stranded here a long time ago");
  add_item("remains|rowboat","There's not much left of it now. Only the "+
           "wood that hasn't rotted away yet");
  add_item("wood","Most of it looks pretty rotten");
  add_item("stone","The big stone lies a few yards out into the water. It "+
           "does look close enough and the water looks shallow enough that "+
           "you think you will be able to wade out to it");
  add_item("water","The water looks very clear here, and the waves lap "+
           "gently against the shore");
  add_item("waves","They lap gently against the shore");
  add_item("shore","The waves lap gently against it");
  add_item("sea","Looks like most seas. Blue and gray and very big");
  add_item("Larsia|larsia|continent","You see it far in the distance to the "+
           "east");

  add_exit(NROOM+"shore1","north");

  hour = query_daylight();
  switch (hour)
  {
    case 0: /* night */
      foo = "moon";
      break;
    case 1..3: /* dawn, daylight, dusk */
      foo = "sun";
      break;
    default: /* not supposed to happen */
      foo = "rectangular football";
      break;
  }

  add_sounds(30,80,({"The waves lap gently against the shoreline.\n",
                     "A cloud passes in front of the "+foo+" for a moment.\n",
                     "A wooden tub with someone sitting in it drifts by "+
                     "the island.\n"}));

}

void init(void)
{
  add_action("do_climb", "climb");
  add_action("do_swim",  "swim");
  add_action("do_wade",  "wade");
  add_action("do_search","search");
  ::init();
}

int do_climb(string str)
{
  if(str == "slope")
  {
    W("Didn't you look at it? If you did, you saw you won't be able to "+
      "climb it, duh.\n");
    S(TP->QN+" stares dreamily at the slope.\n");
    return 1;
  }
  notify_fail("Climb what?\n");
}

int do_swim(string str)
{
  if(str == "water" || str == "in water" || str == "sea" || str == "in sea")
  {
    W("The water does look nice, but you think you have more important "+
      "things to do.\n");
    return 1;
  }
  notify_fail("Swim where?\n");
}

int do_wade(string str)
{ 
  if(str == "stone" || str == "to stone" || str == "out to stone" || 
     str == "out")
  {
    W("You pull the legs of your trousers up a bit and start wading out "+
      "to the stone. Looks as if the water was a bit deeper than it first "+
      "looked, but you still manage to get there with no problems.\n");
    TP->move_player("wades out to the stone",
                    NROOM+"fishing_stone",
                    "crawls up onto the stone beside you",
                    1);
    return 1;
  }
  notify_fail("Wade where?\n");
}

int do_search(string str)
{
  if(str == "debris" || str == "rowboat" || str == "remains")
  {
    W("You search the debris, but there is nothing salvagable there.\n");
    return 1;
  }
}
