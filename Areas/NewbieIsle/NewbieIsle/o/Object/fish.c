//======================================================================
// fish.c - Some fish you catch for the fish tale quest
//======================================================================
// Added decaying and catcher's name to the long desc
// Yoda - 990417
//----------------------------------------------------------------------
#pragma strict_types
#include "../def.h"
inherit STD_TREASURE;

void   create_object(void);
void   decay(void);
void   set_catcher(object player);
void   set_tale_told(void);
object query_catcher(void);
int    query_tale_told(void);
int    query_fish_tale_quest_fish(void);
void   init(void);
int    do_throw_it_back(string str);
int    do_eat(string str);

int    tale_told_for_this_fish;
object catcher;
string *names = ({"tiny fish",
                  "small fish",
                  "nice fish",
                  "big fish",
                  "huge fish"});
string *long_descs = ({"A really tiny fish. You sure are a sad excuse for a "+
                       "fisherman. I'd throw this one back if I were you.\n",
                       "This is a small fish. You feel sort of ashamed for "+
                       "even catching it. Perhaps it would be best to throw "+
                       "this one back.\n",
                       "Ah, a nice looking fish, this one. Quite respectable "+
                       "indeed. This is a keeper.\n",
                       "Oh, what a big fish! This one would be well worth "+
                       "telling a nice fish tale about.\n",
                       "Holy trout! This must be the biggest fish you've ever"+
                       " seen! And you've caught it! A mere fish tale would "+
                       "not suffice for this fish, it would take a fish "+
                       "LEGEND to do it justice!\n"});

void create_object(void)
{
  int i = random(5);
  set_name("fish");
  add_id(names[i]);
  add_id("_fish_tale_quest_fish_");
  set_short("A " + names[i]);
  set_long(long_descs[i]);
  set_weight(i + 1);
  set_value(i * 10);
  tale_told_for_this_fish = 0;

  set_alarm(3600.0,0.0,"decay");
  set_material("flesh"); //Angelwings
}

void decay(void)
{
  tell_room(ENV(TO),"The fish rots and decays into nothing.\n");
  destroy();
}

void set_catcher(object player)
{
  catcher = player;
  set_long(query_long_desc() + "This fish was caught by " + catcher->QN +
           ".\n");
}

void set_tale_told(void)
{
  tale_told_for_this_fish = 1;
}

object query_catcher(void)
{
  return catcher;
}

int query_tale_told(void)
{
  return tale_told_for_this_fish;
}

int query_fish_tale_quest_fish(void)
{
  return 1;
}

void init(void)
{
  add_action("do_throw_it_back","throw");
  add_action("do_eat","eat");
  ::init();
}

int do_throw_it_back(string str)
{
  if(ENV(TP)->query_fish_tale_quest_fishing_place())
  {
    if(str == "fish" || str == "fish back")
    {
      if(TP == catcher)
      {
        if(query_weight() > 2)
        {
          W("Come on! This fish is a keeper! You can't throw this one "+
            "back.\n");
          return 1;
        }
        else
        {
          W("You throw the fish back into the water and hope to catch a "+
            "bigger one instead.\n");
          S(TP->QN+" tries to look innocent as "+TP->QPR+" throws "+TP->QPO+
            " little sad-excuse-for-a-catch fish back into the water.\n");
          ENV(TP)->threw_one_back();
          TO->destroy();
          return 1;
    }
      }
      else
      {
        W("Hey, you didn't catch this fish. Don't throw other people's "+
          "fish back!\n");
        S(TP->QN+"looks sort of guilty all of a sudden.\n");
        return 1;
      }
    }
  }
}

int do_eat(string str)
{
  if(str == "fish")
  {
    W("You don't really think a raw fish will taste very well so "+
      "you decide not to eat it.\n");
    S(TP->QN + " takes a few bites out of the fish and turns a bit "+
    "green.\n");
    return 1;
  }
}
