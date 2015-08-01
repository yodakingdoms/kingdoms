#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;
inherit MOD_SOUND;

void   create_object(void);
void   reset(int arg);
void   init(void);
int    do_use(string str);
int    do_think(string str);
int    do_build(string str);
int    do_leave(void);
void   done_building(void);
int    do_climb(string str);
string long_fun(void);
void   sand_desc(void);
void   cliff_desc(void);
void   rock_desc(void);
void   weed_desc(void);

object builder;
int rocks_moved;

void create_object(void)
{
  set_short("A sheltered beach");
  set_long("#long_fun");
  set_new_light(5);
  set_dragon_visibility(1);
  set_room_hint("Hmm, looks like you really need to _think_ to come up "+
                "with a way of using those rocks, huh?. Sometimes it pays "+
                "to literally do what the hints say, so try to think!;)");

  add_item("beach","A narrow, tranquil beach on the west side of "+
           "the island");
  add_item("island","Well, from where you're standing, you can't really "+
           "see that much of it");
  add_item("shadow|shade","Shade provided by the trees at the top of the "+
           "cliff");
  add_item("tree|trees","They grow up on top of the cliff. Their branches "+
           "reach out over the beach, providing shadow");
  add_item("branch|branches","The things that grow on trees. These particular"+
           " ones don't seem very strange");
  add_item("edge","The edge is quite a way up there. Grass is growing over "+
           "the edge");
  add_item("grass","Grass growing on top of the cliff, sticking out over "+
           "the edge");
  add_item("vegetation","The only vegetation down here are the weeds growing "+
           "in the shallow water");
  add_item("water","The water is clear here near the beach. There are "+
           "weeds growing in the shallows");
  add_item("sea","The sea that lies between Larsia and Kordar");
  add_item("Larsia|larsia|continent","It lies far to the west. It can't be "+
           "as far as it seems from here though, considering you rowed "+
           "here from there");
  add_item("sand","#sand_desc");
  add_item("cliff|cliffwall|cliffside","#cliff_desc");
  add_item("pile|rock|rocks","#rock_desc");
  add_item("weeds","#weed_desc");
  

  add_exit(NROOM+"shore1","southeast");
  
  add_sounds(30,80,({"The waves lap gently against the shoreline.\n",
		     "The waves cluck softly against the rocks among the "+
                     "weeds in the shallow water.\n",
		     "The wind ruffles the leaves in the branches over "+
	             "your head softly.\n",
		     "A bird is singing in one of the trees at the top of "+
                     "the steep cliffside.\n"}));
  reset(0);
}

void reset(int arg)
{
  if(rocks_moved)
  {
    tell_room(TO,"The heap of rocks tumbles to the ground.\n");
    rocks_moved = 0;
  }
}

void init(void)
{
  add_action("do_use","use");
  add_action("do_think","think");
  add_action("do_think","ponder");
  add_action("do_build","stack");
  add_action("do_build","gather");
  add_action("do_build","build");
  add_action("do_leave","se");
  add_action("do_leave","southeast");
  add_action("do_climb","climb");
}

int do_use(string str)
{
  if(str == "rocks" || str == "rock")
  {
    W("You need to _think_ up a way of using the rocks before you do can "+
      "use them.\n");
    S(TP->QN+" seems to try to use the rocks somehow.. Strange.\n");
    return 1;
  }
}

int do_think(string str)
{
  if(str == "harder than that" || str == "hard" || str == "harder")
  {
    W("Hmm, perhaps you could stack the rocks against the cliffwall and "+
      "build a heap you could climb to get to the top?\n");
    S(TP->QN+" goes: Heureka!\n");
    return 1;
  }

  W("No.. You would have to think harder than that.\n");
  
  if(TP->query_int() > 10)
  {
    S(TP->QN+" tries to think but fails due to sheer stupidity.\n");
  }
  else
  {
    S(TP->QN+" thinks carefully.\n");
  }
  return 1;
}
  
int do_build(string str)
{
  if(query_verb() == "stack" && (str != "rocks" && 
     str != "rocks against cliffwall" && str != "rocks against cliffside" &&
     str != "rocks against cliff"))
  {
    W("Stack what against what?\n");
    return 1;
  }

  if(query_verb() == "gather" && str != "rocks")
  {
    W("Gather what?\n");
    return 1;
  }

  if(query_verb() == "build" && str != "heap")
  {
    W("Build what?\n");
    return 1;
  }

  if(builder)
  {
    W(builder->QN+" is already doing that.\n");
    S(TP->QN+" looks as if "+TP->QPR+" wants to build too!\n");
    return 1;
  }

  if(rocks_moved)
  {
    W("The rocks are already stacked nicely against the cliffside.\n");
    S(TP->QN+" looks thoughtfully at the rocks stacked against the "+
      "cliffside.\n");
    return 1;
  }

  W("You start gathering rocks to stack against the cliffside.\n");
  S(TP->QN+" starts gathering rocks and stacking them against the "+
    "cliffside.\n");
  builder = TP;
  set_alarm(2.5,0.0,"done_building");
  return 1;
}

