//===================================================================
// A newbie armour that you get from the cave the trolls live in.
// It is actually too good, but you have to be below lvl 5 to be able
// to use it so it should be ok. If not I will add some more things
// to it later to restrict it.
// Yoda 970419
//-------------------------------------------------------------------
// Made uninnable per Shade's request. (I might just get the area open
// before the two year anniversary of the above comment, heh ;)
// Yoda 990410
//===================================================================
#pragma strict_types
#include "../def.h"
inherit STD_ARMOUR;

void  create_object(void);
mixed query_prevent_login(void);
int   wearing_func(void);
int   removing_func(void);
void  owner_died(void);

int transformed;

void create_object(void)
{
  set_name("sack");
  add_id("armour");
  add_id("armour sack");
  remove_id("mithril chainmail");
  remove_id("chainmail");
  set_short("An armour sack");
  set_long("This looks like a sack that has had holes cut in it to stick "+
           "arms and head through so you should be able to wear it like an "+
           "armour. (Why you would want to wear a sack like an armour is "+
           "beyond me though)\n");
  set_type("armour");
  set_property(({"magic","poor"}));
  set_material("cloth");
  set_weight(1);
  set_value(1);
  set_new_ac(1);
  set_db(0);
  set_wear_object(TO);
  set_remove_object(TO);
  transformed = 0;
}

// Added 990410 - Yoda
mixed query_prevent_login(void)
{
  return 1;
}

int wearing_func(void)
{
  int i;
  object *worn_stuff;

  if(TP->query_level() > 4 && TP->query_level() < LEVELS_NEWBIE)
  {
    return 1;
  }

  worn_stuff = TP->query_armours();

  for(i = 0; i < sizeof(worn_stuff); ++i)
  {
    if(worn_stuff[i]->query_type() == "armour")
    {
      W("You are already wearing armour covering that bodypart, and that "+
        "is "+lower_case(worn_stuff[i]->short())+".\n");
      return 0;
    }
  }
  W("There is a bright flash of light as you wear the\n"+
    "sack and it turns into a shining mithril chainmail!\n");
  S(TP->QN+" pulls the sack over "+TP->QPO+" head to wear it, and suddenly, "+
   "in a bright flash of light, it turns into a wonderful piece of armour!\n");

  set_name("mithril chainmail");
  add_id("chainmail");
  remove_id("sack");
  remove_id("armour sack");
  set_short("A shining mithril chainmail");
  set_long("A wonderfully crafted mithril chainmail. This will give you "+
           "very nice protection indeed. You can almost feel the magic "+
           "flowing through it!\n");
  set_property(({"godlike","magic"}));
  set_material("mithril");
  set_weight(3);
  set_new_ac(25);
  set_db(5);
  transformed = 1;
  return 1;
}

int removing_func(void)
{
  if(transformed)
  {
    W("As you remove the chainmail there is a flash of bright light and "+
      "it turns into a sack again!\n");
    S(TP->QN+" removes the chainmail and there is a bright flash of light "+
      "as it turns into a normal sack!\n");
    create_object();
    return 1;
  }
  return 1;
}

void owner_died(void)
{
  if(transformed)
  {
    create_object();
  }
}

