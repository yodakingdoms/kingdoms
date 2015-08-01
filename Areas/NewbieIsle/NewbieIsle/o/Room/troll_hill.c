#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void create_object(void);
void init(void);
string long_fun(void);
void ground_desc(void);
void depression_desc(void);
void trapdoor_desc(void);
int  do_open(string str);
int  do_close(string str);
int  do_lean(string str);
int  do_climb(string str);
void troll_desc(string str);
int  query_trapdoor_open(void);

void create_object(void)
{
  set_short("A hill in the forest (sd)");
  set_long("#long_fun");
  set_new_light(5);
  set_dragon_visibility(1);

  add_item("top|hill","You are at the top of it. It is deep inside the woods");
  add_item("forest|woods","You are deep inside now. Hope you'll be able "+
           "to find your way out");
  add_item("ground","#ground_desc");
  add_item("depression|strange depression|square shaped depression",
           "#depression_desc");
  add_item("trapdoor|trap door","#trapdoor_desc");
  add_item("moss","A brown moss that seems to grow everywhere in the " +
           "forest. There is a strange square shaped depression in the moss " +
           "on the ground here");
  add_item("stone|stones","The stones seem to have been arranged in a "+
           "circle once. Now they've fallen apart and been overgrown by "+
           "moss, but they seem to have been forming a wall round the top "+
           "of the hill once");
  add_item("circle","A circle of stones that looks as if it's been a wall "+
           "some time long ago");
  add_item("wall","It could still be used to defend this hill, but it's "+
           "not in a good shape");
  add_item("slope","The north slope is way too steep to climb. There is "+
           "a clearing down there");
  add_item("clearing","It's down there to the north. Perhaps if you "+
           "would lean over the wall (or what's left of it) you could "+
           "see it more clearly");
  add_item("troll|trolls","#troll_desc");
  add_item("tree|trees","As you try to get a good look at the forest around "+
           "you, all you see are the ancient trees");

  add_exit(NROOM+"troll_woods5","southdown");
}

void init(void)
{
  "/sys/admin/room/admin_room"->visit(885);
  (NROOM+"troll_clearing")->load_me();
  add_action("do_lean","lean");
  add_action("do_open","open");
  add_action("do_close","close");
  add_action("do_climb","climb");
  ::init();
}

string long_fun(void)
{
   if(!query_trapdoor_open())
   {
      return "You are at the top of a small hill in the middle of the "+
             "forest. The ground here is stony and brown moss grows every"+
             "where. The stones here look somehow different from those in "+
             "the rest of the forest, though. Almost as if they have been "+
             "placed here in an orderly fashion. As you look down the north "+
             "slope of the hill, you see a clearing, and in all other "+
             "directions you see nothing but the old trees.\n";
   }
   else
   {
      return "You are at the top of a small hill in the middle of the "+
             "forest. The ground here is stony and brown moss grows every"+
             "where. The stones here look somehow different from those in "+
             "the rest of the forest, though. Almost as if they have been "+
             "placed here in an orderly fashion. As you look down the north "+
             "slope of the hill, you see a clearing, and in all other "+
             "directions you see nothing but the old trees. There is an " +
             "open trapdoor in the ground.\n";
   }
}

void ground_desc(void)
{
   if(!query_trapdoor_open())
   {
      W("The ground here is as stony as everywhere else in "+
        "the forest. There are no footprints up here though and the "+
        "stones seem to have been placed in an orderly manner. There is "+
        "a depression in the ground that looks a bit strange.\n");
   }
   else
   {
      W("The ground here is as stony as everywhere else in "+
        "the forest. There are no footprints up here though and the "+
        "stones seem to have been placed in an orderly manner. There is "+
        "an open trapdoor in the ground.\n");
   }
}

void depression_desc(void)
{
   if(!query_trapdoor_open())
   {
      W("It's a depression in the ground, shaped like a trapdoor.\n");
   }
   else
   {
      W("There is no depression here.\n");
   }
}

void trapdoor_desc(void)
{
   if(!query_trapdoor_open())
   {
      W("It looks as if there is a trapdoor in the ground. It is " +
        "covered by moss but it looks like you could open it anyway.\n");
   }
   else
   {
      W("There is an open trapdoor in the ground. You can see a ladder " +
        "going down into the room below.\n");
   }
}

