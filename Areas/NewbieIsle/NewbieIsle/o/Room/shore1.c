#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_SOUND;

void create_object(void);
void init(void);
int  do_swim(string str);

void create_object(void)
{
  set_short("A calm shore");
  set_long("You are standing on a small sandy beach on the west side of "+
           "the island. To the east and northeast is a steep, grassy "+
           "slope up to the rest of the island, and you notice a path "+
           "leading up there between the shrubbery and trees to the "+
           "northeast. The sheltered narrow shoreline seems almost to be "+
           "cradled in the lap of the island as the trees growing on the "+
           "slope reach out over you, shading the beach. The shore stretches "+
           "a short way to the south and to the northwest. To the west is "+
           "the sea, and far in the distance you make out the Larsian "+
           "continent.\n");
  set_new_light(5);
  set_room_hint("This is the place you enter this area in. A good way to find"+
                " out where you are, is to type 'creator'. It will tell you "+
                "which area and kingdom you are in, as well as the wizards "+
                "to bug if you find something wrong with it.;)");

  add_item("beachline|beach","A narrow sandy beachline, only a few yards "+
           "wide between the grassy slope and the water's edge");
  add_item("water|water's edge|edge","The water is clear and laps gently "+
           "against the sandy shore");
  add_item("shore|stretch","The shore is basically just a narrow stretch of "+
           "sand between the water and the steep slope");
  add_item("grass","Tall grass grows among the trees and bushes on the "+
           "steep slope");
  add_item("sand","White, fine sand, cooled by the shade provided by the "+
           "trees on the slope");
  add_item("shade|shadow","A nice shade provided by the trees hanging out "+
           "over the beach");
  add_item("island","Well, you don't see that much of it at the moment. "+
           "You would have to follow the path up the slope to do that");
  add_item("slope","The slope is steep but shrubbery and trees still "+
           "find hold among the tall grass. A path leads up the slope "+
           "towards the northeast");
  add_item("path","A narrow path winding its way up the slope between "+
           "the bushes and undergrowth. It looks well travelled");
  add_item("shrubbery|undergrowth","There is a lot of that on the steep "+
           "slope");
  add_item("bushes|bush","Many bushes grow on the steep slope");
  add_item("tree|trees","The trees clinging to the steep slope reach out "+
           "over the beach, leaving it mostly in shadow");
  add_item("branches","The branches hang out above you over the beach, " +
           "leaving it mostly in shadow");
  add_item("branch","You don't notice any particular branch that looks " +
           "different from all the others. They all look pretty much " +
           "the same");
  add_item("shoreline","The narrow beach stretches to the south and "+
           "the northwest");
  add_item("lap","It somehow feels like you are safely cradled in the "+
           "lap of the island as you stand here");
  add_item("sea","The sea you rowed across to get to this island! Well, "+
           "the Larsia continent is not quite a whole sea away, but "+
           "you still rowed quite far!");
  add_item("Larsia|larsia|continent","It is there on the horizon. It "+
           "looks so far away, but perhaps the movement of the sea is "+
           "just tricking your eyes..");
  add_item("movement","The sea rolls and rolls and rolls... You almost "+
           "get seasick just looking at it. You still have to get back "+
           "somehow, so perhaps getting seasick is not a good idea. You "+
           "turn away");
  add_item("horizon","Yep, the horizon is still there!");

  add_exit(NROOM+"shore2","northwest");
  add_exit(NROOM+"shore3","south");
  add_exit(NROOM+"slope","northeast");

  add_sounds(30,80,({"The waves lap gently against the shoreline.\n",
                     "You see a galley ship pass by far on the horizon.\n",
                     "The wind ruffles the leaves in the branches over "+
                     "your head softly.\n",
                     "A bird is singing in one of the trees on the steep "+
                     "slope.\n"}));

}

void init(void)
{
  add_action("do_swim","swim");
  ::init();
}

int do_swim(string str)
{
  if(str == "water" || str == "in water" || str == "sea" || str == "in sea")
  {
    W("It would be wonderful to take a swim now, but don't you "+
      "think it would be more fun to go up the slope and explore "+
      "the island?\nYou think to yourself: Yes it would.\n"+
      "You decide not to swim right now.\n");
    S(TP->QN + " looks at the water, the the path up the slope and "+
      "seems to ponder something.\n");
    return 1;
  }
  W("Where do you want to swim?\n");
  return 1;
}


