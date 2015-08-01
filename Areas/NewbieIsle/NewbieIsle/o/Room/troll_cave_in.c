#pragma strict_types
#include "../def.h"
inherit MASTER_ROOM;

void   create_object(void);
int    query_room_id(void);
void   init(void);
int    do_move(string str);
string long_fun(void);
void   rock_desc(void);
void   opening_desc(void);

void create_object(void)
{
  set_short("In a dark cave (nw)");
  set_long("#long_fun");
  set_new_light(1);
  add_property("indoors");
  set_room_hint("If you're not strong enough to move the stone on your "+
                "own, you could try get someone to help you. If more "+
                "people push it at the same time, it might be easier to "+
                "move it.;) Beware though. The trolls live in this cave "+
                "and they are here during the day and come out at night.\n");

  add_item("cave","The cave continues to the northwest, but the "+
           "horrible smell seems to come from there so perhaps it would "+
           "be best not to go there");
  add_item("%|%odour|%smell","Blaeh! It is a really horrible smell!");
  add_item("odour","You can't see it, but you sure can smell it!");
  add_item("rock","#rock_desc");
  add_item("opening","#opening_desc");

  add_exit(NROOM+"troll_cave","northwest");
}

// Trolls use this function to know which room they 
// are in and which way to go when they return home
int query_room_id(void)
{
  return 12;
}

void init(void)
{
  add_multi_action("do_move","move|push");
/*
  add_action("do_smell","smell");
*/
  ::init();
}

int do_move(string str)
{
  if(str == "rock" || str == "stone" || str == "boulder")
  {
    if(TP->query_race() == "newbie island troll")
    {
      if(!((NROOM+"troll_cave_out")->query_rock_moved()))
      {
        S("The troll pushes the boulder covering the opening.\n");
      }
      else
      {
        S("The troll drags the boulder back in front of the opening.\n");
      }
      (NROOM+"troll_cave_out")->rock_moves();
      return 1;
    }

    if((NROOM+"troll_cave_out")->query_rock_moved())
    {
      W("The stone is too big for you to be able to pull it back in front " +
        "of the opening.\n");
      return 1;
    }

    W("You lean against the boulder and try to push it away from the opening.\n");
    S(TP->QN + " tries to move the boulder.\n");      

    if(random(TP->query_str()) >= 5)
    {
      (NROOM+"troll_cave_out")->rock_moves();
      return 1;
    }
    else
    {
      W("The stone is too heavy. You almost managed to move it, but not " +
        "quite. Perhaps if you try again?\n");
      S(TP->QN + " looks exhausted and stops pushing the rock.");
      return 1;
    }
  }
  notify_fail(C(query_verb())+" what?\n");
}

string long_fun(void)
{
  if(!(NROOM+"troll_cave_out")->query_rock_moved())
  {
    return "You are in a dark, cold cave. The smell here is appalling, "+
           "and the odour seems to come from the northwest, where the cave "+
           "seems to become bigger. There is an opening here, but it is "+
           "covered by a big rock.\n";
  }
  else
  {
    return "You are in a dark, cold cave. The smell here is appalling, "+
           "and the odour seems to come from the northwest, where the cave "+
           "seems to become bigger. There is an opening here, and you "+
           "think it might be a good idea to use it!\n";
  }
}

void rock_desc(void)
{
  if(!(NROOM+"troll_cave_out")->query_rock_moved())
  {
    W("A big rock, covering the opening. It looks heavy, "+
      "but you could still try to move it.\n");
  }
  else
  { 
    W("Somebody has pushed the rock from the opening.\n");
  }
}

void opening_desc(void)
{
  if(!(NROOM+"troll_cave_out")->query_rock_moved())
  {
    W("The opening is covered by the big rock!\n");
  }
  else
  {
    W("The opening leads back out into the forest. The rock that was "+ 
      "covering it is on the outside.\n");
  }
}