int do_open(string str)
{
  if(str == "trapdoor" || str == "trap door")
  {
    if(!query_trapdoor_open())
    {
      W("You push the trapdoor and it swings downwards, revealing a " +
        "ladder going down into a room below the hill.\n");
      S(TP->QN + " opens a trapdoor in the ground.\n");
      PIRATECAVES_ENTRANCE->trapdoor_opens();
      return 1;
    } else {
      W("The trapdoor is already open.\n");
      return 1;
    }
  }
}

int do_close(string str)
{
  if(query_trapdoor_open())
  {
    if(str == "trapdoor" || str == "trap door")
    {
      W("The trapdoor swings downwards and can't be closed from up here. " +
        "You would have to go down there to close it.\n");
      return 1;
    }
  }
  else
  {
    W("The trapdoor is already closed.\n");
    return 1;
  }
}

int do_climb(string str)
{
  if(!query_trapdoor_open()) return 0;

  if(str == "ladder" || str == "down")
  {
    W("You climb down the ladder.\n");
    TP->command("down");
    return 1;
  }
  notify_fail("Climb what?\n");
}

int do_lean(string str)
{
  int i,number_of_trolls,number_of_stones;
  object clearing = find_object((NROOM+"troll_clearing"));
  object *trolls = all_inventory(clearing);

  if(str != "over wall" && str != "over the wall" && str != "over stones")
  {
    W("Lean over what?\n");
    return 1;
  }

  for(i = 0; i < sizeof(trolls); ++i)
  {
    if(trolls[i]->query_race() == "newbie island troll")
    {
      ++number_of_trolls;
    }
    else
    if(trolls[i]->query_name() == "stone troll")
    {
      ++number_of_stones;
    }
  }
  W("There is a small clearing in the forest at the foot of the hill.\n");
  if(number_of_trolls)
  {
    number_of_trolls += number_of_stones;

    switch(number_of_trolls)
    {
      case 1: W("You see a troll strolling about in the moonlight down "+
                "there!\n");
        break;
      case 2: W("You see two trolls strolling about in the moonlight "+
                "down there!\n");
        break;
      default: W("You see some trolls strolling about in the moonlight down "+
                 "there!\n");
        break;
    }
  }
  if(number_of_stones && !number_of_trolls)
  {
    switch(number_of_stones)
    {
      case 1: W("You see a troll standing down there!\n");
        break;
      case 2: W("You see two trolls standing down there!\n");
        break;
      default: W("You see some trolls down there!\n");
        break;
    }
  }
  S(TP->QN+" leans over the stones and looks down into the clearing "+
    "to the north.\n");
  return 1;
}

void troll_desc(string str)
{
  int i,number_of_trolls,number_of_stones;
  object clearing = find_object((NROOM+"troll_clearing"));
  object *trolls = all_inventory(clearing);

  for(i = 0; i < sizeof(trolls); ++i)
  {
    if(trolls[i]->query_race() == "newbie island troll")
    {
      ++number_of_trolls;
    }
    else
    if(trolls[i]->query_name() == "stone troll")
    {
      ++number_of_stones;
    }
  }

  if(number_of_stones && !number_of_trolls)
  {
    if(number_of_stones == 1)
    {
      W("Hmm, when you take a closer look at the troll you think it "+
        "seems very... rigid somehow...\n");
    }
    else
    {
      W("Hmm, when you take a closer look at the trolls you think "+
        "they seem very... rigid somehow.\n");
    }
  }
  else
  if(number_of_trolls)
  {
    number_of_trolls += number_of_stones;

    if(number_of_trolls == 1)
    {
      W("It's walking around down there in the clearing! "+
        "Better watch out!\n");
    }
    else
    {
      W("They are walking around down there in the clearing! "+
        "better watch out!\n");
    }
  }
  else
  {
    switch(str)
    {
      case "troll": case "Troll": W("There is no "+str+" here.\n");
        break;
      case "trolls": case "Trolls": W("There are no "+str+" here.\n");
        break;
    }
  }
}

int query_trapdoor_open(void)
{
  return PIRATECAVES_ENTRANCE->query_trapdoor_open();
}