int do_leave(void)
{
  if(TP == builder)
  {
    W("You leave the half finished pile behind.\n");
    S(builder->QN+" stops piling the rocks and leaves.\n");
    builder = 0;
  }
}

void done_building(void)
{
  if(builder)
  {
    tell_object(builder,"You finish piling the rocks against the wall and "+
                "take a step back to admire your work. There is now a nice "+
                "pile of rocks stacked against the cliffwall, making it "+
                "easy to climb.\n");
    // Changed TP to builder in the exclude list below
    // Yoda 2003-09-21 
    tell_room(TO,builder->QN+" finishes stacking the rocks against the cliff"+
              "side and takes a step back to admire "+builder->QPO+" work.\n",builder);
    rocks_moved = 1;
    builder = 0;
    return;
  }
  tell_room(TO,"The half built pile tumbles to the ground again.\n");
}
    
int do_climb(string str)
{
  if(str == "cliffwall" || str == "cliffside" || str == "cliff")
  {
    if(rocks_moved)
    {
      W("Would it not be easier to climb the heap of rocks?\n");
      S(TP->QN+" looks at the cliffwall.\n");
      return 1;
    }

    if(TP->query_skill("climb") < 50 + random(20))
    {
      W("You climb halfway up the cliffside, but then you fall to the ground "+
        "again with a *BUMP*! Ouch!\n");
      S(TP->QN+" tries to climb the cliffside, but falls to the ground "+
        "with a *BUMP*!\n");
      TP->add_temporary_penalty((2+random(5)));
      return 1;
    }
    else
    {
      W("You climb the side of the cliff with ease.\n");
      TP->move_player("climbs the cliffside with ease",
                      NROOM+"viewpoint", 
                      "comes climbing up the cliffside",1);
      return 1;
    }
  }

  if(str == "pile" || str == "rocks" || str == "heap" || str == "up")
  {
    if(rocks_moved)
    {
      W("You climb the heap of rocks with ease.\n");
      TP->move_player("climbs the heap of rocks with ease",
                      NROOM+"viewpoint",
                      "comes climbing up the heap of rocks",1);
      return 1;
    }
  }   

  W("Climb what?\n");
  return 1;
}

string long_fun(void)
{
  if(!rocks_moved)
  {
    return "The narrow beach ends here, in the shade of the trees "+
           "growing up on the edge of the cliff to the northeast "+
           "and the north. You see grass sticking out over the edge, "+
           "but on the cliffside itself, there is no vegetation. "+
           "There are a few rocks here and there in the sand and "+
           "among the weeds growing in the shallow water. To the "+
           "west is the sea, and far in the distance you see the "+
           "Larsia continent.\n";
  }
  else
  {
    return "The narrow beach ends here, in the shade of the trees "+
           "growing up on the edge of the cliff to the northeast and "+
           "to the north. You see grass sticking out over the edge, "+
           "but on the cliffside itself, there is no vegetation. "+
           "Someone has gathered a pile of rocks and stacked them "+
           "against the cliffside here, making it easy to climb up. "+
           "There are weeds growing in the shallow water. To the "+
           "west is the sea, and far in the distance you see the "+
           "Larsia continent.\n";
  }
}

void sand_desc(void)
{
  if(!rocks_moved)
  {
    W("The white sand is cool here in the shade. There are a "+
           "few rocks here and there in the sand.\n");
  }
  else
  {
    W("The white sand is cool here in the shade.\n");
  }
}

void cliff_desc(void)
{
  if(!rocks_moved)
  {
    W("The cliffwall is very steep and there does not seem to be much "+
      "to grab on to use as a foothold. If you want to climb it, you "+
      "will really have to think hard and come up with a smart way of "+
      "doing it.\n");
  }
  else
  {
    W("There is a pile of rocks stacked neatly against the cliffside, "+
      "making it easy to climb.\n");
  }
}

void rock_desc(void)
{
  if(!rocks_moved)
  {
    W("There are a few rocks here and there in the sand on the beach, "+
      "and also a few among the weeds growing in the shallow water. Hmm "+
      "perhaps you could think up a way of using those rocks...\n");
  }
  else
  {
    W("There is a pile of rocks stacked against the cliffwall, reaching "+
      "all the way to the top. It would be easy to climb up there now!\n");
  }
}

void weed_desc(void)
{
  if(!rocks_moved)
  {
    W("There are some weeds growing in the shallow water near the beach. "+
      "There are some rocks among them.\n");
  }
  else
  {
    W("There are some weeds growing in the shallow water near the beach.\n");
  }
}
